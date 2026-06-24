#include <Adafruit_Fingerprint.h>
#include <Servo.h>
#include <Wire.h>
#include <Adafruit_PN532.h>
#include <Arduino_RouterBridge.h>

Adafruit_Fingerprint finger = Adafruit_Fingerprint(&Serial1);
Servo myservo;
Adafruit_PN532 nfc(20, 21);

const int SERVO_PIN = 9;
const int LED_PIN = 7;
int BUZZER = 8;

const uint8_t TARJETA_A[]    = {0xDE, 0x14, 0x29, 0x6E};
const uint8_t TARJETA_C[]    = {0x1C, 0x3F, 0x04, 0x30};
const uint8_t CELU_VICENTE[] = {0x01, 0x02, 0x03, 0x04};
const uint8_t AMIIBO_PEACH[] = {0x04, 0xF3, 0x09, 0x92, 0x99, 0x3C, 0x84};

bool candado_abierto = false;
bool abierto_por_web = false;
unsigned long tiempo_apertura = 0;
const unsigned long TIEMPO_ABIERTO = 7000;

void abrir_candado(const char* metodo) {
  Serial.print("Desbloqueando cerrojo via: ");
  Serial.println(metodo);
  digitalWrite(LED_PIN, HIGH);
  myservo.write(180);
  candado_abierto = true;
  tiempo_apertura = millis();
  Bridge.call("notificar_abierto_con_metodo", String(metodo));
}

void cerrar_candado() {
  Serial.println("Cerrando cerrojo...");
  myservo.write(90);
  digitalWrite(LED_PIN, LOW);
  candado_abierto = false;
  abierto_por_web = false;
  Bridge.call("notificar_cerrado", true);
  Serial.println("\nEsperando nueva huella o tarjeta...");
}

void cmd_abrir(bool state) {
  abierto_por_web = true;
  abrir_candado("Página Web");
}

void cmd_cerrar(bool state) { cerrar_candado(); }

void setup() {
  Serial.begin(9600);
  delay(3000);
  Serial.println("\n--- XENTLOCK: SISTEMA DE ACCESO CONTROLADO ---");

  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  pinMode(BUZZER, OUTPUT);

  myservo.attach(SERVO_PIN);
  myservo.write(90);
  Serial.println("[INFO] Servomotor inicializado y BLOQUEADO (90°). LED apagado.");

  Serial1.begin(57600);
  delay(500);

  if (finger.verifyPassword()) {
    Serial.println("[OK] Sensor de huellas AS608 detectado.");
  } else {
    Serial.println("[ERROR] No se encuentra el sensor de huellas :(");
    while (1) { delay(1); }
  }

  nfc.begin();
  uint32_t versiondata = nfc.getFirmwareVersion();
  if (versiondata) {
    Serial.println("[OK] Sensor NFC PN532 detectado.");
    nfc.SAMConfig();
  } else {
    Serial.println("[ERROR] No se encuentra el sensor NFC PN532 :(");
  }

  Bridge.begin();
  Bridge.provide("abrir", cmd_abrir);
  Bridge.provide("cerrar", cmd_cerrar);

  Serial.println("Esperando huella, tarjeta NFC o comando web...");
}

void loop() {
  if (candado_abierto && (millis() - tiempo_apertura >= TIEMPO_ABIERTO)) {
    Serial.println("Tiempo agotado. Cerrando automáticamente...");
    cerrar_candado();
  }

  if (!candado_abierto) {
    int result = getFingerprintID();
    if (result > 0) {
      Serial.print("[ACCESO CONCEDIDO] Huella Usuario ID #");
      Serial.println(result);
      String metodo = "Huella Digital #" + String(result);
      abrir_candado(metodo.c_str());
    }
    revisarTarjetaNFC();
  }

  delay(50);
}

int getFingerprintID() {
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK) return -1;
  p = finger.image2Tz();
  if (p != FINGERPRINT_OK) return -1;
  p = finger.fingerFastSearch();
  if (p == FINGERPRINT_OK) {
    return finger.fingerID;
  } else {
    Serial.println("[ACCESO DENEGADO] Huella no registrada en el sistema.");
    return -1;
  }
}

void revisarTarjetaNFC() {
  uint8_t success;
  uint8_t uid[] = { 0, 0, 0, 0, 0, 0, 0 };
  uint8_t uidLength;

  success = nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, uid, &uidLength, 30);

  if (success) {
    if (uidLength == 7 && memcmp(uid, AMIIBO_PEACH, 7) == 0) {
      Serial.println("\n[ACCESO CONCEDIDO] Amiibo Peach detectado.");
      abrir_candado("Amiibo Peach");
    }
    else if (uidLength == 4 && memcmp(uid, TARJETA_A, 4) == 0) {
      Serial.println("\n[ACCESO CONCEDIDO] Tarjeta A detectada.");
      abrir_candado("Tarjeta A NFC");
    }
    else if (uidLength == 4 && memcmp(uid, TARJETA_C, 4) == 0) {
      Serial.println("\n[ACCESO CONCEDIDO] Tarjeta C detectada.");
      abrir_candado("Tarjeta C NFC");
    }
    else if (uidLength == 4 && memcmp(uid, CELU_VICENTE, 4) == 0) {
      Serial.println("\n[ACCESO CONCEDIDO] Celu Vicente Pavez detectado.");
      tone(BUZZER,587.33,150); delay(150);
      tone(BUZZER,587.33,150); delay(150);
      tone(BUZZER,1174.33,250); delay(250);
      tone(BUZZER,880,250); delay(250);
      tone(BUZZER,830.61,350); delay(350);
      tone(BUZZER,783.99,350); delay(350);
      tone(BUZZER,698.46,350); delay(350);
      tone(BUZZER,587.33,250); delay(250);
      tone(BUZZER,698.46,250); delay(250);
      tone(BUZZER,783.99,250); delay(250);
      abrir_candado("Celular Vicente (NFC)");
    }
    else {
      Serial.println("\n[ACCESO DENEGADO] Tarjeta NFC no autorizada.");
      Bridge.call("notificar_denegado", String("Tarjeta no autorizada"));
      tone(BUZZER,783.99,250); delay(250);
      tone(BUZZER,698.46,250); delay(250);
      tone(BUZZER,587.33,600); delay(600);
      for(int i = 0; i < 3; i++) {
        digitalWrite(LED_PIN, HIGH); delay(150);
        digitalWrite(LED_PIN, LOW);  delay(150);
      }
    }
  }
}
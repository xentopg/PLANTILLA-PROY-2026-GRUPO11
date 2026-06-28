#include <Adafruit_Fingerprint.h>

Adafruit_Fingerprint finger = Adafruit_Fingerprint(&Serial1);

void setup() {
  Serial.begin(9600);
  delay(3000); // Espera fija en lugar de while(!Serial)

  Serial.println("Test AS608 - Xentlock");

  Serial1.begin(57600);
  finger.begin(57600);
  delay(500);

  if (finger.verifyPassword()) {
    Serial.println("[OK] Sensor AS608 detectado!");
    finger.getParameters();
    Serial.print("Capacidad: "); Serial.print(finger.capacity); Serial.println(" huellas");
    finger.getTemplateCount();
    Serial.print("Huellas guardadas: "); Serial.println(finger.templateCount);
  } else {
    Serial.println("[ERROR] Sensor no encontrado. Revisa conexiones TX/RX.");
  }
}

void loop() {}
#include <Wire.h>
#include <Adafruit_PN532.h>

// Inicializamos el sensor en la interfaz I2C estándar
Adafruit_PN532 nfc(20, 21);

void setup(void) {
  Serial.begin(9600);
  delay(3000); // Espera estratégica para la Arduino UNO Q

  Serial.println("==========================================");
  Serial.println("    [Xentlock] Lector de Tarjetas NFC    ");
  Serial.println("==========================================");

  nfc.begin();

  uint32_t versiondata = nfc.getFirmwareVersion();
  if (!versiondata) {
    Serial.println("❌ No se encontró el sensor PN532.");
    while (1) delay(10);
  }

  // Configura el PN532 para leer tarjetas RFID/NFC
  nfc.SAMConfig();
  
  Serial.println("Aproxima tu tarjeta o llavero NFC al lector...");
}

void loop(void) {
  uint8_t success;
  uint8_t uid[] = { 0, 0, 0, 0, 0, 0, 0 };  // Buffer para almacenar el UID (soporta hasta 7 bytes)
  uint8_t uidLength;                        // Longitud del UID (Mifare Classic usa 4 bytes, Ultralight usa 7)
    
  // Esperar a que pase una tarjeta por el lector
  success = nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, uid, &uidLength);
  
  if (success) {
    // ¡Tarjeta encontrada!
    Serial.println("\n------------------------------------");
    Serial.println("✅ ¡Tarjeta NFC Detectada!");
    
    // Mostrar la longitud del código
    Serial.print("Longitud del UID: "); 
    Serial.print(uidLength, DEC); 
    Serial.println(" bytes");
    
    // Imprimir el UID en formato Hexadecimal (Este es el código que registraremos)
    Serial.print("Código UID (Hex): ");
    for (uint8_t i = 0; i < uidLength; i++) {
      Serial.print(" 0x");
      if (uid[i] < 0x10) Serial.print("0"); // Añadir cero a la izquierda si es menor de 16
      Serial.print(uid[i], HEX);
    }
    Serial.println();
    
    // Pequeña espera para no leer la misma tarjeta infinitas veces por segundo
    delay(2000);
    Serial.println("\nListo para leer otra tarjeta...");
  }
}
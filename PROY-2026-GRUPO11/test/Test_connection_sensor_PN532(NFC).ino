#include <Wire.h>
#include <Adafruit_PN532.h>

// Usamos la interfaz I2C estándar de la placa (&Wire) 
// En la Arduino UNO R4, los pines 20 (SDA) y 21 (SCL) están mapeados internamente a esta línea.
Adafruit_PN532 nfc(20, 21); 

void setup(void) {
  // Inicializar comunicación serial a 9600
  Serial.begin(9600);
  
  // Espera física de 3 segundos para que te dé tiempo de abrir el Monitor Serial
  delay(3000); 
  
  Serial.println("==========================================");
  Serial.println("   [Xentlock] Iniciando prueba de NFC     ");
  Serial.println("==========================================");
  Serial.println("Paso 1: Intentando inicializar nfc.begin()...");

  // Iniciamos el sensor
  nfc.begin();

  Serial.println("Paso 2: Sensor inicializado. Leyendo versión de firmware...");

  // Intentar obtener la versión del chip
  uint32_t versiondata = nfc.getFirmwareVersion();
  
  if (!versiondata) {
    Serial.println("❌ PASO 2 FALLÓ: No se encontró el sensor PN532.");
    Serial.println("-> Verifica que los interruptores del PN532 estén en modo I2C (GND/SDA/SCL).");
    while (1) delay(10); // Detener de forma segura sin congelar el puerto
  }
  
  // Si responde correctamente:
  Serial.println("✅ ¡PASO 2 EXITOSO! Sensor PN532 detectado.");
  Serial.print("-> Chip: PN53"); 
  Serial.println((versiondata>>24) & 0xFF, HEX); 
  Serial.print("-> Versión de Firmware: "); 
  Serial.print((versiondata>>16) & 0xFF, DEC);
  Serial.print('.'); 
  Serial.println((versiondata>>8) & 0xFF, DEC);
}

void loop(void) {
  // Vacío para la prueba de reconocimiento
}
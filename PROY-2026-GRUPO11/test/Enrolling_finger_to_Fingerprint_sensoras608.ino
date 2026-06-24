#include <Adafruit_Fingerprint.h>

// Forzamos el uso del puerto serial por hardware nativo de la UNO Q
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&Serial1);

void setup() {
  // Inicializamos el puerto de la computadora muy lento para asegurar estabilidad
  Serial.begin(9600);
  delay(4000); // Espera 4 segundos para que abras el Monitor Serie antes de enviar datos
  
  Serial.println("--- PRUEBA MINIMA XENTLOCK ---");

  // Arrancamos la comunicación directa con el lector de huellas
  Serial1.begin(57600);
  delay(1000);
}

void loop() {
  Serial.println("Coloca el dedo en el sensor AHORA para guardarlo como ID #1...");
  
  // 1. Intentar capturar la imagen del dedo hasta que detecte uno
  while (finger.getImage() != FINGERPRINT_OK) {
    delay(100); 
  }
  Serial.println("¡Dedo detectado! Procesando...");

  // 2. Convertir la imagen capturada a formato de características
  if (finger.image2Tz(1) != FINGERPRINT_OK) {
    Serial.println("Error al procesar la huella. Intenta otra vez.");
    delay(2000);
    return;
  }

  // 3. Crear el modelo directamente con la única captura tomada
  finger.createModel();

  // 4. Guardar la huella automáticamente en la posición ID #1
  if (finger.storeModel(1) == FINGERPRINT_OK) {
    Serial.println("¡¡HUELLA GUARDADA EXITOSAMENTE EN EL ID 1!!");
    Serial.println("Ya puedes retirar el dedo.");
    while(1); // Congela el programa para que no se repita en bucle
  } else {
    Serial.println("Error al guardar en memoria. ¿Están bien los cables TX/RX?");
    delay(3000);
  }
}
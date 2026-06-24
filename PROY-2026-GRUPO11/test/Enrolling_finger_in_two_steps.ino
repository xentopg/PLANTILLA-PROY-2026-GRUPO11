#include <Adafruit_Fingerprint.h>

Adafruit_Fingerprint finger = Adafruit_Fingerprint(&Serial1);

void setup() {
  Serial.begin(9600);
  delay(3000); // Espera para abrir el monitor serie sin bloqueos
  
  Serial.println("--- RE-REGISTRO DE ALTA PRECISION XENTLOCK ---");
  Serial1.begin(57600);
  delay(1000);
}

void loop() {
  Serial.println("\n[PASO 1] Coloca tu dedo de forma plana y firme en el cristal...");
  
  // Esperar primera captura
  while (finger.getImage() != FINGERPRINT_OK) { delay(100); }
  
  // Convertir primera captura
  if (finger.image2Tz(1) != FINGERPRINT_OK) {
    Serial.println("Error en la imagen. Intenta de nuevo.");
    delay(2000); return;
  }
  Serial.println("-> Primera captura procesada con éxito.");
  
  Serial.println("\n[PASO 2] !!! RETIRA EL DEDO COMPLETAMENTE !!!");
  delay(2000);
  while (finger.getImage() != FINGERPRINT_NOFINGER) { delay(100); }
  
  Serial.println("\n[PASO 3] Coloca el MISMO dedo otra vez para confirmar...");
  // Esperar segunda captura
  while (finger.getImage() != FINGERPRINT_OK) { delay(100); }
  
  // Convertir segunda captura
  if (finger.image2Tz(2) != FINGERPRINT_OK) {
    Serial.println("Error en la segunda imagen. Intenta de nuevo.");
    delay(2000); return;
  }
  Serial.println("-> Segunda captura procesada con éxito.");
  
  // Crear el modelo combinando ambas tomas
  Serial.println("\n[PASO 4] Comparando y enlazando mapas biométricos...");
  if (finger.createModel() != FINGERPRINT_OK) {
    Serial.println("[FALLO] Las capturas no coincidieron. Asegúrate de usar el mismo dedo.");
    delay(3000); return;
  }
  
  // Guardar de forma fija en la memoria del ID #1 sobrescribiendo el anterior
  if (finger.storeModel(1) == FINGERPRINT_OK) {
    Serial.println("\n¡¡¡EXITO TOTAL: HUELLA DE ALTA PRECISION GUARDADA EN ID #1!!!");
    Serial.println("Ya puedes retirar tu dedo. El sistema se pausará.");
    while(1); // Congela el programa
  } else {
    Serial.println("Error al guardar en la flash interna.");
    delay(3000);
  }
}
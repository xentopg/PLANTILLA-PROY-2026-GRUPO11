# PROY-2026-GRUPO 11

Repositorio del grupo 11 para el proyecto del ramo *Proyecto Inicial (IWG400)* – 2026.

## 👥 Integrantes del grupo

| Nombre y Apellido | Usuario GitHub            | Correo USM               | Rol USM      |
| ----------------- | ------------------------- | ------------------------ | ------------ |
| Vicente Pavez     | @xentopg                  | vpavezg@usm.cl           | 202510156-4  |
| Sebastián Martínez| @sseba07                  | smartinezt@usm.cl        | 202630019-6  |

## 📝 Descripción breve del proyecto

> Xentlock, es un dispositivo capaz de mantener seguras tus pertenencias, siendo este completamente digital, sin ranuras a llaves corrientes, solo es posible desbloquearlo mediante clave NFC, Huella digital y Página web. El objetivo de este proyecto es reforzar la seguridad de un candado convencional, integrando funciones que un candado convencional no posee y eliminando sus vulnerabilidades físicas. Con las tecnologías utilizadas buscamos darle una opción más fresca y renovada a las personas ofreciendoles una alternativa extra, un dispositivo que no fuera complicado de usar y que poseea más de un método de desbloqueo en caso de emergencias. 

## 🔐Video de presentación
[https://youtu.be/0hnv8rGY4yY](https://youtu.be/0hnv8rGY4yY)

---

## 🎯 Objetivos

- Objetivo general:
  -Nuestro objetivo principal es rediseñar el candado convencional e implementar un sistema de control de acceso inteligente (utilizando Arduino Uno Q) que integre tecnologías de identificación para garantizar la mayor seguridad posible para un dispositivo de cierre físico (el candado), también incluyendo un sistema de alerta en caso de golpe o abertura no autorizada. 
- Objetivos específicos:
  - Obtener los componentes necesarios 
  - Aprender a utilizar Arduino Lab 
  - Crear esquema de conexiones 
  - Realizar las conexiones correctamente para evitar percances 
  - Configurar los sensores y piezas por separado (NFC, Huella digital, microservomotor, buzzer) 
  - Ir integrando los sensores a un sistema más complejo hasta completar el circuito final 
  - Utilizar la powerbank como fuente de energía para el dispositivo 
  - compatibilizar la fuente de energía con el Arduino UNO Q
  - Implementación de carga por pines magnéticos (si es que queda tiempo(opcional)) 

---

## 🧩 Alcance del proyecto

> ¿Qué cubre? 

-Autenticación dual 
(Cuenta con la implementación de un sistema de apertura tanto con huella dactilar como con NFC) 

-Gestión de usuarios 
(Capacidad de registrar, almacenar y validar diferentes huellas dactilares y etiquetas NFC autorizadas en la memoria local del sistema) 

-Sistema de Seguridad activa 
(Integración de un sensor de vibración para detectar intentos de manipulación forzada y activar una alarma mediante el buzzer integrado)

-Autonomía energética 
(Powerbank de alta capacidad para asegurar la portabilidad del prototipo y su funcionamiento inalámbrico) 

-Recarga de batería 
(La recarga será mediante pines magnéticos, lo que soluciona problemas como USB killer, humedad o suciedad en el puerto USB) 

> ¿Qué limitaciones presenta? 

-Resistencia climática 
(No hay certeza de que el prototipo pueda aguantar condiciones climáticas como por ejemplo la lluvia) 

-Duración de la batería 
(El prototipo no cuenta con una muy larga duración, por lo que queda como desafío a futuro la optimización de la batería en general)

-Estado en tiempo real 
Otro desafío para resolver a futuro sería la vinculación del candado con una app, en la cual se pueda ver la batería restante, la gestión de las huellas, entre otras.

---

## 🛠️ Tecnologías y herramientas utilizadas

- Lenguaje(s) de programación:
  - Python, C++.
- Microcontroladores
  - Arduino UNO Q.
- Sensores
  - Sensor de huella Dactilar AS608, Sensor NFC PN532 
- componentes
  - Buzzer, led(verde), Servomotor MG996R, resistencia 100ohm
---

## 🗂️ Estructura del repositorio

```
/PROY-2026-GRUPO11
│
├── docs/               # Documentación general y reportes
├── src/                # Código fuente del proyecto
├── tests/              # Casos de prueba
├── assets/             # Imágenes, diagramas, etc.
└── README.md           # Este archivo
```

---

## 🚀 Instrucciones de Instalacion y Uso


1. **Clonar el repositorio:** `git clone https://github.com/xentopg/PLANTILLA-PROY-2026-GRUPO11.git`
2. **Dependencias:**
- [Instalar arduino applab](https://www.arduino.cc/en/software/)

**Una vez dentro de Arduino applab deberás registrar tu arduino asignandole una cuenta y contraseña**
`nota: si te pide actualizar a la ultima versión no es necesario, yo no tuve que hacerlo`
*Una vez instalado creas un proyecto y le instalar las librerias y bricks que aparecen aquí abajo:*

 -Librerías:
   Adafruit Fingerprint sensor library v2.1.3
   Adafruit PN532 v1.3.4
   Servo v1.3.0
   ezBuzzer v1.0.2
 -Bricks:
   WebUI-HTML
*vamos a necesitar editar el archivo sketch.yaml desde la terminal del computador por lo que para acceder a esta haremos uso de este programa*
- [platform-tools-latest-windows](https://developer.android.com/tools/releases/platform-tools?hl=es-419) 
   `también compatible con linux`
   `Es un ejecutable que nos ayudará a acceder a la terminal del arduino para poder editar el archivo sketch.yaml`
   
4. **Ejecución:**
   >> Pasos a seguir:
   *Paso 1 -- Lo primero es, como fue mencionado anteriormente, tener instalado el Arduino Lab. Una vez dentro de este, debes abrir tu proyecto.
   *Paso 2 -- Busca el ícono *>_* en la barra inferior izquierda, justo al lado del nombre de tu proyecto. Tras hacer click en este, se abrira una ventana con un fondo negro, esta será la terminal.
   *Paso 3 -- En la terminal deberas escribir el siguiente comando y ten en cuenta lo siguiente:
   I. En el comando, reemplaza NOMBRE-DE-TU-PROYECTO por el nombre exacto de tu proyecto tal como aparece en el AppLab.
   II. Comando: nano /home/arduino/ArduinoApps/NOMBRE-DE-TU-PROYECTO/sketch/sketch.yaml
   *Paso 4 -- Tras eso, se abrirá el archivo y deberás usar las flechas del teclado para moverte hasta el final, después de la línea que dice "default_profile: default."
   *Paso 5 --  Escribe exactamente esto (con espacios, no tabs):
   rpcs:
  - name: abrir
    returns: void
  - name: cerrar
    returns: void
    *Paso 6 -- Ahora presionas *Ctrl+O* para guardar, luego *Enter* para confirmar. Luego presiona *Ctrl+X* para salir del editor.
    *Paso 7 -- Para finalizar, en el AppLab presiona *Stop* y luego *Run*.

   >> Notas adicionales:
   - Con los archivos del repositorio se deben copiar en sus respectivas carpetas dentro del proyecto en Arduino applab
   - Ya que el .yaml no se puede editar debes ingresar a la terminal del computador por el programa "platform-tools-latest-windows" una vez dentro de ella debes ejecutar el comando 
   "adb install"
   - Si no sabes el nombre exacto de tu proyecto, puedes escribir este comando en la terminal para que te muestra todos los proyectos disponibles:
     ls /home/arduino/ArduinoApps/
---

## 📐 Diseño del Sistema
![Diagrama de Conexiones](./PROY-2026-GRUPO11/assets/diagrama_conexiones.png)

*Explicacion grafica de como es la conexion entre el microcontrolador y los sensores*

---

## 📅 Cronograma de trabajo

[Carta Gantt](https://usmcl-my.sharepoint.com/:x:/g/personal/vpavezg_usm_cl/IQCs5WCaG1q5TqvqJzvkhy9-AWukJlHdecXTcuYyGaN8mHM?e=p2jSog)

---

## 📚 Bibliografía

1. DroneBot Workshop. (2026). *Arduino UNO Q and Arduino App Lab v0.3.2* [Video]. YouTube. [https://youtu.be/6sGz3fy_xT4](https://youtu.be/6sGz3fy_xT4)

2. Arduino. (2026). *WebUI - HTML Brick Documentation*. Arduino App Lab v0.7.0. Documentación interna del panel del AppLab.

3. Arduino. (2026). *Ejemplo oficial blink-with-ui*. Arduino App Lab v0.7.0. Ruta interna: `/var/lib/arduino-app-cli/examples/blink-with-ui/`

4. Arduino. (2026). *Arduino_RouterBridge Library*. GitHub. [https://github.com/arduino-libraries/Arduino_RouterBridge](https://github.com/arduino-libraries/Arduino_RouterBridge)

5. Pallets Projects. (2024). *Flask Documentation*. [https://flask.palletsprojects.com](https://flask.palletsprojects.com)

6. Socket.IO. (2024). *Socket.IO Documentation*. [https://socket.io/docs](https://socket.io/docs)

7. cdnjs. (2024). *Socket.IO Client Library v4.7.2*. [https://cdnjs.cloudflare.com/ajax/libs/socket.io/4.7.2/socket.io.min.js](https://cdnjs.cloudflare.com/ajax/libs/socket.io/4.7.2/socket.io.min.js)

8. Adafruit Industries. (2024). *Adafruit PN532 NFC/RFID Library*. GitHub. [https://github.com/adafruit/Adafruit-PN532](https://github.com/adafruit/Adafruit-PN532)

9. Adafruit Industries. (2024). *Adafruit Fingerprint Sensor Library*. GitHub. [https://github.com/adafruit/Adafruit-Fingerprint-Sensor-Library](https://github.com/adafruit/Adafruit-Fingerprint-Sensor-Library)

10. Arduino. (2024). *Arduino UNO Q Documentation*. [https://docs.arduino.cc/hardware/uno-q](https://docs.arduino.cc/hardware/uno-q)

11. |Conversaciones con Gemini                                                                   |Conversaciones con Claude|
    |--------------------------------------------------------------------------------------------|--------------------------
    |[https://gemini.google.com/share/7a2621253fad](https://gemini.google.com/share/7a2621253fad)|[https://claude.ai/share/3dffba95-4a2a-42d5-a26a-e9908c0b58cb](https://claude.ai/share/3dffba95-4a2a-42d5-a26a-e9908c0b58cb)|
    |[https://gemini.google.com/share/ef1f6a7978c2](https://gemini.google.com/share/ef1f6a7978c2)|
    |[https://gemini.google.com/share/ea64b1a2190e](https://gemini.google.com/share/ea64b1a2190e)|
    |[https://gemini.google.com/share/652d6ab27d4f](https://gemini.google.com/share/652d6ab27d4f)|
    

---

## 📌 Notas adicionales

> *Espacio para dejar cualquier comentario útil, como pendientes, acuerdos del grupo, consideraciones especiales, etc.*

Como equipo consideramos que el prototipo creado es consecuente con lo planteado y es un gran avance en nuestra experiencia ya que logramos aprender bastante trbajando en ello, pese a los contratiempos y dificultades que enfrentamos como la falta de conocimiento acerca de electrónica y programación y el abandono de uno de nuestros compañeros, como equipo nos sentimos realizados con nuestro proyecto.
Aún así hay cosas tuvimos que dejar en el tintero por falta de tiempo, como por ejemplo implementar un modo que ahorre más energía e implementar una carga por pines magnéticos para evitar el uso de "USB killer" contra Xentlock, por parte de la web sería implementar metodo de cuentas y usuarios para que sea seguro abrir la página web a una red pública y de esta manera no sería necesario estar conectado a la misma red además de no perder control o seguridad al momento de utilizar el candado. 

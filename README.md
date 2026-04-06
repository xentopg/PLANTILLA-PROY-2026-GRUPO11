# PROY-2026-GRUPOX

Repositorio del grupo 11 para el proyecto del ramo *Proyecto Inicial (IWG400)* – 2026.

## 👥 Integrantes del grupo

| Nombre y Apellido | Usuario GitHub            | Correo USM               | Rol USM      |
| ----------------- | ------------------------- | ------------------------ | ------------ |
| Vicente Pavez     | @xentopg                  | vpavezg@usm.cl           | 202510156-4  |
| Francisco Navarro | @Francisco-Navarro-Moyano | fnavarromoy@usm.cl       | 202630038-2  |
| Sebastián Martínez| @sseba07                  | smartinezt@usm.cl        | 202630019-6  |
| Nombre4 Apellido4 | @usuario4                 | nombre4.apellido4@usm.cl | 200000000000 |

## 📝 Descripción breve del proyecto

> El Xentlock, es un dispositivo capaz de mantener seguras tus pertenencias, siendo este completamente digital, sin ranuras a llaves corrientes, solo es posible desbloquearlo mediante NFC o Huella digital. El objetivo de este proyecto es reforzar la seguridad de un candado convencional, integrando funciones que este originalmente no posee y eliminando sus vulnerabilidades. Con las tecnologías utilizadas, buscamos resolver las necesidades de seguridad de la gente, con un dispositivo que no fuera complicado de usar, pero más completo que un candado común y corriente. 

---

## 🎯 Objetivos

- Objetivo general:
  - *Describir el objetivo principal del proyecto.*
- Objetivos específicos:
  - *Listar objetivos concretos que permitirán alcanzar el objetivo general.*

---

## 🧩 Alcance del proyecto

> ¿Qué cubre? 

-Autenticación dual 

Cuenta con la implementación de un sistema de apertura tanto con huella dactilar como con NFC. 

-Gestión de usuarios 

Capacidad de registrar, almacenar y validar diferentes huellas dactilares y etiquetas NFC autorizadas en la memoria local del sistema. 

-Sistema de Seguridad activa 

Integración de un sensor de vibración para detectar intentos de manipulación forzada y activar una alarma mediante el buzzer integrado. 

-Autonomía energética 

Powerbank de alta capacidad para asegurar la portabilidad del prototipo y su funcionamiento inalámbrico. 

-Recarga de batería 

La recarga será mediante pines magnéticos, lo que soluciona problemas como USB killer, humedad o suciedad en el puerto USB. 

> ¿Qué limitaciones presenta? 

-Resistencia climática 

No hay certeza de que el prototipo pueda aguantar condiciones climáticas como por ejemplo la lluvia. 

-Duración de la batería 

El prototipo no cuenta con una muy larga duración, por lo que queda como desafío a futuro la optimización de la batería en general. 

-Estado en tiempo real 
Otro desafío para resolver a futuro sería la vinculación del candado con una app, en la cual se pueda ver la batería restante, la gestión de las huellas, entre otras.

---

## 🛠️ Tecnologías y herramientas utilizadas

- Lenguaje(s) de programación:
  - Ej: Python, JavaScript, C++
- Microcontroladores
  - Arduino UNO Q, ESP32
- Sensores

---

## 🗂️ Estructura del repositorio

```
/PROY-2026-GRUPOX
│
├── docs/               # Documentación general y reportes
├── src/                # Código fuente del proyecto
├── tests/              # Casos de prueba
├── assets/             # Imágenes, diagramas, etc.
└── README.md           # Este archivo
```

---

## 🚀 Instrucciones de Instalacion y Uso


1. **Clonar el repositorio:** `git clone ...`
2. **Dependencias:** Listar qué librerías necesitan (ej: `pip install -r requirements.txt` o librerías de Arduino).
3. **Ejecución:** Cómo se corre el código principal.

---

## 📐 Diseño del Sistema
![Diagrama de Conexiones](./assets/diagrama_conexiones.png)

*Explicacion grafica de como es la conexion entre el microcontrolador y los sensores*

---

## 📅 Cronograma de trabajo

[Carta Gantt](https://usmcl-my.sharepoint.com/:i:/r/personal/vpavezg_usm_cl/Documents/Carta%20Gantt%20Xentlock%201.jpg?csf=1&web=1&e=6PnHd7)

---

## 📚 Bibliografía

[Enlace](https://google.com)

---

## 📌 Notas adicionales

> *Espacio para dejar cualquier comentario útil, como pendientes, acuerdos del grupo, consideraciones especiales, etc.*

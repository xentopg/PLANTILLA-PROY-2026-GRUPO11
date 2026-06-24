# Versiones previas de Xentlock

Estos archivos son versiones intermedias del desarrollo de Xentlock,
ordenadas cronológicamente. Ninguna está completa — cada una fue
reemplazada al integrar nuevos componentes. El código final se encuentra
en `sketch.ino` en la raíz de `src/`.

| Archivo | Versión | Descripción |
|---|---|---|
| `Xentlock_V0.1.0.ino` | 0.1.0 | Primera versión funcional: autenticación por huella dactilar y control del servo |
| `Xentlock_V0.1.5_sketch_only_Fingerprint_enrolling.ino` | 0.1.5 | Herramienta de registro de huellas dactilares (sketch auxiliar, no es el sistema principal) |
| `Xentlock_V0.2.0.ino` | 0.2.0 | Versión de depuración: solo huella, sin servo, con salida por monitor serial |
| `Xentlock_V0.5.0.ino` | 0.5.0 | Primera integración completa: huella + NFC + servo |
| `Xentlock_V0.6.0_amiibo.ino` | 0.6.0 | Actualización sistema NFC integrando dispositivos amiibo y celular |
| `Xentlock_V0.7.0_buzzer.ino` | 0.7.0 | Se agrega sistema de alarma con buzzer ante desbloqueo |
| `Xentlock_V0.8.0_web.ino` | 0.8.0 | Se integra interfaz web de control (previa a la versión final) |

> **Nota:** Los saltos en la numeración (de 0.2.0 a 0.5.0) reflejan versiones
> intermedias descartadas durante el proceso de desarrollo.

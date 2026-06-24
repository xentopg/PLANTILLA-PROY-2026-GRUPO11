Documentación general — Xentlock

- ¿Qué es Xentlock?
Xentlock es una alternativa innovadora al candado convencional eliminando vulnerabilidades físicas e implementando sensores y comunicaciones que un candado convencional no posee

Programa utilizado: Arduino applab v0.7.0
(no se ha probado en Arduino IDE)

- Estructura del repositorio


En "src/" 
--> Se encuentra el código fuente y final del prototipo del proyecto:

-'sketch.ino' - Código principal de Arduino(Xentlock v0.9.0)
-'main.py' - Servidor Python con la interfaz web de control y monitoreo
- 'requirements.txt' — Dependencias Python necesarias para correr 'main.py'
- 'versiones/' — Historial de versiones intermedias del desarrollo (ver README dentro de esa carpeta)

En "test/" 
--> Se encuentran casos de prueba individuales para cada componente por separado:

- Prueba de escritura en monitor serial
- Detección del sensor NFC PN532
- Lectura de UID de tarjetas NFC
- Enrollamiento de huella dactilar paso a paso
- Entre otros

Estos códigos fueron usados para verificar que cada sensor funcionaba
correctamente antes de integrarlo al sistema completo.

En "assets/" 
--> Contiene el diagrama de conexiones entre el microcontrolador y los sensores,
además de fotografías del prototipo físico.

 "docs/"
Este archivo y cualquier reporte o informe entregado durante el desarrollo del proyecto.

---

|AVISO| Consideraciones técnicas importantes

-Sensor de huella dactilar AS608

El sensor AS608 presenta desconexiones intermitentes durante el uso.
Si el sistema no reconoce la huella o no responde ante su uso, se recomienda:
1.- Revisar físicamente que el conector del AS608 esté bien asentado
2.- Verificar que los pines RX1/TX1 estén correctamente conectados a la Arduino UNO Q
3.- Reiniciar el sistema y esperar el delay de inicialización (3 segundos)

Se recomienda revisar esta conexión cada vez que se monte o transporte el prototipo.

-Página web:

Para acceder a la web para monitorear y controlar el dispositivo es necesario estar conectado a la misma red wifi que el Arduino UNO Q (que es dónde se está ejecutando)
Puede que uno de los dos enlaces generados no cargue, pruebe con el segundo, si ninguno llega a cargar revise su conexión wifi y verifique que sea la misma que utiliza el Arduino UNO Q
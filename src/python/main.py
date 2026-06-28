from arduino.app_utils import *
from arduino.app_bricks.web_ui import WebUI
import json
import os
from datetime import datetime

ui = WebUI(assets_dir_path="/app/assets")

estado_candado = "🔒 CERRADO"
RUTA_ARCHIVO = "usuarios.json"
RUTA_REGISTRO = "registro.json"

def cargar_usuarios():
    if os.path.exists(RUTA_ARCHIVO):
        with open(RUTA_ARCHIVO, 'r', encoding='utf-8') as f:
            return json.load(f)
    usuarios_defecto = [
        {"nombre": "Sebastian", "metodo": "Tarjeta A NFC", "id_sensor": "DE:14:29:6E"},
        {"nombre": "Francisco", "metodo": "Tarjeta B NFC", "id_sensor": "0E:E9:1B:6E"},
        {"nombre": "Vicente",   "metodo": "Tarjeta C NFC", "id_sensor": "1C:3F:04:30"},
        {"nombre": "Vicente (celular)", "metodo": "Celular NFC", "id_sensor": "01:02:03:04"}
    ]
    guardar_usuarios(usuarios_defecto)
    return usuarios_defecto

def guardar_usuarios(lista):
    with open(RUTA_ARCHIVO, 'w', encoding='utf-8') as f:
        json.dump(lista, f, indent=4, ensure_ascii=False)

def cargar_registro():
    if os.path.exists(RUTA_REGISTRO):
        with open(RUTA_REGISTRO, 'r', encoding='utf-8') as f:
            return json.load(f)
    return []

def guardar_registro(lista):
    with open(RUTA_REGISTRO, 'w', encoding='utf-8') as f:
        json.dump(lista, f, indent=4, ensure_ascii=False)

def agregar_registro(metodo, tipo="✅ Acceso concedido"):
    registro = cargar_registro()
    entrada = {
        "hora": datetime.now().strftime("%d/%m/%Y %H:%M:%S"),
        "metodo": metodo,
        "tipo": tipo
    }
    registro.insert(0, entrada)
    registro = registro[:50]
    guardar_registro(registro)
    ui.send_message("registro_update", {"registro": registro})

lista_usuarios = cargar_usuarios()

def notificar_abierto_con_metodo(metodo):
    global estado_candado
    estado_candado = "🔓 ABIERTO"
    ui.send_message("estado_update", {"estado": estado_candado})
    agregar_registro(metodo, "✅ Acceso concedido")
    print("Arduino abrió:", metodo)

def notificar_cerrado(state):
    global estado_candado
    estado_candado = "🔒 CERRADO"
    ui.send_message("estado_update", {"estado": estado_candado})
    print("Arduino cerró el candado")

def notificar_denegado(metodo):
    agregar_registro(metodo, "❌ Acceso denegado")
    print("Acceso denegado:", metodo)

Bridge.provide("notificar_abierto_con_metodo", notificar_abierto_con_metodo)
Bridge.provide("notificar_cerrado", notificar_cerrado)
Bridge.provide("notificar_denegado", notificar_denegado)

def api_abrir():
    global estado_candado
    estado_candado = "🔓 ABIERTO"
    try:
        Bridge.call("abrir", True)
        print("Bridge: ABRIR enviado al Arduino")
    except Exception as e:
        print("Error Bridge:", e)
    return {"status": "success", "nuevo_estado": estado_candado}

def api_cerrar():
    global estado_candado
    estado_candado = "🔒 CERRADO"
    try:
        Bridge.call("cerrar", True)
        print("Bridge: CERRAR enviado al Arduino")
    except Exception as e:
        print("Error Bridge:", e)
    return {"status": "success", "nuevo_estado": estado_candado}

def api_estado():
    return {"estado": estado_candado, "usuarios": lista_usuarios}

def api_registro():
    return {"registro": cargar_registro()}

def api_agregar(nombre=""):
    global lista_usuarios
    lista_usuarios.append({
        "nombre": nombre,
        "metodo": "Tarjeta NFC",
        "id_sensor": "PENDIENTE"
    })
    guardar_usuarios(lista_usuarios)
    return {"status": "success"}

def api_eliminar(nombre=""):
    global lista_usuarios
    lista_usuarios = [u for u in lista_usuarios if u["nombre"] != nombre]
    guardar_usuarios(lista_usuarios)
    return {"status": "success"}

ui.expose_api("POST", "/api/abrir",    lambda: api_abrir())
ui.expose_api("POST", "/api/cerrar",   lambda: api_cerrar())
ui.expose_api("GET",  "/api/estado",   lambda: api_estado())
ui.expose_api("GET",  "/api/registro", lambda: api_registro())
ui.expose_api("POST", "/api/agregar",  lambda nombre="": api_agregar(nombre))
ui.expose_api("POST", "/api/eliminar", lambda nombre="": api_eliminar(nombre))

print("URL pública:", ui.url)
App.run()
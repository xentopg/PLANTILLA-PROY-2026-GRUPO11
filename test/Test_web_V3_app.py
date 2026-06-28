from flask import Flask, render_template, jsonify, request
import json
import os

app = Flask(__name__)

# Definimos el estado del candado y la ruta del archivo de persistencia
estado_candado = "🔒 CERRADO"
RUTA_ARCHIVO = "usuarios.json"

# Función para cargar los usuarios desde el archivo JSON
def cargar_usuarios():
    if os.path.exists(RUTA_ARCHIVO):
        with open(RUTA_ARCHIVO, 'r', encoding='utf-8') as f:
            return json.load(f)
    
    # Lista inicial por defecto si el archivo no existe
    usuarios_defecto = [
        {"nombre": "Sebastian", "metodo": "Tarjeta A NFC", "id_sensor": "DE:14:29:6E"},
        {"nombre": "Francisco", "metodo": "Tarjeta B NFC", "id_sensor": "0E:E9:1B:6E"},
        {"nombre": "Vicente", "metodo": "Tarjeta C NFC", "id_sensor": "1C:3F:04:30"}
    ]
    guardar_usuarios(usuarios_defecto)
    return usuarios_defecto

# Función para escribir los cambios en el JSON
def guardar_usuarios(lista):
    with open(RUTA_ARCHIVO, 'w', encoding='utf-8') as f:
        json.dump(lista, f, indent=4, ensure_ascii=False)

# Inicializamos la lista al arrancar el servidor
lista_usuarios = cargar_usuarios()

@app.route('/')
def pantalla_principal(): 
    # Enviamos tanto el estado como la lista de usuarios al HTML
    return render_template('index.html', estado=estado_candado, usuarios=lista_usuarios)

@app.route('/api/abrir', methods=['POST'])
def api_abrir():
    global estado_candado
    estado_candado = "🔓 ABIERTO"
    print("Comando: ¡ABRIR CANDADO!")
    return jsonify({"status": "success", "nuevo_estado": estado_candado})

@app.route('/api/cerrar', methods=['POST'])
def api_cerrar():
    global estado_candado
    estado_candado = "🔒 CERRADO"
    print("Comando: ¡CERRAR CANDADO!")
    return jsonify({"status": "success", "nuevo_estado": estado_candado})

# NUEVO ENDPOINT: Permite recibir un nombre desde la web y registrarlo
@app.route('/api/agregar', methods=['POST'])
def agregar_usuario():
    global lista_usuarios
    datos = request.get_json()
    nuevo_nombre = datos.get('nombre')

    # Se creaba el usuario con método base y el ID del sensor en "PENDIENTE"
    nuevo_usuario = {
        "nombre": nuevo_nombre,
        "metodo": "Tarjeta NFC",
        "id_sensor": "PENDIENTE"
    }
    lista_usuarios.append(nuevo_usuario)
    guardar_usuarios(lista_usuarios) # Se guarda inmediatamente en el archivo físico

    return jsonify({"status": "success"})

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000, debug=True)

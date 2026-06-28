from flask import Flask, render_template, jsonify

app = Flask(__name__)

# Se define el estado inicial del candado en la memoria del servidor
estado_candado = "🔒 CERRADO"

@app.route('/')
def pantalla_principal(): 
    # Ya no se usa texto plano; pasamos el estado al archivo HTML
    return render_template('index.html', estado=estado_candado)

@app.route('/api/abrir', methods=['POST'])
def api_abrir():
    global estado_candado
    estado_candado = "🔓 ABIERTO"
    
    # Simulación de la orden en la consola de VS Code
    print("Comando: ¡ABRIR CANDADO!") 
    return jsonify({"status": "success", "nuevo_estado": estado_candado})

@app.route('/api/cerrar', methods=['POST'])
def api_cerrar():
    global estado_candado
    estado_candado = "🔒 CERRADO"
    
    # Simulación de la orden en la consola de VS Code
    print("Comando: ¡CERRAR CANDADO!") 
    return jsonify({"status": "success", "nuevo_estado": estado_candado})

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000, debug=True)

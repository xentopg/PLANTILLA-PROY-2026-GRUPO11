from flask import Flask

app = Flask(__name__)

@app.route('/')
def pantalla_principal(): 
    return """
    <!DOCTYPE html>
    <html>
    <head>
        <title>Proyecto Xentlock</title>
    </head>
    <body style="font-family: Arial, sans-serif; text-align: center; padding-top: 100px; background-color: #ffffff;">
        <h1>Xentlock</h1>
        <h2 style="color: #7f8c8d; font-weight: normal;">Servidor funcionando correctamente</h2>
    </body>
    </html>
    """

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000, debug=True)

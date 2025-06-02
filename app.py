from flask import Flask, render_template, jsonify
import threading
import serial
import time
from datetime import datetime

app = Flask(__name__)
data = {
    "heure": "N/A",
    "temperature": "N/A",
    "humidite": "N/A"
}

def communication_serial():
    global data
    try:
        ser = serial.Serial('COM5', 9600, timeout=1)
        time.sleep(2)

        while True:
            heure_pc = datetime.now().strftime("%H:%M")
            ser.write((heure_pc + '\n').encode())
            time.sleep(0.1)

            line = ser.readline().decode().strip()
            print("REÇU:", line)

            try:
                parts = line.split()
                data["heure"] = parts[0].split(":", 1)[1]
                data["temperature"] = parts[1].split(":")[1]
                data["humidite"] = parts[2].split(":")[1]
            except Exception as e:
                print("Erreur de parsing:", e)

            time.sleep(1)

    except Exception as e:
        print("Erreur série:", e)

@app.route("/")
def index():
    return render_template("index.html")

@app.route("/data")
def get_data():
    return jsonify(data)

if __name__ == "__main__":
    t = threading.Thread(target=communication_serial)
    t.daemon = True
    t.start()
    app.run(host="0.0.0.0", port=5000)

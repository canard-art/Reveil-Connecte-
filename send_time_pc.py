import serial
import time
from datetime import datetime

# Remplacer par le port de l’Arduino (exemple: 'COM3' sous Windows, '/dev/ttyACM0' sous Linux)
ser = serial.Serial('COM3', 9600)
time.sleep(2)  # Laisse le temps à l’Arduino de démarrer

while True:
    now = datetime.now()
    heure_str = now.strftime("%H:%M")
    ser.write((heure_str + '\n').encode())
    print(f"Heure envoyée : {heure_str}")
    time.sleep(60)  # Envoie toutes les minutes
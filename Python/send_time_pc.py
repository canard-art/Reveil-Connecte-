import serial
import time
from datetime import datetime

ser = serial.Serial('COM5', 9600)
time.sleep(2)

while True:
    heure_str = datetime.now().strftime("%H:%M")
    ser.write((heure_str + '\n').encode())
    print(f"Heure envoyée : {heure_str}")
    time.sleep(60)

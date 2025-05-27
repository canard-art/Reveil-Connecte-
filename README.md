# Réveil Connecté
Ce projet est réalisé dans le cadre du module Communication Sans Fil en Licence 1 à l’Université
Nice Sophia Antipolis

Un réveil qui affiche l’heure, la température, l’humidité et la luminosité, avec alarme programmable et consultation à distance via le web.

## Matériel utilisé
- UCA board version 2021
- Capteurs : température/humidité (DHT22), luminosité (LDR)
- Écran OLED
- Buzzer

## Fonctionnalités
- Affichage en temps réel sur écran OLED
- Alarme programmable
- Page web consultable sur smartphone/PC pour voir les mesures à distance

## Installation
1. Branche les composants selon le schéma (voir dossier `docs/`).
2. Téléverse le code Arduino/ESP32 (`arduino/`).
3. Lance le script Python sur le PC (`python/send_time_pc.py`) si besoin de synchroniser l'heure.
4. Accède à la page web (voir instructions dans le dossier `web/`).

## Aperçu

![Photo](docs/photo_montage.jpg)

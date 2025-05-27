# Réveil Connecté
📄 Ce projet est réalisé dans le cadre du module Communication Sans Fil en Licence 1 à l’Université
Nice Sophia Antipolis

Un réveil qui affiche l’heure, la température, l’humidité et la luminosité, avec alarme programmable et consultation à distance via le web.

## 🛠️ Matériel utilisé
- UCA board version 2021
- Capteurs : température/humidité (DHT22), luminosité (LDR)
- Écran OLED
- Câbles
- Buzzer

## 📦 Organisation du dépôt

- `arduino/` : Code microcontrôleur
- `python/` : Script pour synchroniser l’heure depuis le PC
- `web/` : (optionnel) fichiers du site web embarqué
- `docs/` : Schémas, images, documentation

## ⚡Fonctionnalités
- Affichage de l’heure en temps réel
- Mesure température, humidité, luminosité
- Alarme programmable
- Affichage des infos sur écran OLED et sur page web consultable sur smartphone/PC

## 🚀 Installation
1. **Branche les composants** (voir schéma dans `docs/`).
2. **Téléverse le code du dossier `arduino/`** sur le microcontrôleur
3. **Lance le script Python** (`python/send_time_pc.py`) si besoin pour envoyer l’heure depuis le PC.
4. **Accède à la page web** générée par le microcontrôleur (voir IP affichée dans le moniteur série).

## ✨Aperçu

![Photo](docs/photo_montage.jpg)


#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


// Dimensions de l'écran OLED
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1  // Pas de pin de reset utilisée
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


// Variables simulées (à remplacer par les vraies lectures capteurs)
String heure = "18:00";
float temperature = 23.5;
float humidite = 55.0;
int luminosite = 82;


void setup() {
  Serial.begin(9600);


  // Initialisation de l'écran
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("Échec de l'écran OLED"));
    for(;;); // Stop si écran non détecté
  }


  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.setCursor(0, 0);


  display.println("Initialisation...");
  display.display();
  delay(1000);
}


void loop() {
  display.clearDisplay();


  // Heure
  display.setTextSize(2);
  display.setCursor(0, 0);
  display.print(heure);
  display.setTextSize(1);
  display.setCursor(100, 5);
  display.print("☀");


  // Température
  display.setCursor(0, 25);
  display.print("Temp : ");
  display.print(temperature);
  display.println(" C");


  // Humidité
  display.setCursor(0, 38);
  display.print("Hum  : ");
  display.print(humidite);
  display.println(" %");


  // Luminosité
  display.setCursor(0, 51);
  display.print("Lumi : ");
  display.print(luminosite);
  display.println(" %");


  display.display();
  delay(2000);  // Actualisation toutes les 2 secondes
}




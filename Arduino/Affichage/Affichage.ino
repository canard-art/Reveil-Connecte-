#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_SHTC3.h>  

// Dimensions de l'écran OLED
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Capteur SHTC3
Adafruit_SHTC3 shtc3 = Adafruit_SHTC3();

// Variables capteurs
float temperature = 0.0;
float humidite = 0.0;
int luminosite = 82;  // Tu peux le connecter à un capteur LDR si tu veux
String heure = "18:00"; // Optionnel, à remplacer par un RTC plus tard

void setup() {
  Serial.begin(9600);
  Wire.begin();

  // Initialisation écran OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("Échec de l'écran OLED"));
    while (true);
  }

  // Initialisation capteur SHTC3
  if (!shtc3.begin()) {
    Serial.println("Erreur capteur SHTC3");
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("Erreur SHTC3");
    display.display();
    while (true);
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
  // Lecture des données capteur
  sensors_event_t humidityEvent, tempEvent;
  shtc3.getEvent(&humidityEvent, &tempEvent);
  temperature = tempEvent.temperature;
  humidite = humidityEvent.relative_humidity;

  display.clearDisplay();

  // Affichage heure
  display.setTextSize(2);
  display.setCursor(0, 0);
  display.print(heure);
  display.setTextSize(1);
  display.setCursor(100, 5);
  display.print("☀");  // Icône soleil

  // Température
  display.setCursor(0, 25);
  display.print("Temp : ");
  display.print(temperature, 1);  // 1 décimale
  display.println(" C");

  // Humidité
  display.setCursor(0, 38);    
  display.print("Hum  : ");
  display.print(humidite, 1);
  display.println(" %");

  // Luminosité (simulée ici)
  display.setCursor(0, 51);
  display.print("Lumi : ");
  display.print(luminosite);
  display.println(" %");

  display.display();
  delay(2000);
}

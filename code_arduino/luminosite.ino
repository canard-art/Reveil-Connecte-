#include <Wire.h>
#include <Adafruit_LTR329_LTR303.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Taille de l'écran OLED
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Adresse I2C de l'écran OLED
#define OLED_ADDR 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
Adafruit_LTR303 ltr = Adafruit_LTR303();

void setup() {
  Serial.begin(115200);
  while (!Serial) delay(10);

  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
    Serial.println(F("Échec de l'initialisation de l'écran OLED"));
    while (1);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.println("Initialisation...");
  display.display();

  if (!ltr.begin()) {
    Serial.println("Échec de l'initialisation du capteur LTR-303");
    display.println("Capteur LTR303 ERROR");
    display.display();
    while (1);
  }

  ltr.setGain(LTR3XX_GAIN_1); 
  ltr.setIntegrationTime(LTR3XX_INTEGTIME_100); 
  ltr.setMeasurementRate(LTR3XX_MEASRATE_50); 

  display.clearDisplay();
  display.setCursor(0,0);
  display.println("Capteur OK");
  display.display();
  delay(1000);
}

void loop() {
  bool valid;
  uint16_t visible, infrared;

  
  valid = ltr.readBothChannels(visible, infrared);

  display.clearDisplay();
  display.setCursor(0, 0);

  if (valid) {
    display.println("Luminosité:");
    display.print("Visible: ");
    display.println(visible);
    display.print("IR     : ");
    display.println(infrared);

    Serial.print("Visible: ");
    Serial.print(visible);
    Serial.print(" | IR: ");
    Serial.println(infrared);
  } else {
    display.println("Lecture invalide");
    Serial.println("Erreur de lecture");
  }

  display.display();
  delay(1000);
}

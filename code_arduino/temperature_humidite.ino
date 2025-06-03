#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_SHTC3.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
Adafruit_SHTC3 shtc3 = Adafruit_SHTC3();  

String heure = "";

void setup() {
  Serial.begin(9600);
  
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    while(true); 
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.print("Initialisation...");
  display.display();

  if (!shtc3.begin()) {
    display.clearDisplay();
    display.setCursor(0, 0);
    display.print("SHTC3 erreur!");
    display.display();
    while (1);
  }

  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Pret !");
  display.display();
  delay(1000);
}

void loop() {
  sensors_event_t humidity, temp;
  shtc3.getEvent(&humidity, &temp);  

  if (Serial.available() > 0) {
    heure = Serial.readStringUntil('\n');  
  }

  display.clearDisplay();

  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print("Heure:");
  display.setCursor(40, 0);
  display.print(heure);

  display.setCursor(0, 20);
  display.print("Temp: ");
  display.print(temp.temperature, 1);
  display.print(" C");

  display.setCursor(0, 35);
  display.print("Hum:  ");
  display.print(humidity.relative_humidity, 1);
  display.print(" %");

  display.display();

  Serial.print("Heure:");
  Serial.print(heure);
  Serial.print(" Temp:");
  Serial.print(temp.temperature, 1);
  Serial.print(" Hum:");
  Serial.println(humidity.relative_humidity, 1);

  delay(1000);  
}

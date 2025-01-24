#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display
int redLed = 10;

int greenLed = 12;

int buzzer = 8;

int smokeA0 = A0;

// Your threshold value

int sensorThres = 250;


void setup()
{
  lcd.init();         // initialize the lcd
  lcd.backlight();    // Turn on the LCD screen backlight
  pinMode(redLed, OUTPUT);

  pinMode(greenLed, OUTPUT);

  pinMode(buzzer, OUTPUT);

  pinMode(smokeA0, INPUT);

  Serial.begin(9600);

  lcd.clear();
}

void loop()
{



  int analogSensor = analogRead(smokeA0);



  Serial.print("Pin A0: ");

  Serial.println(analogSensor);

  lcd.print("Smoke Level:");

  lcd.print(analogSensor);
  lcd.setCursor(1, 4);

  lcd.print(".....Normal.....");


  // Checks if it has reached the threshold value

  if (analogSensor > sensorThres)

  {

    digitalWrite(redLed, HIGH);
 lcd.clear();
    //lcd.setCursor(0, 2);

    lcd.print("Alert....!!!");

    digitalWrite(12, LOW);

    tone(buzzer, 2000, 200);

  }

  else

  {

    digitalWrite(redLed, LOW);

    digitalWrite(12, HIGH);


    noTone(buzzer);

  }

  delay(500);

  lcd.clear();
}

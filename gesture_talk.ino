
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>

int rxPin = 3;
int txPin = 2;
int led = LED_BUILTIN;
int a0 = A0, a1 = A1,  a2 = A2, a3 = A3;
LiquidCrystal_I2C lcd(0x27, 16, 2);
SoftwareSerial softwareSerial(rxPin, txPin);
DFRobotDFPlayerMini player;

void setup() {
  Serial.begin(9600);
  pinMode(a0, INPUT_PULLUP);
  pinMode(a1, INPUT_PULLUP);
  pinMode(a2, INPUT_PULLUP);
  pinMode(a3, INPUT_PULLUP);

 softwareSerial.begin(9600);

  if (player.begin(softwareSerial)) {
    Serial.println("OK");

    player.volume(30);
   
    player.playMp3Folder(1);

  } else {
    Serial.println("Connecting to DFPlayer Mini failed!");
  }
  
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  delay(1000);

}

void loop() {
  int a0Value = analogRead(a0);
  int a1Value = analogRead(a1);
  int a2Value = analogRead(a2);
  int a3Value = analogRead(a3);


  // print out the value you read:
  Serial.print("a0: ");
  Serial.print(a0Value);
  Serial.print(", ");
  Serial.print("a1: "); 
  Serial.print(a3Value);
  Serial.println (", ");
  delay(1000);
  lcd.setCursor(0, 0);
  lcd.print("NO GESTURES YET ");

  if (a0Value > 100 && a1Value < 20 && a2Value < 20 && a3Value > 100 )
  {
    lcd.setCursor(0, 0);
    lcd.print(" How are you? ");
    player.play(1);

  }
  else if (a0Value > 1000 && a1Value > 100  && a2Value < 20  && a3Value < 20)
  {
    lcd.setCursor(0, 0);
    lcd.print("  I am sorry ");
    player.play(2);

  }
  else if (a0Value > 100 && a1Value > 100 && a2Value > 100  && a3Value > 100)
  {
    lcd.setCursor(0, 0);
    lcd.print("   I need Food  ");
    player.play(3);
  }
  else if (a0Value < 20 && a1Value < 20 && a2Value < 20  && a3Value < 20) {
    lcd.setCursor(0, 0);
    lcd.print("   I need Water ");
    player.play(4);
  }
  delay(3000);
}
/*else if(a0Value <20 && a1Value < 20 && a2Value < 20 && a3Value >100 )
  {
    lcd.setCursor(0, 0);
    lcd.print("NICE TO MEET YOU ");
  }
  else if(a0Value < 20 && a1Value >100 && a2Value >100 && a3Value >100)
  {
    lcd.setCursor(0, 0);
    lcd.print("    GOODBYE!    ");
  }

  delay(100);
  }*/

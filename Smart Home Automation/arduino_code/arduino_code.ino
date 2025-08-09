#include <Keypad.h>
#include <Servo.h>
#include <LiquidCrystal.h>
#include <SoftwareSerial.h>

// Bluetooth
SoftwareSerial BT(10, 11);  // HC-05 TX, RX

// LCD: RS=A1, E=A2, D4=A3, D5=A4, D6=A5, D7=D0(RX)
LiquidCrystal lcd(A1, A2, A3, A4, A5, 0);

// Servo
Servo lockServo;

// Relay Pins
#define relayLight 12
#define relayFan 13

// Keypad Setup
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {2,3,4,5};
byte colPins[COLS] = {6,7,8,A0};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

String password = "1234";
String input = "";

void setup() {
  lcd.begin(16, 2);
  BT.begin(9600);

  pinMode(relayLight, OUTPUT);
  pinMode(relayFan, OUTPUT);

  lockServo.attach(9);
  lockServo.write(0);  // Locked initially

  // Startup Message
  lcd.setCursor(0,0);
  lcd.print("Welcome Smart");
  lcd.setCursor(0,1);
  lcd.print("Home");
  delay(5000);  // Show for 5 seconds
  
  lcd.clear();
  lcd.print("Enter Password:");
}

void loop() {
  // Bluetooth Commands
  if(BT.available()) {
    String cmd = BT.readStringUntil('\n');
    cmd.trim();

    if(cmd == "turn on the light") {
      digitalWrite(relayLight, HIGH);
      lcd.clear();
      lcd.print("Light: ON");
      delay(5000);
      lcd.clear();
      lcd.print("Enter Password:");
    }
    else if(cmd == "turn off the light") {
      digitalWrite(relayLight, LOW);
      lcd.clear();
      lcd.print("Light: OFF");
      delay(5000);
      lcd.clear();
      lcd.print("Enter Password:");
    }
    else if(cmd == "turn on the fan") {
      digitalWrite(relayFan, HIGH);
      lcd.clear();
      lcd.print("Fan: ON");
      delay(5000);
      lcd.clear();
      lcd.print("Enter Password:");
    }
    else if(cmd == "turn off the fan") {
      digitalWrite(relayFan, LOW);
      lcd.clear();
      lcd.print("Fan: OFF");
      delay(5000);
      lcd.clear();
      lcd.print("Enter Password:");
    }
  }

  // Keypad Input Handling
  char key = keypad.getKey();
  if(key) {
    if(key == '#') {
      if(input == password) {
        lcd.clear();
        lcd.print("Access Granted");
        lockServo.write(90);  // Unlock Door
        delay(5000);

        lcd.clear();
        lcd.print("SafeZoneIsYours");
        delay(5000);

        lockServo.write(0);   // Re-lock door after message
      } else {
        lcd.clear();
        lcd.print("Wrong Password");
        delay(5000);
      }
      lcd.clear();
      lcd.print("Enter Password:");
      input = "";
    }
    else if(key == '*') {
      input = "";
      lcd.clear();
      lcd.print("Cleared");
      delay(1000);
      lcd.clear();
      lcd.print("Enter Password:");
    }
    else {
      input += key;
      lcd.setCursor(0,1);
      lcd.print(input);
    }
  }
}


#include <Keypad.h>

#define BUZZER 10
#define PIR 9

#define LED_GREEN 12
#define LED_YELLOW 13
#define LED_RED 11

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {1, 2, 3, 4};
byte colPins[COLS] = {5, 6, 7, 8};

Keypad keypad = Keypad(makeKeymap(keys),
                       rowPins, colPins,
                       ROWS, COLS);

int melody[] = {2000, 1000};
int noteDuration = 500;

enum SystemState {
  OFF,
  ARMING,
  ARMED
};

SystemState state = OFF;

void setup() {

  pinMode(BUZZER, OUTPUT);
  pinMode(PIR, INPUT);

  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_RED, OUTPUT);

  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_YELLOW, LOW);
  digitalWrite(LED_RED, LOW);

  Serial.begin(9600);

  Serial.println("Nacisnij # aby wlaczyc system");
}

void loop() {

  switch (state) {

    // SYSTEM WYLACZONY
    case OFF:

      digitalWrite(LED_GREEN, LOW);
      digitalWrite(LED_YELLOW, LOW);
      digitalWrite(LED_RED, LOW);

      if (keypad.getKey() == '#') {

        Serial.println("UZBRAJANIE SYSTEMU...");

        state = ARMING;
      }

      break;


    // UZBRAJANIE SYSTEMU
    case ARMING:

      digitalWrite(LED_GREEN, LOW);
      digitalWrite(LED_YELLOW, HIGH);
      digitalWrite(LED_RED, LOW);

      delay(5000);

      digitalWrite(LED_YELLOW, LOW);

      state = ARMED;

      Serial.println("SYSTEM UZBROJONY!");

      break;


    // SYSTEM UZBROJONY
    case ARMED:

      if (digitalRead(PIR) == HIGH) {

        Serial.println("WYKRYTO RUCH!");

        // Swieci tylko czerwona dioda
        digitalWrite(LED_GREEN, LOW);
        digitalWrite(LED_YELLOW, LOW);
        digitalWrite(LED_RED, HIGH);

        for (int i = 0; i < 2; i++) {

          if (digitalRead(PIR) == LOW) {
            noTone(BUZZER);
            break;
          }

          tone(BUZZER, melody[i]);
          delay(noteDuration);

          noTone(BUZZER);
          delay(30);
        }

      } else {

        // Brak ruchu - swieci tylko zielona
        digitalWrite(LED_GREEN, HIGH);
        digitalWrite(LED_YELLOW, LOW);
        digitalWrite(LED_RED, LOW);

        noTone(BUZZER);
      }

      break;
  }
}


#include <Servo.h>
#include <IRremote.hpp>

Servo serwo1, serwo2;

#define IR_PIN 10
#define POWER 0x00
#define LED 12
#define PIR_PIN 4

int pozycja1 = 0, pozycja2 = 180;
int cel1 = 0, cel2 = 180;
int stan = 0, kierunek = 0;

bool ruch = false;

unsigned long czas = 0, przycisk = 0;

// STAN 0 - ZAMKNIETA
void zamknieta() {
  cel1 = 0;
  cel2 = 180;
  stan = 0;
  ruch = false;
}

// STAN 1 - OTWARTA
void otwarta() {
  cel1 = 90;
  cel2 = 90;
  stan = 1;
  ruch = false;
}

// STAN 4 - OTWIERANIE
void otwieranie() {
  cel1 = 90;
  cel2 = 90;
  stan = 4;
  kierunek = 4;
  ruch = true;
}

// STAN 5 - ZAMYKANIE
void zamykanie() {
  cel1 = 0;
  cel2 = 180;
  stan = 5;
  kierunek = 5;
  ruch = true;
}

// STAN 6 - UCHYLENIE / ZATRZYMANIE
void zatrzymanie() {
  kierunek = (stan == 4) ? 5 : 4;

  cel1 = pozycja1;
  cel2 = pozycja2;

  ruch = false;
  stan = 6;
}

// OBSLUGA POWER
void obslugaPower() {
  if (ruch) {
    zatrzymanie();
  }
  else if (stan == 0) {
    otwieranie();
  }
  else if (stan == 1) {
    zamykanie();
  }
  else if (stan == 6) {
    if (kierunek == 4) otwieranie();
    else zamykanie();
  }
}

// OBSLUGA PIR
void obslugaPIR() {
  if (digitalRead(PIR_PIN) == HIGH && ruch) {
    zamykanie();
  }
}

// STEROWANIE SERWAMI
void sterowanieSerwami() {
  if (!ruch || millis() - czas < 15) return;

  czas = millis();

  if (pozycja1 < cel1) pozycja1++;
  else if (pozycja1 > cel1) pozycja1--;

  if (pozycja2 < cel2) pozycja2++;
  else if (pozycja2 > cel2) pozycja2--;

  serwo1.write(pozycja1);
  serwo2.write(pozycja2);

  if (pozycja1 == cel1 && pozycja2 == cel2) {
    if (stan == 4) otwarta();
    else if (stan == 5) zamknieta();
  }
}

// ODCZYT PILOTA
void obslugaPilota() {
  if (!IrReceiver.decode()) return;

  if (IrReceiver.decodedIRData.command == POWER &&
      !(IrReceiver.decodedIRData.flags & IRDATA_FLAGS_IS_REPEAT) &&
      millis() - przycisk > 300) {

    przycisk = millis();
    obslugaPower();
  }

  IrReceiver.resume();
}

void setup() {
  serwo1.attach(3);
  serwo2.attach(5);

  pinMode(LED, OUTPUT);
  pinMode(PIR_PIN, INPUT);

  serwo1.write(pozycja1);
  serwo2.write(pozycja2);

  IrReceiver.begin(IR_PIN, ENABLE_LED_FEEDBACK);
}

void loop() {
  obslugaPIR();
  obslugaPilota();
  sterowanieSerwami();

  digitalWrite(LED, ruch);
}
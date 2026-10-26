
const int zielone1 = 4;
const int czerwone1 = 5;

const int zielone2 = 6;
const int czerwone2 = 7;

const int czujnik1 = 2;
const int czujnik2 = 3;

volatile bool ruch1 = false;
volatile bool ruch2 = false;

void obslugaCzujnika1() {
  ruch1 = true;
}

void obslugaCzujnika2() {
  ruch2 = true;
}

void wszystkieCzerwone() {
  digitalWrite(czerwone1, HIGH);
  digitalWrite(zielone1, LOW);

  digitalWrite(czerwone2, HIGH);
  digitalWrite(zielone2, LOW);
}

void zieloneSwiatlo(int nr) {
  wszystkieCzerwone();

  if (nr == 1) {
    digitalWrite(czerwone1, LOW);
    digitalWrite(zielone1, HIGH);
  } else {
    digitalWrite(czerwone2, LOW);
    digitalWrite(zielone2, HIGH);
  }
}

void setup() {
  pinMode(zielone1, OUTPUT);
  pinMode(czerwone1, OUTPUT);
  pinMode(zielone2, OUTPUT);
  pinMode(czerwone2, OUTPUT);

  pinMode(czujnik1, INPUT);
  pinMode(czujnik2, INPUT);

  wszystkieCzerwone();

  attachInterrupt(digitalPinToInterrupt(czujnik1),
                  obslugaCzujnika1, RISING);

  attachInterrupt(digitalPinToInterrupt(czujnik2),
                  obslugaCzujnika2, RISING);
}

void loop() {
  bool r1;
  bool r2;

  noInterrupts();
  r1 = ruch1;
  r2 = ruch2;
  ruch1 = false;
  ruch2 = false;
  interrupts();

  if (r1) {
    zieloneSwiatlo(1);
  } else if (r2) {
    zieloneSwiatlo(2);
  }
}

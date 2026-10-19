int czerwone1 = 3;
int zielone1 = 2;

int czerwone2 = 5;
int zielone2 = 4;

int czerwone3 = 7;
int zielone3 = 6;

int czerwone4 = 9;
int zielone4 = 8;

// Czujniki PIR
int czujnik1 = 10;
int czujnik2 = 11;
int czujnik3 = 12;
int czujnik4 = 13;

int aktualnyKierunek = 1;

const unsigned long czasZielonego = 2000;
const unsigned long czasCzerwonego = 1000;

void setup() {
  pinMode(czerwone1, OUTPUT);
  pinMode(zielone1, OUTPUT);

  pinMode(czerwone2, OUTPUT);
  pinMode(zielone2, OUTPUT);

  pinMode(czerwone3, OUTPUT);
  pinMode(zielone3, OUTPUT);

  pinMode(czerwone4, OUTPUT);
  pinMode(zielone4, OUTPUT);

  pinMode(czujnik1, INPUT);
  pinMode(czujnik2, INPUT);
  pinMode(czujnik3, INPUT);
  pinMode(czujnik4, INPUT);

  wszystkieCzerwone();
}

void wszystkieCzerwone() {
  digitalWrite(czerwone1, HIGH);
  digitalWrite(czerwone2, HIGH);
  digitalWrite(czerwone3, HIGH);
  digitalWrite(czerwone4, HIGH);

  digitalWrite(zielone1, LOW);
  digitalWrite(zielone2, LOW);
  digitalWrite(zielone3, LOW);
  digitalWrite(zielone4, LOW);
}

void zieloneSwiatlo(int nr) {
  // Najpierw wszystkie kierunki mają czerwone
  wszystkieCzerwone();

  switch (nr) {
    case 1:
      digitalWrite(czerwone1, LOW);
      digitalWrite(zielone1, HIGH);
      break;

    case 2:
      digitalWrite(czerwone2, LOW);
      digitalWrite(zielone2, HIGH);
      break;

    case 3:
      digitalWrite(czerwone3, LOW);
      digitalWrite(zielone3, HIGH);
      break;

    case 4:
      digitalWrite(czerwone4, LOW);
      digitalWrite(zielone4, HIGH);
      break;
  }
}

void czerwoneNaSekunde() {
  wszystkieCzerwone();
  delay(czasCzerwonego);
}

int odczytajCzujnik() {
  // Priorytet: czujnik 1, potem 2, 3 i 4
  if (digitalRead(czujnik1) == HIGH) return 1;
  if (digitalRead(czujnik2) == HIGH) return 2;
  if (digitalRead(czujnik3) == HIGH) return 3;
  if (digitalRead(czujnik4) == HIGH) return 4;

  return 0;
}

void loop() {
  int wykrytyKierunek = odczytajCzujnik();

  if (wykrytyKierunek != 0) {
    // Wykryto ruch: zielone dla danego kierunku
    zieloneSwiatlo(wykrytyKierunek);
    delay(czasZielonego);

    // Wszystkie kierunki czerwone
    czerwoneNaSekunde();

    // Następny cykl rozpocznie się od kolejnego kierunku
    aktualnyKierunek = wykrytyKierunek % 4 + 1;
  } else {
    // Brak ruchu: kolejno kierunki 1, 2, 3, 4
    zieloneSwiatlo(aktualnyKierunek);
    delay(czasZielonego);

    czerwoneNaSekunde();

    aktualnyKierunek++;

    if (aktualnyKierunek > 4) {
      aktualnyKierunek = 1;
    }
  }
}
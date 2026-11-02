
#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0);

// W³asne znaki
byte fire1[8] = {
  B00100,
  B00100,
  B01010,
  B01010,
  B10001,
  B10001,
  B01110,
  B00100
};

byte fire2[8] = {
  B00100,
  B01110,
  B10101,
  B10101,
  B11111,
  B01110,
  B00100,
  B00000
};

byte star[8] = {
  B00100,
  B10101,
  B01110,
  B11111,
  B01110,
  B10101,
  B00100,
  B00000
};

byte kebab[8] = {
  B00100,
  B01110,
  B11111,
  B11111,
  B11111,
  B01110,
  B00100,
  B00100
};

void setup() {
  lcd.begin(16, 2);
  lcd.setBacklight(1);

  lcd.createChar(0, fire1);
  lcd.createChar(1, fire2);
  lcd.createChar(2, star);
  lcd.createChar(3, kebab);

  // START REKLAMY
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("   WITAMY W");
  lcd.setCursor(0, 1);
  lcd.print(" COMILLA KEBAB!");
  delay(2500);
}

void scrollText(String tekst, int speed) {
  tekst = "                " + tekst + "                ";

  for (int i = 0; i <= tekst.length() - 16; i++) {
    lcd.setCursor(0, 1);
    lcd.print(tekst.substring(i, i + 16));
    delay(speed);
  }
}

void flames() {
  for (int i = 0; i < 8; i++) {
    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.write((i % 2) ? byte(0) : byte(1));
    lcd.print(" COMILLA KEBAB ");
    lcd.write((i % 2) ? byte(1) : byte(0));

    lcd.setCursor(0, 1);
    lcd.print("   ");
    lcd.write(byte(3));
    lcd.print(" MEGA SMAK ");
    lcd.write(byte(3));

    lcd.setBacklight(i % 2);
    delay(250);
  }

  lcd.setBacklight(1);
}

void loop() {

  // EKRAN 1 - LOGO
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.write(byte(0));
  lcd.print(" COMILLA KEBAB ");
  lcd.write(byte(1));

  lcd.setCursor(0, 1);
  lcd.print("  SMAK LEGENDY!");
  delay(2500);

  // EKRAN 2 - ANIMACJA
  flames();

  // EKRAN 3 - REKLAMA
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("MASZ GLOWA?");
  lcd.setCursor(0, 1);
  lcd.print("ZJEDZ KEBABA!");
  delay(2500);

  // EKRAN 4 - PRZEWIJANIE
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("   COMILLA TOP");
  scrollText("GORACY SOCZYSTY KEBAB - SMAK NIE DO OPISANIA!", 180);

  // EKRAN 5 - GWIAZDKI
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.write(byte(2));
  lcd.print(" NAJLEPSZY SMAK");
  lcd.write(byte(2));

  lcd.setCursor(0, 1);
  lcd.print("   TYLKO U NAS!");
  delay(2500);

  // EKRAN 6 - PROMOCJA
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("GLODNY?!");
  lcd.setCursor(0, 1);
  lcd.print("NIE CZEKAJ! JEDZ!");
  delay(2500);

  // EKRAN 7 - FINA£
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("COMILLA KEBAB");
  lcd.setCursor(0, 1);
  lcd.print("   OGIEN!!!");

  for (int i = 0; i < 6; i++) {
    lcd.setBacklight(0);
    delay(200);
    lcd.setBacklight(1);
    delay(200);
  }

  // I OD NOWA!
}


#include <Adafruit_LiquidCrystal.h>
#include <Keypad.h>

Adafruit_LiquidCrystal lcd_1(0);

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {2, 3, 4, 5};
byte colPins[COLS] = {6, 7, 8, 9};

Keypad keypad = Keypad(makeKeymap(keys),
                       rowPins, colPins, ROWS, COLS);

String liczba1 = "";
String liczba2 = "";

char znak = 0;
bool druga = false;
bool wynikPokazany = false;

void pokazDzialanie()
{
  lcd_1.clear();
  lcd_1.print(liczba1);

  if (znak != 0)
  {
    lcd_1.setCursor(0, 1);

    if (znak == 'A') lcd_1.print("+");
    if (znak == 'B') lcd_1.print("-");
    if (znak == 'C') lcd_1.print("*");
    if (znak == 'D') lcd_1.print("/");

    lcd_1.print(liczba2);
  }
}

void setup()
{
  lcd_1.begin(16, 2);
  lcd_1.setBacklight(1);
  lcd_1.clear();
}

void loop()
{
  char klawisz = keypad.getKey();

  if (klawisz)
  {
    // RESET
    if (klawisz == '*')
    {
      liczba1 = "";
      liczba2 = "";
      znak = 0;
      druga = false;
      wynikPokazany = false;

      lcd_1.clear();
    }

    // WYBOR DZIALANIA
    else if (klawisz == 'A' || klawisz == 'B' ||
             klawisz == 'C' || klawisz == 'D')
    {
      if (liczba1.length() > 0 && !druga)
      {
        znak = klawisz;
        druga = true;
        liczba2 = "";
        wynikPokazany = false;

        pokazDzialanie();
      }
    }

    // OBLICZANIE WYNIKU
    else if (klawisz == '#')
    {
      if (liczba1.length() > 0 &&
          liczba2.length() > 0 && znak != 0)
      {
        float a = liczba1.toFloat();
        float b = liczba2.toFloat();
        float wynik = 0;

        if (znak == 'A') wynik = a + b;
        if (znak == 'B') wynik = a - b;
        if (znak == 'C') wynik = a * b;

        if (znak == 'D')
        {
          if (b == 0)
          {
            lcd_1.clear();
            lcd_1.print("Blad!");
            lcd_1.setCursor(0, 1);
            lcd_1.print("Dzielenie przez 0");

            liczba1 = "";
            liczba2 = "";
            znak = 0;
            druga = false;
            wynikPokazany = false;
            return;
          }

          wynik = a / b;
        }

        liczba1 = String(wynik, 2);
        liczba2 = "";
        znak = 0;
        druga = false;
        wynikPokazany = true;

        lcd_1.clear();
        lcd_1.print("=");
        lcd_1.setCursor(0, 1);
        lcd_1.print(liczba1);
      }
    }

    // WPISYWANIE CYFR
    else if (klawisz >= '0' && klawisz <= '9')
    {
      if (!druga)
      {
        if (wynikPokazany)
        {
          liczba1 = "";
          wynikPokazany = false;
        }

        if (liczba1.length() < 7)
          liczba1 += klawisz;
      }
      else
      {
        if (liczba2.length() < 7)
          liczba2 += klawisz;
      }

      pokazDzialanie();
    }
  }
}
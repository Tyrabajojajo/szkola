🧮 Kalkulator Arduino – LCD + Keypad

Prosty kalkulator wykonany na platformie Arduino Uno, wykorzystujący klawiaturę matrycową 4×4 oraz wyświetlacz LCD 16×2 z interfejsem I2C.

Projekt umożliwia wykonywanie podstawowych działań matematycznych: dodawania, odejmowania, mnożenia i dzielenia. Wyniki obliczeń wyświetlane są na ekranie LCD.

📸 Wygląd projektu

!Kalkulator Arduino

🛠️ Wykorzystane komponenty
Arduino Uno
Wyświetlacz LCD 16×2 z modułem I2C
Klawiatura matrycowa 4×4 (Keypad)
Przewody połączeniowe
Kabel USB do zasilania i programowania Arduino
🔌 Podłączenie elementów
Wyświetlacz LCD I2C
Pin LCD	Pin Arduino
GND	GND
VCC	5V
SDA	A4
SCL	A5
Klawiatura matrycowa 4×4
Pin klawiatury	Pin Arduino
R1	D2
R2	D3
R3	D4
R4	D5
C1	D6
C2	D7
C3	D8
C4	D9
⚙️ Funkcje kalkulatora

Kalkulator obsługuje cztery podstawowe operacje matematyczne:

Przycisk	Funkcja
A	Dodawanie (+)
B	Odejmowanie (-)
C	Mnożenie (*)
D	Dzielenie (/)
#	Obliczenie wyniku
*	Reset kalkulatora
0–9	Wprowadzanie liczb
Dodatkowe możliwości
Wyświetlanie wprowadzanych liczb na ekranie LCD.
Wyświetlanie wybranego działania matematycznego.
Prezentowanie wyniku z dokładnością do dwóch miejsc po przecinku.
Zabezpieczenie przed dzieleniem przez zero.
Możliwość rozpoczęcia nowego działania po uzyskaniu wyniku.
Ograniczenie długości wprowadzanych liczb do 7 znaków.
💻 Wykorzystane biblioteki

Projekt wykorzystuje dwie biblioteki Arduino:

Adafruit_LiquidCrystal.h – obsługa wyświetlacza LCD.
Keypad.h – obsługa klawiatury matrycowej.

Przed uruchomieniem programu należy upewnić się, że obie biblioteki są zainstalowane w środowisku Arduino IDE.

🚀 Jak korzystać z kalkulatora?

Przykład wykonania działania:

Wpisz pierwszą liczbę, np. 12.
Naciśnij przycisk A, aby wybrać dodawanie.
Wpisz drugą liczbę, np. 8.
Naciśnij #, aby otrzymać wynik.

Rezultat na wyświetlaczu:

text
=
20.00


Aby wyczyścić kalkulator i rozpocząć od nowa, naciśnij *.

📋 Technologie
Arduino / C++
Arduino IDE
Komunikacja I2C
Klawiatura matrycowa 4×4
Wyświetlacz LCD 16×2
🎯 Cel projektu

Celem projektu było stworzenie prostego kalkulatora z wykorzystaniem Arduino, który pozwala poznać podstawy programowania mikrokontrolerów, obsługi wyświetlaczy LCD, komunikacji I2C oraz odczytywania danych z klawiatury matrycowej.

Projekt ma charakter edukacyjny i może stanowić podstawę do dalszego rozwijania urządzeń elektronicznych opartych na Arduino.

Autor: tyra

Projekt edukacyjny – Arduino Calculator
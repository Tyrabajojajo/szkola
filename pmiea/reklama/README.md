🌯 COMILLA KEBAB – LCD Advertising Display

<p align="center">

🔥 Reklama, która przyciąga uwagę! 🔥

Animowany wyświetlacz reklamowy dla COMILLA KEBAB oparty na Arduino i ekranie LCD 16x2.

</p>

📌 O projekcie

COMILLA KEBAB LCD Display to projekt wykorzystujący Arduino oraz wyświetlacz LCD 16x2 do prezentowania animowanej reklamy lokalu gastronomicznego.

Wyświetlacz prezentuje nazwę lokalu, hasła reklamowe, animacje ognia, gwiazdki oraz przewijane komunikaty zachęcające do spróbowania kebaba.

Całość działa automatycznie w nieskończonej pętli, dzięki czemu może pełnić funkcję niewielkiego ekranu reklamowego.

✨ Funkcje
🌯 Wyświetlanie logo COMILLA KEBAB.
🔥 Animacja ognia z wykorzystaniem własnych znaków LCD.
⭐ Animowane i statyczne symbole gwiazdek.
🥙 Dedykowany symbol kebaba.
📢 Kilka różnych ekranów reklamowych.
➡️ Przewijanie długich komunikatów tekstowych.
💡 Efekty migania podświetlenia LCD.
🔄 Automatyczne powtarzanie całej reklamy.
🛠️ Wykorzystane komponenty
Komponent	Ilość
Arduino UNO / kompatybilne	1
LCD 16x2	1
Przewody połączeniowe	Według potrzeb

Biblioteka:

Adafruit_LiquidCrystal
🔌 Podłączenie

Projekt wykorzystuje bibliotekę Adafruit_LiquidCrystal i inicjalizację:

cpp
Adafruit_LiquidCrystal lcd(0);


Wymagany jest zgodny moduł LCD obsługiwany przez tę bibliotekę, np. moduł z ekspanderem I2C.

Adres urządzenia i sposób podłączenia należy dostosować do posiadanego modułu.

💻 Instalacja
Pobierz repozytorium z GitHuba.
Otwórz plik projektu w Arduino IDE.
Zainstaluj bibliotekę Adafruit_LiquidCrystal.
Podłącz wyświetlacz LCD do Arduino.
Wybierz odpowiednią płytkę i port COM.
Wgraj program na Arduino.
Gotowe! Reklama COMILLA KEBAB zacznie działać automatycznie. 🌯
🎬 Jak działa program?

Program składa się z kilku ekranów reklamowych:

Ekran	Opis
1	Powitanie i logo COMILLA KEBAB
2	Animacja ognia 🔥
3	Hasło „MASZ GŁOWA? ZJEDZ KEBABA!”
4	Przewijany tekst reklamowy
5	Ekran z gwiazdkami ⭐
6	Komunikat promocyjny
7	Finał z migającym podświetleniem

Po zakończeniu wszystkich ekranów reklama rozpoczyna się ponownie.

🎨 Własne znaki LCD

Projekt wykorzystuje cztery niestandardowe znaki zapisane w pamięci CGRAM wyświetlacza:

fire1 – pierwszy wariant płomienia.
fire2 – drugi wariant płomienia.
star – gwiazdka.
kebab – symbol kebaba.

Dzięki temu reklama jest bardziej charakterystyczna i przyciąga wzrok.

⚙️ Konfiguracja

Możesz łatwo dostosować reklamę do własnych potrzeb:

Zmienić teksty reklamowe za pomocą lcd.print().
Zmienić szybkość przewijania w scrollText().
Zmienić czas wyświetlania poszczególnych ekranów za pomocą delay().
Zaprojektować własne symbole LCD w tablicach byte.
Zmodyfikować animację ognia w funkcji flames().
📸 Efekt końcowy

Projekt tworzy niewielki, automatyczny wyświetlacz reklamowy, który może być wykorzystany w lokalu gastronomicznym, na stanowisku sprzedaży lub jako ciekawy projekt Arduino.

<p align="center">

🌯 COMILLA KEBAB 🌯

GORĄCY • SOCZYSTY • PEŁEN SMAKU

🔥 SMAK LEGENDY! 🔥

</p>

👨‍💻 Technologie

Arduino C++ LCD 16x2 Adafruit_LiquidCrystal Embedded Systems

📄 Licencja

Projekt udostępniony do celów edukacyjnych i demonstracyjnych. Możesz go rozwijać i dostosowywać do własnych potrzeb.

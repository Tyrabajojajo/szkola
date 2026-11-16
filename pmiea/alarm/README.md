🔐 Alarm Arduino – System alarmowy z czujnikiem ruchu PIR
📌 Opis projektu

Projekt przedstawia prosty system alarmowy wykonany na platformie Arduino. System wykorzystuje czujnik ruchu PIR, klawiaturę membranową 4x4, buzzer oraz trzy diody LED informujące o aktualnym stanie alarmu.

Alarm można uzbroić za pomocą klawiatury. Po naciśnięciu przycisku # rozpoczyna się 5-sekundowe odliczanie, podczas którego świeci żółta dioda. Po tym czasie system zostaje uzbrojony.

W przypadku wykrycia ruchu uruchamiany jest alarm dźwiękowy oraz czerwona dioda LED.

🧰 Wykorzystane komponenty
Arduino UNO
Czujnik ruchu PIR
Klawiatura membranowa 4x4
Buzzer
Zielona dioda LED
Żółta dioda LED
Czerwona dioda LED
3 rezystory 220–330 Ω
Przewody połączeniowe
Płytka stykowa
🔌 Podłączenie elementów
Element	Pin Arduino
Buzzer	10
Czujnik PIR	9
Zielona LED	12
Żółta LED	13
Czerwona LED	A0
Klawiatura – R1	1
Klawiatura – R2	2
Klawiatura – R3	3
Klawiatura – R4	4
Klawiatura – C1	5
Klawiatura – C2	6
Klawiatura – C3	7
Klawiatura – C4	8

Diody LED należy podłączyć przez osobne rezystory 220–330 Ω. Ich krótsze nóżki należy podłączyć do GND.

💡 Działanie diod LED
Stan systemu	Zielona	Żółta	Czerwona
System wyłączony	⚫	⚫	⚫
Uzbrajanie systemu	⚫	🟡	⚫
System uzbrojony	🟢	⚫	⚫
Wykrycie ruchu	⚫	⚫	🔴
⚙️ Zasada działania
Po uruchomieniu Arduino system pozostaje wyłączony.
Użytkownik naciska przycisk # na klawiaturze.
Rozpoczyna się 5-sekundowy proces uzbrajania – świeci żółta dioda LED.
Po upływie 5 sekund system zostaje uzbrojony – zapala się zielona dioda LED.
Czujnik PIR monitoruje otoczenie.
Po wykryciu ruchu zielona dioda gaśnie, a zapala się czerwona.
Buzzer odtwarza sygnał alarmowy składający się z dwóch tonów.
Po ustaniu wykrywania ruchu czerwona dioda gaśnie, a zielona ponownie się zapala.
💻 Wykorzystane technologie
Arduino IDE
Język programowania C++
Biblioteka Keypad.h
Czujnik PIR
Sterowanie diodami LED
Obsługa buzzera za pomocą funkcji tone() i noTone()
Instrukcja switch i case
📚 Biblioteki

Do poprawnego działania projektu wymagana jest biblioteka:

Keypad Library
🎯 Cel projektu

Celem projektu jest stworzenie prostego systemu alarmowego, który pozwala zapoznać się z programowaniem Arduino, obsługą czujników, klawiatury oraz sygnalizacją świetlną i dźwiękową.

👨‍💻 Autor

Projekt edukacyjny – system alarmowy Arduino.

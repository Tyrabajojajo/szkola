🚦 System sygnalizacji świetlnej z czujnikami ruchu PIR

Projekt oparty na Arduino Uno, który wykorzystuje dwa czujniki ruchu PIR do sterowania dwoma zestawami sygnalizatorów LED. System reaguje na wykrycie ruchu, przełączając odpowiedni sygnalizator na zielone światło, podczas gdy drugi pozostaje czerwony.

Projekt wykorzystuje przerwania sprzętowe, dzięki którym wykrycie ruchu może zostać zarejestrowane bez ciągłego sprawdzania stanu czujników w głównej pętli programu.

📸 Schemat układu
Umieść tutaj zdjęcie swojego układu Arduino.

Zapisz obraz w repozytorium, np. jako images/schemat.png, a następnie wyświetl go za pomocą:

!Schemat połączeń Arduino

✨ Funkcjonalności
🔴 Domyślnie oba sygnalizatory wyświetlają czerwone światło.
🟢 Wykrycie ruchu przez pierwszy czujnik uruchamia pierwsze zielone światło.
🟢 Wykrycie ruchu przez drugi czujnik uruchamia drugie zielone światło.
🔄 W danym momencie zielone światło może świecić tylko na jednym sygnalizatorze.
⚡ Obsługa czujników za pomocą przerwań sprzętowych.
🧩 Prosta konstrukcja umożliwiająca dalszą rozbudowę projektu.
🧰 Wykorzystane komponenty
Komponent	Ilość
Arduino Uno	1
Czujnik ruchu PIR	2
Zielona dioda LED	2
Czerwona dioda LED	2
Rezystory do diod LED	4
Płytka stykowa	1
Przewody połączeniowe	Według potrzeb
Kabel USB do Arduino	1
🔌 Schemat podłączenia

Poniższa tabela odpowiada wersji programu wykorzystującej przerwania na pinach 2 i 3.

Element	Pin Arduino Uno
Wyjście OUT czujnika PIR 1	D2
Wyjście OUT czujnika PIR 2	D3
Zielona dioda 1	D4
Czerwona dioda 1	D5
Zielona dioda 2	D6
Czerwona dioda 2	D7
Zasilanie czujników	5V lub zgodnie ze specyfikacją modułu
Masa czujników	GND

Ważne: piny D2 i D3 obsługują standardowe przerwania zewnętrzne w Arduino Uno. Każda dioda LED musi mieć odpowiednio dobrany rezystor ograniczający prąd. Wszystkie elementy muszą mieć wspólną masę.

⚙️ Jak działa projekt?
Po uruchomieniu Arduino oba sygnalizatory ustawiają się na czerwone światło.
Czujnik PIR wykrywa ruch i generuje sygnał na wyjściu OUT.
Zmiana sygnału z LOW na HIGH wywołuje przerwanie sprzętowe.
Funkcja przerwania ustawia odpowiednią flagę informującą o wykryciu ruchu.
Główna pętla programu odczytuje flagę i zmienia stan świateł.
Drugi sygnalizator pozostaje czerwony, aby nie dopuścić do jednoczesnego świecenia obu zielonych świateł.

Czujniki PIR potrzebują chwili na ustabilizowanie się po podłączeniu zasilania. Czas ten zależy od konkretnego modułu.

💻 Wymagania
Arduino Uno lub kompatybilna płytka obsługująca przerwania na pinach 2 i 3.
Arduino IDE.
Dwa czujniki ruchu PIR.
Cztery diody LED z rezystorami.
Przewody oraz płytka stykowa.

Projekt nie wymaga dodatkowych bibliotek — korzysta ze standardowych funkcji Arduino.

🚀 Uruchomienie projektu
Podłącz komponenty zgodnie z tabelą połączeń.
Pobierz lub sklonuj repozytorium.
Otwórz plik .ino w Arduino IDE.
Wybierz odpowiednią płytkę Arduino oraz port COM.
Wgraj program na mikrokontroler.
Po uruchomieniu poczekaj, aż czujniki PIR się ustabilizują.
Sprawdź działanie obu czujników, poruszając się przed nimi.
🧠 Zastosowane rozwiązania
Przerwania sprzętowe

Funkcja attachInterrupt() pozwala reagować na zmianę sygnału z czujnika niezależnie od zwykłego przebiegu pętli loop().

cpp
attachInterrupt(
  digitalPinToInterrupt(czujnik1),
  obslugaCzujnika1,
  RISING
);


Parametr RISING oznacza wykrywanie zbocza narastającego, czyli zmiany sygnału z LOW na HIGH.

Zmienne volatile

Flagi współdzielone przez główny program i funkcje przerwań są oznaczone jako volatile, aby kompilator prawidłowo uwzględniał ich zmiany.

Rozdzielenie obsługi przerwań i logiki programu

Funkcje przerwań wykonują minimalną pracę — ustawiają jedynie flagi. Sterowanie diodami odbywa się w loop(), poza funkcjami przerwań.

🔮 Możliwe rozszerzenia
⏱️ Automatyczne wyłączanie zielonego światła po określonym czasie.
🚶 Wykrywanie ruchu z regulowanym czasem podtrzymania sygnału.
🔁 Obsługa kolejki zdarzeń, gdy oba czujniki wykryją ruch niemal jednocześnie.
📟 Wyświetlanie aktualnego stanu systemu na ekranie LCD.
🔊 Dodanie sygnalizacji dźwiękowej.
🛠️ Rozbudowa układu o kolejne czujniki z wykorzystaniem innych mechanizmów obsługi przerwań.
📚 Technologie
Język: C++
Platforma: Arduino
Mikrokontroler: ATmega328P (Arduino Uno R3)
Czujniki: PIR
Mechanizm sterowania: przerwania sprzętowe
👨‍💻 Autor

Projekt edukacyjny demonstrujący wykorzystanie czujników PIR, diod LED oraz przerwań sprzętowych w środowisku Arduino.

⭐ Jeśli projekt okaże się pomocny, zostaw gwiazdkę w repozytorium!
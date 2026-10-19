🚦 Inteligentna sygnalizacja świetlna z czujnikami PIR



Projekt inteligentnej sygnalizacji świetlnej oparty na Arduino Uno, czterech czujnikach ruchu PIR oraz ośmiu diodach LED. System wykrywa ruch w czterech kierunkach i automatycznie przydziela zielone światło odpowiedniemu kierunkowi.



Gdy żaden czujnik nie wykrywa ruchu, sygnalizacja przełącza się kolejno między wszystkimi kierunkami, zapewniając ciągłą pracę układu.



📸 Schemat połączeń



Schemat przedstawia połączenie Arduino Uno z czterema czujnikami PIR oraz diodami sygnalizującymi światło czerwone i zielone.



Wskazówka: Zapisz załączony schemat w repozytorium jako schemat.png, a następnie umieść go w katalogu głównym projektu.



!Schemat połączeń inteligentnej sygnalizacji świetlnej z Arduino Uno



✨ Funkcje projektu

🚶 Wykrywanie ruchu — cztery czujniki PIR monitorują poszczególne kierunki.

🟢 Dynamiczne sterowanie światłami — wykrycie ruchu uruchamia zielone światło dla odpowiedniego kierunku.

🔴 Bezpieczne przełączanie — przed zmianą kierunku wszystkie światła przechodzą w stan czerwony.

🔄 Tryb automatyczny — przy braku wykrytego ruchu kierunki obsługiwane są kolejno: 1 → 2 → 3 → 4.

⚙️ Konfigurowalne czasy — długość zielonego i czerwonego światła można zmienić w kodzie.

🧩 Prosta konstrukcja — projekt wykorzystuje popularne komponenty i może być rozbudowywany.

🧰 Wykorzystane komponenty

Komponent	Liczba	Zastosowanie

Arduino Uno	1	Sterowanie całym układem

Czujnik ruchu PIR	4	Wykrywanie ruchu w czterech kierunkach

Czerwona dioda LED	4	Sygnalizacja zatrzymania

Zielona dioda LED	4	Sygnalizacja przejazdu

Rezystor do każdej diody LED	8	Ograniczenie prądu diod

Płytka stykowa	1 lub więcej	Montaż układu

Przewody połączeniowe	Według potrzeb	Połączenie komponentów

Kabel USB	1	Zasilanie i programowanie Arduino

🔌 Przypisanie pinów Arduino

Diody LED

Kierunek	Czerwona LED	Zielona LED

Kierunek 1	D3	D2

Kierunek 2	D5	D4

Kierunek 3	D7	D6

Kierunek 4	D9	D8

Czujniki PIR

Czujnik	Pin sygnałowy Arduino

PIR 1	D10

PIR 2	D11

PIR 3	D12

PIR 4	D13



Zasilanie czujników: podłącz VCC do odpowiedniego napięcia zasilania czujnika, GND do masy Arduino, a OUT do przypisanego pinu cyfrowego.



Ważne: każda dioda LED powinna mieć odpowiednio dobrany rezystor ograniczający prąd. Sprawdź również wymagania napięciowe swoich modułów PIR.



⚙️ Jak działa program?

1\. Inicjalizacja



Po uruchomieniu Arduino konfiguruje piny wejściowe i wyjściowe. Następnie włącza czerwone światło na wszystkich kierunkach.



2\. Odczyt czujników



Program sprawdza kolejno czujniki PIR 1, 2, 3 i 4. Jeżeli kilka czujników zgłosi ruch jednocześnie, pierwszeństwo ma czujnik sprawdzany jako pierwszy.



3\. Wybór zielonego światła

Jeżeli wykryto ruch, zielone światło zostaje włączone dla wykrytego kierunku.

Jeżeli ruch nie został wykryty, system kontynuuje cykliczne przełączanie kierunków.

4\. Czas przejazdu



Wybrany kierunek otrzymuje zielone światło przez 2 sekundy.



5\. Zmiana świateł



Po zakończeniu zielonego światła wszystkie kierunki otrzymują czerwone światło na 1 sekundę. Następnie rozpoczyna się kolejny cykl.



⏱️ Konfiguracja czasów



Czasy działania sygnalizacji można zmienić na początku kodu:



const unsigned long czasZielonego = 2000;

const unsigned long czasCzerwonego = 1000;





Wartości podawane są w milisekundach.



Parametr	Wartość domyślna	Znaczenie

czasZielonego	2000 ms	Czas świecenia zielonej diody

czasCzerwonego	1000 ms	Czas świecenia czerwonych diod na wszystkich kierunkach



Przykładowo, aby ustawić 5 sekund zielonego światła, zmień wartość czasZielonego na 5000.



💻 Uruchomienie projektu

Zbuduj układ zgodnie ze schematem połączeń.

Podłącz Arduino Uno do komputera przez USB.

Otwórz program w Arduino IDE.

Wybierz płytkę Arduino Uno oraz właściwy port COM.

Wgraj program na płytkę.

Po uruchomieniu sprawdź działanie diod oraz reakcję czujników PIR na ruch.



Uwaga: czujniki PIR mogą wymagać chwili na inicjalizację po włączeniu zasilania. Ich czułość i czas podtrzymania sygnału zależą od konkretnego modelu i ustawień modułu.



🧠 Najważniejsze funkcje w kodzie

Funkcja	Opis

setup()	Konfiguruje piny i inicjalizuje sygnalizację

wszystkieCzerwone()	Włącza czerwone światło na wszystkich kierunkach

zieloneSwiatlo(int nr)	Wybiera kierunek, dla którego ma zapalić się zielone światło

czerwoneNaSekunde()	Włącza wszystkie czerwone światła na określony czas

odczytajCzujnik()	Sprawdza czujniki PIR według ustalonej kolejności

loop()	Realizuje główną logikę działania systemu

🔧 Możliwe rozszerzenia



Projekt można rozbudować o dodatkowe funkcje:



🚥 Dodanie żółtych diod LED i fazy ostrzegawczej.

⏳ Wydłużanie zielonego światła zależnie od czasu wykrywania ruchu.

⚖️ Zmiana priorytetów czujników lub obsługa kilku aktywnych czujników.

🖥️ Wyświetlanie aktualnego kierunku i stanu sygnalizacji na ekranie LCD.

📡 Zdalne monitorowanie stanu systemu.

⚡ Zastąpienie funkcji delay() rozwiązaniem opartym na millis(), aby umożliwić równoczesne odczytywanie czujników podczas zmiany świateł.

⚠️ Ograniczenia

Program obsługuje tylko jeden zielony kierunek naraz.

Czujniki są sprawdzane sekwencyjnie, więc przy jednoczesnym wykryciu ruchu obowiązuje priorytet czujnika o niższym numerze.

Funkcja delay() blokuje wykonywanie pozostałej części programu na czas oczekiwania.

Jest to projekt edukacyjny, a nie certyfikowany system sterowania ruchem drogowym. Nie należy stosować go do sterowania rzeczywistą sygnalizacją drogową.

🎯 Cel projektu



Celem projektu jest nauka programowania mikrokontrolerów Arduino, obsługi czujników ruchu, sterowania diodami LED oraz tworzenia prostych systemów automatyki reagujących na otoczenie.



Technologie: Arduino Uno · C/C++ · Arduino IDE · PIR · LED


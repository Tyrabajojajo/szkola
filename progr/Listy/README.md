📋 Lista jednokierunkowa w C++

Prosty projekt w języku C++, przedstawiający obsługę listy jednokierunkowej z wykorzystaniem struktur (struct) oraz dynamicznego zarządzania pamięcią.

📌 Opis projektu

Program wczytuje liczby całkowite z pliku tekstowego i zapisuje je w postaci elementów listy jednokierunkowej. Następnie wyświetla zawartość listy i zwalnia zaalokowaną pamięć.

Projekt został wykonany w celach edukacyjnych, aby przećwiczyć podstawowe operacje na dynamicznych strukturach danych.

⚙️ Funkcjonalności
🧱 Tworzenie elementów listy jednokierunkowej.
📂 Wczytywanie danych z pliku tekstowego.
➕ Dodawanie elementów na koniec listy.
🖨️ Wyświetlanie wszystkich elementów listy.
🗑️ Zwalnianie pamięci za pomocą delete.
🛠️ Technologie
Język: C++
Biblioteki: iostream, fstream
Struktury danych: lista jednokierunkowa oparta na struct
Pamięć: dynamiczna alokacja za pomocą new i zwalnianie za pomocą delete

Projekt nie korzysta z gotowej implementacji listy, takiej jak std::list.

📁 Struktura projektu
text
lista-jednokierunkowa/
├── main.cpp
├── dane.txt
└── README.md

main.cpp – kod źródłowy programu.
dane.txt – plik zawierający liczby do wczytania.
README.md – dokumentacja projektu.
📄 Przykładowe dane

Plik dane.txt:

text
3 7 1 2

▶️ Uruchomienie programu
Sklonuj repozytorium:
bash
git clone <URL_REPOZYTORIUM>

Przejdź do katalogu projektu:
bash
cd lista-jednokierunkowa

Skompiluj program za pomocą kompilatora g++:
bash
g++ main.cpp -o lista

Uruchom program:

Linux / macOS:

bash
./lista


Windows:

bash
lista.exe


Upewnij się, że plik dane.txt znajduje się w katalogu, z którego uruchamiasz program.

💻 Przykładowy wynik
text
3 7 1 2

🎯 Cel projektu

Celem projektu jest nauka:

działania list jednokierunkowych,
obsługi wskaźników i struktur,
odczytu danych z plików tekstowych,
dynamicznego przydzielania i zwalniania pamięci,
podstaw organizacji kodu w C++.

Autor: [Twoje imię lub nick na GitHubie]

Status projektu: Edukacyjny / ukończony
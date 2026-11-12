📊 Porównanie sortowania – Tablica vs Lista dwukierunkowa
📌 Opis projektu

Projekt przedstawia porównanie wydajności dwóch struktur danych:

Tablicy (Array)
Listy dwukierunkowej (Doubly Linked List)

Do sortowania obu struktur wykorzystano algorytm Insertion Sort (sortowanie przez wstawianie).

Głównym celem projektu jest sprawdzenie, która struktura danych pozwala na szybsze sortowanie tych samych zestawów liczb.

⚙️ Wykorzystane technologie
C++
chrono – pomiar czasu wykonywania operacji
cstdlib – generowanie losowych liczb
ctime – inicjalizacja generatora liczb losowych
🧠 Zastosowany algorytm
Insertion Sort – sortowanie przez wstawianie

Algorytm działa na zasadzie pobierania kolejnych elementów i umieszczania ich na odpowiednim miejscu w już posortowanej części zbioru.

Złożoność obliczeniowa:

Przypadek	Złożoność
Najlepszy	O(n)
Średni	O(n²)
Najgorszy	O(n²)
🗂️ Porównywane struktury danych
1. Tablica
Elementy przechowywane są w ciągłym obszarze pamięci.
Dostęp do elementu za pomocą indeksu wynosi O(1).
Dobra lokalność pamięci podręcznej.
2. Lista dwukierunkowa
Każdy element przechowuje wartość oraz dwa wskaźniki: next i prev.
Umożliwia poruszanie się w obu kierunkach.
Elementy nie muszą znajdować się obok siebie w pamięci.

Przykładowa struktura:

cpp
struct lista2
{
    int liczba;
    lista2* next;
    lista2* prev;
};

⏱️ Pomiar czasu

Do pomiaru czasu sortowania wykorzystano bibliotekę chrono.

Program mierzy osobno:

Czas sortowania tablicy.
Czas sortowania listy dwukierunkowej.
Porównuje uzyskane wyniki i wskazuje szybszą strukturę.
📈 Testy wydajności

Testy można przeprowadzić dla różnych rozmiarów zbiorów danych:

Liczba elementów	Tablica	Lista dwukierunkowa
1 000	—	—
5 000	—	—
10 000	—	—
20 000	—	—

Wyniki należy uzupełnić po uruchomieniu programu.

🏁 Wnioski

Celem eksperymentu jest sprawdzenie wpływu struktury danych na szybkość działania algorytmu Insertion Sort.

Przewidywane rezultaty:

Tablica powinna osiągać lepsze czasy sortowania dzięki ciągłemu rozmieszczeniu danych w pamięci.
Lista dwukierunkowa wymaga dodatkowej pamięci na wskaźniki.
Obie implementacje mają średnią i najgorszą złożoność O(n²).

Ostateczne wnioski zostaną wyciągnięte na podstawie przeprowadzonych pomiarów.

🚀 Uruchomienie programu

Skompilowanie programu za pomocą g++:

bash
g++ main.cpp -o sortowanie


Uruchomienie:

bash
./sortowanie


W systemie Windows:

bash
sortowanie.exe

👨‍💻 Autor

Projekt edukacyjny – porównanie struktur danych i wydajności algorytmów sortowania w języku C++.
# Drzewo binarnych wyszukiwań – C++

## Opis programu

Program służy do tworzenia i obsługi drzewa binarnych wyszukiwań (BST).

Liczby są odczytywane z pliku tekstowego `liczby.txt`, a następnie dodawane do drzewa za pomocą funkcji rekurencyjnej.

## Funkcjonalności

1. **Wczytywanie danych** – program odczytuje liczby z pliku `liczby.txt`.
2. **Dodawanie elementów** – funkcja `wstaw()` rekurencyjnie dodaje liczby do drzewa.
3. **Wypisywanie drzewa** – funkcja `wypisz()` wypisuje liczby w kolejności rosnącej.
4. **Usuwanie drzewa** – funkcja `usun()` rekurencyjnie zwalnia pamięć zajmowaną przez wszystkie elementy drzewa.
5. **Liczenie usuniętych elementów** – zmienna globalna `usuniete` zlicza wykonane operacje `delete`.

## Struktura drzewa

Każdy element drzewa zawiera:
- `liczba` – przechowywana wartość.
- `lewy` – wskaźnik na lewe poddrzewo.
- `prawy` – wskaźnik na prawe poddrzewo.

Mniejsze lub równe wartości trafiają do lewego poddrzewa, a większe do prawego.

## Funkcje programu

- `wstaw()` – dodaje nowy element do drzewa.
- `wypisz()` – wypisuje elementy w kolejności: lewe poddrzewo, korzeń, prawe poddrzewo.
- `usun()` – usuwa wszystkie elementy drzewa i zlicza operacje `delete`.

## Pliki

- `main.cpp` – kod źródłowy programu.
- `liczby.txt` – plik zawierający liczby do wczytania.
- `README.md` – dokumentacja programu.

## Uruchomienie

1. Umieść pliki `main.cpp` i `liczby.txt` w tym samym katalogu.
2. Skompiluj program.
3. Uruchom program.

## Sprawdzanie pamięci

Po zakończeniu działania programu porównywana jest liczba wczytanych elementów z liczbą wykonanych operacji `delete`.

Jeżeli obie wartości są takie same, oznacza to, że wszystkie elementy drzewa zostały usunięte.
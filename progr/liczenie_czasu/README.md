# Porównanie struktur danych w C++

Program porównuje wydajność trzech struktur danych w języku **C++**:

- `std::vector`
- tablica dynamiczna
- `std::list`

Dla każdej struktury wykonywane są te same operacje, a ich czas jest mierzony za pomocą biblioteki `chrono`.

## Zakres testów

Program wykonuje następujące operacje:

1. Generuje **100 000 losowych liczb**.
2. Wstawia wszystkie liczby do badanej struktury.
3. Sortuje 100 000 elementów.
4. Wstawia **50 000 elementów do środka** struktury.
5. Usuwa **50 000 elementów ze środka** struktury.
6. Mierzy czas każdej operacji.

## Wykorzystane technologie

- **C++**
- `std::vector`
- `std::list`
- tablica dynamiczna
- `std::chrono` – pomiar czasu
- `std::random` – generowanie losowych liczb
- `std::algorithm` – sortowanie

## Przykładowy wynik

Wyniki zależą od komputera oraz aktualnego obciążenia systemu.

```
VECTOR
Wstawienie 100000: XX ms
Sortowanie: XX ms
Wstawienie 50000 do srodka: XX ms
Usuniecie 50000 ze srodka: XX ms

TABLICA
Wstawienie 100000: XX ms
Sortowanie: XX ms
Wstawienie 50000 do srodka: XX ms
Usuniecie 50000 ze srodka: XX ms

STD::LIST
Wstawienie 100000: XX ms
Sortowanie: XX ms
Wstawienie 50000 do srodka: XX ms
Usuniecie 50000 ze srodka: XX ms
```

## Złożoność operacji

| Operacja | `vector` | Tablica | `list` |
| --- | --- | --- | --- |
| Wstawianie na końcu | O(1)\* | O(1) | O(1) |
| Sortowanie | O(n log n) | O(n log n) | O(n log n) |
| Wstawianie w środku | O(n) | O(n) | O(1) |
| Usuwanie ze środka | O(n) | O(n) | O(1) |

\* Średnio, dzięki mechanizmowi zwiększania pojemności `vector`.

\*\* Jeśli mamy już iterator wskazujący odpowiednie miejsce. Samo znalezienie środka listy wymaga przejścia przez elementy.

## Najważniejsze różnice

### `std::vector`

Elementy są przechowywane w ciągłym obszarze pamięci.

**Zalety:**

- szybki dostęp przez indeks,
- dobra wydajność podczas przechodzenia po elementach,
- wygodne sortowanie.

**Wady:**

- wstawianie i usuwanie ze środka wymaga przesuwania elementów.

### Tablica dynamiczna

Tablica dynamiczna również przechowuje elementy w ciągłym obszarze pamięci.

**Zalety:**

- szybki dostęp przez indeks,
- prosta struktura,
- dobra wydajność podczas sortowania.

**Wady:**

- ręczne zarządzanie pamięcią,
- wstawianie i usuwanie ze środka wymaga przesuwania elementów.

### `std::list`

`std::list` jest listą dwukierunkową. Elementy nie muszą znajdować się obok siebie w pamięci.

**Zalety:**

- szybkie wstawianie i usuwanie elementów, jeśli mamy iterator,
- brak konieczności przesuwania pozostałych elementów.

**Wady:**

- brak dostępu przez indeks,
- wolniejsze przechodzenie po elementach,
- większe zużycie pamięci.

## Uruchomienie

### Wymagania

Potrzebny jest kompilator obsługujący standard **C++11 lub nowszy**.

### Kompilacja

```
g++ main.cpp -std=c++11 -O2 -o program
```

### Uruchomienie

Linux / macOS:

```
./program
```

Windows:

```
program.exe
```

## Cel projektu

Celem projektu jest praktyczne porównanie wydajności różnych struktur danych oraz sprawdzenie, jak ich właściwości wpływają na czas wykonywania podstawowych operacji.

Wyniki pomiarów mogą być różne na różnych komputerach, dlatego najważniejsze jest porównanie struktur danych **na tym samym sprzęcie i w tych samych warunkach**.

---

### Autor

Projekt wykonany w ramach nauki języka **C++** i struktur danych. :::
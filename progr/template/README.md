# Szablonowa funkcja wypisująca w C++ (`wypisz`)

Prosty, edukacyjny projekt w języku C++, który demonstruje wykorzystanie **szablonów funkcji (templates)** oraz ich **przeciążania** do obsługi różnorodnych typów danych – od typów prostych (liczby, znaki, wartości logiczne) po złożone struktury danych, takie jak `std::vector` oraz zwykłe tablice statyczne.

## 🚀 Funkcjonalności

Kod potrafi automatycznie rozpoznać przekazany typ danych i dobrać odpowiednią wersję funkcji `wypisz`:
* **Typy podstawowe:** `int`, `double`, `char`, `bool` oraz `std::string`.
* **Kontener `std::vector`:** Wypisuje wszystkie elementy wektora w czytelnej formie.
* **Tablice statyczne (C-style arrays):** Automatycznie wyznacza rozmiar tablicy w czasie kompilacji i wyświetla jej zawartość.
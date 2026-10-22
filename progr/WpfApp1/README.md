# 🔢 Licznik punktów

Prosta aplikacja desktopowa napisana w **C# i WPF**, która pozwala na szybkie zliczanie punktów. Program posiada czytelny interfejs graficzny oraz trzy przyciski umożliwiające zmianę wyniku.

## 🖥️ Funkcje

- ➕ **Dodaj 1** — zwiększa licznik o jeden punkt.
- ➖ **Odejmij 1** — zmniejsza licznik o jeden punkt.
- 🔄 **Resetuj** — ustawia licznik ponownie na `0`.
- 🔢 **Aktualny wynik** — wyświetla bieżącą liczbę punktów.
- 🎨 **Prosty interfejs** — jasne tło, zaokrąglony panel i niebieski akcent kolorystyczny.

## 🛠️ Technologie

- **C#** — obsługa logiki programu.
- **WPF (Windows Presentation Foundation)** — interfejs graficzny.
- **XAML** — wygląd i układ okna aplikacji.
- **.NET** — środowisko uruchomieniowe aplikacji.

## 📂 Struktura projektu

```text
LicznikWPF/
├── MainWindow.xaml       # Interfejs aplikacji
├── MainWindow.xaml.cs    # Logika licznika
├── App.xaml              # Konfiguracja aplikacji
├── App.xaml.cs           # Punkt wejścia aplikacji
└── LicznikWPF.csproj     # Plik projektu
```

*Struktura może się nieznacznie różnić w zależności od konfiguracji projektu.*

## 🚀 Uruchomienie

1. Sklonuj repozytorium:

   ```bash
   git clone URL_REPOZYTORIUM
   ```

2. Otwórz plik `LicznikWPF.sln` lub `LicznikWPF.csproj` w Visual Studio.
3. Poczekaj na przywrócenie wymaganych zależności.
4. Uruchom aplikację przyciskiem **Start** lub klawiszem `F5`.

## 📋 Jak działa program?

Licznik przechowuje aktualną liczbę punktów w zmiennej `count`.

- Po kliknięciu **Dodaj 1** wartość zwiększa się o jeden.
- Po kliknięciu **Odejmij 1** wartość zmniejsza się o jeden.
- Po kliknięciu **Resetuj** wartość wraca do zera.

Po każdej zmianie wynik jest aktualizowany w elemencie `CounterBlock`.

## 🎯 Cel projektu

Projekt służy do nauki podstaw programowania w C#, obsługi zdarzeń oraz tworzenia interfejsów graficznych w technologii WPF.

## 📄 Licencja

Projekt edukacyjny. Możesz dodać własną licencję, jeśli planujesz udostępniać kod innym osobom.

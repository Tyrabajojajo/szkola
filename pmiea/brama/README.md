# 🚪 Arduino Gate Control (IR & PIR)

Projekt systemu sterowania dwoma serwomechanizmami (np. brama/drzwiczki) za pomocą Arduino, pilota na podczerwień (IR) oraz czujnika ruchu PIR.

## 📋 Spis treści
- [Funkcje](#-funkcje)
- [Wymagania sprzętowe](#-wymagania-sprzętowe)
- [Schemat podłączenia](#-schemat-podłączenia)
- [Opis działania i logika stany](#-opis-działania-i-logika-stany)
- [Instalacja i uruchomienie](#-instalacja-i-uruchomienie)

---

## ✨ Funkcje
- **Sterowanie pilotem IR:** Otwieranie, zamykanie oraz zatrzymywanie/uchylanie mechanizmu za pomocą przycisku `POWER`.
- **Bezpieczeństwo (PIR):** Jeśli czujnik wykryje ruch podczas zamykania bramy, mechanizm automatycznie zmienia kierunek i otwiera się ponownie.
- **Płynny ruch:** Sterowanie serwami opcone na funkcji czasowej (`millis()`), co zapobiega blokowaniu programu.
- **Sygnalizator LED:** Dioda LED informująca o tym, że mechanizm jest w ruchu.

---

## 🛠 Wymagania sprzętowe
- Płytka Arduino (np. Uno / Nano)
- 2x Serwomechanizm
- Odbiornik podczerwieni (IR Receiver) + pilot (np. protokoły NEC / biblioteka `IRremote`)
- Czujnik ruchu PIR
- Dioda LED + rezektor ogranicznikowy
- Przewody połączeniowe i zasilanie zewnętrzne dla serw (zalecane)

---

## 📌 Schemat podłączenia (Pinout)
W kodzie zdefiniowano następujące przypisanie pinów:
- **Serwo 1:** Pin cyfrowy `3`
- **Serwo 2:** Pin cyfrowy `5`
- **Odbiornik IR:** Pin cyfrowy `10`
- **Czujnik PIR:** Pin cyfrowy `4`
- **Dioda LED:** Pin cyfrowy `12`

---

## 🔄 Opis działania
Projekt opiera się na prostej maszynie stanów:
1. **Stan Zohandlowany (Zamknięta):** Serwa ustawione w pozycji bazowej ($0^\circ$ / $180^\circ$).
2. **Otwieranie / Zamykanie:** Płynny ruch serw do pozycji docelowych.
3. **Reakcja na PIR:** Podczas zamykania bramy, wykrycie ruchu przez czujnik PIR natychmiast wyzwala ponowne otwarcie.

---

## 🚀 Instalacja i uruchomienie
1. Pobierz i zainstaluj środowisko [Arduino IDE](https://www.arduino.cc/).
2. Zainstaluj bibliotekę **IRremote** wened managerem bibliotek (Library Manager).
3. Skopiuj kod źródłowy do pliku `.ino`.
4. Podłącz układy zgodnie z opisem pinów i wgraj program na płytkę Arduino.
# 🚦 Inteligentna sygnalizacja świetlna z czujnikami PIR

Projekt sygnalizacji świetlnej opartej na **Arduino**, która steruje czterema kierunkami ruchu. System wykorzystuje czujniki ruchu PIR, aby wykrywać obecność obiektów i przydzielać zielone światło odpowiedniemu kierunkowi.

## 📌 Funkcje projektu

- 🚦 Sterowanie czterema niezależnymi sygnalizatorami.
- 👁️ Wykrywanie ruchu za pomocą czterech czujników PIR.
- 🟢 Przydzielanie zielonego światła kierunkowi, na którym wykryto ruch.
- 🔴 Automatyczne przełączanie wszystkich świateł na czerwone pomiędzy cyklami.
- 🔄 Naprzemienne zmienianie kierunków, gdy żaden czujnik nie wykrywa ruchu.
- ⚙️ Możliwość łatwej zmiany czasu trwania poszczególnych faz sygnalizacji.

## 🧰 Wykorzystane komponenty

- Arduino
- 4 × czujnik ruchu PIR
- 4 × czerwona dioda LED
- 4 × zielona dioda LED
- Rezystory do diod LED
- Płytka stykowa
- Przewody połączeniowe

## 🔌 Podłączenie pinów

| Element | Pin Arduino |
|---|---|
| 🔴 Czerwone światło 1 | 3 |
| 🟢 Zielone światło 1 | 2 |
| 🔴 Czerwone światło 2 | 5 |
| 🟢 Zielone światło 2 | 4 |
| 🔴 Czerwone światło 3 | 7 |
| 🟢 Zielone światło 3 | 6 |
| 🔴 Czerwone światło 4 | 9 |
| 🟢 Zielone światło 4 | 8 |
| Czujnik PIR 1 | 10 |
| Czujnik PIR 2 | 11 |
| Czujnik PIR 3 | 12 |
| Czujnik PIR 4 | 13 |

## ⚙️ Zasada działania

**1. Uruchomienie**

Po uruchomieniu programu wszystkie sygnalizatory ustawiają czerwone światło.

**2. Wykrycie ruchu**

Jeżeli jeden z czujników PIR wykryje ruch, odpowiadający mu kierunek otrzymuje zielone światło na 2 sekundy.

**3. Zmiana świateł**

Po zakończeniu fazy zielonej wszystkie kierunki otrzymują czerwone światło na 1 sekundę.

**4. Brak wykrytego ruchu**

Jeśli żaden czujnik nie wykrywa ruchu, system kolejno przydziela zielone światło kierunkom 1, 2, 3 i 4.

**5. Priorytet czujników**

Jeżeli kilka czujników wykrywa ruch jednocześnie, program wybiera pierwszy aktywny czujnik według kolejności: 1 → 2 → 3 → 4.

## ⏱️ Ustawienia czasu

Czasy działania sygnalizacji można zmienić w kodzie:

```cpp
const unsigned long czasZielonego = 2000;
const unsigned long czasCzerwonego = 1000;
```

- `czasZielonego` – czas zielonego światła w milisekundach.
- `czasCzerwonego` – czas, przez który wszystkie kierunki mają czerwone światło.

## 🚀 Uruchomienie projektu

1. Podłącz komponenty do Arduino zgodnie z tabelą.
2. Otwórz kod projektu w Arduino IDE.
3. Wybierz odpowiednią płytkę i port komunikacyjny.
4. Wgraj program na Arduino.
5. Sprawdź działanie diod i czujników PIR.

## 📂 Struktura projektu

```text
sygnalizacja-swietlna/
├── sygnalizacja-swietlna.ino
└── README.md
```

## 🎯 Cel projektu

Celem projektu jest poznanie podstaw programowania Arduino, obsługi czujników ruchu, sterowania diodami LED oraz wykorzystania instrukcji warunkowych i funkcji do zarządzania prostym systemem sygnalizacji świetlnej.

---

**Technologie:** C++ · Arduino · Czujniki PIR · Elektronika

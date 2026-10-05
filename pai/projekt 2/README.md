⚔️ Geralt — Karta Postaci RPG

Interaktywna karta postaci RPG inspirowana klimatem Wiedźmina.
Projekt przedstawia Geralta wraz z jego statystykami, paskiem zdrowia, bronią oraz ekwipunkiem.

🎮 Podgląd

Karta zawiera:

⚔️ profil postaci Geralta

📊 poziom postaci

❤️ aktualne HP oraz maksymalne HP

🪙 ilość złota

🗡️ aktualnie wyposażoną broń

🎒 ekwipunek z obrazkami przedmiotów

📈 dynamiczny pasek zdrowia

🛠️ Technologie

Projekt został wykonany przy użyciu:

HTML5 — struktura strony

CSS3 — wygląd i stylowanie

JavaScript — dane postaci oraz dynamiczne generowanie elementów

📁 Struktura projektu
projekt/
│
├── index.html
├── style.css
├── script.js
│
├── geralt.jpg
├── mikstura.jpg
└── bomba.jpg

⚙️ Jak uruchomić?

Sklonuj repozytorium:

git clone https://github.com/TWOJ-LOGIN/TWOJE-REPO.git


Przejdź do folderu projektu:

cd TWOJE-REPO


Otwórz plik index.html w przeglądarce.

Nie są wymagane żadne dodatkowe biblioteki ani instalacje.

🧙 Dane postaci

Przykładowe dane znajdują się w pliku script.js:

const player = {
    name: "Geralt",
    level: 12,
    gold: 43,
    hp: 85,
    maxHP: 100,

    weapon: {
        name: "Srebrny miecz",
        dmg: 35
    },

    inventory: [
        {
            name: "Mikstura",
            image: "mikstura.jpg"
        },
        {
            name: "Bomba",
            image: "bomba.jpg"
        }
    ]
};


Możesz dowolnie zmieniać wartości, np. poziom, HP, złoto, broń czy ekwipunek.

🎨 Możliwości rozbudowy

Projekt można w przyszłości rozszerzyć o:

🧪 używanie mikstur

💥 rzucanie bomb

⚔️ zmianę broni

❤️ regenerację HP

⭐ zdobywanie doświadczenia

🆙 system levelowania

👹 przeciwników

⚔️ system walki

💾 zapisywanie postępów w localStorage

🌙 animacje i efekty wizualne

📌 Cel projektu

Projekt został stworzony jako ćwiczenie z podstaw:

HTML

CSS

JavaScript

manipulacji DOM

pracy z obiektami i tablicami

dynamicznego generowania elementów strony

👨‍💻 Autor

Tyrabajojajo

⭐ Jeśli projekt Ci się podoba, zostaw gwiazdkę na GitHubie!
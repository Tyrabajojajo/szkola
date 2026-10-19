
const player = {
    name: "Geralt",
    level: 13,
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

document.getElementById("name").textContent = player.name;

document.getElementById("level").textContent =
    "POZIOM " + player.level;

document.getElementById("hp-text").textContent =
    player.hp + " / " + player.maxHP;

document.getElementById("hp-bar").style.width =
    (player.hp / player.maxHP * 100) + "%";

document.getElementById("gold").textContent = player.gold;

document.getElementById("damage").textContent =
    player.weapon.dmg;

document.getElementById("weapon").textContent =
    player.weapon.name;

const items = document.getElementById("items");

player.inventory.forEach(function(item) {
    items.innerHTML += `
        <div class="item">
            <img src="${item.image}" alt="${item.name}">
            <p>${item.name}</p>
        </div>
    `;
});
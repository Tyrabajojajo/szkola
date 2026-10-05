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
        },
    ]
};

// PODSTAWOWE INFORMACJE

document.getElementById("playerName").textContent =
    player.name;

document.getElementById("level").textContent =
    player.level;

document.getElementById("levelStat").textContent =
    player.level;

document.getElementById("gold").textContent =
    player.gold;


// HP

document.getElementById("hp").textContent =
    player.hp;

document.getElementById("maxHP").textContent =
    player.maxHP;

const hpPercent =
    (player.hp / player.maxHP) * 100;

document.getElementById("hpBar").style.width =
    hpPercent + "%";


// BROŃ

document.getElementById("weaponName").textContent =
    player.weapon.name;

document.getElementById("damage").textContent =
    player.weapon.dmg;


// EKWIPUNEK

const inventory =
    document.getElementById("inventory");

    player.inventory.forEach(item => {

        const element = document.createElement("div");
        element.className = "item";
        element.innerHTML = `
            <img src="${item.image}" alt="${item.name}">
            <span>${item.name}</span>
        `;

        inventory.appendChild(element);
    });
    
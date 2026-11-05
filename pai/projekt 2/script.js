
const player = {
    name: "Geralt",
    level: 13,
    gold: 100,
    hp: 85,
    maxHP: 100,

    weapon: {
        name: "Srebrny miecz",
        dmg: 35,
        image: "anigivare.jpg"
    },

    inventory: [
        {
            name: "Mikstura leczenia",
            image: "mikstura.jpg",
            type: "healing",
            quantity: 1
        },
        {
            name: "Bomba",
            image: "bomba.jpg",
            type: "bomb",
            quantity: 1
        }
    ]
};


// SKLEP

const sklep = [
    {
        id: "healing",
        name: "Mikstura leczenia",
        description: "Przywraca 30 punktów zdrowia.",
        price: 15,
        image: "mikstura.jpg",
        type: "healing"
    },
    {
        id: "strength",
        name: "Mikstura siły",
        description: "Zwiększa obrażenia o 10 punktów.",
        price: 25,
        image: "sila.png",
        type: "strength"
    },
    {
        id: "sword",
        name: "Ulepszony miecz",
        description: "Zwiększa obrażenia o 20 punktów.",
        price: 60,
        image: "arbitrator.jpg",
        type: "sword"
    },
    {
        id: "bomb",
        name: "Bomba",
        description: "Wiedźmiński materiał wybuchowy.",
        price: 20,
        image: "bomba.jpg",
        type: "bomb"
    }
];


// QUESTY

const quests = [
    {
        id: 1,
        name: "Bestia z Białego Sadu",
        description: "Wieśniacy donoszą o potworze atakującym podróżnych. Zbadaj okolicę i dowiedz się, co się tam czai.",
        reward: 100
    },
    {
        id: 2,
        name: "Zaginiony kupiec",
        description: "Kupiec nie wrócił z podróży do pobliskiej wioski. Odszukaj go i sprawdź, co się wydarzyło.",
        reward: 75
    },
    {
        id: 3,
        name: "Problemy na trakcie",
        description: "Na trakcie pojawili się bandyci. Mieszkańcy proszą o pomoc w rozwiązaniu problemu.",
        reward: 50
    }
];

let acceptedQuests = [];


// ELEMENTY HTML

const nameElement = document.getElementById("name");
const levelElement = document.getElementById("level");
const hpText = document.getElementById("hp-text");
const hpBar = document.getElementById("hp-bar");
const goldElement = document.getElementById("gold");
const damageElement = document.getElementById("damage");
const weaponElement = document.getElementById("weapon");
const itemsElement = document.getElementById("items");
const inventoryMessage = document.getElementById("inventory-message");

const shopGold = document.getElementById("shop-gold");
const shopItems = document.getElementById("shop-items");
const shopMessage = document.getElementById("shop-message");

const availableQuests = document.getElementById("available-quests");
const acceptedQuestsElement = document.getElementById("accepted-quests");


// AKTUALIZOWANIE POSTACI

function updatePlayer() {
    nameElement.textContent = player.name;
    levelElement.textContent = "POZIOM " + player.level;

    hpText.textContent = player.hp + " / " + player.maxHP;

    hpBar.style.width =
        (player.hp / player.maxHP * 100) + "%";

    goldElement.textContent = player.gold;
    shopGold.textContent = player.gold;

    damageElement.textContent = player.weapon.dmg;
    weaponElement.textContent = player.weapon.name;

    renderInventory();
    renderShop();
    renderQuests();
}


// EKWIPUNEK

function renderInventory() {
    itemsElement.innerHTML = "";

    player.inventory.forEach(function(item) {
        const div = document.createElement("div");
        div.className = "item";

        const img = document.createElement("img");
        img.alt = item.name;
        img.src = item.image || "";

        img.onerror = function() {
            img.style.display = "none";
        };

        const p = document.createElement("p");
        p.textContent = item.name +
            (item.quantity > 1 ? " x" + item.quantity : "");

        div.appendChild(img);
        div.appendChild(p);

        // Bomba nie może być używana
        if (item.type !== "bomb") {
            div.addEventListener("click", function() {
                useItem(item.type);
            });
        }

        itemsElement.appendChild(div);
    });
}


// WYŚWIETLANIE SKLEPU

function renderShop() {
    shopItems.innerHTML = "";

    sklep.forEach(function(item) {
        const card = document.createElement("div");
        card.className = "shop-item";

        const image = document.createElement("img");
        image.className = "shop-item-image";
        image.src = item.image;
        image.alt = item.name;

        image.onerror = function() {
            image.style.display = "none";
        };

        const title = document.createElement("h3");
        title.textContent = item.name;

        const description = document.createElement("p");
        description.className = "description";
        description.textContent = item.description;

        const price = document.createElement("p");
        price.className = "price";
        price.textContent = "🪙 " + item.price + " złota";

        const button = document.createElement("button");
        button.className = "buy-button";

        button.textContent =
            player.gold >= item.price
                ? "KUP PRZEDMIOT"
                : "ZA MAŁO ZŁOTA";

        button.disabled = player.gold < item.price;

        button.addEventListener("click", function() {
            buyItem(item.id);
        });

        card.appendChild(image);
        card.appendChild(title);
        card.appendChild(description);
        card.appendChild(price);
        card.appendChild(button);

        shopItems.appendChild(card);
    });
}


// DODAWANIE PRZEDMIOTU DO EKWIPUNKU

function addToInventory(name, type, image = "") {
    const existingItem = player.inventory.find(function(item) {
        return item.type === type;
    });

    if (existingItem) {
        existingItem.quantity =
            (existingItem.quantity || 1) + 1;

        if (!existingItem.image && image) {
            existingItem.image = image;
        }
    } else {
        player.inventory.push({
            name: name,
            image: image,
            type: type,
            quantity: 1
        });
    }
}


// UŻYWANIE PRZEDMIOTÓW

function useItem(type) {
    const item = player.inventory.find(function(item) {
        return item.type === type;
    });

    if (!item) {
        return;
    }

    switch (type) {
        case "healing":
            if (player.hp >= player.maxHP) {
                inventoryMessage.textContent =
                    "Masz już pełne zdrowie!";
                return;
            }

            player.hp += 30;

            if (player.hp > player.maxHP) {
                player.hp = player.maxHP;
            }

            inventoryMessage.textContent =
                "Użyto mikstury leczenia! Przywrócono zdrowie.";

            break;

        case "strength":
            player.weapon.dmg += 10;

            inventoryMessage.textContent =
                "Użyto mikstury siły! Obrażenia zwiększone o 10.";

            break;

        case "sword":
            inventoryMessage.textContent =
                "Ten miecz jest już wyposażony.";

            return;

        default:
            return;
    }

    // Zmniejszenie ilości przedmiotu
    item.quantity--;

    // Usunięcie przedmiotu, jeśli ilość wynosi 0
    if (item.quantity <= 0) {
        player.inventory = player.inventory.filter(function(inventoryItem) {
            return inventoryItem !== item;
        });
    }

    updatePlayer();
}


// KUPOWANIE PRZEDMIOTÓW

function buyItem(id) {
    const item = sklep.find(function(shopItem) {
        return shopItem.id === id;
    });

    if (!item) {
        return;
    }

    if (player.gold < item.price) {
        showMessage("Nie masz wystarczająco złota!", "error");
        return;
    }

    player.gold -= item.price;

    switch (item.type) {
        case "healing":
            addToInventory(
                item.name,
                item.type,
                item.image
            );

            showMessage(
                "Kupiono miksturę leczenia! Trafiła do ekwipunku.",
                "success"
            );
            break;

        case "strength":
            addToInventory(
                item.name,
                item.type,
                item.image
            );

            showMessage(
                "Kupiono miksturę siły! Trafiła do ekwipunku.",
                "success"
            );
            break;

        case "sword":
            player.weapon.name = "Ulepszony miecz";
            player.weapon.dmg += 20;

            addToInventory(
                item.name,
                item.type,
                item.image
            );

            showMessage(
                "Kupiono lepszy miecz! Obrażenia +20.",
                "success"
            );
            break;

        case "bomb":
            addToInventory(
                item.name,
                item.type,
                item.image
            );

            showMessage(
                "Kupiono bombę! Trafiła do ekwipunku.",
                "success"
            );
            break;
    }

    updatePlayer();
}


// WYŚWIETLANIE QUESTÓW

function renderQuests() {
    availableQuests.innerHTML = "";
    acceptedQuestsElement.innerHTML = "";

    if (quests.length === 0) {
        availableQuests.innerHTML =
            '<p class="no-quests">Brak dostępnych zadań.</p>';
    }

    quests.forEach(function(quest) {
        const card = document.createElement("div");
        card.className = "quest-item";

        const title = document.createElement("h3");
        title.textContent = quest.name;

        const description = document.createElement("p");
        description.className = "description";
        description.textContent = quest.description;

        const reward = document.createElement("p");
        reward.className = "quest-reward";
        reward.textContent = "🪙 Nagroda: " + quest.reward + " złota";

        const button = document.createElement("button");
        button.className = "quest-button";
        button.textContent = "PRZYJMIJ ZADANIE";

        button.addEventListener("click", function() {
            acceptQuest(quest.id);
        });

        card.appendChild(title);
        card.appendChild(description);
        card.appendChild(reward);
        card.appendChild(button);

        availableQuests.appendChild(card);
    });

    if (acceptedQuests.length === 0) {
        acceptedQuestsElement.innerHTML =
            '<p class="no-quests">Nie masz jeszcze żadnych przyjętych zadań.</p>';
    }

    acceptedQuests.forEach(function(quest) {
        const card = document.createElement("div");
        card.className = "quest-item";

        const title = document.createElement("h3");
        title.textContent = quest.name;

        const description = document.createElement("p");
        description.className = "description";
        description.textContent = quest.description;

        const status = document.createElement("p");
        status.className = "quest-status";
        status.textContent = "ZADANIE PRZYJĘTE";

        card.appendChild(title);
        card.appendChild(description);
        card.appendChild(status);

        acceptedQuestsElement.appendChild(card);
    });
}


// PRZYJMOWANIE QUESTÓW

function acceptQuest(id) {
    const questIndex = quests.findIndex(function(quest) {
        return quest.id === id;
    });

    if (questIndex === -1) {
        return;
    }

    const quest = quests.splice(questIndex, 1)[0];

    acceptedQuests.push(quest);

    renderQuests();
}


// KOMUNIKATY

function showMessage(message, type) {
    shopMessage.textContent = message;
    shopMessage.className = "shop-message " + type;
}


// ZMIANA ZAKŁADEK

document.querySelectorAll(".tab").forEach(function(tab) {
    tab.addEventListener("click", function() {
        document.querySelectorAll(".tab").forEach(function(button) {
            button.classList.remove("active");
        });

        document.querySelectorAll(".tab-content").forEach(function(content) {
            content.hidden = true;
        });

        tab.classList.add("active");

        document.getElementById(tab.dataset.tab).hidden = false;
    });
});


// URUCHOMIENIE

updatePlayer();

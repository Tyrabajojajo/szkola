
const player = {
    name: "Geralt",
    level: 13,
    gold: 100,
    hp: 85,
    maxHP: 100,
    weapon: {
        name: "Srebrny miecz",
        dmg: 15,
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

const shopItems = [
    {
        name: "Mikstura leczenia",
        price: 15,
        description: "Przywraca 25 HP",
        type: "healing",
        image: "mikstura.jpg"
    },
    {
        name: "Wzmocnienie",
        price: 25,
        description: "Zwiększa obrażenia o 10",
        type: "strength",
        image: "anigivare.jpg"
    },
    {
        name: "Lepszy miecz",
        price: 60,
        description: "Zwiększa obrażenia o 20",
        type: "sword",
        image: "anigivare.jpg"
    },
    {
        name: "Bomba",
        price: 20,
        description: "Zadaje 25 obrażeń podczas walki",
        type: "bomb",
        image: "bomba.jpg"
    }
];

const quests = [
    {
        id: 1,
        name: "Bestia z Białego Sadu",
        description: "Pokonaj wilka terroryzującego okolicę.",
        reward: 100,
        enemy: {
            name: "Wilk",
            image: "wilk.jpg",
            hp: 100,
            damage: 18
        }
    },
    {
        id: 2,
        name: "Zaginiony kupiec",
        description: "Odnajdź kupca i pokonaj ghula.",
        reward: 75,
        enemy: {
            name: "Ghoul",
            image: "ghul.jpg",
            hp: 150,
            damage: 23
        }
    },
    {
        id: 3,
        name: "Problemy na trakcie",
        description: "Pokonaj bandytów na trakcie.",
        reward: 50,
        enemy: {
            name: "Bandyta",
            image: "bandyta.jpg",
            hp: 120,
            damage: 20
        }
    }
];

let acceptedQuests = [];
let completedQuests = [];

let currentQuest = null;
let currentEnemy = null;
let enemyHP = 0;
let attackInterval = null;
let attackPosition = 0;
let attackDirection = 1;
let battleActive = false;

const $ = id => document.getElementById(id);

// Zakładki

document.querySelectorAll(".tab").forEach(button => {
    button.addEventListener("click", () => {
        document.querySelectorAll(".tab").forEach(tab => {
            tab.classList.remove("active");
        });

        document.querySelectorAll(".tab-content").forEach(section => {
            section.hidden = true;
        });

        button.classList.add("active");
        $(button.dataset.tab).hidden = false;
    });
});

// Wyświetlanie postaci

function renderPlayer() {
    $("name").textContent = player.name;
    $("level").textContent = "Poziom " + player.level;

    $("gold").textContent = player.gold;
    $("shop-gold").textContent = player.gold;
    $("damage").textContent = player.weapon.dmg;

    $("hp-text").textContent = `${player.hp} / ${player.maxHP}`;
    $("hp-bar").style.width = `${player.hp / player.maxHP * 100}%`;

    $("weapon").innerHTML = `
        <div class="item">
            <img src="${player.weapon.image}" alt="Miecz">
            <strong>${player.weapon.name}</strong>
            <p>Obrażenia: ${player.weapon.dmg}</p>
        </div>
    `;

    renderInventory();
}

function renderInventory() {
    $("items").innerHTML = "";

    player.inventory.forEach((item, index) => {
        const element = document.createElement("div");
        element.className = "item";

        element.innerHTML = `
            <img src="${item.image}" alt="${item.name}">
            <strong>${item.name}</strong>
            <p>Ilość: ${item.quantity}</p>
        `;

        if (item.type !== "bomb") {
            element.addEventListener("click", () => useItem(index));
        }

        $("items").appendChild(element);
    });
}

function useItem(index) {
    const item = player.inventory[index];

    if (!item || item.quantity <= 0) return;

    if (item.type === "healing") {
        if (player.hp === player.maxHP) {
            $("inventory-message").textContent = "Masz pełne zdrowie!";
            return;
        }

        player.hp = Math.min(player.maxHP, player.hp + 25);
        item.quantity--;

        $("inventory-message").textContent = "Użyto mikstury leczenia!";
    }

    if (item.type === "strength") {
        player.weapon.dmg += 10;
        item.quantity--;

        $("inventory-message").textContent = "Twoja broń została wzmocniona!";
    }

    renderPlayer();
}

// Sklep

function renderShop() {
    $("shop-items").innerHTML = "";

    shopItems.forEach((item, index) => {
        const element = document.createElement("div");
        element.className = "shop-item";

        element.innerHTML = `
            <h3>${item.name}</h3>
            <p>${item.description}</p>
            <p>Cena: ${item.price} złota</p>
            <button>KUP</button>
        `;

        element.querySelector("button").addEventListener("click", () => {
            buyItem(index);
        });

        $("shop-items").appendChild(element);
    });
}

function buyItem(index) {
    const item = shopItems[index];

    if (player.gold < item.price) {
        $("shop-message").textContent = "Nie masz wystarczająco złota!";
        return;
    }

    player.gold -= item.price;

    if (item.type === "sword") {
        player.weapon.dmg += 20;
        player.weapon.name = "Ulepszony srebrny miecz";
    } else if (item.type === "strength") {
        player.inventory.push({
            name: item.name,
            image: item.image,
            type: "strength",
            quantity: 1
        });
    } else {
        const existing = player.inventory.find(i => i.type === item.type);

        if (existing) {
            existing.quantity++;
        } else {
            player.inventory.push({
                name: item.name,
                image: item.image,
                type: item.type,
                quantity: 1
            });
        }
    }

    $("shop-message").textContent = `Kupiono: ${item.name}`;

    renderPlayer();
}

// Questy

function renderQuests() {
    $("available-quests").innerHTML = "";
    $("accepted-quests").innerHTML = "";
    $("completed-quests").innerHTML = "";

    quests.forEach(quest => {
        const isAccepted = acceptedQuests.includes(quest.id);
        const isCompleted = completedQuests.includes(quest.id);

        if (isAccepted || isCompleted) return;

        const element = document.createElement("div");
        element.className = "quest-item";

        element.innerHTML = `
            <h3>${quest.name}</h3>
            <p>${quest.description}</p>
            <p>Nagroda: ${quest.reward} złota</p>
            <button>PRZYJMIJ</button>
        `;

        element.querySelector("button").addEventListener("click", () => {
            acceptQuest(quest.id);
        });

        $("available-quests").appendChild(element);
    });

    acceptedQuests.forEach(id => {
        const quest = quests.find(q => q.id === id);

        const element = document.createElement("div");
        element.className = "quest-item";

        element.innerHTML = `
            <h3>${quest.name}</h3>
            <p>${quest.description}</p>
            <button>ROZPOCZNIJ</button>
        `;

        element.querySelector("button").addEventListener("click", () => {
            startBattle(id);
        });

        $("accepted-quests").appendChild(element);
    });

    completedQuests.forEach(id => {
        const quest = quests.find(q => q.id === id);

        const element = document.createElement("div");
        element.className = "quest-item";

        element.innerHTML = `
            <h3>${quest.name}</h3>
            <p>Ukończono!</p>
        `;

        $("completed-quests").appendChild(element);
    });
}

function acceptQuest(id) {
    acceptedQuests.push(id);
    renderQuests();
}

// Walka

function startBattle(id) {
    currentQuest = quests.find(q => q.id === id);
    currentEnemy = currentQuest.enemy;
    enemyHP = currentEnemy.hp;
    battleActive = true;

    document.querySelectorAll(".tab-content").forEach(section => {
        section.hidden = true;
    });

    document.querySelector(".tabs").hidden = true;
    $("battle").hidden = false;

    $("battle-quest-name").textContent = currentQuest.name;

    $("enemy-icon").innerHTML = `
        <img src="${currentEnemy.image}" alt="${currentEnemy.name}">
    `;

    $("enemy-name").textContent = currentEnemy.name;

    $("battle-log").textContent = "Rozpoczyna się walka!";

    $("attack-panel").hidden = true;
    $("item-panel").hidden = true;
    $("battle-result").hidden = true;

    $("fight-button").hidden = false;
    $("item-button").hidden = false;
    $("escape-button").hidden = false;

    $("battle-player-hp").textContent = `${player.hp} / ${player.maxHP}`;
    $("battle-player-hp-bar").style.width = `${player.hp / player.maxHP * 100}%`;

    updateEnemyHP();
}

// Pasek zdrowia przeciwnika

function updateEnemyHP() {
    $("enemy-hp-text").textContent = `${enemyHP} / ${currentEnemy.hp}`;
    $("enemy-hp-bar").style.width = `${Math.max(0, enemyHP / currentEnemy.hp * 100)}%`;
}

// Atak Geralta

function startAttack() {
    if (!battleActive) return;

    $("attack-panel").hidden = false;
    $("item-panel").hidden = true;

    $("fight-button").hidden = true;
    $("item-button").hidden = true;
    $("escape-button").hidden = true;

    attackPosition = 0;
    attackDirection = 1;

    clearInterval(attackInterval);

    attackInterval = setInterval(() => {
        attackPosition += attackDirection * 2.5;

        if (attackPosition >= 100 || attackPosition <= 0) {
            attackDirection *= -1;
        }

        $("attack-marker").style.left = attackPosition + "%";
    }, 20);
}

$("attack-confirm").addEventListener("click", () => {
    if (!battleActive) return;

    clearInterval(attackInterval);

    const accuracy = Math.abs(attackPosition - 50);

    let multiplier;

    if (accuracy < 8) {
        multiplier = 2;
    } else if (accuracy < 25) {
        multiplier = 1.5;
    } else if (accuracy < 55) {
        multiplier = 1;
    } else {
        multiplier = 0.5;
    }

    const damage = Math.floor(player.weapon.dmg * multiplier);

    enemyHP = Math.max(0, enemyHP - damage);

    $("attack-panel").hidden = true;

    $("battle-log").textContent = `Geralt zadaje ${damage} obrażeń!`;

    updateEnemyHP();

    if (enemyHP <= 0) {
        winBattle();
        return;
    }

    enemyTurn();
});

// Tura przeciwnika

function enemyTurn() {
    if (!battleActive) return;

    const damage = Math.floor(Math.random() * 7) + currentEnemy.damage;

    player.hp = Math.max(0, player.hp - damage);

    $("battle-player-hp").textContent = `${player.hp} / ${player.maxHP}`;
    $("battle-player-hp-bar").style.width = `${player.hp / player.maxHP * 100}%`;

    $("battle-log").textContent += ` ${currentEnemy.name} zadaje ${damage} obrażeń!`;

    if (player.hp <= 0) {
        loseBattle();
        return;
    }

    $("fight-button").hidden = false;
    $("item-button").hidden = false;
    $("escape-button").hidden = false;
}

// Przedmioty w walce

$("item-button").addEventListener("click", () => {
    if (!battleActive) return;

    $("item-panel").hidden = false;
    $("attack-panel").hidden = true;

    $("fight-button").hidden = true;
    $("item-button").hidden = true;
    $("escape-button").hidden = true;

    renderBattleItems();
});

function renderBattleItems() {
    $("battle-items").innerHTML = "";

    player.inventory.forEach((item, index) => {
        if (item.quantity <= 0) return;

        const element = document.createElement("div");
        element.className = "battle-item";

        let description = "";

        if (item.type === "healing") {
            description = "Przywraca 25 HP";
        } else if (item.type === "strength") {
            description = "Zwiększa obrażenia o 10";
        } else if (item.type === "bomb") {
            description = "Zadaje 25 obrażeń";
        }

        element.innerHTML = `
            <img src="${item.image}" alt="${item.name}">
            <div class="battle-item-info">
                <strong>${item.name}</strong>
                <p>${description}</p>
                <small>Ilość: ${item.quantity}</small>
            </div>
        `;

        element.addEventListener("click", () => {
            useBattleItem(index);
        });

        $("battle-items").appendChild(element);
    });

    if ($("battle-items").innerHTML === "") {
        $("battle-items").textContent = "Nie masz żadnych przedmiotów!";
    }
}

function useBattleItem(index) {
    if (!battleActive) return;

    const item = player.inventory[index];

    if (!item || item.quantity <= 0) return;

    if (item.type === "healing") {
        if (player.hp === player.maxHP) {
            $("battle-log").textContent = "Masz pełne zdrowie!";
            return;
        }

        player.hp = Math.min(player.maxHP, player.hp + 25);
        item.quantity--;

        $("battle-log").textContent = "Geralt używa mikstury leczenia!";
    } else if (item.type === "strength") {
        player.weapon.dmg += 10;
        item.quantity--;

        $("battle-log").textContent = "Geralt wzmacnia swoją broń!";
    } else if (item.type === "bomb") {
        enemyHP = Math.max(0, enemyHP - 25);
        item.quantity--;

        $("battle-log").textContent = "Geralt rzuca bombę! Przeciwnik otrzymuje 25 obrażeń!";

        updateEnemyHP();

        if (enemyHP <= 0) {
            $("item-panel").hidden = true;
            winBattle();
            return;
        }
    }

    $("item-panel").hidden = true;

    $("battle-player-hp").textContent = `${player.hp} / ${player.maxHP}`;
    $("battle-player-hp-bar").style.width = `${player.hp / player.maxHP * 100}%`;

    renderPlayer();
    enemyTurn();
}

$("close-items").addEventListener("click", () => {
    $("item-panel").hidden = true;

    $("fight-button").hidden = false;
    $("item-button").hidden = false;
    $("escape-button").hidden = false;
});

// Ucieczka

$("escape-button").addEventListener("click", () => {
    if (!battleActive) return;

    endBattle();

    $("battle-result").hidden = false;
    $("result-title").textContent = "Uciekłeś!";
    $("result-description").textContent = "Zadanie nadal czeka na ukończenie.";
});

// Zwycięstwo

function winBattle() {
    endBattle();

    player.gold += currentQuest.reward;

    acceptedQuests = acceptedQuests.filter(id => id !== currentQuest.id);
    completedQuests.push(currentQuest.id);

    $("battle-result").hidden = false;
    $("result-title").textContent = "Zwycięstwo!";
    $("result-description").textContent =
        `Pokonałeś przeciwnika i otrzymujesz ${currentQuest.reward} złota!`;

    renderPlayer();
}

// Porażka

function loseBattle() {
    endBattle();

    $("battle-result").hidden = false;
    $("result-title").textContent = "Porażka!";
    $("result-description").textContent =
        "Geralt został pokonany. Po powrocie odzyskasz część zdrowia.";

    player.hp = 30;
}

// Zakończenie walki

function endBattle() {
    battleActive = false;

    clearInterval(attackInterval);

    $("attack-panel").hidden = true;
    $("item-panel").hidden = true;

    $("fight-button").hidden = true;
    $("item-button").hidden = true;
    $("escape-button").hidden = true;

    $("battle-result").hidden = false;
}

// Powrót do questów

$("return-button").addEventListener("click", () => {
    $("battle").hidden = true;
    $("battle-result").hidden = true;

    document.querySelector(".tabs").hidden = false;

    document.querySelectorAll(".tab-content").forEach(section => {
        section.hidden = true;
    });

    $("questy").hidden = false;

    document.querySelectorAll(".tab").forEach(tab => {
        tab.classList.remove("active");
    });

    document.querySelector('[data-tab="questy"]').classList.add("active");

    renderPlayer();
    renderQuests();
});

// Przyciski walki

$("fight-button").addEventListener("click", startAttack);

// Uruchomienie strony

renderPlayer();
renderShop();
renderQuests();

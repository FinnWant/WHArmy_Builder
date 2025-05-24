# ⚔️ WHArmy Builder 🔧

### Your Digital Forge World for the 41st Millennium

> "Knowledge is power. Guard it well." – *Adeptus Mechanicus proverb*

Welcome, honored Tech-Adept. You've uncovered the WHArmy Builder – a sacred script compiled for the glory of the Emperor (and for organizing your glorious tabletop campaigns).

This project is a Qt-based desktop application for crafting, editing, and managing custom Warhammer 40,000 armies. Whether you're a seasoned Chapter Master or a newly-forged Skitarii, this builder equips you to bring order to the chaos of army creation.

## 🛠 Features

### 🛡 Unit Creation

Summon units from the warp! Create new unit profiles with full customization:

* Name and Faction (Chaos, Imperium, Xenos, etc.)
* Movement, Wounds, Save, Bravery, and more
* Manage your forces with the precision of a Forge World artisan

### 📦 JSON Import/Export

* Save your army rosters as `.json` files – perfect for sharing with your fellow Commanders or backing up your crusades
* Load existing rosters in seconds
* Future-proof your campaigns with easy serialization

### 🖥 Modern UI (Work in Progress)

* Built using the holy relic known as **Qt**
* Clean, focused interface designed to minimize cognitive load so you can concentrate on *total annihilation*

### ⚔️ Cross-Platform Compatibility (Work in Progress)

* Whether you run Linux (like a stoic Iron Hand), Windows (like a loyal Guardsman), or macOS (like a fancy-pants Eldar), WHArmy Builder is being forged for your warzone

## 🚧 Development Status

The application is in active development. Here’s what’s been fully consecrated and what still requires the Machine Spirit’s blessing:

| Feature                         | Status         |
| ------------------------------- | -------------- |
| Unit creation and editing       | ✅ Complete    |
| JSON import/export              | ✅ Complete    |
| GUI polish and UX refinement    | ⚙️ In Progress |
| Cross-platform builds           | ⚙️ In Progress |
| Army validation rules           | ⏳ Planned      |
| Drag-and-drop unit organization | ⏳ Planned      |
| Save/load multiple armies       | ⏳ Planned      |

## 📁 Repository Structure

```
WHArmy_Builder/
├── assets/          # Icons and UI assets
├── backend/             # Main source code (C++ & Qt)
├── resources/            # Example JSON army lists
├── tests/           # Unit tests (forthcoming)
└── README.md        # You are here, inquisitor
```

## ⚙️ Tech Stack

* **C++** – For maximum purity and performance
* **Qt 6** – Blessed UI framework
* **JSON** – For storage and interoperability

## 🧠 Why Use WHArmy Builder?

* Custom army creation for your homebrew lore
* Save time managing rosters so you can focus on dice rolling and purging heretics
* Built by hobbyists, for hobbyists – this is a project of passion, not profit

## ✨ Future Plans

* GUI overhaul with QML
* Army point cost validation
* Theme customization (dark mode, faction-based skins)
* Web or mobile sync options (Machine Spirit willing)

## 📜 How to Build

1. Clone the repository:

```bash
git clone https://github.com/FinnWant/WHArmy_Builder.git
```

2. Open the project in Qt Creator or build via CMake:

```bash
cd WHArmy_Builder
mkdir build && cd build
cmake ..
make
```

3. Deploy to your OS of choice and begin crusading

## 🤝 Contributing

Pull requests from fellow Tech-Priests are welcome. Open an issue, fork the repository, and sanctify your additions with clarity and precision.

## 📢 Contact

For inquiries or to report a rogue servitor, open an issue on the [GitHub repository](https://github.com/FinnWant/WHArmy_Builder/issues).

## 👑 Ave Imperator

May your units be balanced, your JSONs be well-formed, and your tabletop victories glorious.

> "Even a single cog in the machine has its place. Do not disregard what appears insignificant." – *Omnissiah's Commentary on Unit Loadouts*


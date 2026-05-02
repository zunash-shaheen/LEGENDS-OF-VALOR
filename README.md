#  Legends of Valor: My C++ RPG Project

Welcome to **Legends of Valor**! This is a console-based RPG I built using C++ to push my Object-Oriented Programming skills to the limit. It’s got everything from turn-based combat to a full save/load system, all running right in your terminal.

##  The Story & Gameplay
In this game, you don't just play a generic hero. I've integrated characters and worlds inspired by some of my favorite series (like Jujutsu Kaisen and Demon Slayer). You can choose to play as **Gojo, Tanjiro, Zenitsu, or Yuta**.

Each character has their own stats, and you’ll need to explore different "worlds"—starting from a Wild Forest all the way to Gojo’s "Infinite Void." Along the way, you'll encounter enemies, find loot, and try to survive long enough to beat the final bosses.

##  How I Built It (The Technical Stuff)
Since this was a project for my OOP course at FAST-NUCES, I made sure to include all the core concepts:

* **Inheritance & Polymorphism:** I used a base `Player` class and branched out into specific characters. This allowed me to use virtual functions so that every character reacts differently in a fight.
* **Encapsulation:** All the important data is tucked away safely. I used `const` accessors to make sure the UI can read stats without accidentally breaking the game logic.
* **Static Members:** I added a `playerCount` tracker just to keep tabs on how many hero instances are floating around.
* **Memory Management:** C++ can be tricky with memory, so I implemented **Copy Constructors** to handle deep copies of the inventory—preventing the game from crashing when data is duplicated.
* **File Handling:** Your progress isn't lost! I wrote logic to save your stats and items into `haiqa.txt` so you can pick up where you left off.

##  What’s Inside?
* `Classes.h`: The "brain" of the project where all the hierarchies are defined.
* `gameManager.cpp`: This is the engine. It handles the stages, the battles, and the save system.
* `inventory.cpp` & `helpingObject.cpp`: How I managed items and weapons.
* `enemy.cpp`: Where I defined the different types of AI you'll face.
* `main.cpp`: The starting point that kicks everything off.

##  Running the Game
If you want to try it out, you'll need a C++ compiler. Just run these commands:

1. **Compile everything:**
   `g++ main.cpp gameManager.cpp enemy.cpp inventory.cpp manageStats.cpp helpingObject.cpp -o LegendsOfValor`

2. **Start the adventure:**
   `./LegendsOfValor`

---
*Developed as a Semester Final Project for the Object-Oriented Programming Course.*

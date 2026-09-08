# Pokemon Battle Simulator

A C++ object-oriented battle simulator in which two trainers build teams of Pokémon and compete until one trainer has no remaining Pokémon able to battle.

## Overview

The program simulates turn-based Pokémon battles using object-oriented programming principles. Each Pokémon has a name, type, health points, ID, and a collection of attacks. Trainers can create teams, select Pokémon for battle, view team statistics, and save or load team data from text files.

The simulator includes Fire, Grass, and Water Pokémon types implemented through inheritance. Attack damage is adjusted dynamically according to type advantages and disadvantages. During battle, trainers select available Pokémon and attacks until one team is defeated.

## Key Features

- Turn-based battles between two trainers
- Pokémon teams containing up to six members
- Fire, Grass, and Water derived classes
- Type-based attack advantages and disadvantages
- Dynamic health and attack damage updates
- Trainer badge and victory tracking
- Pokémon selection and team management
- File-based team saving and loading
- Personal Pokémon statistics and attack information
- Automatic detection of defeated Pokémon and trainers

## Object-Oriented Concepts

- Base and derived classes
- Inheritance
- Runtime polymorphism through virtual functions
- Encapsulation using private and protected data
- Dynamic memory allocation
- Copy constructors
- Copy assignment operators
- Destructors
- Vectors of object pointers

## Project Structure

- `main.cpp` — Creates trainers, Pokémon, attacks, and battles
- `pokemon.h` / `pokemon.cpp` — Base Pokémon class
- `firetype.h` / `firetype.cpp` — Fire-type implementation
- `grasstype.h` / `grasstype.cpp` — Grass-type implementation
- `watertype.h` / `watertype.cpp` — Water-type implementation
- `trainer.h` / `trainer.cpp` — Trainer team management
- `battle.h` / `battle.cpp` — Battle sequence and winner determination
- `team1.txt`, `team2.txt`, `team3.txt` — Example saved teams

## Battle Logic

1. Each trainer selects an available Pokémon.
2. The program updates attack damage based on the opposing Pokémon's type.
3. Trainers choose attacks during each turn.
4. Attack damage is subtracted from the opponent's HP.
5. When a Pokémon reaches zero HP, the trainer selects another available Pokémon.
6. The battle ends when one trainer has no Pokémon remaining with positive HP.
7. The winning trainer receives an additional badge.

## Technologies

### Language

- C++

### Concepts and Libraries

- Object-oriented programming
- Standard Template Library
- `std::vector`
- File input and output
- Dynamic memory management

## My Contributions

- Designed and implemented the Pokémon class hierarchy.
- Implemented type-specific damage adjustment through virtual functions.
- Developed trainer team-management functionality.
- Implemented battle flow, Pokémon selection, and winner detection.
- Added file-based saving and loading of trainer teams.
- Applied copy constructors, assignment operators, and destructors for dynamically allocated data.

## Documentation

- [Final Project Report](https://uofh-my.sharepoint.com/:v:/r/personal/vdeoliv2_cougarnet_uh_edu/Documents/Recordings/Screen%20Recording%20Demo-20250429_095717-Meeting%20Recording.mp4?csf=1&web=1&nav=eyJyZWZlcnJhbEluZm8iOnsicmVmZXJyYWxBcHAiOiJPbmVEcml2ZUZvckJ1c2luZXNzIiwicmVmZXJyYWxBcHBQbGF0Zm9ybSI6IldlYiIsInJlZmVycmFsTW9kZSI6InZpZXciLCJyZWZlcnJhbFZpZXciOiJNeUZpbGVzTGlua0NvcHkifX0&e=iHTGSS)

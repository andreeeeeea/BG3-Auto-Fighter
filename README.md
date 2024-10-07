# Baldur's Gate 3 Combat Automation Bot

## Introduction

This project was developed as my final year university project. The aim was to create a bot capable of automating the combat gameplay in *Baldur's Gate 3*. The provided GitHub files contain the framework for the bot, along with a simple demo implementation.

## Features

- **Memory Reading:** Access game character data directly from the game's memory.
- **Control Simulation:** Simulate keyboard and mouse movements to automate gameplay actions.
- **Entity Management:** Manage and interact with player and enemy characters.
- **Game State Monitoring:** Continuously check the state of the game to make decisions.

## Required Game Version

**This bot is designed to work with an outdated version of *Baldur's Gate 3*, specifically the version prior to patch #4.** Ensure you are using this version for optimal functionality.

## Files Overview

The project contains the following main files:

- **Autoplayer.cpp:** This file retrieves character data from the game's memory and includes the implementation of the demo bot.

- **Controller.cpp:** Responsible for simulating game controls, including mouse and keyboard movements.

- **Enemies.cpp:** Defines the `Enemies` class, containing properties such as health, coordinates, and methods for accessing enemy information.

- **Players.cpp:** Defines the `Players` class, containing properties such as health, resources, coordinates, and methods for accessing player information.

- **GameChecker.cpp:** Checks various states of the game, such as:
  - If the input character is downed.
  - If the input character's health is low.
  - If the input enemy is close to the input character.
  - Getting the distance between two characters.

- **dllmain.cpp:** The main entry point for the DLL application, which opens a console terminal to display the game's base address, process ID, and utilizes the other files to function.

## Usage

1. **Clone the Repository:**

   ```bash
   git clone https://github.com/andreeeeeea/BG3-Auto-Fighter.git
2. **Build the Project:**

Make sure you have a C++ development environment set up. Compile the code using your preferred IDE or build system.

3. **Inject the DLL:**

The bot is designed to be injected into the Baldur's Gate 3 process using NativeModLoader. Please follow the installation instructions provided on the NativeModLoader GitHub page to set it up.

4. **Control the Bot:**

Use F6 to retrieve and display player and enemy stats.
Use F7 to move the camera to the closest enemy's coordinates.

## Requirements
- Windows operating system
- Baldur's Gate 3 (version prior to patch #4)
- A C++ compiler (e.g., Visual Studio)

## Notes
1. Please be aware that the demo bot is not 100% accurate or flawless. It serves as a foundational framework for building a more sophisticated bot. Users are encouraged to modify and improve upon the demo to achieve better performance and reliability in combat automation.
2. As this was developed using an outdated version of the game, the memory extraction may or may not (most likely may not) work. I have yet to update this in order to support the newest version of the game.

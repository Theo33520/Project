
# ⚠️ **Attention**: This project must be run on a Linux environment.

# Project

## Arcade Project

**Description**:

**Arcade is a gaming platform that allows users to select and play games while keeping track of player scores.**

**To manage the elements of your gaming platform at runtime, both the graphics libraries and the games must be implemented as dynamic libraries, loaded during execution. Each available GUI for the program should also be implemented as a shared library, which will be loaded and utilized dynamically by the main program.**

## 🛠️ How to Run It?

🖥️ `make fclean && make`

🔷 `./arcade ./lib/arcade_sfml.so`

🔷 `./arcade ./lib/arcade_sdl2.so`

🔷 `./arcade ./lib/arcade_ncurses.so`


## Lem-in Project

**Description**:

Lem-in is a project that simulates the journey of an ant colony. The objective is to find the optimal path for all the ants to move from their starting point (the start room) to their final destination (the end room) within a network of interconnected rooms and tunnels. The goal is to minimize the number of moves required to achieve this.

Key Features:
Input Parsing: The program reads a description of the ant colony, which includes:

The number of ants.
A list of rooms with their coordinates.
A list of tunnels that connect the rooms.
Pathfinding: The program calculates the shortest path or paths that allow the ants to travel from the start room to the end room.

Collision Management: The program must handle the fact that ants cannot pass each other in the tunnels, adding complexity to the movement management.

Movement Display: After calculating the optimal paths, the program sequentially displays the movements of the ants, showing how each ant progresses from the start room to the end room.

## 🛠️ How to Run It?

🖥️ `make fclean && make`

🔷 `./lem_in < map/input`

🔷 `./lem_in < map/new_anthill`



## Login Template


Login Form:

Input Fields:

    ● Username or Email: A text field where users enter their username or email address.
    
    ● Password: A text field for entering the password, often accompanied by an eye icon to toggle visibility for ease of entry.
    
    ● Login Button: A clickable button to submit the login information.
    
    ● Remember Me Option: A checkbox that allows users to stay logged in for a certain period.
    
    ● Forgot Password Link: A link that directs users to a page where they can recover or reset their forgotten password.

##Build 

Dependencies: 

`npm -y init in the file backend/`
`npm install react-router-dom`


## 🛠️ How to Run It?

🖥️ `cd backend/ -> 🔷 node server.js`

🖥️ `cd frontend/ -> 🔷 npm start`


# RPG Development Project Overview 🌄

## 🎯 Objective
Create a complete RPG game that showcases the skills you and your team have acquired throughout the year. This project is designed to challenge your ability to integrate and apply your knowledge in game development.

## 📜 Requirements

### ⚔️ Combat System
- **Implement a combat system** where player statistics influence the outcome of battles against enemies.

### 🧑‍🤝‍🧑 Non-Playable Characters (NPCs)
- **Include NPCs** within the game world for player interaction.

### 🗺️ Quest Implementation
- **Develop and integrate at least one quest** that players can undertake.

### 🎒 Inventory Management
- **Create an inventory system** with a limited number of item slots for the player.

### 📈 Experience and Leveling Up
- **Allow players to earn experience points** through combat and quest completion. Accumulating enough experience should enable players to level up and enhance their attributes.

## 🚫 Constraints
- You are **restricted from using certain functions**, including `printf`. You'll need to find alternative methods to display information and debug your game.

---

## 🛠️ How to Run It?

🖥️ `make fclean && make`

🔷 `./rpg`


# 🍪 Cookie Clicker Game Overview

## 🎮 Gameplay Introduction

**Click on the Big Cookie:**

The primary action in the game involves clicking on a large cookie displayed on the screen. Each click generates a certain number of cookies. 🍪

**Accumulating Cookies:**

By clicking on the cookie, you accumulate cookies, which serve as the main currency in the game. 💰

## 🌟 Key Features

- **🍪 Cookie Production:** Clicking on the big cookie produces cookies, allowing you to build up your cookie count.
- **🔧 Upgrades:** Use the cookies you collect to purchase upgrades and other items to enhance your gameplay.



## 🛠️ How to Run It?

- Load page html
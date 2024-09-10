
# ⚠️ **Attention**: This project must be run on a Linux environment.

# Project

## Arcade Project

**Description**:

**Arcade is a gaming platform that allows users to select and play games while keeping track of player scores.**

**To manage the elements of your gaming platform at runtime, both the graphics libraries and the games must be implemented as dynamic libraries, loaded during execution. Each available GUI for the program should also be implemented as a shared library, which will be loaded and utilized dynamically by the main program.**

## How to run it?

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

## How to run it?

🖥️ `make fclean && make`

🔷 `./lem_in < map/input`

🔷 `./lem_in < map/new_anthill`


# So Long @ 42KualaLumpur

This project is a very small 2D game. Its purpose is to make you work with textures, sprites, and some other very basic gameplay elements.

![Screen Recording 2022-11-08 at 1 51 31 PM](https://user-images.githubusercontent.com/32697686/200486320-35c01381-561b-4b87-9bcf-46eab28490c8.gif)

## About
The purpose of this project is to help you improve your skills in the following areas: window management, event handling, colors, textures, and so forth.
We are only allowed to use the school graphical library: the MiniLibX! This library was developed internally and includes basic necessary tools to open a window, create images and deal with keyboard and mouse events.\
I've created a 2 player version for this game which consist of only 1 Player & 0 or more enemy, Player must collect all the coins before it can exit the game and win.

## Installation & Usage

### Requirements
The only requirements are:
- GNU make (v3.81)
- GCC (v4.2.1)
- [MiniLibX](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html)

### Building the program

1. Download/Clone this repo

        git clone https://github.com/jasonkwm/so_long.git so_long
2. `cd` into the root directory and run `make`

        cd so_long
        make

### Running the program

After building the source, run `./so_long ./maps/bonus3.ber` from the project root. The maps can be changed. You can even create your own maps!

#### Mandatory:
- You **must** use the **MiniLibX**. Either the version available on the school machines,
or installing it using its sources.
- Your program has to take as parameter a map description file ending with the **.ber**
extension.
- **Game:**
  - The player’s goal is to collect every collectible present on the map, then escape chosing the shortest possible route.
  - The **W**, **A**, **S**, and **D** keys must be used to move the main character.
  - The player should be able to move in these **4 directions**: up, down, left, right.
  - The player should not be able to move into walls.
  - At every move, the current **number of movements** must be displayed in the shell.
  - You have to use a **2D view** (top-down or profile).
  - The game doesn’t have to be real time.
- **Grapihc Management:**
  - Your program has to display the image in a window.
  - The management of your window must remain smooth (changing to another window, minimizing, and so forth).
  - Pressing **ESC** must close the window and quit the program in a clean way.
  - Clicking on the cross on the window’s frame must close the window and quit the program in a clean way.
  - The use of the **images** of the **MiniLibX** is mandatory.
- **Map:**
  - The map has to be constructed with 3 components: **walls**, **collectibles**, and **free space**.
  - The map can be composed of only these 5 characters:\
    **0** for an empty space,\
    **1** for a wall,\
    **C** for a collectible,\
    **E** for a map exit,\
    **P** for the player’s starting position.\
  - Example of a valid map:\
    <img width="170" alt="Screenshot 2022-11-08 at 3 17 48 PM" src="https://user-images.githubusercontent.com/32697686/200499364-9618e627-6e7d-4f13-a348-733a9f5e947e.png"><img width="300" alt="Screenshot 2022-11-08 at 3 21 28 PM" src="https://user-images.githubusercontent.com/32697686/200499880-51b3bcea-3e62-452b-a3e7-071eef9f6405.png">
  - The map must contain at least 1 **exit**, 1 **collectible**, and 1 **starting position**.
  - The map must be rectangular.
  - The map must be closed/surrounded by walls. If it’s not, the program must return an *error*.
  - You must be able to parse any kind of map, as long as it respects the above rules.
  - If any misconfiguration of any kind is encountered in the file, the program must exit in a clean way, and return `"Error\n"` followed by an explicit error message of your choice.

#### Bonus:
- You will get extra points if you:
  - Make the player lose when they touch an enemy patrol.
  - Add some sprite animation.
  - Display the movement count directly on screen instead of writing it in the shell.



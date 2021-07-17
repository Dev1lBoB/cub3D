# cub3D
A simple raycasting game

The constraints are as follows:
- Display different wall textures (the choice is yours) that vary depending on whichside the wall is facing (North, South, East, West).
- Your program must be able to display an item (sprite) instead of a wall.
- Your program must be able to set the floor and ceilling colors to two different ones.
- In case theDeepthoughthas eyes one day to evaluate your project, your programmust save the first rendered image inbmpformat when its second argument is "––save".
- If no second argument is supllied, the program displays the image in a window andrespects the following rules:
  - The left and right arrow keys of the keyboard must allow you to look left andright in the maze.
  - The W, A, S and D keys must allow you to move the point of view throughthe maze.
  - PressingESCmust close the window and quit the program cleanly.
  - Clicking on the red cross on the window’s frame must close the window andquit the program cleanly.
- Your program must take as a first argument a scene description file with the.cubextension.
  - The map must be composed of only 12 possible characters: '0' for an emptyspace, '1' for a wall, 'G' for a secret door, '2' for an item, 'H' for a first aid kit, 'A' for an ammo, 'U' for an enemy unit, 'T' for the trap and 'N', 'S', 'E' or 'W' for the player’s startposition and spawning orientation.
  - The map must be closed/surrounded by walls, if not the program must returnan error.
  - Except for the map content, each type of element can be separated by one ormore empty line(s).
  - Except for the map content which always has to be the last, each type of element can be set in any order in the file.
  - Except for the map, each type of information from an element can be separatedby one or more space(s).
  - The map must be parsed as it looks like in the file. Spaces are a valid part ofthe map, and is up to you to handle. You must be able to parse any kind ofmap, as long as it respects the maps rules.
  - Each element (except the map) firsts information is the type identifier (com-posed by one or two character(s)), followed by all specific informations for eachobject in a strict order.
    - Resolution:
      - identifier: R
      - x render size
      - y render size
    - North texture:
      - identifier: NO
      - path to the north texure
    - South texture:
      - identifier: SO
      - path to the south texure
    - West texture:
      - identifier: WE
      - path to the west texure
    - East texture:
      - identifier: EA
      - path to the east texure
    - Sprite texture:
      - identifier: S
      - path to the sprite texure 
    - Floor color:
      - identifier: F
      - R,G,B colors in range [0,255]:0, 255, 255
    - Ceilling color:
      - identifier: C
      - R,G,B colors in range [0,255]:0, 255, 255

I also added some bonus parts to the map such as:
- Next level:
  - identifier: NT
  - path to the next "*.cub" file
- Floor texture:
  - identifier: FL
  - path to the floor texture
- Ceilling texture:
  - identifier: CL
  - path to ceilling texture
- Enemy texture:
  - identifier: EN
  - path to the enemy texture
- Background music:
  - identifier: MC
  - path to the audio file

The format of all textures must be ".xpm".

The name of the "Enemy texture" must end with '1' and there also should be 2 more files with the same name ended with '2' and '3' respectively.

The field "Next level" could be either the next "*.cub" file or "none" if this map is the last level.

The map must be surrounded by walls ('1').

Example of the valid map:

<img width="413" alt="Screen Shot 2021-07-17 at 12 10 32 PM" src="https://user-images.githubusercontent.com/74947297/126032240-68fd5169-05ad-4b24-97b2-8a236b3cfb9b.png">

The goal of every level is to kill all the enemies. You have 3 lives and general HP and Ammo for the whole game. After completion of every lvl the enemies damage is getting increased by 2. There are some secret doors in every lvl, hiding some useful things like ammo. To open secret door you need to stand close to it and press 'E' on the keyboard. If you want to get back control of cursor just press 'P'. Press 'P' again to return control of the game. At the end of the game you recieve your final score in the terminal.

In the following screenshot there are 3 enemies, 1 of which is sees player and is trying to attack him right now:

<img width="1024" alt="Screen Shot 2021-07-17 at 12 28 16 PM" src="https://user-images.githubusercontent.com/74947297/126032736-11d579da-be32-442e-92f1-b6a7bfec6157.png">

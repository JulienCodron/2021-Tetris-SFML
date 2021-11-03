#pragma once

#define SCREEN_WIDTH 590
#define SCREEN_HEIGHT 960
#define MAIN_MENU_BACKGROUND_FP "Ressources/Main_Menu/background.jpg"
#define MAIN_MENU_TITLE_FP "Ressources/L.png"
#define CUBE "Ressources/Block.png"
#define GAMEOVER "Ressources/GameOver.png"

#define MEMORY_ALLOCATED 100000
#define PLAYGROUND_WIDTH_POSTION 17
#define PLAYGROUND_HEIGHT_POSTION 94
#define BLOCK_SIZE 40

#define COLOR_RED 231, 76, 60 
#define COLOR_YELLOW 241, 196, 15
#define COLOR_DARK_GREEN 17, 122, 101 
#define COLOR_ORANGE 230, 126, 34 
#define COLOR_PURPLE 142, 68, 173  
#define COLOR_GREEN  88, 214, 141  
#define COLOR_BLUE 46, 64, 83  

enum class StateEnum{MainMenu, Game, PauseMenu, GameOverMenu};
enum class TetrominoEnum { S1, S2, T, R, L1, L2, I };

#pragma once

#define SCREEN_WIDTH 590
#define SCREEN_HEIGHT 960
#define MAIN_MENU_BACKGROUND_FP "Ressources/Main_Menu/Grille.png"
#define MAIN_MENU_TITLE_FP "Ressources/Main_Menu/Titre.png"
#define MAIN_MENU_INFO_FP "Ressources/Main_Menu/MainMenuInfo.png"

#define PAUSE "Ressources/Game/pause.png"
#define CONTINUE "Ressources/Game/continue.png"
#define RESTART "Ressources/Game/restart.png"
#define QUIT "Ressources/Game/close.png"
#define GAME_BACKGROUND_FP "Ressources/Game/background.jpg"
#define CUBE "Ressources/Game/Block.png"
#define LITLE_CUBE "Ressources/Game/LitleBlock.png"
#define GAMEOVER "Ressources/Game/gameover.png"
#define FONT "Ressources/Font/telelower.ttf"

#define MEMORY_ALLOCATED 100000
#define PLAYGROUND_WIDTH_POSTION 17
#define PLAYGROUND_HEIGHT_POSTION 94
#define SIDE_TETROMINO_WIDTH_POSTION 461
#define HOLDED_TETROMINO_HEIGHT_POSTION 130
#define SECONDE_TETROMINO_HEIGHT_POSTION 300
#define THIRD_TETROMINO_HEIGHT_POSTION	400
#define FOURTH_TETROMINO_HEIGHT_POSTION	500
#define LINELEFT_INF_WIDTH_POSTION 445
#define LINELEFT_SUP_WIDTH_POSTION 435
#define LINELEFT_HEIGHT_POSTION 715
#define LVL_INF_WIDTH_POSTION 483
#define LVL_SUP_WIDTH_POSTION 463
#define LVL_HEIGHT_POSTION 855
#define SCORE_WIDTH_POSTION 330
#define SCORE_HEIGHT_POSTION 911
#define BEST_SCORE_WIDTH_POSTION 110
#define BEST_SCORE_HEIGHT_POSTION 911
#define ADVANCED_BAR_WIDTH_POSTION 480
#define ADVANCED_BAR_HEIGHT_POSTION 724


#define BLOCK_SIZE 40
#define LITLE_BLOCK_SIZE 30

#define COLOR_RED 231, 76, 60 
#define COLOR_YELLOW 241, 196, 15
#define COLOR_DARK_GREEN 17, 122, 101 
#define COLOR_ORANGE 230, 126, 34 
#define COLOR_PURPLE 142, 68, 173  
#define COLOR_GREEN  88, 214, 141  
#define COLOR_BLUE 46, 64, 83  

enum class StateEnum{MainMenu, Game, PauseMenu, GameOverMenu};
enum class TetrominoEnum { S1, S2, T, R, L1, L2, I };

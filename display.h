#ifndef DISPLAY_H_INCLUDED
#define DISPLAY_H_INCLUDED

#define VERSION "V.1.1.0"

#define SIZE_BOARD 9

#define EMPTY " "
#define DIVIDER_V "|"
#define DIVIDER_H "-"
#define INTERSECTION "+"

#define ABOUT '?'
#define SING_PLAYER 'a'
#define MULT_PLAYER 'b'
#define EXIT 'e'



// #define MSG_GOODBYE

// char board[SIZE_BOARD] = {'1','2','3','4','5','6','7','8','9'};
// char board[SIZE_BOARD];

void about();
void clrscr();
void goodbye();
void menu();
void menuGame();
void presentationScreen();


#endif //DISPLAY_H_INCLUDED
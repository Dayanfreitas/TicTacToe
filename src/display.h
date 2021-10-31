#ifndef DISPLAY_H_INCLUDED
#define DISPLAY_H_INCLUDED

#define ABOUT '?'
#define DIVIDER_H "-"
#define DIVIDER_V "|"
#define EMPTY " "
#define EXIT 'e'
#define INTERSECTION "+"
#define MULT_PLAYER 'b'
#define SING_PLAYER 'a'
#define SIZE_BOARD 9
#define VERSION "V.1.1.0"


void about(void);
void clearBoard(char *board);
void clrscr(void);
void goodbye(void);
void menu(void);
void menuGame(void);
void presentationScreen(void);
void showBoard(char *board);
#endif //DISPLAY_H_INCLUDED
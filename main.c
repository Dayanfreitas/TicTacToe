#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "display.h"

#define SINGLE_PLAYER 1
#define MULTI_PLAYER 2

#define N_COLUMN 3
#define SIZE_MARKS 2

typedef enum {FALSE , TRUE} bool;
char board[SIZE_BOARD] = {'1','2','3','4','5','6','7','8','9'};
char marks[SIZE_MARKS] = {'X','O'};


typedef struct ContextGame
{
    int NPlayers;//1 | 2
    int Level; //1 | 2 | 3
} ContextGame;

void showBoard();
void clearBoard();
void startGame(ContextGame c);
void showDisplayPlayers(ContextGame c);

int main () {
    struct ContextGame contextGame;
    int operation;
   
    
    presentationScreen();
    menu();
    while (TRUE)
    {
        operation = getchar();
        int isSingleplay = (bool) operation == 'a';
        int isMultiplayer = (bool) operation == 'b';
        int isExit = (bool) operation == EXIT;
        
        contextGame.Level = 1;
        if (isSingleplay == TRUE) {
            // printf("is single%d\n", isSingleplay);
            contextGame.NPlayers = SINGLE_PLAYER;    
            startGame(contextGame);
        }
        if (isMultiplayer == TRUE) {
            contextGame.NPlayers = 2;    
            printf("is mult %d\n", isMultiplayer);
            startGame(contextGame);
        }

        if (isExit == TRUE) {
            goodbye();
            break;
        }
    }
    
        
        
        
    return EXIT_SUCCESS;
}

void showBoard() {
    int sizeLine = (int) SIZE_BOARD/N_COLUMN;
    for (int line=0; line < sizeLine; line++) {            
        int first = line*3;
        int second = first+1;
        int third = second+1;
        bool isMiddleLine = line == 1;

        if (isMiddleLine) {
    	    printf("\t\t%s \t%s \t%s \t%s \t%s\n",EMPTY, INTERSECTION, EMPTY, INTERSECTION, EMPTY);
        	printf("\t\t%c \t%s \t%c \t%s \t%c\n",board[first], DIVIDER_V, board[second], DIVIDER_V, board[third]);
	        printf("\t\t%s \t%s \t%s \t%s \t%s\n",EMPTY, INTERSECTION, EMPTY, INTERSECTION, EMPTY);    
        }else {
        	printf("\t\t%c \t%s \t%c \t%s \t%c\n",board[first], DIVIDER_V, board[second], DIVIDER_V, board[third]);
        }
    }
}

void clearBoard() {
    char numero = '0'; 
    for (int i=0; i<SIZE_BOARD; i++) {
        board[i] = ++numero;
    }
}

void startGame(ContextGame c) {
    clrscr();
    // printf("level of game %d", c.Level);

    showDisplayPlayers(c);
    clearBoard();
    showBoard();
}

void showDisplayPlayers(ContextGame c) { 
    // printf("Numero de jogadores %d\n", n);

    
    // printf("\tPlayer-1<%c>\t\t\tPlayer-2<%c>",marks[0], marks[1]);

    printf("\tPlayer-1<%c>\r", marks[0]);
    if (c.NPlayers == MULTI_PLAYER) {
        printf("\t\t\t\tPlayer-2<%c>", marks[1]);
    }
	puts("");
	puts("");
	puts("");
}
 
#include "display.h"
#include <stdio.h>
#include <stdlib.h>

void about(void) 
{
	printf("\t**   O jogo da velha eh uma atividade     **\n");
    printf("\t**   da faculdade, feita no dia 06/06/2019 **\n");
   	printf("\t**   pelo estudante Dayan O. De Freitas  **\n");
}

void clearBoard(char *board) 
{
	char n = '0';
    for (int i = 0; i < SIZE_BOARD; i++)
    {
        board[i] = ++n;
    }
}

void clrscr(void)
{
    system("@cls||clear");
}

void goodbye(void)
{
	clrscr();
    puts("Bye Bye!");
}

void menu(void)
{
	puts("");
	printf("\t[%c].>> Single player\n", SING_PLAYER);
	printf("\t[%c].>> Multiplayers\n", MULT_PLAYER);
	printf("\t[%c].>> Exit\n", EXIT);
	printf("\t[%c].>> About\n", ABOUT);
	puts("");
}

void menuGame(void) {
	printf("\t[%c].>> Exit\n", EXIT);
}

void presentationScreen(void) {
    printf("\n");
	printf("\t*********************************************\n");
	printf("\t**              TIC TAC TOE                **\n");
	printf("\t**                                         **\n");
    printf("\t*********************************************\n");
	printf("\t**        Your Terminal Tic Tac Toe        **\n");
    printf("\t*********************************************\n");
	printf("\t*************************************%s*\n",VERSION);
	printf("\t*********************************************\n");    
}

void showBoard(char *board)
{
	int line = 3;
	int sizeLine = (int)SIZE_BOARD/line;
    for (int line = 0; line < sizeLine; line++)
    {
        int first = line * 3;
        int second = first + 1;
        int third = second + 1;
        int isMiddleLine = line == 1;

        if (isMiddleLine)
        {
            printf("\t\t%s \t%s \t%s \t%s \t%s\n", EMPTY, INTERSECTION, EMPTY, INTERSECTION, EMPTY);
            printf("\t\t%c \t%s \t%c \t%s \t%c\n", board[first], DIVIDER_V, board[second], DIVIDER_V, board[third]);
            printf("\t\t%s \t%s \t%s \t%s \t%s\n", EMPTY, INTERSECTION, EMPTY, INTERSECTION, EMPTY);
        }
        else
        {
            printf("\t\t%c \t%s \t%c \t%s \t%c\n", board[first], DIVIDER_V, board[second], DIVIDER_V, board[third]);
        }
    }

}
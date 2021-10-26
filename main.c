#include <stdio.h>
#include <stdlib.h>
#include "Display/display.h"


#define N_COLUMN 3
#define SIZE_BOARD 9
#define SIZE_BOOKMARKS 2

#define EMPTY " "
#define DIVIDER_V "|"
#define DIVIDER_H "-"
#define INTERSECTION "+"

typedef enum {FALSE , TRUE} bool;
char board[SIZE_BOARD] = {'1','2','3','4','5','6','7','8','9'};
char bookmarks[SIZE_BOOKMARKS] = {'X','O'};

void clrscr(){
    system("@cls||clear");
}

void presentationScreen() {
    // char name[5] = {"v","1","0","0"};
    char version[4] = "v1.1";
	
    printf("\n");
	printf("\t*********************************************\n");
	printf("\t**              JOGO DA VELHA %s         **\n", version);
	printf("\t**                                         **\n");
    printf("\t*********************************************\n");
    printf("\t**  /*O jogo da velha eh uma atividade     **\n");
    printf("\t**   da faculdade, feita no dia 06/06/2019 **\n");
   	printf("\t**   pelo estudante Dayan O. De Freitas*/  **\n");
	printf("\t*********************************************\n");
	printf("\t*********************************************\n");    
}

void main () {
    int sizeLine = (int) SIZE_BOARD/N_COLUMN;
    // clrscr();
    presentationScreen();

    for (int line=0; line < sizeLine; line++) {            
        int first = line*3;
        int second = first+1;
        int third = second+1;
        bool isMiddleLine = line == 1;

        if (isMiddleLine) {
    	    printf("\t%s \t%s \t%s \t%s \t%s\n",EMPTY, INTERSECTION, EMPTY, INTERSECTION, EMPTY);
        	printf("\t%c \t%s \t%c \t%s \t%c\n",board[first], DIVIDER_V, board[second], DIVIDER_V, board[third]);
	        printf("\t%s \t%s \t%s \t%s \t%s\n",EMPTY, INTERSECTION, EMPTY, INTERSECTION, EMPTY);    
            // sprintf(text_board_line, "\t%s \t%s \t%s \t%s \t%s\n \t%c \t%s \t%c \t%s \t%c\n\t%s \t%s \t%s \t%s \t%s\n", EMPTY, INTERSECTION, EMPTY, INTERSECTION, EMPTY,DIVIDER_V, board[first], DIVIDER_V, board[second], DIVIDER_V, board[third],EMPTY, INTERSECTION, EMPTY, INTERSECTION, EMPTY,DIVIDER_V);

        }else {
        	printf("\t%c \t%s \t%c \t%s \t%c\n",board[first], DIVIDER_V, board[second], DIVIDER_V, board[third]);
            // sprintf(text_board_line, "\t%c \t%s \t%c \t%s \t%c\n", board[first], DIVIDER_V, board[second], DIVIDER_V, board[third]);
        }

        // printf("%s", text_board_line);
    }

    // printf("\t%c \t%s \t%c \t%s \t%c\n",board[7],"|",board[8],"|",board[9]);
    // for (int i=0,y=i+1,z=y+1; i < size; i++, y=i+1, z=y+1) {

        // printf("%d,%d,%d\n", i,y,z);
    
    	// printf("\t%c \t%s \t%c \t%s \t%c\n",board[i],DIVIDER_V,board[y],DIVIDER_V,board[z]);
    
        // printf("\t%s \n\t%s", DIVIDER_H, DIVIDER_V);
        // printf("%s", DIVIDER_V);
        // printf("%s", INTERSECTION);
    // }
}
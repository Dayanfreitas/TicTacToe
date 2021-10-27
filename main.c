#include <stdio.h>
#include <stdlib.h>
// #include <conio.h>

#include "display.h"


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


int main () {
    int sizeLine = (int) SIZE_BOARD/N_COLUMN;
    int operation;
    
    clrscr();

    presentationScreen();

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

    operation = getchar();
    printf("%c", operation);
 
    return EXIT_SUCCESS;
}
#include <stdio.h>

#define VICTORY 1
#define NOT_VICTORY 0

#define CAN 1 
#define CANOT 0 


int canScratch(int position, char *board) {
    if (position <= 0 || position > 9) {
        return CANOT;
    }

    int cp = position--;
    char po = '0';
    po += cp;

    if (po == cp) { 
        return CAN;
    }

    return CANOT;
}

int checkBoardVictoryInLine(char *board) {
    int isVictory = NOT_VICTORY;

    int first, second, third = 0;
    for (int i=0; i<=7; i=i+3)
    {
        first = i;
        second = i + 1;
        third = i + 2;
        if (board[first] == board[second] && board[second] == board[third]) { isVictory = VICTORY; }
    }
    
    return isVictory;
}

int checkBoardVictoryInColumn(char *board) {
    int isVictory = NOT_VICTORY;

    int first, second, third = 0;
    for (int i = 0; i<=3; i++){
        first = i;
        second = i + 3;
        third = i + 6;
        if (board[first] == board[second] && board[second] == board[third]) { isVictory = VICTORY; }
    }

    return isVictory;
}

int checkBoardVictoryInDiagonal(char *board) {
    int isVictory = NOT_VICTORY;
    if (
        ((board[0] == board[4]) && ( board[4] == board[8]))||
        ((board[2] == board[4]) && (board[4] == board[6]))
        )
    { isVictory = VICTORY; }

    return isVictory;
}

int checkTheTie(char *board, char mask1, char mask2) {
    int tied = 1;

    for (int i = 0; i < 8; i++) {
        if ((board[i] != mask1) && 
            (board[i] != mask2)) 
        { 
            tied = 0; 
        }
    }

    if (tied == 1) { 
        printf("EMPATESS");
        
        return 1; 
    }

    return 0;
}

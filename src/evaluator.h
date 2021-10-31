#ifndef EVALUATOR_H_INCLUDED
#define EVALUATOR_H_INCLUDED


int canScratch(int position,char* board);

int checkBoardVictoryInLine(char *board);
int checkBoardVictoryInColumn(char *board);
int checkBoardVictoryInDiagonal(char *board);
int checkTheTie(char *board, char mask1, char mask2);

#endif
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#include "display.h"
#include "src/evaluator.h"

#define SINGLE_PLAYER 1
#define MULTI_PLAYER 2

#define N 3
#define N_LINE 3
#define N_COLUMN 3
#define SIZE_MARKS 2

typedef enum
{
    FALSE,
    TRUE
} bool;

typedef enum
{
    ZERO,
    ONE,
    SECOND
} playersID;

char board[SIZE_BOARD] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char marks[SIZE_MARKS] = {'X', 'O'};

typedef struct ContextGame
{
    int NPlayers; //1 | 2
    int Level;    //1 | 2 | 3
} ContextGame;

typedef struct Player
{
    int ID;
    char *Name;
    char Mask;
    int Point;
    bool IsMachine;
} Player;

bool checkVictoryOrFinishGame(Player *p);

void showBoard();
void clearBoard();
void startGame(ContextGame c);
void displayPlayers(Player *p1, Player *p2);

Player * tooglePlayer(Player *c, Player *p1, Player *p2);
Player createPlayer(playersID playerId, char *name, char mask, bool isMachine);

// bool checkBoardVictoryInLine();
// bool checkBoardVictoryInColumn();
// bool checkBoardVictoryInDiagonal();
// bool checkTheTie();

void showVictory(Player *p);

int main()
{
    struct ContextGame contextGame;
    int operation;

    while (TRUE)
    {
        clrscr();
        presentationScreen();
        menu();

        operation = getchar();
        int isSingleplay = (bool)operation == SING_PLAYER;
        int isMultiplayer = (bool)operation == MULT_PLAYER;
        int isAbout = (bool)operation == ABOUT;
        int isExit = (bool)operation == EXIT;

        
        if (isSingleplay == TRUE)
        {
            contextGame.Level = 1;
            contextGame.NPlayers = SINGLE_PLAYER;
            startGame(contextGame);
        }
        if (isMultiplayer == TRUE)
        {
            contextGame.NPlayers = MULTI_PLAYER;
            startGame(contextGame);
        }

        if (isAbout == TRUE) {
            about();
            system("read -p \"Press enter to exit\"");
        }

        if (isExit == TRUE)
        {
            goodbye();
            break;
        }
    }

    return EXIT_SUCCESS;
}

void run (Player player1, Player player2, int level) {
    struct Player *currentPlayer = &player1;
    bool finish = FALSE;
    int operation;
    
    clearBoard();

    while (!finish)
    {
        int position;
        int positionOnBoard;
        bool canScratch;

        if (currentPlayer->IsMachine == FALSE) {
            clrscr();
    
            displayPlayers(&player1, &player2);
            printf("\n\n");
            showBoard();
            printf("\n\n");
        
            puts("|========================================");
            printf("|====>>");
            printf("\tPlayer-%d<%c> your turn:", currentPlayer->ID, currentPlayer->Mask);
        }

        do
        {
            if (currentPlayer->IsMachine == FALSE) {
                scanf("%d", &position);
            }else { 
                if (level == 1) {
                    //TODO: IMPLEMENTAR DEMAIS NIVES
                    position = rand() % SIZE_BOARD;
                }else{
                    position = rand() % SIZE_BOARD;
                }
            }

            canScratch = TRUE;
            positionOnBoard = position - 1;
            if ((board[positionOnBoard] == player1.Mask) || (board[positionOnBoard] == player2.Mask))
            {
                canScratch = FALSE;
            }
        } while (position <= 0 || position > SIZE_BOARD || !canScratch);
        board[positionOnBoard] = currentPlayer->Mask;

        finish = checkVictoryOrFinishGame(currentPlayer);

        if (finish) { showVictory(currentPlayer); }

        currentPlayer = tooglePlayer(currentPlayer, &player1, &player2);
    }
    
}

void showBoard()
{
    int sizeLine = (int)SIZE_BOARD / N_COLUMN;
    for (int line = 0; line < sizeLine; line++)
    {
        int first = line * 3;
        int second = first + 1;
        int third = second + 1;
        bool isMiddleLine = line == 1;

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

void clearBoard()
{
    char numero = '0';
    for (int i = 0; i < SIZE_BOARD; i++)
    {
        board[i] = ++numero;
    }
}

void initSinglePlayer(Player player1, Player player2, int level)
{
    run(player1, player2, level);
}

void initMultiPlayer(Player player1, Player player2)
{
    run(player1, player2, 0);
}

void startGame(ContextGame c)
{
    char operation;
    do {
        struct Player player1, player2;
        
        if (c.NPlayers == SINGLE_PLAYER) {
            player1 = createPlayer(ONE, "Player 1", marks[0], FALSE);
            player2 = createPlayer(SECOND, "Machine", marks[1], TRUE);
            
            initSinglePlayer(player1, player2, c.Level);
        }

        if (c.NPlayers == MULTI_PLAYER) {
            player1 = createPlayer(ONE, "Player 1", marks[0], FALSE);
            player2 = createPlayer(SECOND, "Player 2", marks[1], FALSE);

            initMultiPlayer(player1, player2);
        }

        puts("");

        while ((getchar()) != '\n');
        puts("[Enter]Restart Game");
        puts("[E]Exit");
        operation = getchar();
    } while (operation != EXIT);
    
}

void displayPlayers(Player *p1, Player *p2)
{
    printf("\t%s<%c>", p1->Name, p1->Mask);
    printf("\t%s<%c>", p2->Name, p2->Mask);
    puts("");
}

bool checkVictoryOrFinishGame(Player *p)
{
    bool victoryOrFinish = FALSE;
    if (checkBoardVictoryInLine(board)) {
        victoryOrFinish = TRUE;
    }
    
    if (checkBoardVictoryInColumn(board) == TRUE) {
        victoryOrFinish = TRUE;
    }
    
    if (checkBoardVictoryInDiagonal(board) == TRUE) {
        victoryOrFinish = TRUE;
    }
    
    if (checkTheTie(board, marks[0], marks[1]) == TRUE) {
        victoryOrFinish = TRUE;
    }
    return victoryOrFinish;
}

// bool checkBoardVictoryInLine() {    
//     int first, second, third = 0;
//     for (int i=0; i<=7; i=i+3)
//     {
//         first = i;
//         second = i + 1;
//         third = i + 2;
//         if (board[first] == board[second] && board[second] == board[third]) { return TRUE; }
//     }
//     return FALSE;
// }

// bool checkBoardVictoryInColumn() {
//     int first, second, third = 0;
//     for (int i = 0; i<=3; i++){
//         first = i;
//         second = i + 3;
//         third = i + 6;
//         if (board[first] == board[second] && board[second] == board[third]) { return TRUE; }
//     }

//     return FALSE;
// }
// bool checkBoardVictoryInDiagonal() {
    // if (
    //     ((board[0] == board[4]) && ( board[4] == board[8]))||
    //     ((board[2] == board[4]) && (board[4] == board[6]))
    //     )
    // { return TRUE; }


    // return FALSE;
// }
// bool checkTheTie() {
//     bool tied = TRUE;
//     for (int i = 0; i < 8; i++) {
//         if ((board[i] != marks[0]) && (board[i] != marks[1])) { tied = FALSE; }
//     }

//     if (tied) { return TRUE; }

//     return FALSE;
// }

void showVictory(Player *p) {
    printf("\n\n%s-%d<%c>  Win!!!", p->Name, p->ID, p->Mask);
}

Player * tooglePlayer(Player *c, Player *p1, Player *p2) {
    if (c->ID == p1->ID) { return p2; }
    else { return p1; }
}

Player createPlayer(playersID playerId, char *name, char mask, bool isMachine) {
    struct Player player;
    memset(&player, 0, sizeof(player));

    player.ID      = playerId;
    player.Name    = name;
    player.Mask    = mask;
    player.IsMachine = isMachine;
    return player;
}


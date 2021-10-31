#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#include "display.h"
#include "evaluator.h"

#define SINGLE_PLAYER 1
#define MULTI_PLAYER 2
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

bool checkIsTheTie();
bool checkVictory();

Player * tooglePlayer(Player *c, Player *p1, Player *p2);
Player createPlayer(playersID playerId, char *name, char mask, bool isMachine);

void displayPlayers(Player *p1, Player *p2);
void showTicTacToe();
void showVictory(Player *p);
void startGame(ContextGame c);

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
    bool victory= FALSE;
    bool tie = FALSE;
    int operation;
    
    clearBoard(board);

    while (!finish)
    {
        int position;
        int positionOnBoard;
        bool canScratch;

        if (currentPlayer->IsMachine == FALSE) {
            clrscr();
    
            displayPlayers(&player1, &player2);
            printf("\n\n");
            showBoard(board);
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

        victory = checkVictory();
        tie = checkIsTheTie();
        
        if (victory) { 
            showVictory(currentPlayer); 
            finish = TRUE;
        }else if (tie) {
            showTicTacToe();
            finish = TRUE;
        }

        currentPlayer = tooglePlayer(currentPlayer, &player1, &player2);
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

bool checkIsTheTie(void) 
{
    return checkTheTie(board, marks[0], marks[1]);
}

bool checkVictory(void)
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

    return victoryOrFinish;
}

void showVictory(Player *p) {
    printf("\n\n%s-%d<%c>  Win!!!", p->Name, p->ID, p->Mask);
}

void showTicTacToe(void) {
    puts("\n\nTicTacToe !!!");
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


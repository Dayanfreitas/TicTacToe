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

// #define MAGIC_SQUARE
#define MAGIC_SQUARE_SOLUTION 15

typedef enum
{
    FALSE,
    TRUE
} bool;
int MAGIC_SQUARE[SIZE_BOARD] = {8, 1, 6, 3, 5, 7, 4, 9, 2};

// char board3[N_LINE][N_COLUMN] = {{'1','2','3'},
//                                 {'4','5','6'},
//                                 {'7','8','9'}};

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

} Player;

bool checkVictoryOrFinishGame(Player *p);

void printPlayer(Player p)
{
    puts("");
    puts("JOGADOR");

    printf("ID::%d\n", p.ID);
    printf("NAME::%s\n", p.Name);
    printf("_>::%c\n", p.Mask);
}

void showBoard();
void clearBoard();
void startGame(ContextGame c);
void showDisplayPlayers(ContextGame c);
void displayPlayers(Player *p1, Player *p2);

// helper
int drawPlayerToStart();

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
        // int isSingleplay = 0;
        int isMultiplayer = (bool)operation == MULT_PLAYER;
        int isExit = (bool)operation == EXIT;

        contextGame.Level = 1;
        if (isSingleplay == TRUE)
        {
            contextGame.NPlayers = SINGLE_PLAYER;
            startGame(contextGame);
        }
        if (isMultiplayer == TRUE)
        {
            contextGame.NPlayers = MULTI_PLAYER;
            startGame(contextGame);
        }

        if (isExit == TRUE)
        {
            goodbye();
            break;
        }
    }

    return EXIT_SUCCESS;
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

void initSinglePlayer()
{
}

void initMultiPlayer()
{
    bool finish = FALSE;
    int operation;

    struct Player player1, player2;
    struct Player *currentPlayer;

    memset(&player1, 0, sizeof(player1));
    memset(&player2, 0, sizeof(player1));

    player1.ID = 1;
    player1.Name = "Player 1";
    player1.Mask = marks[0];
    player2.Point = 0;

    player2.ID = 2;
    player2.Name = "Player 2";
    player2.Mask = marks[1];
    player2.Point = 0;

    currentPlayer = &player1;

    while (!finish)
    {
        int position;
        int positionOnBoard;
        bool canScratch;
        // puts("CURRENT PLAYER");
        // printf("%d\n",currentPlayer->ID);
        // printf("%s\n",currentPlayer->Name);
        // printf("%c\n",currentPlayer->Mask);

        clrscr();
        displayPlayers(&player1, &player2);
        printf("\n\n");
        showBoard();
        printf("\n\n");

        puts("|========================================");
        printf("|====>>");
        printf("\tPlayer-%d<%c> your turn:", currentPlayer->ID, currentPlayer->Mask);

        do
        {
            scanf("%d", &position);
            // flush_in();
            // position = getchar();
            canScratch = TRUE;
            positionOnBoard = position - 1;

            if ((board[positionOnBoard] == player1.Mask) || (board[positionOnBoard] == player2.Mask))
            {
                canScratch = FALSE;
            }

        } while (position <= 0 || position > SIZE_BOARD || !canScratch);
        board[positionOnBoard] = currentPlayer->Mask;

        finish = checkVictoryOrFinishGame(currentPlayer);

        //TODO: EXTRAIR FUNÇÂO
        // tooglePlayer(currentPlayer, &player1, &player2);
        if (currentPlayer->ID == player1.ID)
        {
            currentPlayer = &player2;
        }
        else
        {
            currentPlayer = &player1;
        }
    
        
    }

    // while ((getchar()) != '\n');
    // puts("[Enter]restart");
    // puts("[E]exit");
    // operation = getchar();
    
}

void startGame(ContextGame c)
{
    // clrscr();
    // showDisplayPlayers(c);
    // clearBoard();
    // showBoard();
    initMultiPlayer();
}

void displayPlayers(Player *p1, Player *p2)
{
    printf("\t%s<%c>", p1->Name, p1->Mask);
    printf("\t%s<%c>", p2->Name, p2->Mask);
    puts("");
}

void showDisplayPlayers(ContextGame c)
{
    if (c.NPlayers == SINGLE_PLAYER)
    {
        printf("Level  %d/3\n", c.Level);
        printf("\tPlayer<%c>\t\t\tMachine<%c>", marks[0], marks[1]);
    }
    else if (c.NPlayers == MULTI_PLAYER)
    {
        printf("\tPlayer-1<%c>\t\t\tPlayer-2<%c>", marks[0], marks[1]);
    }

    puts("");
    puts("");
    puts("");
}

bool checkVictoryOrFinishGame(Player *p)
{
    int first, second, third = 0;

    // vericar linhas
    for (int i = 0; i <= 7; i = i + 3)
    {
        //linhas
        first = i;
        second = i + 1;
        third = i + 2;

        if (board[first] == board[second] && board[second] == board[third])
        {
            // printf("\n\n %s-%d<%c>  Win!!!", p->Name, p->ID, p->Mask);
            // clearBoard();
            return TRUE;
        }
    }

    // vericar pontos de cada jogado em coluna
    for (int i = 0; i <= 3; i++)
    {
        //colunas
        first = i,
        second = i + 3;
        third = i + 6;

        if (board[first] == board[second] && board[second] == board[third])
        {
            // printf("\n\n %s-%d<%c>  Win!!!", p->Name, p->ID, p->Mask);
            // clearBoard();
            return TRUE;
        }
    }

    //diagonal
    if (board[0] == board[4] && board[4] == board[8] ||
        board[2] == board[4] && board[4] == board[6])
    {
        // printf("\n\n %s-%d<%c>  Win!!!", p->Name, p->ID, p->Mask);
        // clearBoard();
        return TRUE;
    }

    bool tied = TRUE;
    for (int i = 0; i < SIZE_BOARD; i++)
    {
        printf("%c - ", board[i]);
        if ((board[i] != marks[0]) || (board[i] != marks[1]))
        {
            tied = FALSE;
        }
    }

    if (tied)
    {
        // printf("\n\nGame was a draw!!!");
        // clearBoard();

        return TRUE;
    }
    return FALSE;
}

//HELPER
int drawPlayerToStart()
{
    // srand(time(NULL));
    // int result = (rand() % (1 - 2)) + 1;
    //TODO: implementar sorteio
    return 1;
}

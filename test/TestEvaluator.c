#include "../src/evaluator.h"
#include "../Unity/src/unity.h"
#include "../Unity/extras/fixture/src/unity_fixture.h"

TEST_GROUP(Evaluator);

TEST_SETUP(Evaluator){}

TEST_TEAR_DOWN(Evaluator){}

TEST(Evaluator, FunctionCheckBoardVictoryInLineOne) {
    char board[9] = {'X', 'X', 'X', '4', '5', '6', '7', '8', '9'};
    TEST_ASSERT_TRUE_MESSAGE(checkBoardVictoryInLine(board), "Vitoria na linha 1");
}

TEST(Evaluator, FunctionCheckBoardVictoryInLineSecond) {
    char board[9] = {'1', '2', '3', 'X', 'X', 'X', '7', '8', '9'};
    TEST_ASSERT_TRUE_MESSAGE(checkBoardVictoryInLine(board), "Vitoria na linha 2");
}

TEST(Evaluator, FunctionCheckBoardVictoryInLineThird) {
    char board[9] = {'1', '2', '3', '4', '5', '6', 'X', 'X', 'X'};
    TEST_ASSERT_TRUE_MESSAGE(checkBoardVictoryInLine(board), "Vitoria na linha 3");
}

TEST(Evaluator, FunctionCheckBoardVictoryInColumnOne) {
    char board[9] = {'X', '2', '3', 'X', '5', '6', 'X', '8', '9'};
    TEST_ASSERT_TRUE_MESSAGE(checkBoardVictoryInColumn(board), "Vitoria na coluna 1");
}

TEST(Evaluator, FunctionCheckBoardVictoryInColumnSecond) {
    char board[9] = {'1', 'X', '3', '4', 'X', '6', '7', 'X', '9'};
    TEST_ASSERT_TRUE_MESSAGE(checkBoardVictoryInColumn(board), "Vitoria na coluna 2");
}

TEST(Evaluator, FunctionCheckBoardVictoryInColumnThird) {
    char board[9] = {'1', '2', 'X', '4', '5', 'X', '7', '8', 'X'};
    TEST_ASSERT_TRUE_MESSAGE(checkBoardVictoryInColumn(board), "Vitoria na coluna 3");
}

TEST(Evaluator, FunctionCheckBoardVictoryInDiagonalOne) {
    char board[9] = {'X', '2', '4', '4', 'X', '6', '7', '8', 'X'};
    TEST_ASSERT_TRUE_MESSAGE(checkBoardVictoryInDiagonal(board), "diagonal esqueda para direita");
}

TEST(Evaluator, FunctionCheckBoardVictoryInDiagonalSecond) {
    char board[9] = {'1', '2', 'X', '4', 'X', '6', 'X', '8', '9'};
    TEST_ASSERT_TRUE_MESSAGE(checkBoardVictoryInDiagonal(board), "diagonal direita para esquerda");
}

TEST(Evaluator, FunctionCheckTheTie) {
    char board[9] = {'X', 'O', 'O', 'X', 'O', 'X', 'O', 'X', 'O'};
    TEST_ASSERT_TRUE_MESSAGE(checkTheTie(board, 'X', 'O'), "Deu velha");
}

TEST(Evaluator, FunctionCheckTheTieNot) {
    char board[9] = {'1', '2', 'X', '4', 'X', '6', 'X', '8', '9'};
    TEST_ASSERT_FALSE_MESSAGE(checkTheTie(board, 'X', 'O'), "Deu velha");
}
#include "Unity/unity.h"
#include "../../TicTacToe/display.h"

void setUp(){};
void tearDown(){};

void test_funcao() {
    TEST_ASSERT_EQUAL(1, funcao());
}

void main (void) {
    UNITY_BEGIN();
    RUN_TEST();
    return UNITY_END();
}
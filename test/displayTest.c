#include "../Unity/src/unity.h"
#include "../../TicTacToe/src/display.h"

void setUp(){};
void tearDown(){};

void test_funcao(void) {
    TEST_ASSERT_EQUAL(1, funcao());
}

int main (void) {
    UNITY_BEGIN();
    RUN_TEST(test_funcao);
    return UNITY_END();
}
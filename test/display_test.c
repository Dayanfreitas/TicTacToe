#include "../Unity/src/unity.h"
#include "../../TicTacToe/display.h"

void setUp(){};
void tearDown(){};

void test_funcao(void) {
    TEST_ASSERT_EQUAL_STRING("HELLO", "HELLO");

}

void test_funcao2(void) {
    TEST_ASSERT_MESSAGE(2==2, "Ertto");
}

int main (void) {
    UNITY_BEGIN();
    RUN_TEST(test_funcao);
    RUN_TEST(test_funcao2);
    return UNITY_END();
}
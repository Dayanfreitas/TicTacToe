#include "../Unity/src/unity.h"
#include "../../TicTacToe/display.h"

void setUp(){};
void tearDown(){};

void test_funcao(void) {
    //Não usar, não'preciso apenas int
    // TEST_ASSERT_EQUAL(2.0, 2.9);

    // TEST_ASSERT_FLOAT_WITHIN(0.1,2.0,2.1);
    // TEST_ASSERT_FLOAT_WITHIN(0.1,2.0,1.9);
    TEST_ASSERT_FLOAT_WITHIN(0.1,2.0,1.91);
}

void test_second_example() {
    TEST_ASSERT_FALSE(1 == 2);
    
    TEST_IGNORE();
    TEST_ASSERT(1 == 1);
}

int main (void) {
    UNITY_BEGIN();
    RUN_TEST(test_funcao);
    
    RUN_TEST(test_second_example);
    return UNITY_END();
}
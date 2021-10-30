#include "../src/evaluator.h"
#include "../Unity/src/unity.h"
#include "../Unity/extras/fixture/src/unity_fixture.h"

TEST_GROUP(Evaluator);

TEST_SETUP(Evaluator){}

TEST_TEAR_DOWN(Evaluator){}

TEST(Evaluator, FunctionReturnOne) {
    TEST_ASSERT_EQUAL(1,1);
}
#include "../src/display.h"
#include "../Unity/src/unity.h"
#include "../Unity/extras/fixture/src/unity_fixture.h"

TEST_GROUP(Display);

TEST_SETUP(Display){}

TEST_TEAR_DOWN(Display){}

TEST(Display, FunctionReturnOne) {
    TEST_ASSERT_EQUAL(1,2);
}
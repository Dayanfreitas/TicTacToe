#include "../../Unity/src/unity.h"
#include "../../Unity/extras/fixture/src/unity_fixture.h"

TEST_GROUP_RUNNER(Evaluator)
{
  RUN_TEST_CASE(Evaluator, FunctionReturnOne);
}
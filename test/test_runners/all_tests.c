#include "unity_fixture.h"

static void RunAllTests(void)
{
//   RUN_TEST_GROUP(ProductionCode);
  RUN_TEST_GROUP(Evaluator);
  RUN_TEST_GROUP(Display);
}

int main(int argc, const char * argv[])
{
  return UnityMain(argc, argv, RunAllTests);
}

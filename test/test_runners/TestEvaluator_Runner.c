#include "../../Unity/src/unity.h"
#include "../../Unity/extras/fixture/src/unity_fixture.h"

TEST_GROUP_RUNNER(Evaluator)
{

  RUN_TEST_CASE(Evaluator, FunctionCheckBoardVictoryInLineOne);
  RUN_TEST_CASE(Evaluator, FunctionCheckBoardVictoryInLineSecond);
  RUN_TEST_CASE(Evaluator, FunctionCheckBoardVictoryInLineThird);

  RUN_TEST_CASE(Evaluator, FunctionCheckBoardVictoryInColumnOne);
  RUN_TEST_CASE(Evaluator, FunctionCheckBoardVictoryInColumnSecond);
  RUN_TEST_CASE(Evaluator, FunctionCheckBoardVictoryInColumnThird);

  RUN_TEST_CASE(Evaluator, FunctionCheckBoardVictoryInDiagonalOne);
  RUN_TEST_CASE(Evaluator, FunctionCheckBoardVictoryInDiagonalSecond);
  
  RUN_TEST_CASE(Evaluator, FunctionCheckTheTie);
  RUN_TEST_CASE(Evaluator, FunctionCheckTheTieNot);

}
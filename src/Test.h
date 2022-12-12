#include <iostream>
#include "CustomMath.h"
#include "SecondExercise.h"

using std::cout;
using std::endl;

void test1()
{
  const int res1 = CustomMath::greatestCommonDivisor(6936, 1200);
  const int res2 = CustomMath::greatestCommonDivisor(192, 348);
  const int res3 = CustomMath::smallestCommonMultiple(6936, 1200);
  const int res4 = CustomMath::smallestCommonMultiple(192, 348);

  if (res1 != 24 || res2 != 12 || res3 != 346800 || res4 != 5568)
  {
    cout << "1: Test fails" << endl;
    return;
  }

  cout << "1: Test success" << endl;
}

void test2()
{
  int case1[] = {2, 3, 4, 5, 6};
  int case2[] = {1, 2, 4, 5, 6};
  int case3[] = {1, 2, 3, 4, 5, 6, 7, 9};
  int case4[] = {1, 2, 3, 4, 5, 6, 7, 8};
  const int res1 = secondExercise(case1, 5);
  const int res2 = secondExercise(case2, 5);
  const int res3 = secondExercise(case3, 8);
  const int res4 = secondExercise(case4, 8);

  if (res1 != 1 || res2 != 3 || res3 != 8 || res4 != 9)
  {
    cout << "2: Test fails" << endl;
    return;
  }

  cout << "2: Test success" << endl;
}
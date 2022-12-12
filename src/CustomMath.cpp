#include "CustomMath.h"

#include <iostream>

int CustomMath::greatestCommonDivisor(int num1, int num2)
{
  for (int i = std::min(num1, num2); i >= 2; i--)
  {
    if ((num1 % i == 0) && (num2 % i == 0))
    {
      return i;
    }
  }
  return 1;
}

int CustomMath::smallestCommonMultiple(int num1, int num2)
{
  const int gcd = greatestCommonDivisor(num1, num2);
  const int mod = abs(num1 * num2);
  return mod / gcd;
}

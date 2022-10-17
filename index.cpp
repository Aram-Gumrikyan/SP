#include "iostream"
#include "RowColumnCrypto.h"
using namespace std;

int greatestCommonDivisor(int num1, int num2)
{
  for (int i = min(num1, num2); i >= 2; i--)
  {
    if ((num1 % i == 0) && (num2 % i == 0))
    {
      return i;
    }
  }
  return 1;
}

int smallestCommonMultiple(int num1, int num2)
{
  const int gcd = greatestCommonDivisor(num1, num2);
  const int mod = abs(num1 * num2);
  return mod / gcd;
}

int secondExercise(int numbers[], int numbersLength)
{
  const int possibleGreatestNumber = numbersLength + 1;

  int realSum = 0, fakeSum = 0;

  for (int i = 1; i <= numbersLength; i++)
  {
    realSum += i;

    const int tempNumber = numbers[i - 1];

    if (tempNumber == possibleGreatestNumber)
    {
      continue;
    }

    fakeSum += tempNumber;
  }

  if (realSum == fakeSum)
  {
    return possibleGreatestNumber;
  }

  return realSum - fakeSum;
}

void test1()
{
  const int res1 = greatestCommonDivisor(6936, 1200);
  const int res2 = greatestCommonDivisor(192, 348);
  const int res3 = smallestCommonMultiple(6936, 1200);
  const int res4 = smallestCommonMultiple(192, 348);

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

int main()
{
  const u_int key = 3;
  RowColumnCrypto Crypto;
  const string encryptedData = Crypto.encrypt("123456789ABCDEFGHI", key);
  const string decryptedData = Crypto.decrypt(encryptedData, key);
  cout << encryptedData << endl;
  cout << decryptedData << endl;

  test1();
  test2();
  /*
  123
  456
  789
  ABC
  DEF
  GHI
  ====
  147
  258
  369
  ADG
  BEH
  CFI
  */
  return 0;
}

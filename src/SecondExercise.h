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

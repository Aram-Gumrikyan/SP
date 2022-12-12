#include "RleCrypto.h"

using std::to_string;

string RleCrypto::encode(string str, int key)
{
  string result = "";
  int n = str.length();
  for (int i = 0; i < n; i++)
  {

    int count = 1;
    while (i < n - 1 && str[i] == str[i + 1])
    {
      count++;
      i++;
    }
    result += (str[i] + to_string(count));
  }

  return result;
}

string RleCrypto::decode(string str, int key)
{
  string result = "";
  int n = str.length();
  for (int i = 1; i < n; i += 2)
  {
    for (int j = 0; j < int(str[i]) - 48; j++)
    {
      result += str[i - 1];
    }
  }

  return result;
}

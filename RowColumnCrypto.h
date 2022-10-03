#ifndef ROW_COLUMN_CRYPTO_H
#define ROW_COLUMN_CRYPTO_H

#include "iostream"
#include "math.h"
using namespace std;

class RowColumnCrypto
{
protected:
  string mainAlgorithm(string data, u_int columnLength, u_int rowLength, int rest = 0);

public:
  string encrypt(string data, u_int key);
  string decrypt(string data, u_int key);
};

string RowColumnCrypto::encrypt(string data, u_int key)
{
  const u_int dataLength = data.length();
  const u_int rows = ceil((double)dataLength / key);

  return mainAlgorithm(data, key, rows);
}

string RowColumnCrypto::decrypt(string data, u_int key)
{
  const u_int dataLength = data.length();
  const u_int rows = ceil((double)dataLength / key);
  const u_int rest = (rows * key) - dataLength;

  return mainAlgorithm(data, rows, key, rest);
}

string RowColumnCrypto::mainAlgorithm(string data, u_int columnLength, u_int rowLength, int rest)
{
  string result = "";
  u_int deviation = 0;
  const u_int diff = rowLength - rest;

  for (u_int c = 0; c < columnLength; c++)
  {
    for (u_int r = 0; r < rowLength; r++)
    {
      // (rowIndex * columnLength) + columnIndex
      const u_int index = (r * columnLength) + c;

      // if (rest && c == columnLength - 1)
      // {
      //   if (diff >= r)
      //   {
      //     deviation++;
      //     continue;
      //   }
      // }

      if (index - deviation >= data.length())
        continue;

      result += data[index - deviation];
    }
  }

  return result;
}

#endif /*ROW_COLUMN_CRYPTO_H*/
#ifndef ROW_COLUMN_CRYPTO_H
#define ROW_COLUMN_CRYPTO_H

#include "iostream"
#include "math.h"
using namespace std;

class RowColumnCrypto
{
protected:
  string mainAlgorithm(string data, u_int columnLength);

public:
  string encrypt(string data, u_int key);
  string decrypt(string data, u_int key);
};

string RowColumnCrypto::encrypt(string data, u_int key)
{
  const u_int dataLength = data.length();
  const u_int chunkLength = key * key;
  const u_int count = dataLength / chunkLength;
  string result = "";

  for (int i = 0; i < count; i++)
  {
    const u_int start = i * chunkLength;
    result += mainAlgorithm(data.substr(start, start + chunkLength), key);
  }

  const u_int lastPartStart = count * chunkLength;
  result += data.substr(lastPartStart, lastPartStart + chunkLength);
  return result;
}

string RowColumnCrypto::decrypt(string data, u_int key)
{
  return encrypt(data, key);
}

string RowColumnCrypto::mainAlgorithm(string data, u_int key)
{
  string result = "";

  for (u_int c = 0; c < key; c++)
  {
    for (u_int r = 0; r < key; r++)
    {
      // (rowIndex * key) + columnIndex
      const u_int index = (r * key) + c;

      if (index >= data.length() || !data[index])
      {
        continue;
      }

      result += data[index];
    }
  }

  return result;
}

#endif /*ROW_COLUMN_CRYPTO_H*/
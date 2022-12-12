#include "RowColumnCrypto.h"

string RowColumnCrypto::encode(string data, int key)
{
  const int dataLength = data.length();
  const int chunkLength = key * key;
  const int count = dataLength / chunkLength;
  string result = "";

  for (int i = 0; i < count; i++)
  {
    const int start = i * chunkLength;
    result += mainAlgorithm(data.substr(start, start + chunkLength), key);
  }

  const int lastPartStart = count * chunkLength;
  result += data.substr(lastPartStart, lastPartStart + chunkLength);
  return result;
}

string RowColumnCrypto::decode(string data, int key)
{
  return encode(data, key);
}

string RowColumnCrypto::mainAlgorithm(string data, int key)
{

  string result = "";

  for (int c = 0; c < key; c++)
  {
    for (int r = 0; r < key; r++)
    {
      // (rowIndex * key) + columnIndex
      const int index = (r * key) + c;

      if (index >= data.length() || !data[index])
      {
        continue;
      }

      result += data[index];
    }
  }

  return result;
}
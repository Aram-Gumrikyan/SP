#ifndef ROW_COLUMN_CRYPTO_H
#define ROW_COLUMN_CRYPTO_H

#include "Crypto.h"
#include <string>
#include <iostream>

using std::string;

class RowColumnCrypto : public Crypto<string, int>
{
public:
  string encode(string data, int key);
  string decode(string data, int key);

protected:
  string mainAlgorithm(string data, int key);
};

#endif
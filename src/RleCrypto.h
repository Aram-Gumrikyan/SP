#ifndef RLE_CRYPTO_H
#define RLE_CRYPTO_H

#include "Crypto.h"
#include <string>
#include <iostream>

using std::string;

class RleCrypto : public Crypto<string>
{
public:
  string encode(string data, int key = 0);
  string decode(string data, int key = 0);
};

#endif
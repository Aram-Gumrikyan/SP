#ifndef TEMPLATE_CRYPTO_H
#define TEMPLATE_CRYPTO_H

#include "Crypto.h"
#include <string>
#include <iostream>

using std::string;

struct TemplateCryptoKey
{
  string initial;
  string toChange;
};

class TemplateCrypto : public Crypto<string, TemplateCryptoKey>
{
public:
  string encode(string data, TemplateCryptoKey key);
  string decode(string data, TemplateCryptoKey key);
};

#endif
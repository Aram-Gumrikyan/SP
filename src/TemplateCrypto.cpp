#include "TemplateCrypto.h"

string TemplateCrypto::encode(string text, TemplateCryptoKey key)
{
  for (int i = 0; i <= text.length(); i++)
  {
    for (int j = 0; j <= key.initial.length(); j++)
    {
      if (text[i] == key.initial[j])
      {
        text[i] = key.toChange[j];
        break;
      }
    }
  }
  return text;
}

string TemplateCrypto::decode(string text, TemplateCryptoKey key)
{
  for (int i = 0; i <= text.length(); i++)
  {
    for (int j = 0; j <= key.initial.length(); j++)
    {
      if (text[i] == key.toChange[j])
      {
        text[i] = key.initial[j];
        break;
      }
    }
  }
  return text;
}
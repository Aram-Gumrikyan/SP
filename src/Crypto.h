#ifndef CRYPTO_H
#define CRYPTO_H
#include <cstddef>

template <typename T, typename K = int>
class Crypto
{
public:
  virtual T encode(T data, K key = NULL) = 0;
  virtual T decode(T data, K key = NULL) = 0;
};

#endif
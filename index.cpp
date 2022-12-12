#include "iostream"
#include "./src/RowColumnCrypto.h"
#include "./src/TemplateCrypto.h"
#include "./src/RleCrypto.h"
#include "./src/Test.h"

using namespace std;

int main()
{
  test1();
  test2();

  const int key = 3;
  RowColumnCrypto rowColumnCrypto;
  const string encodedData = rowColumnCrypto.encode("123456789ABCDEFGHI", key);
  const string decodedData = rowColumnCrypto.decode(encodedData, key);
  cout << encodedData << endl;
  cout << decodedData << endl;

  TemplateCryptoKey templateCryptoKey;
  templateCryptoKey.initial = "AaBbCc1234";
  templateCryptoKey.toChange = "cCAaBb2143";
  TemplateCrypto templateCrypto;
  cout << templateCrypto.encode("abc42A", templateCryptoKey) << endl;
  cout << templateCrypto.decode("Cab31c", templateCryptoKey) << endl;

  RleCrypto rleCrypto;
  cout << rleCrypto.encode("aaabaaabbba") << endl;
  cout << rleCrypto.decode("a3b1a3b3a1") << endl;

  return 0;
}

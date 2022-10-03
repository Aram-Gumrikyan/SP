#include "iostream"
#include "RowColumnCrypto.h"
using namespace std;

int main()
{
  const u_int key = 3;
  RowColumnCrypto Crypto;
  const string encryptedData = Crypto.encrypt("Hello  World", key);
  const string decryptedData = Crypto.decrypt(encryptedData, key);
  cout << encryptedData << endl;
  cout << decryptedData << endl;

  /*
  Hel
  lo
   Wo
  rld
  ====
  Hl r
  eoWl
  l od
  */
  return 0;
}

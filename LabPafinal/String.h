#pragma once
#include "./Interfaces/Headers/ICollectible.h"
#include "./Interfaces/Headers/IOrderedKey.h"

/**
 *  Implementación simple del datatype String que hereda tanto de ICollectible
 *  como de HashedKey
 */

 #include <string>
 using std::string;

 //#include "interfaces/OrderedKey.h"

 struct StringKey : public OrderedKey {
 public:
     StringKey(string str);

     ComparisonRes compare(OrderedKey* k) const;

     ~StringKey() {}

 private:
     string s;
 };

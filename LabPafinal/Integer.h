#pragma once
#include "./Interfaces/Headers/ICollectible.h"
#include "./Interfaces/Headers/IOrderedKey.h"

// datatype para representar un entero
class Integer: public ICollectible, public OrderedKey
{
private:
    const int val;
public:
    Integer(int i);
    int getValue() const;
    ComparisonRes compare(OrderedKey *k) const;
};

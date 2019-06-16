#pragma once
#include "./ListNode.h"


class ListIterator: public IIterator {
public:
    ListIterator(ListNode *head, bool disposeHeadOnDelete = false);
    ICollectible *getCurrent();
    bool hasCurrent();
    void next();

    virtual ~ListIterator();
private:
    ListNode *head;
    ListNode *current;
    bool disposeHeadOnDelete;
};

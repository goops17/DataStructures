#ifndef STACKTYPE_H
#define STACKTYPE_H
#include "ItemType.h"
#include "errorClasses.h"
struct NodeType
{
  ItemType info;
  NodeType *next;
};
class StackType
{
public:
    NodeType *location;
    NodeType *topPtr;
    StackType();
    void Push(ItemType newItem);
    bool IsFull();
    bool IsEmpty();
    void Pop();
    ItemType Top();
    ~StackType();

};

#endif

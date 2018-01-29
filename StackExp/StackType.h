// file: StackType.h
// by: Dawn Lawrie
//     as implemented in C++ Data Structure 3rd Ed. by Dale
// date: September 25, 2003

#include "errorClasses.h"

#ifndef STACKTYPE_H
#define STACKTYPE_H

typedef char ItemType;
const int MAX_ITEMS = 100;

class StackType {

private:
  int top;
  ItemType items[MAX_ITEMS];

public:

  // Constructor
  StackType();

  // Sets stack to an empty state
  // Preconditions: none
  // Postconditions: Stack is empty
  void MakeEmpty();

  // Determines whether the stack is empty
  // Precondition: Stack has been initialized
  // Postcondition: Function value = (stack is empty)
  bool IsEmpty() const;

  // Determines whether the stack is full
  // Precondition: Stack has been initialized
  // Postconidtion: Function value = (stack is full)
  bool IsFull() const;

  // Adds newItems to the top of the stack
  // Precondition: Stack has been initialized
  // Postcondition: If (stack is full)
  //                  an exception that communicates 'push on stack full'
  //                  is thrown
  //                else
  //                  newItem is at the top of the stack
  void Push(const ItemType& item);

  // Removes top item from stack and returns it in item.
  // Preconditions: Stack has been initialized
  // Postcondidtions: If stack is empty
  //                    an exception that communicates 'pop on stack empty'
  //                    is thrown
  //                  else
  //                    top element has been removed from stack
  void Pop(ItemType& item);
  ItemType Top();
};

#endif

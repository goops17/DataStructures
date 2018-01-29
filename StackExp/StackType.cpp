// file: StackType.cc
// by: Dawn Lawrie
//     as implemented in C++ Data Structure 3rd Ed. by Dale
// date: September 25, 2003

#include "StackType.h"

// Constructor
StackType::StackType() {
  top = -1;
}

// Sets stack to an empty state
// Preconditions: none
// Postconditions: Stack is empty
void StackType::MakeEmpty() {
  top = -1;
}

// Determines whether the stack is empty
// Precondition: Stack has been initialized
// Postcondition: Function value = (stack is empty)
bool StackType::IsEmpty() const {
  return (top == -1);
}

// Determines whether the stack is full
// Precondition: Stack has been initialized
// Postconidtion: Function value = (stack is full)
bool StackType::IsFull() const {
  return (top == MAX_ITEMS-1);
}

// Adds newItems to the top of the stack
// Precondition: Stack has been initialized
// Postcondition: If (stack is full)
//                  an exception that communicates 'push on stack full'
//                  is thrown
//                else
//                  newItem is at the top of the stack
void StackType::Push(const ItemType& newItem) {
  if (IsFull())
    throw PushOnFullStack();

  top++;
  items[top] = newItem;
}

// Removes top item from stack and returns it in item.
// Preconditions: Stack has been initialized
// Postcondidtions: If stack is empty
//                    an exception that communicates 'pop on stack empty'
//                    is thrown
//                  else
//                    top element has been removed from stack
void StackType::Pop(ItemType &item) {

  if(IsEmpty())
    throw PopOnEmptyStack();
  item = items[top];
  top--;
}




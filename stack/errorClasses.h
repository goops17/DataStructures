
// file: errorClasses.h
// by: Dawn Lawrie
//     as implemented in C++ Data Structure 3rd Ed. by Dale
// date: September 25, 2003


#include<string>
using namespace std;
#ifndef ERRORCLASSES_H
#define ERRORCLASSES_H

class FullStack {
private:
  string msg;

public:
  FullStack() {msg = string("Stack underflow: operation aborted");}
  const string message() const {return msg;}
};

class EmptyStack {
private:
  string msg;

public:
  EmptyStack() {msg = string("Stack overflow: operation aborted");}
  const string message() const {return msg;}
};

#endif

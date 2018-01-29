#include <iostream>
#include "nQueensPuzzle.h"

using namespace std;

int main()
{
    nQueensPuzzle  Q1;
    Q1.queensConfig(0);
    int c = Q1.solutionsCount();
    cout << "Count = " << c << endl;
    Q1.~nQueensPuzzle();
    return 0;
}

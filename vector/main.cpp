#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;
/*
int main()
{
    vector<int> intList;
    intList.push_back(13);
    intList.push_back(75);
    intList.push_back(28);
    intList.push_back(35);

    cout << "List Elements: ";
    for (int i = 0; i < 4; i++)
        cout << intList[i] << " ";
    cout << endl;

    for (int i = 0; i < 4; i++)
        intList[i] *= 2;

    cout << "List Elements: ";
    for (int i = 0; i < 4; i++)
        cout << intList[i] << " ";
    cout << endl;

    vector<int>::iterator listIt;

    cout << "List Elements Iterator: ";
    for (listIt = intList.begin(); listIt != intList.end(); ++listIt)
        cout << *listIt << " ";
    cout << endl;

    listIt = intList.begin();
    ++listIt;
    ++listIt;
    intList.insert(listIt, 88);

    cout << "List Elements: ";
    for (listIt = intList.begin(); listIt != intList.end(); ++listIt)
        cout << *listIt << " ";
    cout << endl;

    //Next
    int intArray[] = {5,6,8,3,40,36,98,29,75};
    vector<int> vecList(9);
    copy(intArray, intArray+9, vecList.begin());

    //display
    cout << "List New Elements: ";
    for (listIt = vecList.begin(); listIt != vecList.end(); ++listIt)
        cout << *listIt << " ";
    cout << endl;

    //Next copy
    copy(intArray+1, intArray+9,intArray);
    //display array
    for (int i = 0; i < 9; i++)
        cout << intArray[i] << " ";
    cout << endl;

    //Vector
    copy(vecList.rbegin() + 2, vecList.rend(), vecList.rbegin());

    //display again
    cout << "List Copied Elements: ";
    for (listIt = vecList.begin(); listIt != vecList.end(); ++listIt)
        cout << *listIt << " ";
    cout << endl;

    //Using copy with ostream iterator
    ostream_iterator<int> screen(cout, " ");
    copy(intArray, intArray+9, screen);
    cout << endl;

    //display again
    cout << "List Screen Elements: ";
    copy(vecList.begin(), vecList.end(), screen);
    cout << endl;

    return 0;
}
*/

    /**Recursion Example :::: */



    int largest(const int list[], int lowerIndex, int upperIndex);

    int main ()
    {
        int intArray[10] = {23, 43, 35, 38, 67, 12, 76, 10, 34, 8};
        cout << "The largest element in intArray: "
             << largest(intArray, 0, 9);
        cout << endl;

        return 0;
    }

    int largest(const int list[], int lowerIndex, int upperIndex)
    {
        int max;
        if(lowerIndex == upperIndex) //size of sublist is one
            return list[lowerIndex];
        else
        {
            max = largest(list, lowerIndex + 1, upperIndex);
            if(list[lowerIndex] >= max)
                return list[lowerIndex];
            else
                return max;
        }
    }



#include <iostream>
#include "arrayListType.h"

using namespace std;

int main()
{
    arrayListType<int> intList(100);
    arrayListType<string> stringList;
    int number;
    cout << "Enter 5 integers: ";
    for(int i = 0; i < 5; i++)
    {
        cin >> number;
        intList.insertAt(i, number);
    }
    cout << endl;
    cout << "The list you entered is: ";
    intList.print();
    cout << endl;

    cout << "Enter the item to be deleted: ";
    cin >> number;
    intList.remove(number);
    cout << "After removing " << number << ", the list is: " << endl;
    intList.print();
    cout << endl;

    string str;
    cout << "Enter 5 strings: ";
    for (int i = 0; i < 5; i++)
    {
        cin >> str;
        stringList.insertAt(i, str);
    }
    cout << endl;
    cout << "The list you entered is: " << endl;
    stringList.print();
    cout << endl;
    cout << "Enter a string to be deleted: ";
    cin >> str;
    stringList.remove(str);
    cout << "After removing " << str << ", the list is " << endl;
    stringList.print();
    cout << endl;
    return 0;
}

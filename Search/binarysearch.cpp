#include <stdio.h>
#include <iostream>
using namespace std;

int binarysearch(int key, int arr[], int min, int max);
int midpoint=0;

int main(){
	int arr[11] = {0,2,5,9,13,21,43,56,76,96,242}; //sample binary tree

	int key=0; //number you are trying to find
	int found=0; //if key is found

	cout << endl << "Enter the number you are looking for: ";
	cin >> key;

	found = binarysearch(key, arr, 0, (sizeof(arr)/4)-1);
	if(found==key){
		cout << endl << key << " exists in the tree" << endl;
	}
	else
		cout << endl << "Sorry, the number " << key << " does not exist in the tree :(" << endl;

	cout << endl;
	return 0;
}

int binarysearch(int key, int arr[], int min, int max){
	if(max < min)
		return -1;
	else{
		midpoint = (min + max)/2; //finds midpoint
		if(arr[midpoint] < key) //checks whether the value you are searching for is greater than the midpoint value
			binarysearch(key, arr, midpoint+1, max); //searches right half
		else if(arr[midpoint] > key) //checks whether the value you are searching for is less than the midpoint value
			binarysearch(key, arr, min, midpoint-1); //searches left half
	}
	return arr[midpoint];	
}

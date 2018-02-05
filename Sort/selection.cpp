#include<iostream>
#include<fstream>
#include<stdio.h>
#include <algorithm> 

using namespace std;


void SelectionSort(int *array, int begin, int end){
	for (int i = 0; i < end - 1; i++){
		int min = i;
		for (int j = i + 1; j < end; j++){
			if (array[j] < array[min]){
				min = j;
			}
		}
		if (min != i){
			swap(array[i], array[min]);
		}
	}
}

int main(){
	int n;
	cin >> n;
	int *array = new int[n];
	for (int i = 0; i < n; i++){
		array[i] = rand() % n;
		cout << array[i] << " ";
	}
	SelectionSort(array, 0, n);

	system("pause");

	delete[]array;

	return 0;
}

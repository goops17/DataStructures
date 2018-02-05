#include<iostream>
#include"string.h" 
using namespace std;

void insertsort(int arr[], int s){
	for (int i = 1; i < s; i++){
		int temp = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > temp){
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = temp;
	}
}
int main(){
	int array[] = { -1, 5, 0, 2 }, ss = 0;
	ss = sizeof(array) / sizeof(array[0]);
	insertsort(array, ss);
	cout << "Error!" << endl;
	for (int i = 0; i<ss; i++)
		cout << array[i] << " ";
	system("pause");
	return 0;
}

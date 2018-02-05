#include<iostream>
#include"string.h"
#include"stdlib.h"
using namespace std;

void mergearray(int a[], int first, int mid, int last, int temp[])
{
	int i = first, j = mid + 1;
	int m = mid, n = last;
	int k = 0;

	while (i <= m && j <= n)
	{
		if (a[i] <= a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}

	while (i <= m)
		temp[k++] = a[i++];

	while (j <= n)
		temp[k++] = a[j++];

	for (i = 0; i < k; i++)
		a[first + i] = temp[i];
}
void mergesort(int a[], int first, int last, int temp[])
{
	if (first < last)
	{
		int mid = (first + last) / 2;
		mergesort(a, first, mid, temp);    
		mergesort(a, mid + 1, last, temp); 
		mergearray(a, first, mid, last, temp); 
	}
}

bool MergeSort(int a[], int n)
{
	int *p = new int[n];
	if (p == NULL)
		return false;
	mergesort(a, 0, n - 1, p);
	delete[] p;
	return true;
}
int main(){
	int n;
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	if (arr == NULL)
		return false;
	MergeSort(arr, n);
	for (int i = 0; i < n; i++)
		cout << arr[i] << " " << endl;
	system("pasue");
	return 0;
}

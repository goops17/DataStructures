#include<stdio.h>
int recSearch(int arr[], int l, int r, int x)
{
     if (r < l)
        return -1;
     if (arr[l] == x)
        return l;
     return recSearch(arr, l+1, r, x);
}
 
int main()
{
    int arr[] = {12, 34, 54, 2, 3}, i;
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 3;
    int index = recSearch(arr, 0, n-1, x);
    if (index != -1)
       printf("Element %d is present at index %d", x, index);
    else
        printf("Element %d is not present", x);
    return 0;
}

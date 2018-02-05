
#include <iostream>

using namespace std;

void countingSort( int array[], int size, int k );

// main ////
int main() {

   // initialize variables
   int a[20] = {5,6,9,4,4,2,2,9,5,3,4,0,1,8,5,3,8,7};

   // sort array and print result
   countingSort( a, 18, 10 );

   // print array after results
   for( int i = 0; i < 18; i++ ){
   
      cout << a[i] << endl;
   }

   return 0;
}

void countingSort( int array[], int size, int k ){

   // initialize variables
   int c[k];
   int temp[size];

   // initialize count to 0
   for( int i = 0; i < k+1; i++ ){
   
      c[i] = 0;
   }

   // count of each integer
   for( int i = 0; i < size; i++ ){

      c[array[i]] += 1;
   }

   // count now contains positions of integers
   for( int i = 1; i <= k; i++ ){
   
      c[i] += c[i-1];      
   }

   // print out range
   cout << "The number of integers that fall between 2 and 7 are " << (c[7] - c[2-1]) << endl << endl;

   // insert position of array into a temp
   for( int i = 0; i < size; i++ ){
   
      temp[c[array[i]]-1] = array[i];
      c[array[i]] -= 1;
   }

   // copy temp to array
   for( int i = 0; i < size; i++ ){
   
      array[i] = temp[i];
   } 

}

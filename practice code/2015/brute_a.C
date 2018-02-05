#include <iostream>
#include <fstream>
using namespace std;
const int MAX_N = 100000000;
int binary_search(int a[], int n, int x)
  {
  int low;
  int mid;
  int high;
  int result;
  result = 0;
  low = 0;
  high = n - 1;
  while (low <= high)
    {
    mid = (low + high) / 2;
    result++;
    if (a[mid] == x)
      break;
    if (a[mid] < x)
      low = mid + 1;
    else
      high = mid - 1;
    }
  return result;
  }

int main()
  {
  long c;
  int  i;
  int  n;
  int  a[MAX_N];
  int  right;
  int  left;
  int  mid;
  int      n_case;
  ifstream inf;
  ofstream outf;

  inf . open("a.in");
  outf . open("a.out");

  n_case = 0;
  while (inf >> n)
    {
    n_case++;
    c = 0;
    for (i = 0; i < n; i++)
      a[i] = i;
    for (i = 0; i < n; i++)
      c += binary_search(a, n, a[i]);
    outf << "Case " << n_case << ": " << c << endl;
    }
  }


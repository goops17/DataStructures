include <iostream>
#include <fstream>
using namespace std;

const int MAX_N = 10000000;

int main()
  {
  long c[MAX_N+1];
  int  i;
  int  right;
  int  left;
  int  mid;
  int      n_case;
  ifstream inf;
  ofstream outf;

  inf . open("a.in");
  outf . open("a.out");

  c[0] = 0;
  c[1] = 1;
  for (i = 2; i <= MAX_N; i++)
    {
    mid = i / 2;
    left = mid;
    right = i - 1 - mid;
    c[i] = c[left] + left + c[right] + right + 1;
    }

  n_case = 0;
  while (inf >> i)
    {
    n_case++;
    outf << "Case " << n_case << ": " << c[i] << endl;
    }
  }


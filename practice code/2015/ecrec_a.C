#include <iostream>
#include <fstream>
using namespace std;

const int THOUSAND = 1000;
const int MAX_N = 10 * THOUSAND * THOUSAND;

long t[MAX_N + 1] = {0};

long bsc(int n)
  {
  if (n < 2)
    return n;
  if (t[n] > 0)
    return t[n];
  t[n] = n + bsc(n/2) + bsc(n - n/2 - 1);
  return t[n];
  }

int main()
  {
  int      i;
  int      n_case;
  long     result;
  ifstream inf;
  ofstream outf;

  inf . open("binary_search.in");
  outf . open("binary_search_recursive.out");

  n_case = 0;
  while (inf >> i)
    {
    result = bsc(i);
    n_case++;
    outf << "Case " << n_case << ": " << result << endl;
    }
  }


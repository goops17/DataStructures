#include <iostream>
#include <fstream>
using namespace std;

const int MAX_N = 40;
const int MAX_T = 40;

long table[MAX_N][MAX_T] = {0};

long comb(int n, int k)
  {
  long result;
  if (n == k)
    return 1;
  if (k == 0)
    return 1;
  if (table[n][k] > 0)
    return table[n][k];
  result = comb(n - 1, k - 1) + comb(n - 1, k);
  table[n][k] = result;
  return result;
  }

int main()
  {
  ifstream inf;
  int      case_num;
  int      n_cases;
  int      i;
  int      j;
  int      n;
  ofstream outf;
  int      result;
  int      k;

  inf . open("g.in");
  outf . open("g.out");

  inf >> n_cases;
  for (case_num = 1; case_num <= n_cases; case_num++)
    {
    inf >> n >> k;
    cout << "case " << case_num << " " << n << " " << k << endl;
    result = comb(n, k - 1);
    outf << "Case " << case_num << ": " << result << endl;      
    } 
  } 


#include <iostream>
#include <fstream>
using namespace std;
const int THOUSAND = 1000;
const int MAX_N = THOUSAND * THOUSAND + 1;

int loc_big(int a[], int n)
  {
  int i;
  int result;

  result = 0;
  for (i = 1; i < n; i++)
    if (a[i] > a[result])
      result = i;
  return result;
  }
int main()
  {
  ifstream inf;
  int      i;
  int      j;
  int      loc_a;
  int      loc_b;
  int      loc_err;
  int      n;
  int      n_case;
  ofstream outf;
  int      a[MAX_N];
  int      b[MAX_N];
  bool     same;

  inf . open("c.in");
  outf . open("c.out");

  n_case = 0;
  while (inf >> n)
    {
    n_case ++;
    cout << "Case " << n_case << ", n =  " << n << endl;
    for (i = 0; i < n; i++)
      inf >> a[i];
    for (i = 0; i < n; i++)
      inf >> b[i];
 
    same = true;
    for (i = 0; i < n; i++)
      {
      loc_a = loc_big(a, n);
      loc_b = loc_big(b, n);
      if (loc_a != loc_b)
        {
        loc_err = i + 1;
        same = false;
        break;
        }
      a[loc_a] = -999;
      b[loc_b] = -999;
      }

    outf << "Case " << n_case << ": ";
    if (same)
      outf << "agree" << endl;      
    else
      outf << loc_err << endl;      
    } 
  } 


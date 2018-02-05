#include <iostream>
#include <fstream>
using namespace std;

const bool PRINT_CASE = true;  
const int MAX_N = 60;
const int MAX_T = 600;

int main()
  {
  ifstream inf;
  int      i;
  int      j;
  int      n;
  int      n_case;
  ofstream outf;
  int      result;
  int      task[MAX_N];
  int      t;

  inf . open("d.in");
  outf . open("d.out");

  n_case = 0;
  while (inf >> n >> t)
    {
    n_case ++;
    for (i = 0; i < n; i++)
      inf >> task[i];
 
    result = 0;
    for (i = 0; i < n; i++)
      {
      if (task[i] <= t)
        result ++;
      t -= task[i];
      if (t <= 0)
        break;
      }
    if (PRINT_CASE)
      outf << "Case " << n_case << ": ";
    outf << result << endl;      
    } 
  } 


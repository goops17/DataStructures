#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

const int THOUSAND = 1000;
const int MAX_N = THOUSAND * THOUSAND + 1;
const bool DEBUG = false;

typedef pair<int, int> intpair;
typedef vector<intpair> rankings;

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
  rankings a_vec;
  rankings b_vec;
  intpair  a_pair;
  intpair  b_pair;
  
  bool     same;

  inf . open("c.in");
  outf . open("c.out");

  n_case = 0;
  while (inf >> n)
    {
    n_case ++;
    a_vec.clear();
    b_vec.clear();
    for (i = 0; i < n; i++)
      inf >> a[i];
    for (i = 0; i < n; i++)
      inf >> b[i];
    for (i = 0; i < n; i++)
      {
      a_pair = intpair(a[i], i); 
      a_vec.push_back(a_pair);
      b_pair = intpair(b[i], i); 
      b_vec.push_back(b_pair);
      }
 
    same = true;
    sort(a_vec.begin(), a_vec.end() );
    sort(b_vec.begin(), b_vec.end() );
    reverse(a_vec.begin(), a_vec.end() );
    reverse(b_vec.begin(), b_vec.end() );
    if (DEBUG)
      {
      cout << "a_vec" << endl;
      for (i = 0; i < n; i++)
        cout << "(" << a_vec[i] . first << "  "
             <<  a_vec[i] . second << ")" << "  ";
      cout << endl;
      cout << "b_vec" << endl;
      for (i = 0; i < n; i++)
        cout << "(" << b_vec[i] . first << "  "
             <<  b_vec[i] . second << ")" << "  ";
      cout << endl;
      }
    
    for (i = 0; i < n; i++)
      {
      if (a_vec[i] . second != b_vec[i] . second)
        {
        if (DEBUG)
          {
          cout << "different at spot " << i << endl;
          cout << a_vec[i] . second << endl;
          cout << b_vec[i] . second << endl;
          }
        loc_err = i + 1;
        same = false;
        break;
        }
      }

    outf << "Case " << n_case << ": ";
    if (same)
      outf << "agree" << endl;      
    else
      outf << loc_err << endl;      
    } 
  } 


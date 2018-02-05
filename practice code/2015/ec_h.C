#include <iostream>
#include <fstream>
using namespace std;

const bool PRINT_CASE = true; 
const int MAX_N = 100; 
ofstream outf;

void continued_to_rational(int n, int a[], long &top, long &bottom)
  {
  int i;
  long new_top;
  long new_bottom;

  top = a[n-1];
  bottom = 1;
  for (i = n - 2; i >= 0; i--)
    {
    new_top = bottom + top * a[i];
    new_bottom = top;
    top = new_top;
    bottom = new_bottom;
    }
  }

void rational_to_continued(int &n, int a[], long top, long bottom)
  {
  long new_bottom;
 
  if (top == 0)
    {
    n = 1;
    a[0] = 0;
    a[1] = -99999; 
    return;
    }
  if (bottom == 1)
    {
    n = 1;
    a[0] = top;
    a[1] = -99999; 
    return;
    }

  n = 1;
  if (top > 0)
    {
    a[0] = top / bottom;
    top = top - a[0] * bottom;
    }
  else
    {
    a[0] = top / bottom;
    if (a[0] * bottom != top)
      a[0] --;
    top = top - a[0] * bottom;
    }

  while (top > 0)
    {
    a[n] = bottom / top;
    new_bottom = top;
    top = bottom - a[n] * top;
    bottom = new_bottom;
    n ++;
    if (n >= MAX_N)
      {
      cerr << "n too big" << endl;
      exit(12);
      }
    }
  }


void print_cf(int n, int a[])
  {
  int i;
  for (i = 0; i < n; i++)
    {
    if (i > 0)
      outf << " ";
    outf << a[i];
    } 
  outf << endl;
  } 


int main()
  {
  ifstream inf;
  int      r1[MAX_N];
  int      r2[MAX_N];
  int      result[MAX_N];
  int      i;
  int      j;
  int      n1;
  int      n_case;
  int      n2;
  int      nr;
  long     top1;
  long     bottom1;
  long     top2;
  long     bottom2;
  long     sum_top;
  long     sum_bottom;
  long     prod_top;
  long     prod_bottom;
  long     diff_top;
  long     diff_bottom;
  long     div_top;
  long     div_bottom;

  inf . open("h.in");
  outf . open("h.out");

  n_case = 0;
  while (inf >> n1 >> n2)
    {
    n_case ++;
    if(PRINT_CASE)
      outf << "Case " << n_case << ":" << endl;

    for (i = 0; i < n1; i++)
      inf >> r1[i];
    for (i = 0; i < n2; i++)
      inf >> r2[i];
 
    continued_to_rational(n1, r1, top1, bottom1);
    continued_to_rational(n2, r2, top2, bottom2);

    // r1 + r2
    sum_bottom = bottom1 * bottom2;
    sum_top = top1 * bottom2 + top2 * bottom1;
    rational_to_continued(nr, result, sum_top, sum_bottom);
    print_cf(nr, result);

    // r1 - r2
    diff_bottom = bottom1 * bottom2;
    diff_top = top1 * bottom2 - top2 * bottom1;
    rational_to_continued(nr, result, diff_top, diff_bottom);
    print_cf(nr, result);

    // r1 * r2
    prod_bottom = bottom1 * bottom2;
    prod_top = top1 * top2;
    rational_to_continued(nr, result, prod_top, prod_bottom);
    print_cf(nr, result);

    // r1 / r2
    div_bottom = bottom1 * top2;
    div_top = top1 * bottom2;
    rational_to_continued(nr, result, div_top, div_bottom);
    print_cf(nr, result);

    } 
  } 


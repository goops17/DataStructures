#include <iostream>
#include <fstream>
using namespace std;

const int MAX_N = 20;
const int MAX_SUM = 35;
long less_table[MAX_SUM][MAX_N];
long equal_table[MAX_SUM][MAX_N];

long  count_less(long sum, int n)
  {
  int    i;
  long   result;

  if (less_table[sum][n] >= 0)
    return less_table[sum][n];
  if (n == 0)
    return 0;

  if (n == 1)
    return sum;

  result = 0;
  for (i = 0; i <= sum; i++)
    result += count_less(sum - i, n - 1);
  less_table[sum][n] = result;
  return result;
  }

long  count_equal(long sum, int n)
  {
  int    i;
  long   result;

  if (sum < 0)
    return 0;
  if (equal_table[sum][n] >= 0)
    return equal_table[sum][n];
  if (n == 0)
    return 0;

  if (n == 1)
    return 1;

  result = 0;
  for (i = 0; i <= sum; i++)
    result += count_equal(sum - i, n - 1);
  equal_table[sum][n] = result;
  return result;
  }

long count_ways(int r[], int n)
  {
  int    i;
  int    j;
  long   result;
  long   sum;
  long   subtotal;
  long   equal_count;
  long   total_left;
  long   raters_left;

  result = 0;

  sum = 0;
  for (i = 0; i < n; i++)
    sum += r[i];
result += count_less(sum, n);

  subtotal = 0;
  for (i = 0; i < n - 1; i++)
    {
    raters_left = n - i - 1;
    for (j = 0; j < r[i]; j++)
      {
      total_left = sum - subtotal - j;
      equal_count = count_equal(total_left, raters_left);
      result += equal_count;
      }
    subtotal += r[i];
    }

  result ++;   // tie
  return result;
  }

int main()
  {
  ifstream inf;
  int      i;
  int      j;
  int      n;
  int      n_case;
  ofstream outf;
  int      r[MAX_N];
  long     result;

  inf . open("f.in");
  outf . open("f.out");

  for (i = 0; i < MAX_SUM; i++)
    for (j = 0; j < MAX_N; j++)
      less_table[i][j] = -1;

  for (i = 0; i < MAX_SUM; i++)
    for (j = 0; j < MAX_N; j++)
      equal_table[i][j] = -1;
  n_case = 0;
  while (inf >> n)
    {
    if (n == 0)
      break;
    n_case ++;
    for (i = 0; i < n; i++)
      inf >> r[i];
    result = count_ways(r, n);
    outf << "Case " << n_case << ": ";
    outf << result << endl;
    } 
  } 


#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAX_DICT = 1000010;
const int MAX_PAIRS = 120;
void convert_to_lower(string &s)
  {
  int i;
  for (i = 0; i < s . length(); i++)
    s[i] = tolower(s[i]);
  }

void insertion_sort(string &a)
  {
  int  i;
  int  n;
  int  j;
  char temp;

  n = a . length();
  for (i = 1; i < n; i++)
    {
    temp = a[i];
    j = i - 1;
    while ((j >= 0) && (a[j] > temp))
      {
      a[j + 1] = a[j];
      j --;
      }
    a[j + 1] = temp;
    }
  }

int find_word(string current, string d[], int n)
  {
  int    i;
  for (i = 0; i < n; i++)
    if (d[i] == current)
      return i;
  return -1;
  }


bool pyramid(string d[], int n_dict, string w1, string w2)
  {
  string current;
  int    i;
  int    n;

  cout << "start of pyramid '" << w1 << "' and '" << w2 << "'" << endl;
  if (w1 == w2)
    return true;
  if (w2.length() <= w1.length())
    return false;
  n = w2 . length();
  for (i = 0; i < n; i++)
    {
    current = w2;
    current . erase(i, 1);
    if (find_word(current, d, n_dict) >= 0)
      if (pyramid(d, n_dict, w1, current))
        return true;
    }
  
  return false;
  }

int main()
  {
  ifstream inf;
  int      i;
  int      j;
  int      n_dict;
  int      n_pairs;
  int      n_case;
  ofstream outf;
  bool     result;
  string   d[MAX_DICT];  
  string   w1;  
  string   w2;  

  inf . open("i.in");
  outf . open("i.out");

  n_case = 0;
  while (inf >> n_dict)
    {
    n_case ++;
    outf << "Case " << n_case << ":" << endl;
    for (i = 0; i < n_dict; i++)
      {
      inf >> d[i];
      convert_to_lower(d[i]);
      }
    for (i = 0; i < n_dict; i++)
      insertion_sort(d[i]);
    for (i = 0; i < n_dict; i++)
      cout << d[i] << endl;
 
    inf >> n_pairs;
    for (i = 0; i < n_pairs; i++)
      {
      inf >> w1 >> w2;
      convert_to_lower(w1);
      convert_to_lower(w2);
      cout << "checking '" << w1 << "' and '" << w2 << "'" << endl;
      insertion_sort(w1);
      insertion_sort(w2);
      result = pyramid(d, n_dict, w1, w2);
      if (result)
        {
        outf << "yes" << endl;      
        cout << "yes" << endl;      
        }
      else
        {
        outf << "no" << endl;      
        cout << "no" << endl;      
        }
      } 
    } 
  } 


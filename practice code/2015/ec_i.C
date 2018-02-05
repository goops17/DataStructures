#include <iostream>
#include <fstream>
#include <string>
#include <set>
using namespace std;

const int MAX_DICT = 1000010;
const int MAX_PAIRS = 120;
const int MAX_LENGTH = 40;
const bool DEBUG = false;

set<string>  d_set[MAX_LENGTH + 1];
set<string>  check_d_set[MAX_LENGTH + 1];

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

bool pyramid(string d[], int n_dict, string w1, string w2)
  {
  string current;
  string previous;
  int    i;
  int    n;
  set<string>::iterator loc;

  cout << "start of pyramid '" << w1 << "' and '" << w2 << "'" << endl;
  if (w1 == w2)
    return true;
  n = w2 . length();
  previous = "";
  for (i = 0; i < n; i++)
    {
    current = w2;
    current . erase(i, 1);
    if (current != previous)
      {
      previous = current;
      loc = d_set[current.length()].find(current);
      if (loc != d_set[current.length()].end())
        if (pyramid(d, n_dict, w1, current))
          return true;
      }
    }
  
  return false;
  }


int main()
  {
  ifstream inf;
  int      i;
  int      j;
  set<string>::iterator loc;
  int      n_dict;
  int      n_pairs;
  int      n_case;
  ofstream outf;
  bool     result;
  string   d[MAX_DICT];  // dictionary
  string   check_d[MAX_DICT];  // dictionary for check of data
  string   w1;  // first word in pyramid
  string   w2;  // second word in pyramid

  inf . open("i.in");
  outf . open("i.out");

  n_case = 0;
  while (inf >> n_dict)
    {
    n_case ++;
    outf << "Case " << n_case << ":" << endl;
    for (i = 0; i <= MAX_LENGTH; i++)
      d_set[i] . clear();
    for (i = 0; i <= MAX_LENGTH; i++)
      check_d_set[i] . clear();
    for (i = 0; i < n_dict; i++)
      {
      inf >> d[i];
      if ((d[i].length() < 1) || (d[i].length() > 30))
        {
        cout << "Invalid word '" << d[i] << "'" << endl;
        cerr << "*****Invalid word '" << d[i] << "'" << endl;
        continue;
        }
      convert_to_lower(d[i]);
      check_d[i] = d[i];
      }
    for (i = 0; i < n_dict; i++)
      insertion_sort(d[i]);
    for (i = 0; i < n_dict; i++)
      d_set[d[i].length()].insert(d[i]);
    for (i = 0; i < n_dict; i++)
      check_d_set[d[i].length()].insert(check_d[i]);
    if (DEBUG)
      for (i = 0; i < n_dict; i++)
        cout << d[i] << endl;
 
    inf >> n_pairs;
    if (inf . fail())
      {
      cout << "failed reading n_pairs" << endl;
      exit(1);
      }
    for (i = 0; i < n_pairs; i++)
      {
      inf >> w1 >> w2;
      if (w1.length() >= w2.length())
        {
        cout << "Invalid case '" << w1 << "' and '" << w2 << "'" << endl;
        cerr << "*****Invalid case '" << w1 << "' and '" << w2 << "'" << endl;
        continue;
        }
      convert_to_lower(w1);
      convert_to_lower(w2);
      loc = check_d_set[w1.length()].find(w1);
      if (loc == check_d_set[w1.length()].end())
        {
        cout << "Invalid case '" << w1 << "' and '" << w2 << "'" << endl;
        cerr << "*****Invalid case '" << w1 << "' and '" << w2 << "'" << endl;
        continue;
        }
      loc = check_d_set[w2.length()].find(w2);
      if (loc == check_d_set[w2.length()].end())
        {
        cout << "Invalid case '" << w1 << "' and '" << w2 << "'" << endl;
        cerr << "*****Invalid case '" << w1 << "' and '" << w2 << "'" << endl;
        continue;
        }
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


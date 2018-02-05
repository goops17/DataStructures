
#include <iostream>
#include <fstream>
using namespace std;

struct   node
               {
               int   data;
               node *left;
               node *right;
               };
typedef  node *node_ptr;
const int MAX_N = 1010;

void insert(node_ptr &root, int num)
  {
  if (root == nullptr)
    {
    root = new (node);
    root -> data = num;
    root -> left = nullptr;
    root -> right = nullptr;
    return;
    }

  if (num == root -> data)
    return;  
  if (num < root -> data)
    insert(root -> left, num);
  else 
    insert(root -> right, num);
  } 

node_ptr build_tree(int a[], int n)
  {
  int        i;
  node_ptr   result;

  result = nullptr;
  for (i = 0; i < n; i++)
    insert(result, a[i]);

  return result;
  } 
void preorder(int p[], node_ptr root, int &i)
  {
  if (root != nullptr)
    {
    p[i] = root -> data;
    i++;
    preorder(p, root -> left, i);
    preorder(p, root -> right, i);
    }
  }

int main()
  {
  int         a[MAX_N];
  int         i;
  ifstream    inf;
  int         n;
  int         n_case;
  ofstream    outf;
  int         p[MAX_N];
  node_ptr    root;
  bool        same;

  inf.open("b.in");
  outf.open("b.out");

  n_case = 0;
  while (true)
    {
    n_case ++;
    n = 0;
    while (inf >> a[n])
      {
      if (a[n] < 0)
        break;
      n++;
      }
    if (n == 0)
      break;
    root = build_tree(a, n);
    for (i = 0; i < n; i++)
      p[i] = -1;
    i = 0;
    preorder(p, root, i);
    same = true;
    for (i = 0; i < n; i++)
      if (p[i] != a[i])
        {
        same = false;
        break;
        }

    if (same)
      {
      cout << "Case " << n_case << ": yes" << endl;
      outf << "Case " << n_case << ": yes" << endl;
      }
    else
      {
      cout << "Case " << n_case << ": no" << endl;
      outf << "Case " << n_case << ": no" << endl;
      }
    }
  inf.close();
  }

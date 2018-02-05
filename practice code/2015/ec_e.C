#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;

const int MAX_N = 110;
const bool DEBUG = false;
const bool PRINT_CASE = true;

struct point
  {
  double x;
  double y;
  };

void print_point(point p)
  {
  cout << "(" << p . x << ", " << p . y << ")";
  }

double area(point p[], int n)
  {
  int i;
  int j;
  double result;

  result = 0;
  for (i = 0; i < n; i++)
    {
    j = (i + 1) % n;
    result += p[i].x * p[j].y;
    result -= p[i].y * p[j].x;
    }
  return fabs(result / 2);
  }

void reverse_rotate(point p[], int n)
  {
  int   i;
  point rev[MAX_N];
  int   loc_low_left;

  for (i = 0; i < n; i++)
    rev[n - 1 - i] = p[i];
  if (DEBUG)
    {
    cout << "reversed point list" << endl;
    for (i = 0; i < n; i++)
      print_point(rev[i]);
    cout << endl;
    }
    
  loc_low_left = -1;
  for (i = 0; i < n; i++)
    if (rev[i].y == 0)
      {
      if (loc_low_left < 0)
        loc_low_left = i;
      else
        if (rev[loc_low_left].x > rev[i].x)
          loc_low_left = i;
      }
  if (DEBUG)
    cout << "loc_low_left = " << loc_low_left << endl;
  if (loc_low_left == 0)
    {
    for (i = 0; i < n; i++)
      p[i] = rev[i];
    return;
    }
  for (i = 0; i < n; i++)
    p[i] = rev[(i + loc_low_left) % n];
  if (DEBUG)
    {
    cout << "fixed point list" << endl;
    for (i = 0; i < n; i++)
      print_point(p[i]);
    cout << endl;
    }
  return;
  }

void interpolate(point p1, point p2, double y, point &xy)
  {
  double big_diff_x;
  double big_diff_y;
  double small_diff_x;
  double small_diff_y;

  xy . y = y;
  if (p1 . x == p2 . x)
    {
    xy . x = p1 . x;
    return;
    }
  big_diff_x = p2 . x - p1 . x;
  big_diff_y = p2 . y - p1 . y;
  small_diff_y = y - p1 . y;
  small_diff_x = (big_diff_x / big_diff_y) * small_diff_y;
  xy . x = p1 . x + small_diff_x;
  }


double find_height(point p[], int n, double desired_area)
  {
  int      i;
  int      i_left;
  int      i_right;
  double   high;
  double   low;
  double   bottom_area;
  double   mid;
  int      n_bottom;
  point    left_point;
  point    right_point;
  point    p_bottom[MAX_N];

  low = 0;
  high = 0;
  for (i = 0; i < n; i++)
    if (p[i] . y > high)
      high = p[i] . y;  
  mid = (high + low) / 2.0;
  while (high - low > 1.0e-6)
    {
    mid = (high + low) / 2.0;
    if (DEBUG)
      {
      cout << "high = " << high << ", low = " << low
           << ", mid = " << mid << endl;
      }

    // find left side intersect
    for (i_left = 0; i_left < n; i_left++)
      {
      if ((p[i_left].y < mid) && (p[i_left+1].y >= mid))
        break;
      }

    // find right side intersect
    for (i_right = n - 2; i_right > 0; i_right--)
      {
      if ((p[i_right].y > mid) && (p[i_right+1].y <= mid))
        break;
      }
    if ((i_left == n) || (i_right == 0))
      {
      cout << "================== ERROR ==============" << endl;
      cout << "mid = " << mid << endl;
      cout << "i_left = " << i_left << endl;
      cout << "i_right = " << i_right << endl;
      return -999;
      }
    if (DEBUG)
      {
      cout << "mid = " << mid << endl;
      cout << "i_left = " << i_left << endl;
      cout << "i_right = " << i_right << endl;
      }
    interpolate(p[i_left], p[i_left+1], mid, left_point);
    if (DEBUG)
      {
      cout << "left_point = ";
      print_point(left_point);
      cout << endl;
      }
    interpolate(p[i_right], p[i_right+1], mid, right_point);
    if (DEBUG)
      {
      cout << "right_point = ";
      print_point(right_point);
      cout << endl;
      }
    n_bottom = 0;
    for (i = 0; i <= i_left; i++)
      {
      p_bottom[n_bottom] = p[i];
      n_bottom ++;
      }
    p_bottom[n_bottom] = left_point;
    n_bottom ++;
    p_bottom[n_bottom] = right_point;
    n_bottom ++;
    for (i = i_right + 1; i < n; i++)
      {
      p_bottom[n_bottom] = p[i];
      n_bottom ++;
      }
    bottom_area = area(p_bottom, n_bottom);
    if (DEBUG)
      cout << "bottom_area = " << bottom_area << endl;
    if (bottom_area < desired_area)
      {
      low = mid;
      if (DEBUG)
        cout << "low reset to " << mid << endl;
      }
    else
      {
      high = mid;
      if (DEBUG)
        cout << "high reset to " << mid << endl;
      }
    }
  if (DEBUG)
    {
    cout << "At end of find height" << endl;
    cout << "  high = " << high << ", low = " << low
         << ", mid = " << mid << endl;
    cout << "  bottom_area = " << bottom_area << endl;
    cout << "  desired_area = " << desired_area << endl;
    }

  return mid;
  }

////////////////////////////////////////////////////////////////////

int main()
  {
  ifstream inf;
  int      i;
  int      j;
  int      n;
  int      n_case;
  int      n_bad;
  ofstream outf;
  double   result;
  point    p[MAX_N];
  int      t;
  double   depth;
  double   desired_area;
  double   liters;
  int      result_int;
  int      check_digits;

  inf . open("e.in");
  outf . open("e.out");

  n_case = 0;
  n_bad = 0;
  while (inf >> n)
    {
    n_case ++;
    inf >> depth >> liters;
    for (i = 0; i < n; i++)
      inf >> p[i] . x >> p[i] . y;
    reverse_rotate(p, n);
 
    desired_area = 1000 * liters / depth;
    if (DEBUG)
      cout << "desired_area = " << desired_area << endl;
    result = find_height(p, n, desired_area);

    outf << setprecision(4);
    outf . setf(ios::showpoint);
    outf . setf(ios::fixed);
    if ( PRINT_CASE )
      outf << "Case " << n_case << ": ";
    outf << result << endl;      
    if (result < 0)  // error check, should not be negative
      break;

    // make sure next digit isn't 5 to avoid rounding errors
    
    result_int = int(result * 1000000.0 + 0.1);
    cout << setprecision(4);
    cout . setf(ios::showpoint);
    cout . setf(ios::fixed);
    cout << result << "  ";      
    cout << result_int;
    check_digits = result_int % 100;
    if ((check_digits > 40) && (check_digits < 60))
      {
      cout << "***** delete this case *****";
      outf << "***** delete above case *****" << endl;
      outf << "n = " << n;
      outf << ", depth = " << depth;
      outf << ", liters = " << liters;
      outf << endl << endl; 
      n_bad ++;
      }
    cout << endl;      

    
    } 
  cout << n_bad << " bad cases found." << endl;
  } 


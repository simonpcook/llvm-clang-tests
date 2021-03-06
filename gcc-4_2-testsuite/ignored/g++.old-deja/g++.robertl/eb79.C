// { dg-do assemble  }
// Makes bogus x86 assembly code.
#include <iostream>

using namespace std;

template<class T>
T max(T a, T b)  // { dg-error "" } 
{
  return (a > b) ? a : b;
}

// Prototypes (enable one or the other)
double max<>(double, double);      // { dg-error "" } bogus code
// int max(int, int);

int main()
{
  int i = 123;
  double d = 1234.5678;

  cout.precision(12);
  cout << max(d, i) << endl;  // { dg-error "" } 
  cout << max(i, d) << endl;  // { dg-error "" } 
  return 0;
}

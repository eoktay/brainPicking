
/*
Disclaimer: the following aims to solve the core of the problem
and some trivial details[implementation or logic wise] may have been
omitted.
*/


#include <iostream>

using namespace std;

int main()
{
  int n = 5;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 0; j < i; j++)
      cout << "*";
    cout << endl;
  }
}
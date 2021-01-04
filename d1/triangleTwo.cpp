
/*
Disclaimer: the following aims to solve the core of the problem
and some trivial details[implementation or logic wise] may have been
omitted.
*/



#include <iostream>
#include <vector>

using namespace std;

int main()
{
  vector <int> range;
  range.push_back(5);
  range.push_back(5);

  while (range[0] != -1)
  {
    for (int i = 0; i <= 5 * 2; i++)
    {
      if (i >= range[0] && i <= range[1])
      {
        cout << "*";
      }
      else
      {
        cout << " ";
      }
    }
    cout << endl;
    range[0] = range[0] - 1;
    range[1] = range[1] + 1;
  }
}
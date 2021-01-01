
/*
Disclaimer: the following aims to solve the core of the problem
and some trivial/non-trivial details/gaps[implementation or 
logic wise] may have been omitted.
*/


#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
  string one = "10^1000";
  string two = "-2*10^1000";

  int posOne = one.find('^');
  int firstNum = stoi(one.substr(0, posOne));

  int coeffPos = two.find('*');
  int coeff;
  int value = 1;
  if (two[0] == '-')
  {
    value = -1;
    coeff = stoi(two.substr(1, coeffPos - 1));
  }
  else
  {
    coeff = stoi(two.substr(0, coeffPos));
  }
  
  int powPos = two.find('^');
  value *= stoi(two.substr(coeffPos + 1, powPos - coeffPos));
  cout << value * coeff << endl;
  int secondNum = value * coeff;

  // int secondPart = stoi(one.substr(posOne + 1));
  // cout << secondPart << endl;
  
  cout << to_string(firstNum + secondNum) + '^' 
    + one.substr(posOne + 1) << endl;
}

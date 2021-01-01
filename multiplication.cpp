
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
  string two = "10^1000";

  int posOne = one.find('^');
  int posTwo = two.find('^');

  int firstNum = stoi(one.substr(0, posOne));
  int secondNum = stoi(two.substr(0, posTwo));

  int secondPart = stoi(one.substr(posOne + 1));
  
  cout << to_string(firstNum) + '^' 
    + to_string(secondPart * 2) << endl;
}

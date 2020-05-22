#include <vector>
using namespace std;

// Your first C++ program is here...
int ECBinarySearch(const vector<int> &listNumbers, int value)
{
  // input list of numbers comes as listNumbers vector
  // You need to implement binary search of "value" over this list; 
  // return the position (i.e., array index) of the vector that matches "value"; 
  // or return -1 if not found.
  int maxnum = listNumbers.size() - 1;
  int minnum = 0;
  while(minnum <= maxnum) 
  {
    int temp = (maxnum + minnum) / 2;
    if(value < listNumbers.at(temp))
    {
      maxnum = temp - 1;
    }
    else if(value > listNumbers.at(temp))
    {
      minnum = temp + 1;
    }
    else
    {
      return temp;
    }
  }
  return -1;
}

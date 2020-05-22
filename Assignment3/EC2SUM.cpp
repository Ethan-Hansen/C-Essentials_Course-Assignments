#include <vector>
#include "ECSort.h"
#include "ECBinSearch.h"
#include <iostream>
using namespace std;

void EC2SUM( const vector<int> &listNumbers, 
  const vector<int> &listTargets, vector<bool> &list2SUMRes )
{
  // for each number x = listTargets[i], if there are two numbers 
  // in listNumbers that add up to x, then list2SUMres[i]=true 
  // otherwise, list2SUMRes[i]=false
  vector<int> tempNumlist;
  for(unsigned int i = 0; i < listNumbers.size(); ++i)
  {
    tempNumlist.push_back(listNumbers[i]);
  }
  ECSort(tempNumlist);

  for(unsigned int i = 0; i < listTargets.size(); ++i)
  {
    bool check = false;
    for(unsigned int k = 0; k < tempNumlist.size(); ++k)
    {
      if(listTargets[i] > tempNumlist[k])
      {
        int diff = listTargets[i] - tempNumlist[k];
        int res = ECBinarySearch(tempNumlist, diff);
        if(res != -1)
        {
          check = true;
          break;
        }
      }
    }
    list2SUMRes.push_back(check);
  }
}



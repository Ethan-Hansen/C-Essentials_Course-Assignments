#include "ECLongestPrefix.h"
#include <iostream>

using namespace std;


// Implement the longest prefix function here...
std::string ECLongestPrefix(int numStrings, const std::string arrayStrings[])
{
  // YW: this only serves as a starter code, which just print out the given array of strings
  //Gets length of the smallest string
  int minLength = arrayStrings[0].size();
  string minWord = arrayStrings[0];
  for(int i=1; i<numStrings; ++i)
  {
    if (arrayStrings[i].size() < minLength) {
      minLength = arrayStrings[i].size();
      minWord = arrayStrings[i];
    }
    
  }


  string longestPrefix = minWord;
  for(int i=0; i<numStrings; ++i)
  {
    for(int k=0; k<longestPrefix.size(); ++k)
    {
      if (longestPrefix[k] != (arrayStrings[i])[k]) {
        for(int l=0; l<longestPrefix.size() - k + 1; ++l)
        {
          longestPrefix.pop_back();
        }
        k = longestPrefix.size() + 1;
      }
      if (longestPrefix.size() == 0)
      {
        break;
      }
      
    }
  }

  //for(int i=0; i<numStrings; ++i)
  //{
  //  cout << arrayStrings[i] << " ";
  //}
  //cout << endl;

  return longestPrefix;
}

#include <vector>
#include <set>
#include "ECGetDistinctSubstrings.h"
using namespace std;

bool IsSubString( const std::vector<char> &strInput, 
  const std::vector<char> &strPattern )
{
  set< vector<char> > substrings;
  GetDistinctSubstrings(strInput, strPattern.size(), substrings);
  
  if(substrings.find(strPattern) != substrings.end())
  {
    return true;
  }
  return false;
}



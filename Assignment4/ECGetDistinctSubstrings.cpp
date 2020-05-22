#include <set>
#include <vector>
using namespace std;

void GetDistinctSubstrings( const std::vector<char> & strInput,
  int k, std::set< std::vector<char> > &setUniqueSubstrings  )
{
// find the set of all distinct length-k substrings in a given string.
// store the set of distinct substrings of length-k 
// in strInput into setUniqueSubstrings
  setUniqueSubstrings.clear();
  if(k != 0)
  {
    vector<char> substring;
    for(int i = 0; i < strInput.size() - k + 1; ++i)
    {
      for(int j = 0; j < k; ++j)
      {
        char temp = strInput[i + j];
        substring.push_back(temp);
      }

      if(setUniqueSubstrings.find(substring) == setUniqueSubstrings.end())
      {
        setUniqueSubstrings.insert(substring);
      }
      vector<char>().swap(substring);
    }
  }
}



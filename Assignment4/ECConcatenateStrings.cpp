#include <vector>
using namespace std;

void ConcatenateStrings( std::vector<char> &strConcatTo, 
  const std::vector<char> &strConcating  )
{
// Concatenate two strings - 1) strConcatTo 2) strConcating.
// That is, you need to append the string strConcating to the end of strConcatTo.
// Result: strConcatTo passed to as input should contain the Concatenated string.
  for(int i = 0; i < strConcating.size(); ++i)
  {
    strConcatTo.push_back(strConcating[i]);
  }
}

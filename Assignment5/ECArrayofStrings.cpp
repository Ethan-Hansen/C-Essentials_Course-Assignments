#include <iostream>
#include "ECArrayofStrings.h" 

using namespace std;

ECArrayofStrings :: ECArrayofStrings()
{
}

ECArrayofStrings :: ~ECArrayofStrings()
{
}

void ECArrayofStrings :: AddString( const string &strToAdd )
{
  setofstrings.push_back(strToAdd);
}

int ECArrayofStrings :: GetNumofStrings() const
{
  return setofstrings.size();
}

int ECArrayofStrings :: GetMaxLen() const
{
  int maxsize = 0;
  for(int i = 0; i < setofstrings.size(); ++i)
  {
    if(setofstrings[i].size() > maxsize)
    {
      maxsize = setofstrings[i].size();
    }
  }

  return maxsize;
}

string ECArrayofStrings :: GetLongestCommonPrefix() const
{
  string longest = setofstrings[0];
  if(setofstrings.size() == 1)
  {
    return(setofstrings[0]);
  }
  for(int i = 0; i < setofstrings.size() - 1; ++i)
  {
    int min;
    if(setofstrings[i].size() < longest.size())
    {
      min = setofstrings[i].size();
    }
    else
    {
      min = longest.size();
    }
    
    if(min < longest.size())
    {
      for(int j = 0; j < longest.size() - min; ++j)
      {
        longest.pop_back();
      }
    }

    int k;
    for(k = 0; k < min; ++k)
    {
      if(setofstrings[i][k] != longest[k])
      {
        break;
      }
    }

    if(k < min)
    {
      for(int j = 0; j < min-k; ++j)
      {
        longest.pop_back();
      }
    }
  }
  return longest;
}

string ECArrayofStrings :: Concatnate() const
{
  string res;
  for(int i = 0; i < setofstrings.size(); ++i)
  {
    res.append(setofstrings[i]);
  }
  return res;
}

void ECArrayofStrings:: Dump() const
{
  for(int i = 0; i < setofstrings.size(); ++i)
  {
    cout << setofstrings[i] << endl;
  }
}

string ECArrayofStrings :: GetLongestCommonPrefixofTwo(const string &str1, const string &str2) const
{
  int min;
  string longest;
  if(str1.size() <= str2.size())
  {
    min = str1.size();
  }
  else
  {
    min = str2.size();
  }
  for(int i = 0; i < min; ++i)
  {
    if(str1[i] == str2[i])
    {
      longest.push_back(str1[i]);
    }
    else
    {
      break;
    }
  }
  return longest;
}



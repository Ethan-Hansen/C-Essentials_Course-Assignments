#include <vector>
using namespace std;

void ECSort(vector<int> &listInts)
{
  if(listInts.size() > 1)
  {
    int half = listInts.size() / 2;

    vector<int> split1;
    for(int i = 0; i < half; ++i)
    {
      split1.push_back(listInts[i]);
    }
    
    vector<int> split2;
    for(unsigned int k = 0; k < (listInts.size()) - half; ++k)
    {
      split2.push_back(listInts[k + half]);
    }

    ECSort(split1);
    ECSort(split2);

    unsigned int i = 0;
    unsigned int k = 0;
    int counter = 0;

    while(i < split2.size() && k < split2.size())
    {
      if(split1[i] < split2[k])
      {
        listInts[counter] = split1[i];
        i++;
      }
      else
      {
        listInts[counter] = split2[k];
        k++;
      }
      ++counter;
    }

    while(i < split1.size())
    {
      listInts[counter] = split1[i];
      i++;
      ++counter;
    }
    while(k < split2.size())
    {
      listInts[counter] = split2[k];
      k++;
      ++counter;
    }
  }
  
}


#include "wList.H"
#include <iostream>
#include <list>
#include <string>
#include <iterator>
using namespace std;


int main()
{
   list <string> res;
   buildList(res);
   for(auto iterator = res.begin(); iterator != res.end(); ++iterator)
   {
      cout << *iterator << endl;
   }
   return 0;
}

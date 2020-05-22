#include "wList.H"
#include <iostream>
#include <list>
#include <string>
#include <iterator>
using namespace std;


int main()
{
   list <string>* res = buildList();
   for(auto iterator : (*res))
   {
      cout << iterator << endl;
   }
   delete res;
   res = nullptr;
   return 0;
}

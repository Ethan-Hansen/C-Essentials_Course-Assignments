#include "wList.H"
#include <iostream>
#include <list>
#include <string>
using namespace std;

void buildList(list <string> &wordlist)
{
    string line;
    while(getline(cin, line))
    {
        string word;
        for(int i = 0; i < line.size() + 1; ++i)
        {
            if(line[i] == ' ' || line[i] == '\n' || line[i] == '\0')
            {
                wordlist.push_back(word);
                word.clear();
            }
            else
            {
                word = word + line[i];
            }
            
        }
    }
}
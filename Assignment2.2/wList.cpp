#include "wList.H"
#include <iostream>
#include <list>
#include <string>
using namespace std;

list <string>* buildList()
{
    list <string>* wordlist = new list <string>;
    string line;
    while(getline(cin, line))
    {
        string word;
        for(int i = 0; i < line.size() + 1; ++i)
        {
            if(line[i] == ' ' || line[i] == '\n' || line[i] == '\0')
            {
                (*wordlist).push_back(word);
                word.clear();
            }
            else
            {
                word = word + line[i];
            }
            
        }
    }
    return wordlist;
}
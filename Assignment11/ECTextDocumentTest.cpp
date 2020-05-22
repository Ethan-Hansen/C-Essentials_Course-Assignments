//
//  ECTextDocumentTest.cpp
//  
//
//  Created by Yufeng Wu on 2/26/20.
//
//

#include <iostream>
#include "ECTextDocument.h"

using namespace  std;

static void Test1()
{
    //
    ECTextDocument doc;
    ECTextDocumentCtrl &docCtrl = doc.GetCtrl();
    vector<char> listText1;
    listText1.push_back('a');
    listText1.push_back('b');
    listText1.push_back('c');
    listText1.push_back('d');
    listText1.push_back('e');
    cout << "Made it through the push" << endl;
    docCtrl.InsertTextAt(0, listText1);
    cout << "Made it through the insert" << endl;
    vector<char> listText2;
    listText2.push_back('f');
    listText2.push_back('g');
    listText2.push_back('h');
    cout << "Made it through the second push" << endl;
    int posIns = 2;
    docCtrl.InsertTextAt(posIns, listText2);
    cout << "Made it through the second insert" << endl;
    //int lenDel = 2;
    //docCtrl.RemoveTextAt( posIns, lenDel );
    int posCap = 2;
    int lenCap = 5;
    docCtrl.CapTextAt( posCap, lenCap );
    cout << "Made it through the Cap" << endl;
    int posLow = 3;
    int lenLow = 2;
    docCtrl.LowerTextAt( posLow, lenLow );
    cout << "Made it through the lower" << endl;
    
    cout << "Text: ";
    for(int i=0; i<doc.GetDocLen(); ++i)
    {
        cout << doc.GetCharAt(i);
    }
    cout << endl;
    
    // try undo/redo
    docCtrl.Undo();
    cout << "After undo, text: ";
    for(int i=0; i<doc.GetDocLen(); ++i)
    {
        cout << doc.GetCharAt(i);
    }
    cout << endl;
    
    docCtrl.Redo();
    cout << "After redo, text: ";
    for(int i=0; i<doc.GetDocLen(); ++i)
    {
        cout << doc.GetCharAt(i);
    }
    cout << endl;
}

int main()
{
    // test code
    Test1();
    
    return 0;
}

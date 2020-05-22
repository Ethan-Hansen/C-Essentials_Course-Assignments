//
//  ECTextDocument.cpp
//  
//
//  Created by Yufeng Wu on 2/26/20.
//
//

#include "ECTextDocument.h"
#include <iostream>
#include <cctype>

using namespace std;

// **********************************************************
// Commands

//Insert command
InsertCommand :: ~InsertCommand()
{
}

void InsertCommand :: Execute()
{
  for(char letter : InsChars)
  {
    (*TxtDoc).InsertCharAt(index, (letter));
    index++;
  }
}

void InsertCommand :: UnExecute()
{
  int len = InsChars.size();
  index = index - len;
  for(int i = 0; i < len; i++)
  {
    (*TxtDoc).RemoveCharAt(index);
  } 
}

//RemoveCommand
RemoveCommand :: ~RemoveCommand()
{
}

void RemoveCommand :: Execute()
{
  for(int i = 0; i < len; i++)
  {
    RemChars.push_back((*TxtDoc).GetCharAt(index));
    (*TxtDoc).RemoveCharAt(index);
  }
}

void RemoveCommand :: UnExecute()
{
  for(int i = 0; i < len; i++)
  {
    (*TxtDoc).InsertCharAt(index + i, RemChars[i]);
  }
}

//Cap Command
CapCommand :: ~CapCommand()
{
}

void CapCommand :: Execute()
{
  for(int i = 0; i < len; i++)
  {
    (*TxtDoc).CapCharAt(index + i);
  }
}

void CapCommand :: UnExecute()
{
  for(int i = 0; i < len; i++)
  {
    (*TxtDoc).LowerCharAt(index + i);
  }
}

//Lower Command
LowerCommand :: ~LowerCommand()
{
}

void LowerCommand :: Execute()
{
  for(int i = 0; i < len; i++)
  {
    (*TxtDoc).LowerCharAt(index + i);
  }
}

void LowerCommand :: UnExecute()
{
  for(int i = 0; i < len; i++)
  {
    (*TxtDoc).CapCharAt(index + i);
  }
}

// **********************************************************
// Controller for text document

ECTextDocumentCtrl :: ECTextDocumentCtrl(ECTextDocument &docIn) : doc(docIn)
{
}

ECTextDocumentCtrl :: ~ECTextDocumentCtrl()
{
}

void ECTextDocumentCtrl :: InsertTextAt(int pos, const std::vector<char> &listCharsToIns)
{
  InsertCommand* com = new InsertCommand(&doc, listCharsToIns, pos);
  histCmds.ExecuteCmd(com);
}

void ECTextDocumentCtrl :: RemoveTextAt(int pos, int lenToRemove)
{
  RemoveCommand* com = new RemoveCommand(&doc, pos, lenToRemove);
  histCmds.ExecuteCmd(com);
}

void ECTextDocumentCtrl :: CapTextAt(int pos, int lenToCap)
{
  CapCommand* com = new CapCommand(&doc, pos, lenToCap);
  histCmds.ExecuteCmd(com);
}

void ECTextDocumentCtrl :: LowerTextAt(int pos, int lenToLower)
{
  LowerCommand* com = new LowerCommand(&doc, pos, lenToLower);
  histCmds.ExecuteCmd(com);
}

bool ECTextDocumentCtrl :: Undo()
{
  return histCmds.Undo();
}

bool ECTextDocumentCtrl :: Redo()
{
  return histCmds.Redo();
}

// **********************************************************
// Document for text document


ECTextDocument :: ECTextDocument() : docCtrl(*this)
{
}

ECTextDocument :: ~ECTextDocument()
{
}

ECTextDocumentCtrl & ECTextDocument :: GetCtrl()
{
    return docCtrl;
}

char ECTextDocument :: GetCharAt(int pos) const
{
    return listChars[pos];
}

void ECTextDocument :: InsertCharAt(int pos, char ch)
{
  auto iter = listChars.begin();
  int count = 0;

  while(count != pos)
  {
    iter++;
    count++;
  }

  listChars.insert(iter, ch);
}

void ECTextDocument :: RemoveCharAt(int pos)
{
  auto iter = listChars.begin();
  int count = 0;

  while(count != pos)
  {
    iter++;
    count++;
  }
  listChars.erase(iter);
}

void ECTextDocument :: CapCharAt(int pos)
{
  listChars[pos] = toupper(listChars[pos]);
}

void ECTextDocument :: LowerCharAt(int pos)
{
  listChars[pos] = tolower(listChars[pos]);
}


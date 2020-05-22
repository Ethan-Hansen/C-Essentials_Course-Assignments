//
//  ECCommand.cpp
//  
//
//  Created by Yufeng Wu on 2/26/20.
//
//

#include "ECCommand.h"

// ******************************************************
// Implement command history

ECCommandHistory :: ECCommandHistory() 
{
}

ECCommandHistory :: ~ECCommandHistory()
{

}

bool ECCommandHistory :: Undo()
{
  if(ComList.size() > 0)
  {
    (*ComList[ComList.size() - 1]).UnExecute();
    Undone.push_back(ComList[ComList.size() - 1]);
    ComList.pop_back();
    return true;
  }
  else
  {
    return false;
  }
  
}

bool ECCommandHistory :: Redo()
{
  if(Undone.size() > 0)
  {
    (*Undone[Undone.size() - 1]).Execute();
    ComList.push_back(Undone[Undone.size() - 1]);
    Undone.pop_back();
    return true;
  }
  else
  {
    return false;
  }
}

void ECCommandHistory :: ExecuteCmd( ECCommand *pCmd )
{
  ComList.push_back(pCmd);
  (*pCmd).Execute();
}



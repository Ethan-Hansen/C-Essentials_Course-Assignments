//
//  ECTextDocument.h
//  
//
//  Created by Yufeng Wu on 2/26/20.
//
//

#ifndef ECTextDocument_h
#define ECTextDocument_h

#include "ECCommand.h"
#include <vector>

class ECTextDocument;

// **********************************************************
// Implements Commands for editing 
class InsertCommand : public ECCommand
{
public:
    InsertCommand(ECTextDocument* doc, const std::vector<char> &listCharsToIns, int pos) : TxtDoc(doc), InsChars(listCharsToIns), index(pos)  {}
    ~InsertCommand();
    void Execute() override;
    void UnExecute() override;
private:
    ECTextDocument* TxtDoc;
    int index;
    const std::vector<char> InsChars;
};

class RemoveCommand : public ECCommand
{
public:
    RemoveCommand(ECTextDocument* doc, int pos, int x) : TxtDoc(doc), index(pos), len(x)  {}
    ~RemoveCommand();
    void Execute() override;
    void UnExecute() override;
private:
    ECTextDocument* TxtDoc;
    int index;
    int len;
    std::vector<char> RemChars;
};

class CapCommand : public ECCommand
{
public:
    CapCommand(ECTextDocument* doc, int pos, int x) : TxtDoc(doc), index(pos), len(x)  {}
    ~CapCommand();
    void Execute();
    void UnExecute();
private:
    ECTextDocument* TxtDoc;
    int index;
    int len;
};

class LowerCommand : public ECCommand
{
public:
    LowerCommand(ECTextDocument* doc, int pos, int x) : TxtDoc(doc), index(pos), len(x) {}
    ~LowerCommand();
    void Execute();
    void UnExecute();
private:
    ECTextDocument* TxtDoc;
    int index;
    int len;
};

// **********************************************************
// Controller for text document

class ECTextDocumentCtrl
{
public:
    ECTextDocumentCtrl(ECTextDocument &docIn);          // conroller constructor takes the document as input
    virtual ~ECTextDocumentCtrl();
    void InsertTextAt(int pos, const std::vector<char> &listCharsToIns);    // insert a list of characters starting at position
    void RemoveTextAt(int pos, int lenToRemove);                            // remove a segment of characters  of lenToRemove starting from pos
    void CapTextAt(int pos, int lenToCap);                                  // Capitalize the text of lenToCap long starting from pos
    void LowerTextAt(int pos, int lenToLower);                              // Lowercase the text of lenToLoer starting from pos
    bool Undo();                                                            // undo any change you did to the text
    bool Redo();                                                            // redo the change to the text
    
private:
    ECTextDocument &doc;
    ECCommandHistory histCmds;
};

// **********************************************************
// Document for text document

class ECTextDocument
{
public:
    ECTextDocument();
    virtual ~ECTextDocument();
    ECTextDocumentCtrl &GetCtrl();          // return document controller
    int GetDocLen() const { return listChars.size(); }
    char GetCharAt(int pos) const;          // get char at current position
    void InsertCharAt(int pos, char ch);    // insert a single char at position
    void RemoveCharAt(int pos);             // erase a single char at position
    void CapCharAt(int pos);                // capitalize the char at position
    void LowerCharAt(int pos);              // lowercase the char at position
    
private:
    ECTextDocumentCtrl docCtrl;
    std::vector<char> listChars;
};


#endif /* ECTextDocument_h */

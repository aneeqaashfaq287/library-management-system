
#pragma once
#include "../structures/BookNode.h"

class DoublyLinkedList
{
private:
    BookNode* head;
    BookNode* tail;
    BookNode* current;
    int count;

public:
    DoublyLinkedList();

    bool IsEmpty();
    bool Contains(int id);

    void InsertRight(BookNode* node);
    void InsertAfterCurrent(BookNode* node);

    BookNode* RemoveCurrent();

    void Next();
    void Previous();

    void PrintCurrent();
    void PrintForward();
    void PrintBackward();

    ~DoublyLinkedList();
};

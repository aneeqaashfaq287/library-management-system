
#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>
#include <string>
using namespace std;

struct BookNode
{
    int bookID;
    string title;
    BookNode* left;
    BookNode* right;

    BookNode(int id, string name)
    {
        bookID = id;
        title = name;
        left = nullptr;
        right = nullptr;
    }
};

class DoublyLinkedList
{
private:
    BookNode* head;
    BookNode* current;
    int count;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    bool IsEmpty() const;
    bool Contains(int id) const;
    int Count() const;

    void InsertRight(BookNode* book);
    void InsertAfterCurrent(BookNode* book);
    BookNode* RemoveCurrent();

    void Next();
    void Previous();

    void PrintCurrent() const;
    void PrintForward() const;
    void PrintBackward() const;
    void RemoveAtIndex(int index);
    void RemoveAtIndex(int index);
    void Swap(int index1, int index2);
    void Sort();
    void Reverse();
    void CheckStatus() const;
};

#endif

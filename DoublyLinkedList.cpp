
#include <iostream>
#include "DoublyLinkedList.h"
using namespace std;

DoublyLinkedList::DoublyLinkedList()
{
    head = nullptr;
    tail = nullptr;
    current = nullptr;
    count = 0;
}

bool DoublyLinkedList::IsEmpty()
{
    return head == nullptr;
}

bool DoublyLinkedList::Contains(int id)
{
    BookNode* temp = head;

    while (temp != nullptr)
    {
        if (temp->bookID == id)
            return true;

        temp = temp->right;
    }

    return false;
}

void DoublyLinkedList::InsertRight(BookNode* node)
{
    if (node == nullptr)
        return;

    node->left = tail;
    node->right = nullptr;

    if (tail != nullptr)
        tail->right = node;
    else
        head = node;

    tail = node;

    if (current == nullptr)
        current = node;

    count++;
}

void DoublyLinkedList::InsertAfterCurrent(BookNode* node)
{
    if (node == nullptr)
        return;

    if (current == nullptr)
    {
        InsertRight(node);
        return;
    }

    node->left = current;
    node->right = current->right;

    if (current->right != nullptr)
        current->right->left = node;
    else
        tail = node;

    current->right = node;

    count++;

    cout << "Book inserted after current book.\n";
}

BookNode* DoublyLinkedList::RemoveCurrent()
{
    if (current == nullptr)
        return nullptr;

    BookNode* removed = current;

    BookNode* previous = current->left;
    BookNode* next = current->right;

    if (previous != nullptr)
        previous->right = next;
    else
        head = next;

    if (next != nullptr)
        next->left = previous;
    else
        tail = previous;

    current = (next != nullptr) ? next : previous;

    removed->left = nullptr;
    removed->right = nullptr;

    count--;

    return removed;
}

void DoublyLinkedList::Next()
{
    if (current != nullptr && current->right != nullptr)
    {
        current = current->right;
        PrintCurrent();
    }
    else
    {
        cout << "No next book available.\n";
    }
}

void DoublyLinkedList::Previous()
{
    if (current != nullptr && current->left != nullptr)
    {
        current = current->left;
        PrintCurrent();
    }
    else
    {
        cout << "No previous book available.\n";
    }
}

void DoublyLinkedList::PrintCurrent()
{
    if (current == nullptr)
    {
        cout << "Borrowing session is empty.\n";
        return;
    }

    cout << "\nCurrent Book\n";
    cout << "Book ID: " << current->bookID << endl;
    cout << "Title: " << current->title << endl;
}

void DoublyLinkedList::PrintForward()
{
    if (IsEmpty())
    {
        cout << "Borrowing session is empty.\n";
        return;
    }

    cout << "\nBorrowing Session (First to Last)\n";

    BookNode* temp = head;

    while (temp != nullptr)
    {
        cout << temp->bookID << " - " << temp->title;

        if (temp == current)
            cout << " [CURRENT]";

        cout << endl;

        temp = temp->right;
    }

    cout << "Total Books: " << count << endl;
}

void DoublyLinkedList::PrintBackward()
{
    if (IsEmpty())
    {
        cout << "Borrowing session is empty.\n";
        return;
    }

    cout << "\nBorrowing Session (Last to First)\n";

    BookNode* temp = tail;

    while (temp != nullptr)
    {
        cout << temp->bookID << " - " << temp->title;

        if (temp == current)
            cout << " [CURRENT]";

        cout << endl;

        temp = temp->left;
    }
}

DoublyLinkedList::~DoublyLinkedList()
{
    BookNode* temp = head;

    while (temp != nullptr)
    {
        BookNode* next = temp->right;
        delete temp;
        temp = next;
    }
}

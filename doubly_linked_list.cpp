
#include "../Header-files/doubly_linked_list.h"

DoublyLinkedList::DoublyLinkedList()
{
    head = nullptr;
    current = nullptr;
    count = 0;
}

DoublyLinkedList::~DoublyLinkedList()
{
    if (head == nullptr)
        return;

    BookNode* temp = head;

    while (temp != nullptr)
    {
        BookNode* next = temp->right;
        delete temp;
        temp = next;
    }
}

bool DoublyLinkedList::IsEmpty() const
{
    return head == nullptr;
}

bool DoublyLinkedList::Contains(int id) const
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

int DoublyLinkedList::Count() const
{
    return count;
}

void DoublyLinkedList::Next()
{
    if (current == nullptr)
    {
        cout << "No book available.\n";
        return;
    }

    if (current->right != nullptr)
    {
        current = current->right;
        cout << "Moved to next book.\n";
    }
    else
    {
        cout << "Already at the last book.\n";
    }
}

void DoublyLinkedList::Previous()
{
    if (current == nullptr)
    {
        cout << "No book available.\n";
        return;
    }

    if (current->left != nullptr)
    {
        current = current->left;
        cout << "Moved to previous book.\n";
    }
    else
    {
        cout << "Already at the first book.\n";
    }
}

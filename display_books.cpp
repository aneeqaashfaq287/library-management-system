
#include "../Header Files/doubly_linked_list.h"

void DoublyLinkedList::PrintCurrent() const
{
    if (current == nullptr)
    {
        cout << "No book is currently selected.\n";
        return;
    }

    cout << "\nCurrent Book\n";
    cout << "Book ID: " << current->bookID << endl;
    cout << "Title: " << current->title << endl;
}

void DoublyLinkedList::PrintForward() const
{
    if (head == nullptr)
    {
        cout << "Library is empty.\n";
        return;
    }

    BookNode* temp = head;

    cout << "\nBooks from First to Last:\n";

    while (temp != nullptr)
    {
        cout << "ID: " << temp->bookID
             << " | Title: " << temp->title << endl;

        temp = temp->right;
    }
}

void DoublyLinkedList::PrintBackward() const
{
    if (head == nullptr)
    {
        cout << "Library is empty.\n";
        return;
    }

    BookNode* temp = head;

    while (temp->right != nullptr)
        temp = temp->right;

    cout << "\nBooks from Last to First:\n";

    while (temp != nullptr)
    {
        cout << "ID: " << temp->bookID
             << " | Title: " << temp->title << endl;

        temp = temp->left;
    }
}

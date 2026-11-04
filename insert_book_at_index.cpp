
#include "../Header Files/doubly_linked_list.h"

void DoublyLinkedList::InsertAfterCurrent(BookNode* book)
{
    if (book == nullptr)
        return;

    if (current == nullptr)
    {
        cout << "No current book available.\n";
        delete book;
        return;
    }

    book->left = current;
    book->right = current->right;

    if (current->right != nullptr)
        current->right->left = book;

    current->right = book;
    current = book;

    count++;

    cout << "Book inserted after current book.\n";
}

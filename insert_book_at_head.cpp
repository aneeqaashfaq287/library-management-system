
#include "../Header Files/doubly_linked_list.h"

void DoublyLinkedList::InsertRight(BookNode* book)
{
    if (book == nullptr)
        return;

    book->left = nullptr;
    book->right = nullptr;

    if (head == nullptr)
    {
        head = book;
        current = book;
    }
    else
    {
        BookNode* temp = head;

        while (temp->right != nullptr)
            temp = temp->right;

        temp->right = book;
        book->left = temp;
    }

    count++;
}

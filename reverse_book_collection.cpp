
#include "../Header Files/doubly_linked_list.h"

void DoublyLinkedList::Reverse()
{
    if (count < 2)
    {
        cout << "Not enough books to reverse.\n";
        return;
    }

    BookNode* temp = head;
    BookNode* newHead = nullptr;

    while (temp != nullptr)
    {
        BookNode* nextNode = temp->right;

        temp->right = temp->left;
        temp->left = nextNode;

        newHead = temp;
        temp = nextNode;
    }

    head = newHead;

    cout << "Book collection reversed.\n";
}


#include "../Header Files/doubly_linked_list.h"

void DoublyLinkedList::RemoveAtIndex(int index)
{
    if (index < 0 || index >= count)
    {
        cout << "Invalid index.\n";
        return;
    }

    BookNode* temp = head;

    for (int i = 0; i < index; i++)
        temp = temp->right;

    if (temp->left != nullptr)
        temp->left->right = temp->right;
    else
        head = temp->right;

    if (temp->right != nullptr)
        temp->right->left = temp->left;

    if (current == temp)
    {
        current = temp->right;

        if (current == nullptr)
            current = temp->left;
    }

    cout << "Removed Book: " << temp->title << endl;

    delete temp;
    count--;
}

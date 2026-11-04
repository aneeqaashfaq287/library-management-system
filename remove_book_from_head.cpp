
#include "../Header Files/doubly_linked_list.h"

BookNode* DoublyLinkedList::RemoveCurrent()
{
    if (current == nullptr)
        return nullptr;

    BookNode* removed = current;

    if (removed->left != nullptr)
        removed->left->right = removed->right;
    else
        head = removed->right;

    if (removed->right != nullptr)
        removed->right->left = removed->left;

    current = removed->right;

    if (current == nullptr)
        current = removed->left;

    removed->left = nullptr;
    removed->right = nullptr;

    count--;

    return removed;
}

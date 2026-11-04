
#include "../Header Files/doubly_linked_list.h"

void DoublyLinkedList::Sort()
{
    if (count < 2)
    {
        cout << "Not enough books to sort.\n";
        return;
    }

    for (BookNode* i = head; i != nullptr; i = i->right)
    {
        for (BookNode* j = i->right; j != nullptr; j = j->right)
        {
            if (i->bookID > j->bookID)
            {
                int tempID = i->bookID;
                i->bookID = j->bookID;
                j->bookID = tempID;

                string tempTitle = i->title;
                i->title = j->title;
                j->title = tempTitle;
            }
        }
    }

    cout << "Books sorted by ID.\n";
}

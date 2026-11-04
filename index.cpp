
#include <iostream>
#include "../Header Files/actions.h"
using namespace std;

int main()
{
    DoublyLinkedList session;

    session.InsertRight(new BookNode(101, "Data Structures"));
    session.InsertRight(new BookNode(102, "Database Systems"));
    session.InsertRight(new BookNode(103, "Operating Systems"));

    int choice;

    do
    {
        ShowMenu();
        choice = ReadInt("Enter your choice: ");

        switch (choice)
        {
        case 1:
            session.PrintCurrent();
            break;

        case 2:
            session.Next();
            break;

        case 3:
            session.Previous();
            break;

        case 4:
        {
            BookNode* book = CreateBook(session);

            if (book != nullptr)
            {
                session.InsertRight(book);
                cout << "Book added at the end.\n";
            }
            break;
        }

        case 5:
        {
            BookNode* book = CreateBook(session);

            if (book != nullptr)
                session.InsertAfterCurrent(book);

            break;
        }

        case 6:
        {
            BookNode* removed = session.RemoveCurrent();

            if (removed != nullptr)
            {
                cout << "Removed Book: "
                     << removed->title << endl;
                delete removed;
            }
            else
            {
                cout << "No book available to remove.\n";
            }
            break;
        }

        case 7:
            session.PrintForward();
            break;

        case 8:
            session.PrintBackward();
            break;

        case 9:
        {
            int index = ReadInt("Enter index to remove: ");
            session.RemoveAtIndex(index);
            break;
        }

        case 10:
        {
            int first = ReadInt("Enter first index: ");
            int second = ReadInt("Enter second index: ");
            session.Swap(first, second);
            break;
        }

        case 11:
            session.Sort();
            break;

        case 12:
            session.Reverse();
            break;

        case 13:
            session.CheckStatus();
            break;

        case 14:
            cout << "Exiting Library Management System.\n";
            break;

        default:
            cout << "Invalid choice. Enter 1 to 14.\n";
        }

    } while (choice != 14);

    return 0;
}

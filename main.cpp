
#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include "classes/DoublyLinkedList.h"
using namespace std;

int ReadInt(string prompt)
{
    int value;

    while (true)
    {
        cout << prompt;

        if (cin >> value)
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }

        if (cin.eof())
            exit(0);

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Invalid input. Enter a valid number.\n";
    }
}

string ReadTitle()
{
    string title;

    while (true)
    {
        cout << "Enter Book Title: ";
        getline(cin, title);

        if (cin.eof())
            exit(0);

        if (!title.empty())
            return title;

        cout << "Title cannot be empty.\n";
    }
}

BookNode* CreateBook(DoublyLinkedList& session)
{
    int id = ReadInt("Enter Book ID: ");

    if (session.Contains(id))
    {
        cout << "Book ID already exists.\n";
        return nullptr;
    }

    string title = ReadTitle();

    return new BookNode(id, title);
}

void ShowMenu()
{
    cout << "\n====================================\n";
    cout << "       LIBRARY MANAGEMENT SYSTEM\n";
    cout << "====================================\n";
    cout << "1. Display Current Book\n";
    cout << "2. Move to Next Book\n";
    cout << "3. Move to Previous Book\n";
    cout << "4. Insert Book at the End\n";
    cout << "5. Insert Book After Current Book\n";
    cout << "6. Remove Current Book\n";
    cout << "7. Display Session from First to Last\n";
    cout << "8. Display Session from Last to First\n";
    cout << "9. Exit\n";
    cout << "====================================\n";
}

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
            cout << "Exiting Library Management System.\n";
            break;

        default:
            cout << "Invalid choice. Enter 1 to 9.\n";
        }

    } while (choice != 9);

    return 0;
}

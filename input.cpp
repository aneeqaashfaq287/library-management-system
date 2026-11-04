
#include "../Header Files/input.h"
#include <iostream>
#include <limits>
#include <cstdlib>
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


#pragma once
#include <string>
using namespace std;

struct BookNode
{
    int bookID;
    string title;
    BookNode* left;
    BookNode* right;

    BookNode(int id, string name)
    {
        bookID = id;
        title = name;
        left = nullptr;
        right = nullptr;
    }
};

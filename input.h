
#ifndef INPUT_H
#define INPUT_H

#include <string>
#include "doubly_linked_list.h"

int ReadInt(std::string prompt);
std::string ReadTitle();
BookNode* CreateBook(DoublyLinkedList& session);

#endif

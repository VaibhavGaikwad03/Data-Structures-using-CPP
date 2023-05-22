#ifndef HEADER_NODE
#define HEADER_NODE

#include <iostream>
#include "Server_Header_Linked_List.h"
using std::ostream;

class LinkedList;

class Node
{
    int m_iData;
    Node *m_pNext;
    Node *m_pPrev;

public:
    Node();
    ~Node();

    friend class LinkedList;
    friend ostream &operator<<(ostream &, LinkedList &);
};

#endif // HEADER_NODE
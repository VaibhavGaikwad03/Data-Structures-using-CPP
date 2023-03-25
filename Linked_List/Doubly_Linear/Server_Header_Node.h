#ifndef SERVERNODE_H
#define SERVERNODE_H

#include <iostream>
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

#endif // SERVERNODE_H
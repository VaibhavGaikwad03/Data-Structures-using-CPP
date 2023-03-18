#ifndef SERVERNODE_H
#define SERVERNODE_H

#include <iostream>
using std::ostream;

class Queue;

class Node
{
    int m_iData;
    Node *m_pNext;

public:
    Node();
    ~Node();

    friend class Queue;
    friend ostream &operator<<(ostream &, Queue &);
};

#endif // SERVERNODE_H
#ifndef SERVERNODE_H
#define SERVERNODE_H

#include <iostream>
using std::ostream;

class stack;

class node
{
    int m_iData;
    node *m_pNext;

public:
    node();
    ~node();

    friend class stack;
    friend ostream &operator<<(ostream &, stack &);
};

#endif // SERVERNODE_H
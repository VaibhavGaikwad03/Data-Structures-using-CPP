#ifndef SERVERSTACK_H
#define SERVERSTACK_H

#include "Server_Node_Heder.h"

class stack
{
    node *m_pFirst;
    int m_iCount;

public:
    stack();
    ~stack();
    void push(int iNo);
    int pop();
    bool is_full();
    bool is_empty();
    int count_nodes();
    void display();
    friend ostream& operator<<(ostream &, stack &);
};

#endif //SERVERSTACK_H
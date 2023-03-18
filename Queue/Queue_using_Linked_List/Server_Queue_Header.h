#ifndef SERVERQUEUE_H
#define SERVERQUEUE_H

#include "Server_Node_Header.h"

class Queue
{
    Node *m_pHead;
    int m_iCount;

public:
    Queue();
    ~Queue();
    void display();
    int count_nodes();
    bool is_queue_full();
    bool is_queue_empty();
    void enqueu(int);
    int dequeue();

    friend ostream &operator<<(ostream &, Queue &);
};

#endif // SERVERQUEUE_H
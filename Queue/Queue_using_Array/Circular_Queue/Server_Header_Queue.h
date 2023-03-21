#ifndef SERVERQUEUE_H
#define SERVERQUEUE_H

#include <iostream>
using std::ostream;
#define MAX 10

class Queue;
ostream &operator<<(ostream &out, Queue &refObj);

class Queue
{
    int m_iRear;
    int m_iFront;
    int m_Queue[MAX];

public:
    Queue();
    ~Queue();
    void display();
    int count_nodes();
    bool is_queue_full();
    bool is_queue_empty();
    void enqueue(int iNo);
    int dequeue();

    friend ostream &operator<<(ostream &out, Queue &refObj);
};

#endif // SERVERQUEUE_H
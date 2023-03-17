#ifndef SERVERHEADER_H
#define SERVERHEADER_H
#include <cstring>
#define MAX 10
using std::ostream;

class Stack
{
    int m_iTop;
    int m_Stack[MAX];
public:
    Stack();
    ~Stack();
    int count_nodes();
    void display();
    bool is_full();
    bool is_empty();
    void push(int);
    int pop();
    friend ostream &operator<<(ostream &, Stack &);
};

#endif //SERVERHEADER_H
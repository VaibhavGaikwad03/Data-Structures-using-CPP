#include <iostream>
#include "Server_Header.h"
using std::cout;
using std::ostream;

Stack::Stack()
{
    m_iTop = -1;
    memset(m_Stack, 0, sizeof(int) * MAX);
}

Stack::~Stack()
{
    m_iTop = 0;
    memset(m_Stack, 0, sizeof(int) * MAX);
}

void Stack::display()
{
    if (is_empty())
        return;

    cout << "\nData from the stack is : \n";
    for (int i = m_iTop; i >= 0; i--)
        cout << "|" << m_Stack[i] << "|\n";
}

int Stack::count_nodes()
{
    return m_iTop + 1;
}

bool Stack::is_full()
{
    if (m_iTop == MAX-1)
        return true;
    return false;
}

bool Stack::is_empty()
{
    if (m_iTop == -1)
        return true;
    return false;
}

void Stack::push(int iNo)
{
    if (is_full())
        return;

    m_Stack[++m_iTop] = iNo;
}

int Stack::pop()
{
    if (is_empty())
        return -1;

    return m_Stack[m_iTop--];
}

ostream & operator << (ostream &out, Stack &refObj)
{
    if (refObj.is_empty())
        return out;

    for (int i = refObj.m_iTop; i >= 0; i--)
        out << "|" << refObj.m_Stack[i] << "|\n";
    return out;
}
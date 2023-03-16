#include <iostream>
#include "Server_Node_Heder.h"
#include "Server_Stack_Header.h"
using std::cout;
#define MAX 10

node::node()
{
    m_iData = 0;
    m_pNext = NULL;
}

node::~node()
{
    m_iData = 0;

    if(m_pNext != NULL)
    {
        delete m_pNext;
        m_pNext = NULL;
    }
}

stack::stack()
{
    m_pFirst = NULL;
    m_iCount = 0;
}

stack::~stack()
{
    if(m_pFirst != NULL)
    {
        delete m_pFirst;
        m_pFirst = NULL;
    }
}

bool stack::is_full()
{
    if(m_iCount == MAX)
        return true;
    return false;
}

bool stack::is_empty()
{
    if(m_iCount == 0)
        return true;
    return false;
}

int stack::count_nodes()
{
    return m_iCount;
}

void stack::display()
{
    node *pTemp = m_pFirst;

    if(m_pFirst == NULL)
    {
        cout << "\nStack is empty\n";
        return;
    }

    cout << "\nData from the stack : \n";

    while(pTemp != NULL)
    {
        cout << "|" << pTemp->m_iData << "|\n";
        pTemp = pTemp->m_pNext;
    }
}

void stack::push(int iNo)
{
    node *pNewNode = NULL;

    if(is_full())
    {
        cout << "\nStack overflow\n";
        return;
    }

    pNewNode = new node;
    if(pNewNode == NULL)
        return;

    pNewNode->m_iData = iNo;

    pNewNode->m_pNext = m_pFirst;
    m_pFirst = pNewNode;
    m_iCount++;
}

int stack::pop()
{
    node *pTemp = NULL;
    int iPopData = 0;

    if(is_empty())
        return -1;

    pTemp = m_pFirst;
    iPopData = pTemp->m_iData;
    m_pFirst = m_pFirst->m_pNext;
    pTemp->m_pNext = NULL;
    delete pTemp;
    pTemp = NULL;
    m_iCount--;
    return iPopData;
}

ostream & operator << (ostream &out, stack &obj)
{
    node *pTemp = obj.m_pFirst;

    if(obj.m_pFirst == NULL)
        return out;

    while(pTemp != NULL)
    {
        out << "|" << pTemp->m_iData << "|\n";
        pTemp = pTemp->m_pNext;
    }
    return out;
}
#include <iostream>
#include "Server_Node_Header.h"
#include "Server_Queue_Header.h"
using std::cout;
using std::endl;
#define MAX 5

Node::Node()
{
    m_iData = 0;
    m_pNext = NULL;
}

Node::~Node()
{
    m_iData = 0;

    if (m_pNext != NULL)
    {
        delete m_pNext;
        m_pNext = NULL;
    }
}

Queue::Queue()
{
    m_pHead = NULL;
    m_iCount = 0;
}

Queue::~Queue()
{
    m_iCount = 0;

    if (m_pHead != NULL)
    {
        delete m_pHead;
        m_pHead = NULL;
    }
}

void Queue::display()
{
    Node *pTemp = m_pHead;

    if (m_pHead == NULL)
        return;

    cout << "\nData from the queue : \n";
    while (pTemp != NULL)
    {
        cout << "<-|" << pTemp->m_iData << "|";
        pTemp = pTemp->m_pNext;
    }
    cout << endl;
}

int Queue::count_nodes()
{
    return m_iCount;
}

bool Queue::is_queue_full()
{
    if (m_iCount == MAX)
        return true;
    return false;
}

bool Queue::is_queue_empty()
{
    if (m_iCount == 0)
        return true;
    return false;
}

void Queue::enqueu(int iNo)
{
    Node *pTemp = NULL;
    Node *pNewNode = NULL;

    pNewNode = new Node;

    if (pNewNode == NULL)
        return;

    if (is_queue_full())
    {
        cout << "\nQueue is full\n";
        return;
    }

    pNewNode->m_iData = iNo;
    pNewNode->m_pNext = NULL;

    if (m_pHead == NULL)
    {
        m_pHead = pNewNode;
        pNewNode = NULL;
        m_iCount++;
        return;
    }

    pTemp = m_pHead;

    while (pTemp->m_pNext != NULL)
        pTemp = pTemp->m_pNext;

    pTemp->m_pNext = pNewNode;

    m_iCount++;
}

int Queue::dequeue()
{
    int iDelData = 0;
    Node *pTemp = NULL;

    if (m_pHead == NULL)
        return -1;

    iDelData = m_pHead->m_iData;
    pTemp = m_pHead;
    m_pHead = m_pHead->m_pNext;
    pTemp->m_pNext = NULL;
    delete pTemp;
    pTemp = NULL;

    m_iCount--;
    return iDelData;
}

ostream &operator<<(ostream &out, Queue &refObj)
{
    Node *pTemp = refObj.m_pHead;

    if (refObj.m_pHead == NULL)
        return out;

    while (pTemp != NULL)
    {
        out << "<-|" << pTemp->m_iData << "|";
        pTemp = pTemp->m_pNext;
    }
    return out;
}
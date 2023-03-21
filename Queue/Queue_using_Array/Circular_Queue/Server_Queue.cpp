#include <iostream>
#include <cstring>
#include "Server_Header_Queue.h"
using std::cin;
using std::cout;
using std::endl;

Queue::Queue()
{
    m_iFront = 0;
    m_iRear = -1;
    memset(m_Queue, 0, sizeof(int) * MAX);
}

Queue::~Queue()
{
    m_iFront = 0;
    m_iRear = 0;
    memset(m_Queue, 0, sizeof(int) * MAX);
}

void Queue::display()
{
    int iTempFront = m_iFront;
    int iTempRear = m_iRear;

    if (is_queue_empty())
        return;

    if (iTempFront > iTempRear)
    {
        while (iTempFront < MAX)
        {
            cout << m_Queue[iTempFront];
            iTempFront++;
        }
        iTempFront = 0;
    }
    while (iTempFront <= iTempRear)
    {
        cout << m_Queue[iTempFront];
        iTempFront++;
    }
    cout << endl;
}

int Queue::count_nodes()
{
    int iCount = 0;
    int iTempFront = m_iFront;
    int iTempRear = m_iRear;

    if (is_queue_empty())
        return iCount;

    if (iTempFront > iTempRear)
    {
        while (iTempFront < MAX)
        {
            iCount++;
            iTempFront++;
        }
        iTempFront = 0;
    }
    while (iTempFront <= iTempRear)
    {
        iCount++;
        iTempFront++;
    }
    return iCount;
}

bool Queue::is_queue_full()
{
    if ((m_iFront == 0 && m_iRear == MAX - 1) || (m_iRear == m_iFront - 1 && m_iRear != -1))
        return true;
    return false;
}

bool Queue::is_queue_empty()
{
    if (m_iRear == -1)
        return true;
    return false;
}

void Queue::enqueue(int iNo)
{
    if (is_queue_full())
    {
        cout << "Queue is full.\n";
        return;
    }

    if (m_iRear == MAX - 1)
        m_iRear = 0;
    else
        m_iRear++;
    m_Queue[m_iRear] = iNo;
}

int Queue::dequeue()
{
    int iDelData = 0;

    if (is_queue_empty())
        return -1;

    iDelData = m_Queue[m_iFront];

    if (m_iFront == m_iRear)
    {
        m_iFront = 0;
        m_iRear = -1;
    }
    else if (m_iFront == MAX - 1)
        m_iFront = 0;
    else
        m_iFront++;

    return iDelData;
}

ostream &operator<<(ostream &out, Queue &refObj)
{
    int iTempFront = refObj.m_iFront;
    int iTempRear = refObj.m_iRear;

    if (refObj.is_queue_empty())
        return out;

    if (iTempFront > iTempRear)
    {
        while (iTempFront < MAX)
        {
            out << refObj.m_Queue[iTempFront] << " ";
            iTempFront++;
        }
        iTempFront = 0;
    }
    while (iTempFront <= iTempRear)
    {
        out << refObj.m_Queue[iTempFront] << " ";
        iTempFront++;
    }
    cout << endl;

    return out;
}
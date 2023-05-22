#include <iostream>
#include "Server_Header_Linked_List.h"
using std::cout;
using std::endl;

Node::Node()
{
    m_iData = 0;
    m_pNext = NULL;
}

Node::~Node()
{
    m_iData = 0;
    m_pNext = NULL;
}

LinkedList::LinkedList()
{
    m_iCount = 0;
    m_pHead = m_pTail = NULL;
}

LinkedList::~LinkedList()
{
    Node *pTemp = NULL;

    if (m_pHead == NULL)
        return;

    pTemp = m_pHead;
    m_pTail->m_pNext = NULL;

    while (pTemp != NULL)
    {
        m_pHead = pTemp->m_pNext;
        pTemp->m_pNext = NULL;
        delete pTemp;
        pTemp = m_pHead;
    }

    m_pTail = NULL;
}

bool LinkedList::is_empty()
{
    if (m_pHead == NULL)
        return true;
    return false;
}

int LinkedList::count_nodes()
{
    return m_iCount;
}

void LinkedList::display()
{
    Node *pTemp = NULL;

    if (m_pHead == NULL)
    {
        cout << "List is empty.\n";
        return;
    }

    pTemp = m_pHead;

    cout << "Data from the linked list : \n";
    do
    {
        cout << "|" << pTemp->m_iData << "|->";
        pTemp = pTemp->m_pNext;
    } while (pTemp != m_pTail->m_pNext);

    cout << endl;
}

void LinkedList::insert_first(int iNo)
{
    Node *pNewNode = NULL;

    pNewNode = new Node;

    if (pNewNode == NULL)
        return;

    pNewNode->m_iData = iNo;

    if (m_pHead == NULL)
    {
        m_pHead = m_pTail = pNewNode;
        m_pTail->m_pNext = m_pHead;

        m_iCount++;
        return;
    }

    pNewNode->m_pNext = m_pHead;
    m_pHead = pNewNode;
    m_pTail->m_pNext = m_pHead;

    m_iCount++;
}

void LinkedList::insert_last(int iNo)
{
    Node *pNewNode = NULL;

    pNewNode = new Node;

    if (pNewNode == NULL)
        return;

    pNewNode->m_iData = iNo;

    if (m_pHead == NULL)
    {
        m_pHead = m_pTail = pNewNode;
        m_pTail->m_pNext = m_pHead;

        m_iCount++;
        return;
    }

    m_pTail->m_pNext = pNewNode;
    m_pTail = pNewNode;
    m_pTail->m_pNext = m_pHead;

    m_iCount++;
}

void LinkedList::insert_at_position(int iNo, int iPos)
{
    Node *pTemp = NULL;
    Node *pNewNode = NULL;

    if (iPos < 1 || iPos > m_iCount + 1)
    {
        cout << "Position is invalid.\n";
        return;
    }

    if (iPos == 1)
    {
        insert_first(iNo);
        return;
    }

    if (iPos == m_iCount + 1)
    {
        insert_last(iNo);
        return;
    }

    pNewNode = new Node;

    if (pNewNode == NULL)
        return;

    pNewNode->m_iData = iNo;

    pTemp = m_pHead;

    for (int i = 1; i < iPos - 1; i++)
        pTemp = pTemp->m_pNext;

    pNewNode->m_pNext = pTemp->m_pNext;
    pTemp->m_pNext = pNewNode;

    m_iCount++;
}

int LinkedList::delete_first()
{
    int iDelData = 0;

    if (m_pHead == NULL)
        return -1;

    iDelData = m_pHead->m_iData;

    if (m_pHead == m_pTail)
    {
        m_pHead->m_pNext = NULL;
        delete m_pHead;
        m_pHead = m_pTail = NULL;

        m_iCount--;

        return iDelData;
    }

    m_pHead = m_pHead->m_pNext;
    m_pTail->m_pNext->m_pNext = NULL;
    delete m_pTail->m_pNext;
    m_pTail->m_pNext = m_pHead;

    m_iCount--;

    return iDelData;
}

int LinkedList::delete_last()
{
    int iDelData = 0;
    Node *pTemp = NULL;

    if (m_pHead == NULL)
        return -1;

    iDelData = m_pTail->m_iData;

    if (m_pHead == m_pTail)
    {
        m_pHead->m_pNext = NULL;
        delete m_pHead;
        m_pHead = m_pTail = NULL;

        m_iCount--;

        return iDelData;
    }

    pTemp = m_pHead;

    while (pTemp->m_pNext != m_pTail)
        pTemp = pTemp->m_pNext;

    m_pTail->m_pNext = NULL;
    delete m_pTail;
    m_pTail = pTemp;
    m_pTail->m_pNext = m_pHead;

    m_iCount--;

    return iDelData;
}

int LinkedList::delete_at_position(int iPos)
{
    Node *pTemp1 = NULL;
    Node *pTemp2 = NULL;
    int iDelData = 0;

    if (iPos < 1 || iPos > m_iCount)
        return -1;

    if (iPos == 1)
        return delete_first();

    if (iPos == m_iCount)
        return delete_last();

    pTemp1 = m_pHead;

    for (int i = 1; i < iPos - 1; i++)
        pTemp1 = pTemp1->m_pNext;

    pTemp2 = pTemp1->m_pNext;
    iDelData = pTemp2->m_iData;
    pTemp1->m_pNext = pTemp2->m_pNext;
    pTemp2->m_pNext = NULL;
    delete pTemp2;
    pTemp1 = pTemp2 = NULL;
    m_iCount--;
    return iDelData;
}

int LinkedList::search_first_occurrence(int iKey)
{
    int iPosition = 0;
    Node *pTemp = m_pHead;

    if (pTemp == NULL)
        return 0;

    do
    {
        iPosition++;
        if (pTemp->m_iData == iKey)
            break;
        pTemp = pTemp->m_pNext;
    } while (pTemp != m_pTail->m_pNext);

    if (pTemp == m_pTail->m_pNext)
        iPosition = 0;

    return iPosition;
}

int LinkedList::search_last_occurrence(int iKey)
{
    int iPosition = 0, iLastPos = 0;
    Node *pTemp = m_pHead;

    if (pTemp == NULL)
        return 0;

    do
    {
        iPosition++;
        if (pTemp->m_iData == iKey)
            iLastPos = iPosition;
        pTemp = pTemp->m_pNext;
    } while (pTemp != m_pTail->m_pNext);

    return iLastPos;
}

int LinkedList::search_all_occurrences(int iKey)
{
    int iCountOcc = 0;
    Node *pTemp = m_pHead;

    if (pTemp == NULL)
        return 0;

    do
    {
        if (pTemp->m_iData == iKey)
            iCountOcc++;
        pTemp = pTemp->m_pNext;
    } while (pTemp != m_pTail->m_pNext);

    return iCountOcc;
}

void LinkedList::concat_list(LinkedList *pList)
{
    if (pList->m_pHead == NULL)
        return;

    if (m_pHead == NULL)
    {
        m_pHead = pList->m_pHead;
        m_pTail = pList->m_pTail;
        m_iCount += pList->m_iCount;
        pList->m_pHead = pList->m_pTail = NULL;
        return;
    }

    m_pTail->m_pNext = pList->m_pHead;
    m_pTail = pList->m_pTail;
    m_pTail->m_pNext = m_pHead;
    m_iCount += pList->m_iCount;
    pList->m_pHead = pList->m_pTail = NULL;
}

void LinkedList::concat_list(LinkedList &refList)
{
    if (refList.m_pHead == NULL)
        return;

    if (m_pHead == NULL)
    {
        m_pHead = refList.m_pHead;
        m_pTail = refList.m_pTail;
        m_iCount += refList.m_iCount;
        refList.m_pHead = refList.m_pTail = NULL;
        return;
    }

    m_pTail->m_pNext = refList.m_pHead;
    m_pTail = refList.m_pTail;
    m_pTail->m_pNext = m_pHead;
    m_iCount += refList.m_iCount;
    refList.m_pHead = refList.m_pTail = NULL;
}

void LinkedList::concat_at_position(LinkedList *pList, int iPos)
{
    Node *pTemp = NULL;

    if (iPos < 1 || iPos > m_iCount + 1)
        return;

    if (pList->m_pHead == NULL)
        return;

    if (iPos == 1)
    {
        pList->concat_list(this);
        m_pHead = pList->m_pHead;
        m_pTail = pList->m_pTail;
        m_iCount += pList->m_iCount;
        pList->m_pHead = pList->m_pTail = NULL;
        return;
    }

    if (iPos == m_iCount + 1)
    {
        concat_list(pList);
        m_iCount += pList->m_iCount;
        return;
    }

    pTemp = m_pHead;

    for (int i = 1; i < iPos - 1; i++)
        pTemp = pTemp->m_pNext;

    pList->m_pTail->m_pNext = pTemp->m_pNext;
    pTemp->m_pNext = pList->m_pHead;
    m_iCount += pList->m_iCount;
    pList->m_pHead = pList->m_pTail = NULL;
}

void LinkedList::concat_at_position(LinkedList &refList, int iPos)
{
    Node *pTemp = NULL;

    if (iPos < 1 || iPos > m_iCount + 1)
        return;

    if (refList.m_pHead == NULL)
        return;

    if (iPos == 1)
    {
        refList.concat_list(this);
        m_pHead = refList.m_pHead;
        m_pTail = refList.m_pTail;
        m_iCount += refList.m_iCount;
        refList.m_pHead = refList.m_pTail = NULL;
        return;
    }

    if (iPos == m_iCount + 1)
    {
        concat_list(refList);
        m_iCount += refList.m_iCount;
        return;
    }

    pTemp = m_pHead;

    for (int i = 1; i < iPos - 1; i++)
        pTemp = pTemp->m_pNext;

    refList.m_pTail->m_pNext = pTemp->m_pNext;
    pTemp->m_pNext = refList.m_pHead;
    m_iCount += refList.m_iCount;
    refList.m_pHead = refList.m_pTail = NULL;
}

void LinkedList::physical_reverse()
{
    Node *pPrev = m_pTail;
    Node *pCurrent = m_pHead;
    Node *pNext = NULL;

    if (m_pHead == NULL)
        return;

    do
    {
        pNext = pCurrent->m_pNext;
        pCurrent->m_pNext = pPrev;
        pPrev = pCurrent;
        pCurrent = pNext;

    } while (pCurrent != m_pHead);

    m_pHead = m_pTail;
    m_pTail = pCurrent;
}

void LinkedList::reverse_display()
{
    physical_reverse();
    display();
    physical_reverse();
}

void LinkedList::delete_all()
{
    Node *pTemp = NULL;

    if (m_pHead == NULL)
        return;

    pTemp = m_pHead;
    m_pTail->m_pNext = NULL;

    while (pTemp != NULL)
    {
        m_pHead = pTemp->m_pNext;
        pTemp->m_pNext = NULL;
        delete pTemp;
        pTemp = m_pHead;
    }

    m_pTail = NULL;
}

ostream &operator<<(ostream &out, LinkedList &refList)
{
    Node *pTemp = NULL;

    if (refList.m_pHead == NULL)
    {
        out << "List is empty.\n";
        return out;
    }

    pTemp = refList.m_pHead;

    do
    {
        out << "|" << pTemp->m_iData << "|->";
        pTemp = pTemp->m_pNext;

    } while (pTemp != refList.m_pTail->m_pNext);

    return out;
}
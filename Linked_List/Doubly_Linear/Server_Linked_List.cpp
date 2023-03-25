#include <iostream>
#include "Server_Header_Node.h"
#include "Server_Header_Linked_List.h"
using std::cout;

Node::Node()
{
    m_iData = 0;
    m_pNext = NULL;
    m_pPrev = NULL;
}

Node::~Node()
{
    m_iData = 0;

    if (m_pNext != NULL)
    {
        delete m_pNext;
        m_pNext = NULL;
    }

    if (m_pPrev != NULL)
    {
        delete m_pPrev;
        m_pPrev = NULL;
    }
}

LinkedList::LinkedList()
{
    m_pHead = NULL;
    m_iCount = 0;
}

LinkedList::~LinkedList()
{
    m_iCount = 0;

    if (m_pHead != NULL)
    {
        delete m_pHead;
        m_pHead = NULL;
    }
}

int LinkedList::count_nodes()
{
    return m_iCount;
}

void LinkedList::display()
{
    Node *pTemp = m_pHead;

    if (pTemp == NULL)
    {
        cout << "\nList is empty.\n";
        return;
    }

    cout << "\nData from the linked list : \n";
    cout << "NULL<->";

    while (pTemp != NULL)
    {
        cout << "|" << pTemp->m_iData << "|<->";
        pTemp = pTemp->m_pNext;
    }
    cout << "NULL\n";
}

bool LinkedList::is_empty()
{
    if (m_pHead == NULL)
        return true;
    return false;
}

void LinkedList::insert_first(int iNo)
{
    Node *pNewNode = NULL;

    pNewNode = new Node;

    if (pNewNode == NULL)
    {
        cout << "\nMemory allocation failed.\n";
        return;
    }

    pNewNode->m_iData = iNo;
    pNewNode->m_pPrev = NULL;

    pNewNode->m_pNext = m_pHead;
    if (m_pHead != NULL)
        m_pHead->m_pPrev = pNewNode;
    m_pHead = pNewNode;

    m_iCount++;
}

void LinkedList::insert_last(int iNo)
{
    Node *pTemp = NULL;
    Node *pNewNode = NULL;

    pNewNode = new Node;

    if (pNewNode == NULL)
    {
        cout << "\nMemory allocation failed.\n";
        return;
    }

    pNewNode->m_iData = iNo;
    pNewNode->m_pNext = NULL;

    if (m_pHead == NULL)
    {
        m_pHead = pNewNode;
        m_pHead->m_pPrev = NULL;

        m_iCount++;
        return;
    }

    pTemp = m_pHead;

    while (pTemp->m_pNext != NULL)
        pTemp = pTemp->m_pNext;
    pTemp->m_pNext = pNewNode;
    pNewNode->m_pPrev = pTemp;

    m_iCount++;
}

void LinkedList::insert_at_position(int iNo, int iPos)
{
    Node *pTemp = NULL;
    Node *pNewNode = NULL;

    if (iPos < 1 || iPos > m_iCount + 1)
    {
        cout << "\nPosition is invalid.\n";
        return;
    }

    if (iPos == 1)
    {
        insert_first(iNo);
        return;
    }

    pNewNode = new Node;

    if (pNewNode == NULL)
    {
        cout << "\nMemory allocation failed.\n";
        return;
    }

    pNewNode->m_iData = iNo;
    pNewNode->m_pNext = NULL;
    pNewNode->m_pPrev = NULL;

    pTemp = m_pHead;

    for (int i = 1; i < iPos - 1; i++)
        pTemp = pTemp->m_pNext;

    pNewNode->m_pNext = pTemp->m_pNext;
    pTemp->m_pNext = pNewNode;
    if (pNewNode->m_pNext != NULL)
        pTemp->m_pNext->m_pPrev = pNewNode;
    pNewNode->m_pPrev = pTemp;

    m_iCount++;
}

int LinkedList::delete_first()
{
    int iDelData = 0;
    Node *pTemp = NULL;

    if (m_pHead == NULL)
        return -1;

    pTemp = m_pHead;
    iDelData = pTemp->m_iData;
    m_pHead = m_pHead->m_pNext;
    if (pTemp->m_pNext != NULL)
        m_pHead->m_pPrev = NULL;
    pTemp->m_pNext = NULL;
    delete pTemp;
    pTemp = NULL;

    m_iCount--;

    return iDelData;
}

int LinkedList::delete_last()
{
    int iDelData = 0;
    Node *pTemp = NULL;

    if (m_pHead == NULL)
        return -1;

    if (m_pHead->m_pNext == NULL)
    {
        iDelData = m_pHead->m_iData;
        delete m_pHead;
        m_pHead = NULL;

        return iDelData;
    }

    pTemp = m_pHead;

    while (pTemp->m_pNext != NULL)
        pTemp = pTemp->m_pNext;

    iDelData = pTemp->m_iData;
    pTemp->m_pPrev->m_pNext = NULL;
    delete pTemp;
    pTemp = NULL;

    m_iCount--;

    return iDelData;
}

int LinkedList::delete_at_position(int iPos)
{
    int iDelData = 0;
    Node *pTemp = NULL;
    Node *pTempDelete = NULL;

    if (iPos < 1 || iPos > m_iCount)
        return -1;

    if (iPos == 1)
        return delete_first();

    pTemp = m_pHead;

    for (int i = 1; i < iPos; i++)
        pTemp = pTemp->m_pNext;

    iDelData = pTemp->m_iData;
    pTemp->m_pPrev->m_pNext = pTemp->m_pNext;
    if (pTemp->m_pNext != NULL)
        pTemp->m_pNext->m_pPrev = pTemp->m_pPrev;
    pTemp->m_pPrev = pTemp->m_pNext = NULL;
    delete pTemp;
    pTemp = NULL;

    m_iCount--;

    return iDelData;
}

int LinkedList::search_first_occurrence(int iKey)
{
    Node *pTemp = NULL;
    int iCountPos = 0;

    pTemp = m_pHead;

    while (pTemp != NULL)
    {
        iCountPos++;
        if (pTemp->m_iData == iKey)
            break;
        pTemp = pTemp->m_pNext;
    }

    if (pTemp == NULL)
        iCountPos = 0;

    return iCountPos;
}

int LinkedList::search_last_occurrence(int iKey)
{
    Node *pTemp = NULL;
    int iCountPos = 0;
    int iRetPos = 0;

    pTemp = m_pHead;

    while (pTemp != NULL)
    {
        iCountPos++;
        if (pTemp->m_iData == iKey)
            iRetPos = iCountPos;
        pTemp = pTemp->m_pNext;
    }

    return iRetPos;
}

int LinkedList::search_all_occurrences(int iKey)
{
    Node *pTemp = NULL;
    int iCountOcc = 0;

    pTemp = m_pHead;

    while (pTemp != NULL)
    {
        if (pTemp->m_iData == iKey)
            iCountOcc++;
        pTemp = pTemp->m_pNext;
    }
    return iCountOcc;
}

// void LinkedList::concat_list(LinkedList *pList)
// {
//     Node *pTemp = NULL;

//     if(pList->m_pHead == NULL)
//         return;

//     if(m_pHead == NULL)
//     {
//         m_pHead = pList->m_pHead;
//         pList->m_pHead = NULL;

//         return;
//     }

//     pTemp = m_pHead;

//     while (pTemp->m_pNext != NULL)
//         pTemp = pTemp->m_pNext;

//     pTemp->m_pNext = pList->m_pHead;
//     pList->m_pHead->m_pPrev = pTemp;
//     m_iCount += pList->m_iCount;
//     pList->m_pHead = NULL;
//     pList->m_iCount = 0;
// }

void LinkedList::concat_list(LinkedList &pList)
{
    Node *pTemp = NULL;

    if (pList.m_pHead == NULL)
        return;

    if (m_pHead == NULL)
    {
        m_pHead = pList.m_pHead;
        pList.m_pHead = NULL;

        return;
    }

    pTemp = m_pHead;

    while (pTemp->m_pNext != NULL)
        pTemp = pTemp->m_pNext;

    pTemp->m_pNext = pList.m_pHead;
    pList.m_pHead->m_pPrev = pTemp;
    m_iCount += pList.m_iCount;
    pList.m_pHead = NULL;
    pList.m_iCount = 0;
}

// void LinkedList::concat_at_position(LinkedList *pList, int iPos)
// {
//     Node *pTemp1 = NULL;
//     Node *pTemp2 = NULL;

//     if (iPos < 1 || iPos > m_iCount + 1)
//     {
//         cout << "Position is invalid\n";
//         return;
//     }

//     if (pList->m_pHead == NULL)
//         return;

//     if (iPos == 1)
//     {
//         pList->concat_list(*this);
//         m_pHead = pList->m_pHead;
//         m_iCount += pList->m_iCount;
//         pList->m_iCount = 0;
//         pList->m_pHead = NULL;
//         return;
//     }

//     pTemp1 = m_pHead;

//     for (int i = 1; i < iPos - 1; i++)
//         pTemp1 = pTemp1->m_pNext;

//     pTemp2 = pList->m_pHead;

//     while (pTemp2->m_pNext != NULL)
//         pTemp2 = pTemp2->m_pNext;

//     pTemp2->m_pNext = pTemp1->m_pNext;
//     if (pTemp1->m_pNext != NULL)
//         pTemp1->m_pNext->m_pPrev = pTemp2;
//     pTemp1->m_pNext = pList->m_pHead;
//     pList->m_pHead->m_pPrev = pTemp1;

//     m_iCount += pList->m_iCount;
//     pList->m_iCount = 0;
//     pTemp1 = pTemp2 = pList->m_pHead = NULL;
// }

void LinkedList::concat_at_position(LinkedList &pList, int iPos)
{
    Node *pTemp1 = NULL;
    Node *pTemp2 = NULL;

    if (iPos < 1 || iPos > m_iCount + 1)
    {
        cout << "Position is invalid\n";
        return;
    }

    if (pList.m_pHead == NULL)
        return;

    if (iPos == 1)
    {
        pList.concat_list(*this);
        m_pHead = pList.m_pHead;
        m_iCount += pList.m_iCount;
        pList.m_iCount = 0;
        pList.m_pHead = NULL;
        return;
    }

    pTemp1 = m_pHead;

    for (int i = 1; i < iPos - 1; i++)
        pTemp1 = pTemp1->m_pNext;

    pTemp2 = pList.m_pHead;

    while (pTemp2->m_pNext != NULL)
        pTemp2 = pTemp2->m_pNext;

    pTemp2->m_pNext = pTemp1->m_pNext;
    if (pTemp1->m_pNext != NULL)
        pTemp1->m_pNext->m_pPrev = pTemp2;
    pTemp1->m_pNext = pList.m_pHead;
    pList.m_pHead->m_pPrev = pTemp1;

    m_iCount += pList.m_iCount;
    pList.m_iCount = 0;
    pTemp1 = pTemp2 = pList.m_pHead = NULL;
}

void LinkedList::physical_reverse()
{
    Node *pNext = NULL;
    Node *pCurrent = m_pHead;

    while (pCurrent != NULL)
    {
        pNext = pCurrent->m_pNext;
        pCurrent->m_pNext = pCurrent->m_pPrev;
        pCurrent->m_pPrev = pNext;
        pCurrent = pNext;
    }

    pCurrent = m_pHead;

    while (pCurrent->m_pPrev != NULL)
        pCurrent = pCurrent->m_pPrev;

    m_pHead = pCurrent;
}

void LinkedList::reverse_display()
{
    Node *pTemp = NULL;

    if (m_pHead == NULL)
    {
        cout << "List is empty.\n";
        return;
    }

    pTemp = m_pHead;

    while (pTemp->m_pNext != NULL)
        pTemp = pTemp->m_pNext;

    cout << "NULL<->";

    while (pTemp != NULL)
    {
        cout << "|" << pTemp->m_iData << "|<->";
        pTemp = pTemp->m_pPrev;
    }
    cout << "NULL\n";
}

void LinkedList::delete_all()
{
    Node *pTemp = NULL;
    pTemp = m_pHead;

    while (pTemp != NULL)
    {
        m_pHead = m_pHead->m_pNext;
        pTemp->m_pPrev = NULL;
        pTemp->m_pNext = NULL;
        delete pTemp;
        pTemp = m_pHead;
    }
    m_pHead = pTemp = NULL;
}

ostream &operator<<(ostream &out, LinkedList &refObj)
{
    Node *pTemp = refObj.m_pHead;

    if (pTemp == NULL)
        return out;

    out << "NULL<->";

    while (pTemp != NULL)
    {
        out << "|" << pTemp->m_iData << "|<->";
        pTemp = pTemp->m_pNext;
    }

    out << "NULL";
    return out;
}
#include <iostream>
using std::cout;
using std::endl;

class LinkedList;

class Node
{
    int m_iData;
    Node *m_pNext;

public:
    Node();
    ~Node();

    friend class LinkedList;
};

class LinkedList
{
    int m_iCount;
    Node *m_pHead;

public:
    LinkedList();
    ~LinkedList();
    int count_nodes();
    void display();
    void insert_first(int iNo);
    void insert_last(int iNo);
    void insert_at_position(int iNo, int iPos);
    int delete_first();
    int delete_last();
    int delete_at_position(int iPos);
    int search_first_occurrence(int iKey);
    int search_last_occurrence(int iKey);
    int search_all_occurrences(int iKey);
    void concat_list(LinkedList *pList);
    void concat_at_position(LinkedList *pList, int iPos);
    void physical_reverse();
    void reverse_display();
    void delete_all();
};

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
    while (pTemp != NULL)
    {
        cout << "|" << pTemp->m_iData << "|->";
        pTemp = pTemp->m_pNext;
    }
    cout << "NULL\n";
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
    pNewNode->m_pNext = m_pHead;
    m_pHead = pNewNode;
    pNewNode = NULL;

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
        pNewNode = NULL;
        m_iCount++;
        return;
    }

    pTemp = m_pHead;

    while (pTemp->m_pNext != NULL)
        pTemp = pTemp->m_pNext;

    pTemp->m_pNext = pNewNode;
    pTemp = pNewNode = NULL;

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
    Node *pTemp = NULL;

    if (m_pHead == NULL)
        return -1;

    pTemp = m_pHead;
    iDelData = pTemp->m_iData;
    m_pHead = m_pHead->m_pNext;
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
        m_iCount--;
        return iDelData;
    }

    pTemp = m_pHead;

    while (pTemp->m_pNext->m_pNext != NULL)
        pTemp = pTemp->m_pNext;

    iDelData = pTemp->m_pNext->m_iData;
    delete pTemp->m_pNext;
    pTemp->m_pNext = NULL;

    m_iCount--;

    return iDelData;
}

int LinkedList::delete_at_position(int iPos)
{
    int iDelData = 0;

    if(iPos < 1 || iPos > m_iCount)
        return -1;

    if(iPos == 1)
        return delete_first();

    
}

int main(void)
{
    LinkedList list;
    list.insert_last(10);
    list.insert_last(20);
    list.insert_last(30);
    list.insert_last(40);
    list.display();
    cout << list.count_nodes() << endl;
    list.delete_last();
    list.display();
    list.delete_last();
    list.display();
    list.delete_last();
    list.display();
    list.delete_last();
    list.display();

    return 0;
}
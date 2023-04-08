#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

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
    Node *m_pTail;

public:
    LinkedList();
    ~LinkedList();
    int count_nodes();
    void display();
    bool is_empty();
    void insert_first(int iNo);
    void insert_last(int iNo);
    void insert_at_position(int iNo, int iPos);
    int delete_first();
    int delete_last();
    int delete_at_position(int iPos);
    int search_first_occurrence(int iKey);
    int search_last_occurrence(int iKey);
    int search_all_occurrences(int iKey);
    void concat_list(LinkedList &pList);
    void concat_at_position(LinkedList &pList, int iPos);
    void physical_reverse();
    void reverse_display();
    void delete_all();

    friend ostream &operator<<(ostream &, LinkedList &);
};

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
    m_iCount = 0;

    if (m_pHead != NULL)
        delete m_pHead;

    if (m_pTail != NULL)
        delete m_pTail;

    m_pHead = m_pTail = NULL;
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

int main(void)
{
    {
        LinkedList list;

        list.insert_last(40);
        list.insert_last(30);
        list.insert_last(20);
        list.insert_at_position(10, 1);
        list.display();

        list.delete_last();
        list.display();

        list.delete_last();
        list.display();

        list.delete_last();
        list.display();

        list.delete_last();
        list.display();
    }

    cout << "ok\n";

    return 0;
}
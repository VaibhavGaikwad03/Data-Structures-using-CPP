#include <iostream>
using std::cin;
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
    friend ostream &operator<<(ostream &, LinkedList &);
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
    Node *pTemp = NULL;
    Node *pTempDelete = NULL;

    if (iPos < 1 || iPos > m_iCount)
        return -1;

    if (iPos == 1)
        return delete_first();

    pTemp = m_pHead;

    for (int i = 1; i < iPos - 1; i++)
        pTemp = pTemp->m_pNext;

    pTempDelete = pTemp->m_pNext;
    iDelData = pTempDelete->m_iData;
    pTemp->m_pNext = pTempDelete->m_pNext;
    pTempDelete->m_pNext = NULL;
    delete pTempDelete;
    pTempDelete = NULL;

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
        return 0;

    return iCountPos;
}

int LinkedList::search_last_occurrence(int iKey)
{
    Node *pTemp = NULL;
    int iCountPos = 0;
    int iRetCount = 0;

    pTemp = m_pHead;

    while (pTemp != NULL)
    {
        iCountPos++;
        if (pTemp->m_iData == iKey)
            iRetCount = iCountPos;
        pTemp = pTemp->m_pNext;
    }

    return iRetCount;
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

//     if (pList->m_pHead == NULL)
//         return;

//     if (m_pHead == NULL)
//     {
//         m_pHead = pList->m_pHead;
//         pList->m_pHead = NULL;
//         return;
//     }

//     pTemp = m_pHead;

//     while (pTemp->m_pNext != NULL)
//         pTemp = pTemp->m_pNext;

//     pTemp->m_pNext = pList->m_pHead;
//     pList->m_pHead = NULL;
//     m_iCount += pList->m_iCount;
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
//     pTemp1->m_pNext = pList->m_pHead;
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
    pTemp1->m_pNext = pList.m_pHead;
    m_iCount += pList.m_iCount;
    pList.m_iCount = 0;
    pTemp1 = pTemp2 = pList.m_pHead = NULL;
}

void LinkedList::physical_reverse()
{
    Node *pNext = NULL;
    Node *pCurrent = m_pHead;
    Node *pPrev = NULL;

    while (pCurrent != NULL)
    {
        pNext = pCurrent->m_pNext;
        pCurrent->m_pNext = pPrev;
        pPrev = pCurrent;
        pCurrent = pNext;
    }
    m_pHead = pPrev;
}

void LinkedList::reverse_display()
{
    if (m_pHead == NULL)
        return;

    physical_reverse();
    display();
    physical_reverse();
}

void LinkedList::delete_all()
{
    Node *pTemp = NULL;
    pTemp = m_pHead;

    while (pTemp != NULL)
    {
        m_pHead = m_pHead->m_pNext;
        pTemp->m_pNext = NULL;
        delete pTemp;
        pTemp = m_pHead;
    }
    pTemp = NULL;
}

ostream &operator<<(ostream &out, LinkedList &refObj)
{
    Node *pTemp = refObj.m_pHead;

    if (pTemp == NULL)
        return out;

    while (pTemp != NULL)
    {
        cout << "|" << pTemp->m_iData << "|->";
        pTemp = pTemp->m_pNext;
    }

    cout << "NULL";
    return out;
}

int main()
{
    bool bFlag = false;
    LinkedList list1;
    LinkedList list2;
    int iOccurrence = 0, iPosition;
    int iChoice = 0, iChoiceIn = 0, iData = 0, iCount = 0, iPos = 0, iDeletedData = 0;

    while (1)
    {
        cout << "\nHello, Welcome...\nPlease choose from the below options : \n";
        cout << "\n1. Insert\n2. Delete\n3. Search\n4. Reverse\n5. Count\n6. Concat\n7. Exit\n>_";
        cin >> iChoice;

        switch (iChoice)
        {
        case 1:
            bFlag = true;
            while (bFlag)
            {
                cout << "\nPlease choose from the below options : \n";
                cout << "\n1. Insert First\n2. Insert Last\n3. Insert At Position\n4. Back\n>_";
                cin >> iChoice;

                switch (iChoice)
                {
                case 1:
                    cout << "\nEnter the data : \n";
                    cin >> iData;

                    list1.insert_first(iData);
                    cout << "\nData from the linked list : \n"
                         << list1 << endl;

                    break;

                case 2:
                    cout << "\nEnter the data : \n";
                    cin >> iData;

                    list1.insert_last(iData);
                    cout << "\nData from the linked list : \n"
                         << list1 << endl;

                    break;

                case 3:
                    cout << "\nEnter the Position : \n";
                    cin >> iPos;

                    iCount = list1.count_nodes();

                    if (iPos < 1 || iPos > iCount + 1)
                        cout << "\nERROR: Position is invalid.\n";
                    else
                    {
                        cout << "\nEnter the data : \n";
                        cin >> iData;

                        list1.insert_at_position(iData, iPos);
                        cout << "\nData from the linked list : \n"
                             << list1 << endl;
                    }
                    break;

                case 4:
                    bFlag = false;
                    break;

                default:
                    cout << "\nERROR: Invalid option selected.\n";
                    break;
                }
            }
            break;

        case 2:
            if (!list1.is_empty())
            {
                bFlag = true;
                while (bFlag)
                {
                    cout << "\nPlease choose from the below options : \n";
                    cout << "\n1. Delete First\n2. Delete Last\n3. Delete At Position\n4. Back\n>_";
                    cin >> iChoice;

                    switch (iChoice)
                    {
                    case 1:
                        iDeletedData = list1.delete_first();

                        if (iDeletedData == -1)
                        {
                            cout << "\nList is empty.\n";
                            continue;
                        }

                        cout << "\nDeleted data is : " << iDeletedData;
                        cout << "\nData from the linked list : \n"
                             << list1 << endl;

                        break;

                    case 2:
                        iDeletedData = list1.delete_last();

                        if (iDeletedData == -1)
                        {
                            cout << "\nList is empty.\n";
                            continue;
                        }

                        cout << "\nDeleted data is : " << iDeletedData;
                        cout << "\nData from the linked list : \n"
                             << list1 << endl;

                        break;

                    case 3:
                        cout << "\nEnter the position : \n";
                        cin >> iPos;

                        iCount = list1.count_nodes();

                        if (iPos < 1 || iPos > iCount)
                        {
                            cout << "\nERROR: Position is invalid.\n";
                            continue;
                        }

                        iDeletedData = list1.delete_at_position(iPos);

                        cout << "\nDeleted data is : " << iDeletedData;
                        cout << "\nData from the linked list : \n"
                             << list1 << endl;

                        break;

                    case 4:
                        bFlag = false;
                        break;

                    default:
                        cout << "\nERROR: Invalid option selected.\n";
                        break;
                    }
                }
            }
            else
                cout << "\nList is empty.\n";

            break;

        case 3:

            bFlag = true;
            while (bFlag)
            {
                cout << "\nPlease choose from the below options : \n";
                cout << "\n1. Search First Occurrence\n2. Search Last Occurrence\n3. Search All Occurrences\n4. Back\n>_";
                cin >> iChoice;

                switch (iChoice)
                {
                case 1:
                    cout << "\nPlease enter the data that you would like to search for :\n";
                    cin >> iData;

                    iOccurrence = list1.search_first_occurrence(iData);

                    if (iOccurrence != 0)
                        cout << "\nFirst occurrence of " << iData << " is at position " << iOccurrence << endl;
                    else
                        cout << endl
                             << iData << " not found.\n";

                    break;

                case 2:
                    cout << "\nPlease enter the data that you would like to search for :\n";
                    cin >> iData;

                    iOccurrence = list1.search_last_occurrence(iData);

                    if (iOccurrence != 0)
                        cout << "\nLast occurrence of " << iData << " is at position " << iOccurrence << endl;
                    else
                        cout << endl
                             << iData << " not found.\n";

                    break;

                case 3:
                    cout << "\nPlease enter the data that you would like to search for :\n";
                    cin >> iData;

                    iOccurrence = list1.search_all_occurrences(iData);

                    cout << endl
                         << iData << " Occurred " << iOccurrence << " times\n";

                    break;

                case 4:
                    bFlag = false;
                    break;

                default:
                    cout << "\nERROR: Invalid option selected.\n";
                    break;
                }
            }
            break;

        case 4:
            if (!list1.is_empty())
            {
                bFlag = true;
                while (bFlag)
                {
                    cout << "\nPlease choose from the below options : \n";
                    cout << "\n1. Physical Reverse\n2. Display Reverse\n3. Back\n>_";
                    cin >> iChoice;

                    switch (iChoice)
                    {
                    case 1:
                        list1.physical_reverse();
                        cout << "\nData from the linked list : \n"
                             << list1 << endl;

                        break;

                    case 2:
                        list1.reverse_display();
                        cout << "\nData from the linked list : \n"
                             << list1 << endl;

                        break;

                    case 3:
                        bFlag = false;

                        break;

                    default:
                        cout << "\nERROR: Invalid option selected.\n";

                        break;
                    }
                }
            }
            else
                cout << "\nList is empty.\n";

            break;

        case 5:
            iCount = list1.count_nodes();
            cout << "\nCount of nodes is : " << iCount << endl;

            break;

        case 6:
            bFlag = true;
            while (bFlag)
            {
                cout << "\nPlease choose from the below options :\n";
                cout << "\n1. Concat List\n2. Concat At Position\n3. Back\n>_";
                cin >> iChoice;

                switch (iChoice)
                {
                case 1:
                    bFlag = true;
                    while (bFlag)
                    {
                        cout << "\nPlease choose from the below options :\n";
                        cout << "\n1. Insert First\n2. Insert Last\n3. Insert At Position\n4. Delete At Position\n5. Concat & Back\n>_";
                        cin >> iChoice;

                        switch (iChoice)
                        {
                        case 1:
                            cout << "\nEnter the data : \n";
                            cin >> iData;

                            list2.insert_first(iData);
                            cout << "\nData from the linked list : \n"
                                 << list2 << endl;

                            break;

                        case 2:
                            cout << "\nEnter the data : \n";
                            cin >> iData;

                            list2.insert_last(iData);
                            cout << "\nData from the linked list : \n"
                                 << list2 << endl;

                            break;

                        case 3:
                            iPos = 0;
                            cout << "\nEnter the Position : \n";
                            cin >> iPos;
                            iCount = list2.count_nodes();

                            if (iPos < 1 || iPos > iCount + 1)
                                cout << "\nERROR: Position is invalid.\n";

                            else
                            {
                                cout << "\nEnter the data : \n";
                                cin >> iData;

                                list2.insert_at_position(iData, iPos);
                                cout << "\nData from the linked list : \n"
                                     << list2 << endl;
                            }
                            break;

                        case 4:
                            if (!list2.is_empty())
                            {
                                cout << "\nEnter the position : \n";
                                cin >> iPos;

                                iCount = list2.count_nodes();

                                if (iPos < 1 || iPos > iCount)
                                {
                                    cout << "\nERROR: Position is invalid.\n";
                                    continue;
                                }

                                iDeletedData = list2.delete_at_position(iPos);
                                cout << "\nDeleted data is : " << iDeletedData;
                                cout << "\nData from the linked list : \n"
                                     << list2 << endl;
                            }
                            else
                                cout << "\nList is empty.\n";

                            break;

                        case 5:
                            list1.concat_list(list2);
                            cout << "\nData from the linked list : \n"
                                 << list1 << endl;
                            bFlag = false;
                            break;

                        default:
                            cout << "\nERROR: Invalid option selected.\n";

                            break;
                        }
                    }
                    bFlag = true;

                    break;

                case 2:
                    iCount = list1.count_nodes();

                    cout << "\nEnter the Position : \n";
                    cin >> iPos;

                    if (iPos < 1 || iPos > iCount + 1)
                    {
                        cout << "\nERROR: Position is invalid.\n";
                        continue;
                    }

                    bFlag = true;
                    while (bFlag)
                    {
                        cout << "\nPlease choose from the below options :\n";
                        cout << "\n1. Insert First\n2. Insert Last\n3. Insert At Position\n4. Delete At Position\n5. Concat & Back\n>_";
                        cin >> iChoice;

                        switch (iChoice)
                        {
                        case 1:
                            cout << "\nEnter the data : \n";
                            cin >> iData;

                            list2.insert_first(iData);
                            cout << "\nData from the linked list : \n"
                                 << list2 << endl;

                            break;

                        case 2:
                            cout << "\nEnter the data : \n";
                            cin >> iData;

                            list2.insert_last(iData);
                            cout << "\nData from the linked list : \n"
                                 << list2 << endl;

                            break;

                        case 3:
                            iPos = 0;
                            cout << "\nEnter the Position : \n";
                            cin >> iPos;
                            iCount = list2.count_nodes();

                            if (iPos < 1 || iPos > iCount + 1)
                                cout << "\nERROR: Position is invalid.\n";

                            else
                            {
                                cout << "\nEnter the data : \n";
                                cin >> iData;

                                list2.insert_at_position(iData, iPos);
                                cout << "\nData from the linked list : \n"
                                     << list2 << endl;
                            }
                            break;

                        case 4:
                            if (!list2.is_empty())
                            {
                                cout << "\nEnter the position : \n";
                                cin >> iPos;

                                iCount = list2.count_nodes();

                                if (iPos < 1 || iPos > iCount)
                                {
                                    cout << "\nERROR: Position is invalid.\n";
                                    continue;
                                }

                                iDeletedData = list2.delete_at_position(iPos);
                                cout << "\nDeleted data is : " << iDeletedData;
                                cout << "\nData from the linked list : \n"
                                     << list2 << endl;
                            }
                            else
                                cout << "\nList is empty.\n";

                            break;

                        case 5:
                            list1.concat_at_position(list2, iPos);

                            cout << "\nData from the linked list : \n"
                                 << list1 << endl;
                            bFlag = false;

                            break;

                        default:
                            cout << "\nERROR: Invalid option selected.\n";

                            break;
                        }
                    }
                    bFlag = true;

                    break;

                case 3:
                    bFlag = false;

                    break;

                default:
                    cout << "\nERROR: Invalid option selected.\n";

                    break;
                }
            }
            break;

        case 7:
            list1.delete_all();
            cout << "\nThank You for using our application !\n";

            exit(0);
            break;

        default:
            cout << "\nERROR: Invalid option selected.\n";

            break;
        }
    }

    return 0;
}
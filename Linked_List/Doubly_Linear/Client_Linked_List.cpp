#include <iostream>
#include "Server_Header_Linked_List.h"
using std::cin;
using std::cout;
using std::endl;

int main(void)
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

                        cout << "\nDeleted data is : " << iDeletedData << endl;
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

                        cout << "\nDeleted data is : " << iDeletedData << endl;
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

                        cout << "\nDeleted data is : " << iDeletedData << endl;
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
                                cout << "\nDeleted data is : " << iDeletedData << endl;
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
                                cout << "\nDeleted data is : " << iDeletedData << endl;
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
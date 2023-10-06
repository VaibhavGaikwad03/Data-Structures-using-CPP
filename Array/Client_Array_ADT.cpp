#include <iostream>
#include "Server_Array_ADT.h"
using std::cin;
using std::cout;
using std::endl;

int main(void)
{
    int data;
    int index;
    int choice;
    bool flag = true;
    Array obj1, obj2;
    Array *ret = NULL;

    while (flag)
    {
        cout << "\n1. Add Element\n2. Insert Element\n3. Insert in Sorted Order\n4. Set Element\n5. Get Element\n";
        cout << "6. Merge Array\n7. Find Min\n8. Find Max\n9. Rearrange\n10. Search Element\n11. Difference\n";
        cout << "12. Intersection\n13. Union Merge\n14. Delete Element\n15. Exit\n>_";
        cin >> choice;

        switch (choice)
        {
        case 1:

            cout << "\nEnter the data: ";
            cin >> data;
            obj1.add_element(data);
            obj1.display();

            break;

        case 2:

            cout << "\nEnter valid index: ";
            cin >> index;

            if (index > obj1.length())
            {
                cout << "\nIndex is invalid!\n";
                continue;
            }

            cout << "Enter the data: ";
            cin >> data;

            obj1.insert_element(index, data);
            obj1.display();

            break;

        case 3:

            cout << "\nEnter the data: ";
            cin >> data;

            obj1.insert_sort(data);
            obj1.display();

            break;

        case 4:

            cout << "\nEnter valid index: ";
            cin >> index;

            if (index > obj1.length() - 1)
            {
                cout << "\nIndex is invalid!\n";
                continue;
            }

            cout << "\nEnter the data: ";
            cin >> data;

            obj1.set(index, data);
            obj1.display();

            break;

        case 5:

            cout << "\nEnter valid index: ";
            cin >> index;

            if (index > obj1.length() - 1)
            {
                cout << "\nIndex is invalid!\n";
                continue;
            }

            cout << "\nElement at index: " << index << " is " << obj1.get(index) << endl;

            break;

        case 6:

            while (flag)
            {
                cout << "\n1. Add Element\n2. Insert Element\n3. Insert in Sorted Oreder\n4. Delete Element\n5. Back and Merge\n>_";
                cin >> choice;

                switch (choice)
                {
                case 1:

                    cout << "\nEnter the data: ";
                    cin >> data;

                    obj2.add_element(data);
                    obj2.display();

                    break;

                case 2:

                    cout << "\nEnter valid index: ";
                    cin >> index;

                    if (index > obj2.length())
                    {
                        cout << "\nIndex is invalid!\n";
                        continue;
                    }

                    cout << "Enter the data: ";
                    cin >> data;

                    obj2.insert_element(index, data);
                    obj2.display();

                    break;

                case 3:

                    cout << "\nEnter the data: ";
                    cin >> data;

                    obj2.insert_sort(data);
                    obj2.display();

                    break;

                case 4:

                    cout << "\nEnter valid index: ";
                    cin >> index;

                    if (index > obj2.length() - 1)
                    {
                        cout << "\nIndex is invalid!\n";
                        continue;
                    }

                    obj2.delete_element(index);
                    obj2.display();

                    break;

                case 5:
                    flag = false;
                    ret = obj1.merge(obj2);
                    break;
                }
            }

            flag = true;
            obj1 = *ret;
            obj1.display();

            break;
        
        case 7:

            cout << "\nSmallest data from the array is: " << obj1.min() << endl;

            break;

        case 8:

            cout << "\nBiggest data from the array is: " << obj1.max() << endl;

            break;

        case 9:

            obj1.rearrange();
            obj1.display();

            break;

        case 10:

            cout << "\nEnter the key to search: ";
            cin >> data;

            cout << endl << data << " found at index " << obj1.search_element(data) << endl;

            break;

        case 11:

            while (flag)
            {
                cout << "\n1. Add Element\n2. Insert Element\n3. Insert in Sorted Oreder\n4. Delete Element\n5. Back and Display Difference\n>_";
                cin >> choice;

                switch (choice)
                {
                case 1:

                    cout << "\nEnter the data: ";
                    cin >> data;

                    obj2.add_element(data);
                    obj2.display();

                    break;

                case 2:

                    cout << "\nEnter valid index: ";
                    cin >> index;

                    if (index > obj2.length())
                    {
                        cout << "\nIndex is invalid!\n";
                        continue;
                    }

                    cout << "Enter the data: ";
                    cin >> data;

                    obj2.insert_element(index, data);
                    obj2.display();

                    break;

                case 3:

                    cout << "\nEnter the data: ";
                    cin >> data;

                    obj2.insert_sort(data);
                    obj2.display();

                    break;

                case 4:

                    cout << "\nEnter valid index: ";
                    cin >> index;

                    if (index > obj2.length() - 1)
                    {
                        cout << "\nIndex is invalid!\n";
                        continue;
                    }

                    obj2.delete_element(index);
                    obj2.display();

                    break;

                case 5:
                    flag = false;
                    ret = obj1.difference(obj2);
                    break;
                }
            }

            flag = true;
            ret->display();
            
            break;

        case 12:

            while (flag)
            {
                cout << "\n1. Add Element\n2. Insert Element\n3. Insert in Sorted Oreder\n4. Delete Element\n5. Back and Display Inersection\n>_";
                cin >> choice;

                switch (choice)
                {
                case 1:

                    cout << "\nEnter the data: ";
                    cin >> data;

                    obj2.add_element(data);
                    obj2.display();

                    break;

                case 2:

                    cout << "\nEnter valid index: ";
                    cin >> index;

                    if (index > obj2.length())
                    {
                        cout << "\nIndex is invalid!\n";
                        continue;
                    }

                    cout << "Enter the data: ";
                    cin >> data;

                    obj2.insert_element(index, data);
                    obj2.display();

                    break;

                case 3:

                    cout << "\nEnter the data: ";
                    cin >> data;

                    obj2.insert_sort(data);
                    obj2.display();

                    break;

                case 4:

                    cout << "\nEnter valid index: ";
                    cin >> index;

                    if (index > obj2.length() - 1)
                    {
                        cout << "\nIndex is invalid!\n";
                        continue;
                    }

                    obj2.delete_element(index);
                    obj2.display();

                    break;

                case 5:
                    flag = false;
                    ret = obj1.intersection(obj2);
                    break;
                }
            }

            flag = true;
            ret->display();

            break;

        case 13:

            while (flag)
            {
                cout << "\n1. Add Element\n2. Insert Element\n3. Insert in Sorted Oreder\n4. Delete Element\n5. Back and Display Union Merge\n>_";
                cin >> choice;

                switch (choice)
                {
                case 1:

                    cout << "\nEnter the data: ";
                    cin >> data;

                    obj2.add_element(data);
                    obj2.display();

                    break;

                case 2:

                    cout << "\nEnter valid index: ";
                    cin >> index;

                    if (index > obj2.length())
                    {
                        cout << "\nIndex is invalid!\n";
                        continue;
                    }

                    cout << "Enter the data: ";
                    cin >> data;

                    obj2.insert_element(index, data);
                    obj2.display();

                    break;

                case 3:

                    cout << "\nEnter the data: ";
                    cin >> data;

                    obj2.insert_sort(data);
                    obj2.display();

                    break;

                case 4:

                    cout << "\nEnter valid index: ";
                    cin >> index;

                    if (index > obj2.length() - 1)
                    {
                        cout << "\nIndex is invalid!\n";
                        continue;
                    }

                    obj2.delete_element(index);
                    obj2.display();

                    break;

                case 5:
                    flag = false;
                    ret = obj1.union_merge(obj2);
                    break;
                }
            }

            flag = true;
            ret->display();

            break;

        case 14:

            cout << "Enter valid index: ";
            cin >> index;

            if (index > obj1.length() - 1)
            {
                cout << "\nIndex is invalid!\n";
                continue;
            }

            obj1.delete_element(index);
            obj1.display();

            break;

        case 15:

            flag = false;

            break;

        default:
            cout << "\nInvalid Choice.\n";
        }
    }

    return 0;
}    

        
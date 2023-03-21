#include <iostream>
#include "Server_Header_Queue.h"
using std::cin;
using std::cout;
using std::endl;

int main(void)
{
    Queue queue;
    bool bFlag = true;
    int iChoice = 0, iNo = 0, iRet = 0;

    while (bFlag)
    {
        cout << "\nHello, Welcome...\nChoose from the below options :\n";
        cout << "\n1. EnQueue\n2. DeQueue\n3. Count Nodes\n4. Exit\n>_";
        cin >> iChoice;

        switch (iChoice)
        {
        case 1:

            if (queue.is_queue_full())
            {
                cout << "\nQueue is full.\n";
                continue;
            }

            cout << "\nEnter the data : \n";
            cin >> iNo;
            queue.enqueue(iNo);
            cout << "\nData from the queue is : \n"
                 << queue << endl;

            break;

        case 2:

            iRet = queue.dequeue();
            if (iRet == -1)
            {
                cout << "\nQueue is empty.\n";
                continue;
            }
            cout << "\nDeleted data is : " << iRet << endl;
            cout << "\nData from the queue is : \n"
                 << queue << endl;

            break;

        case 3:

            iRet = queue.count_nodes();

            cout << "\nCount of nodes is : " << iRet << endl;
            break;

        case 4:

            bFlag = false;
            cout << "\nThank You for using our application...\n";

            break;

        default:

            cout << "\nInvalid option selected.\n";
        }
    }
    return 0;
}
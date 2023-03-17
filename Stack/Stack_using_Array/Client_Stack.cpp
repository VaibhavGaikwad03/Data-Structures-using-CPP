#include <iostream>
#include "Server_Header.h"
using std::cin;
using std::cout;
using std::endl;

int main()
{
    Stack obj;
    bool bFlag = true;
    int iChoice = 0, iNo = 0, iRet = 0;
    
    while(bFlag)
    {
        cout << "\nHello, Welcome...\nChoose from the below options :\n";
        cout << "\n1. Push\n2. Pop\n3. Count Nodes\n4. Exit\n>_";
        cin >> iChoice;

        switch(iChoice)
        {
            case 1:
                if(obj.is_full())
                {
                    cout << "\nStack Overflow.\n";
                    continue;
                }
                cout << "\nEnter the data : \n";
                cin >> iNo;
                obj.push(iNo);
                cout << "\nData from the stack is : \n"
                     << obj << endl;

                break;

            case 2:
                iRet = obj.pop();
                if(iRet == -1)
                {
                    cout << "\nStack is empty\n";
                    continue;
                }    
                    
                cout << "\nPopped data is : " << iRet << endl;
                cout << "\nData from the stack is : \n"
                     << obj << endl;

                break;

            case 3:
                cout << "\nCount of nodes is : " << obj.count_nodes() << endl;

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
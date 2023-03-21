#include <iostream>
#include <cstring>
using std::cout;
using std::endl;
#define MAX 10

class Queue
{
    int m_iRear;
    int m_iFront;
    int m_Queue[MAX];

public:
    Queue();
    ~Queue();
    void display();
    int count_nodes();
    bool is_queue_full();
    bool is_queue_empty();
    void enqueue(int iNo);
    int dequeue();
};

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

int main(void)
{
    Queue queue;
    bool bFlag = true;
    int iChoice = 0, iNo = 0, iRet = 0;


    while(bFlag)
    {
        cout << "\nHello, Welcome...\nChoose from the below options :\n";
        cout << "\n1. EnQueue\n2. DeQueue\n3. Count Nodes\n4. Exit\n>_";
        cin >> iChoice;

        switch(iChoice)
        {
            case 1:
            
                if(queue.is_queue_full())
                    cout << "\nQueue is full.\n";
                else
                {
                    printf("Enter the data : \n");
                    scanf("%d", &iNo);
                    enQueue(Queue, &iRear, iFront, iNo);
                    display(Queue, iRear, iFront);
                }   
                break;

            case 2:

                iRet = deQueue(Queue, &iRear, &iFront);
                if(iRet != -1)
                    printf("\nDeleted data is : %d\n", iRet);
                display(Queue, iRear, iFront);
                break;

            case 3:

                iRet = countNodes(Queue, iRear, iFront);
                printf("\nCount of nodes is : %d\n", iRet);
                break;

            case 4:

                bFlag = FALSE;
                printf("\nThank You for using our application...\n");
                break;

            default:
            
                printf("\nInvalid option selected.\n");
        }
    }
    return 0;   

    return 0;
}
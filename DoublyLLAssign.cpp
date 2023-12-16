#include <iostream>
using namespace std;

struct node
{
    int data;
    node *previous;
    node *next;
};

// node creation

struct node *createNode(int data)
{
    struct node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->previous = nullptr;
    newNode->next = nullptr;
    return newNode;
}

void insertAtEnd(struct node *&head, int data)
{
    struct node *temp = head, *newNode = nullptr;

    newNode = createNode(data);

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->previous = temp;
}

void swapFirstSecond(struct node *&head)
{

    struct node *temp = head, *secondNode = nullptr;

    secondNode = temp->next;

    temp->next = secondNode->next;
    temp->previous = secondNode;

    secondNode->next = temp;
    secondNode->previous = nullptr;
    head = secondNode;
}

void swapFirstLast(struct node *&head)
{
    struct node *temp, *firstNode = nullptr, *SecondLast = nullptr;

    temp = head;
    firstNode = head;

    while (temp->next != nullptr)
    {
        SecondLast = temp;
        temp = temp->next;
    }
    temp->next = firstNode->next;
    temp->previous = firstNode->previous;

    firstNode->next->previous = temp;

    firstNode->next = nullptr;
    firstNode->previous = temp->previous;
    SecondLast->next = firstNode;

    head = temp;
}

void swapLastSecondLast(struct node *&head)
{

    struct node *temp = head, *secondLastNode = nullptr;

    while (temp->next != nullptr)
    {
        secondLastNode = temp;
        temp = temp->next;
    }

    temp->next = secondLastNode;
    temp->previous = secondLastNode->previous;

    secondLastNode->previous->next = temp;

    secondLastNode->next = nullptr;
    secondLastNode->previous = temp;
}

void print(struct node *head)
{
    cout << "List elements are:";
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

void swapM_N(node *&head, int m, int n)
{
    if (m == n)
    {

        return;
    }

    node *mthNode = head;
    for (int i = 1; i < m && mthNode; ++i)
    {
        mthNode = mthNode->next;
    }

    node *nthNode = head;
    for (int i = 1; i < n && nthNode; ++i)
    {
        nthNode = nthNode->next;
    }

    if (!mthNode || !nthNode)
    {

        cout << "Invalid M or N" << endl;
        return;
    }

    swap(mthNode->data, nthNode->data);
}

int main()
{
    struct node *head = createNode(1);

    int option;
    int data, key, m, n;

    do
    {
        cout << "\n************** MENU **************";

        cout << "\n1. Insert at end";
        cout << "\n2. Swap first and second nodes";
        cout << "\n3. Swap last and second last nodes";
        cout << "\n4. Swap first and last nodes";
        cout << "\n5. Swap M and N nodes";

        cout << "\n6. Display the linked list";
        cout << "\n7. Exit";
        cout << "\n**********************************\n";

        cout << "Enter your choice: ";
        cin >> option;

        switch (option)
        {
        case 1:
            cout << "Enter data to insert at end: ";
            cin >> data;
            insertAtEnd(head, data);
            break;

        case 2:
            swapFirstSecond(head);
            break;

        case 3:
            swapLastSecondLast(head);
            break;

        case 4:
            swapFirstLast(head);
            break;

        case 5:
            cout << "Enter M and N values to swap: ";
            cin >> m >> n;
            swapM_N(head, m, n);
            break;

        case 6:
            cout << "List elements: ";
            print(head);
            cout << endl;
            break;

        case 7:
            cout << "Exiting the program...\n";
            break;

        default:
            cout << "Invalid option. Please try again.\n";
            break;
        }

    } while (option != 7);

    return 0;
}

// Link List Assignment 2
// 1.Swap first and second node.
// 2. Swap the first and last node.
// 3. Swap the last and second last node.
// 4. Swap Mth and Nth nodes.
// 5. Divide a single link list into two singly list from the middle position of the original link list
// 6. Reverse a singly link list.

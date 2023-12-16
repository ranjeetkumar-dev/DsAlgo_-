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

void insertAtHead(struct node *&head, int data)
{

    struct node *temp = head, *newNode = nullptr;

    newNode = createNode(data);

    newNode->next = temp;
    temp->previous = newNode;
    head = newNode;
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

void insertAtSecond(struct node *&head, int data)
{

    struct node *temp = head, *newNode = nullptr, *secondNode = nullptr;

    newNode = createNode(data);

    newNode->next = temp->next;
    temp->next->previous = newNode;

    newNode->previous = temp;
    temp->next = newNode;

    // or 2nd logic using  secondNode pointer

    // secondNode = temp->next;

    // newNode->next = secondNode;
    // secondNode->previous = newNode;

    // newNode->previous = temp;
    // temp->next = newNode;
}
void insertAtSecondLast(struct node *&head, int data)
{
    struct node *temp = head, *previous = nullptr, *newNode = nullptr;

    newNode = createNode(data);

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    newNode->next = temp;
    newNode->previous = temp->previous;

    temp->previous->next = newNode;
    temp->previous = newNode;

    // or  2nd logic  with using previous pointer

    // while (temp->next != nullptr)
    // {
    //     previous = temp;
    //     temp = temp->next;
    // }

    // previous->next = newNode;
    // newNode->next = temp;
    // newNode->previous = previous;

    // temp->previous = newNode;
}
void insertAfter(struct node *&head, int data, int key)
{

    struct node *temp = head, *newNode = nullptr;

    newNode = createNode(data);

    while (key != temp->data)
    {
        temp = temp->next;
    }

    if (temp->next == nullptr)
    {
        insertAtEnd(head, data);
    }
    else
    {

        newNode->next = temp->next;
        newNode->previous = temp;

        temp->next->previous = newNode;
        temp->next = newNode;
    }

    // 2nd logic

    // while (temp->next != nullptr)
    // {

    //     if (temp->data == key)
    //     {
    //         newNode->next = temp->next;
    //         newNode->previous = temp;

    //         temp->next->previous = newNode;
    //         temp->next = newNode;
    //         break;
    //     }

    //     temp = temp->next;
    // }
    // if (temp->next == nullptr)
    // {
    //     insertAtEnd(head, data);
    // }
}
void insertBefore(struct node *&head, int key, int data)
{

    struct node *temp = head, *newNode = nullptr;

    newNode = createNode(data);

    while (temp->data != key)
    {
        temp = temp->next;
    }

    if (temp->previous == nullptr)
    {
        insertAtHead(head, data);
    }
    else
    {
        newNode->next = temp;
        newNode->previous = temp->previous;

        temp->previous->next = newNode;
        temp->previous = newNode;
    }
}
void delFirstNode(struct node *&head)
{
    struct node *temp = head, *nodeToDelete = nullptr;

    nodeToDelete = temp;

    temp = temp->next;
    temp->previous = nullptr;
    head = temp;

    nodeToDelete->next = nullptr;
    free(nodeToDelete);
}
void delLastNode(struct node *&head)
{

    struct node *temp = head, *nodeToDelete = nullptr;

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    nodeToDelete = temp;

    nodeToDelete->previous->next = nullptr;

    free(nodeToDelete);
}
void delafter(struct node *&head, int key)
{

    struct node *temp = head, *nodeToDelete = nullptr;

    while (temp->data != key)
    {
        temp = temp->next;
    }

    nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    nodeToDelete->next->previous = temp;

    nodeToDelete->next = nullptr;
    nodeToDelete->previous = nullptr;
    free(nodeToDelete);
}
void delbefore(struct node *&head, int key)
{

    struct node *temp = head, *nodeToDelete = nullptr;

    while (temp->next->data != key)
    {
        temp = temp->next;
    }

    nodeToDelete = temp;

    nodeToDelete->previous->next = nodeToDelete->next;
    nodeToDelete->next->previous = nodeToDelete->previous;

    nodeToDelete->next = nullptr;
    nodeToDelete->previous = nullptr;
    free(nodeToDelete);
}
void delSecond(struct node *&head)
{

    struct node *temp = head, *nodeToDelete = nullptr;

    nodeToDelete = temp->next;

    temp->next = nodeToDelete->next;
    nodeToDelete->next->previous = temp;

    nodeToDelete->next = nullptr;
    nodeToDelete->previous = nullptr;
    free(nodeToDelete);
}
void delSecondLast(struct node *&head)
{

    struct node *temp = head, *nodeToDelete = nullptr;

    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }

    nodeToDelete = temp;

    nodeToDelete->previous->next = nodeToDelete->next;
    nodeToDelete->next->previous = nodeToDelete->previous;

    nodeToDelete->next = nullptr;
    nodeToDelete->previous = nullptr;

    free(nodeToDelete);
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

void swapM_N(struct node *&head, int m, int n)
{

    // struct node *temp, *nodeM = nullptr, *previousOfM = nullptr, *previousOfN = nullptr, *nodeN = nullptr;

    // int cnt = 1;

    // while (temp != nullptr)
    // {
    //     if (cnt == m)
    //     {
    //         previousOfM = temp;
    //         nodeM = temp->next;
    //     }

    //     if (cnt == n)
    //     {
    //         previousOfN = temp;
    //         nodeN = temp->next;
    //     }

    //     temp = temp->next;
    //     cnt++;
    // }

    // if (nodeM == nullptr || nodeN == nullptr)
    // {
    //     // One or both of the nodes not found
    //     return;
    // }

    // previousOfM->next = nodeN;

    // previousOfN->next = nodeM;

    // struct node *ttemp = nodeM->next;

    // nodeM->next = nodeN->next;
    // nodeN->next = ttemp;

    // nodeM->previous = nodeN->previous;

    // if (head == nodeM)
    // {
    //     head = nodeN;
    // }
    // else if (head == nodeN)
    // {
    //     head = nodeM;
    // }

    // // swapFirstLast(head);
    // // swapFirstLast(head);

    struct node *temp = head, *nodeM = nullptr, *nodeN = nullptr;

    int cnt = 1;

    while (temp->next != nullptr)
    {
        if (cnt == m)
        {
            nodeM = temp;
        }

        if (cnt == n)
        {
            nodeN = temp;
        }

        cnt++;
        temp = temp->next;
    }

    if (nodeM == nullptr || nodeN == nullptr)
    {
        return;
    }
    else
    {
        nodeM->previous->next = nodeN;
        nodeN->previous = nodeM->previous;

        nodeN->next = nodeM->next;
        nodeM->next->previous = nodeN;

        nodeN->previous->next = nodeM;
        nodeN->previous = nodeM->previous;

        nodeN->next = nodeM->next;
        nodeM->next->previous = nodeN;
    }
}
struct node *reverseLL(struct node *&head) {}
void SplitInto2LL(struct node *head) {
    
}
void listSum(struct node *head)
{

    int sum = 0;
    while (head != nullptr)
    {
        sum += head->data;
        head = head->next;
    }

    cout << "sum of list:" << sum;
}

int main()
{
    struct node *head = createNode(1);

    int option;
    int data, key, m, n;

    do
    {
        cout << "\n************** MENU **************";
        cout << "\n1. Insert at head";
        cout << "\n2. Insert at end";
        cout << "\n3. Insert after a node";
        cout << "\n4. Insert before a node";
        cout << "\n5. Delete first node";
        cout << "\n6. Delete last node";
        cout << "\n7. Delete after a node";
        cout << "\n8. Delete before a node";
        cout << "\n9. Swap first and second nodes";
        cout << "\n10. Swap last and second last nodes";
        cout << "\n11. Swap first and last nodes";
        cout << "\n12. Swap M and N nodes";
        cout << "\n13. Delete second last node";
        cout << "\n14. Insert at second position";
        cout << "\n15. Insert at second last position";
        cout << "\n16. Reverse the linked list";
        cout << "\n17. Split into two linked lists";
        cout << "\n18. Sum of linked list";
        cout << "\n19. Display the linked list";
        cout << "\n20. Exit";
        cout << "\n**********************************\n";

        cout << "Enter your choice: ";
        cin >> option;

        switch (option)
        {
        case 1:
            cout << "Enter data to insert at head: ";
            cin >> data;
            insertAtHead(head, data);

            break;

        case 2:
            cout << "Enter data to insert at end: ";
            cin >> data;
            insertAtEnd(head, data);
            break;

        case 3:
            cout << "Enter data to insert: ";
            cin >> data;
            cout << "Enter key after which to insert: ";
            cin >> key;
            insertAfter(head, data, key);
            break;

        case 4:
            cout << "Enter data to insert: ";
            cin >> data;
            cout << "Enter key before which to insert: ";
            cin >> key;
            insertBefore(head, data, key);
            break;

        case 5:
            delFirstNode(head);
            break;

        case 6:
            delLastNode(head);
            break;

        case 7:
            cout << "Enter key after which to delete: ";
            cin >> key;
            delafter(head, key);
            break;

        case 8:
            cout << "Enter key before which to delete: ";
            cin >> key;
            delbefore(head, key);
            break;

        case 9:
            swapFirstSecond(head);
            break;

        case 10:
            swapLastSecondLast(head);
            break;

        case 11:
            swapFirstLast(head);
            break;

        case 12:
            cout << "Enter M and N values to swap: ";
            cin >> m >> n;
            swapM_N(head, m, n);
            break;

        case 13:
            delSecondLast(head);
            break;

        case 14:
            cout << "Enter data to insert at second position: ";
            cin >> data;
            insertAtSecond(head, data);
            break;

        case 15:
            cout << "Enter data to insert at second last position: ";
            cin >> data;
            insertAtSecondLast(head, data);
            break;

        case 16:
            reverseLL(head);
            cout << "Reversed link list elements:";
            print(head);
            break;

        case 17:
            // struct node *secondListHead = SplitInto2LL(head);
            // cout << "Second list elements: ";
            // print(secondListHead);
            SplitInto2LL(head);
            cout << endl;
            break;

        case 18:
            listSum(head);
            break;

        case 19:
            cout << "List elements: ";
            print(head);
            cout << endl;
            break;

        case 20:
            cout << "Exiting the program...\n";
            break;

        default:
            cout << "Invalid option. Please try again.\n";
            break;
        }

    } while (option != 20);

    return 0;
}
// int main()
// {
//     struct node *head = createNode(6);
//     insertAtEnd(head, 1);
//     insertAtHead(head, 5);
//     insertAtHead(head, 4);
//     insertAtSecond(head, 3);
//     insertAtSecondLast(head, 9);
//     insertAfter(head, 97, 1);
//     insertBefore(head, 1, 2);
//     print(head);
//     cout << endl;
// swapFirstLast(head);
// swapFirstLast(head);
// swapM_N(head, 2, 4);   //not working
// delFirstNode(head);
// delLastNode(head);

// delafter(head, 4);
// delbefore(head, 6);
// delSecond(head);
// delSecondLast(head);
// swapFirstSecond(head);
// swapLastSecondLast(head);
// listSum(head);

//     print(head);

//     return 0;
// }
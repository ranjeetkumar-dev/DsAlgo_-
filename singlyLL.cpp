#include <iostream>
using namespace std;
#define null 0

// node structure
struct node
{
    int data;
    struct node *next;
};

// first node create
struct node *firstNode(int data)
{
    struct node *newNode, *head = null;

    newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = null;
    // head = newNode;
    return head;
}

// insert at start
void insertAtHead(struct node *&head, int data) // here head is passing as a reference not a copy
{

    struct node *newNode, *temp = null;
    temp = head;

    newNode = (node *)malloc(sizeof(struct node));

    newNode->data = data;
    newNode->next = temp;

    // update the head
    head = newNode;
}

// insert at end
void insertAtEnd(struct node *&head, int data)
{
    struct node *temp, *newNode = null;
    temp = head;
    newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = null;

    if (head == null)
    {
        head = newNode;
        return;
    }

    while (temp->next != null)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

void insertAfter(struct node *&head, int data, int key)
{

    struct node *temp, *newNode = null;

    temp = head;
    newNode = (node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = null;

    while (temp->data != key)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}
void insertBefore(struct node *&head, int data, int key)
{

    struct node *current, *previous, *newNode = null;

    current = head;
    newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = null;
    while (current->data != key)
    {
        previous = current;
        current = current->next;
    }

    if (current == head)
    {
        newNode->next = current;
        head = newNode;
    }
    else
    {

        newNode->next = current;
        previous->next = newNode;
    }
}

void delFirstNode(struct node *&head)
{

    struct node *temp = head;
    head = head->next;
    temp->next = null;
    free(temp);
}

void delLastNode(struct node *&head)
{

    // struct node *temp = head;

    // while (temp->next->next != null)
    // {
    //     temp = temp->next;
    // }

    // struct node *nodeToDel = temp->next;

    // temp->next = null;

    // free(nodeToDel);

    // or

    struct node *temp, *ttemp = null;

    temp = head;
    while (temp->next != null)
    {
        ttemp = temp;
        temp = temp->next;
    }
    ttemp->next = null;
    free(temp);
}
void delafter(struct node *&head, int key)
{
    struct node *current, *nodeToDel = null;

    current = head;

    while (current->data != key)
    {
        current = current->next;
    }

    if (current->next == null)
    {
        delLastNode(head);
    }
    else
    {
        nodeToDel = current->next;
        current->next = nodeToDel->next;
        nodeToDel->next = null;
        free(nodeToDel);
    }
}
void delbefore(struct node *&head, int key)
{

    struct node *current, *previous = null;
    current = head;

    if (current->data == key)
    {
        delFirstNode(head);
    }
    else
    {

        while (current->next->data != key)
        {
            previous = current;

            current = current->next;
        }

        previous->next = current->next;
        current->next = null;
        free(current);
    }
}

void swapFirstSecond(struct node *&head)
{

    struct node *firstNode, *secondNode = null;

    firstNode = head;
    secondNode = firstNode->next;

    firstNode->next = secondNode->next;
    secondNode->next = firstNode;
    head = secondNode;
}
void swapLastSecondLast(struct node *&head)
{

    struct node *lastNode, *secondLastNode, *thirdLastNode = null;

    lastNode = head;

    while (lastNode->next != null)
    {
        thirdLastNode = secondLastNode;
        secondLastNode = lastNode;
        lastNode = lastNode->next;
    }

    secondLastNode->next = null;
    lastNode->next = secondLastNode;
    thirdLastNode->next = lastNode;
}
void swapFirstLast(struct node *&head)
{

    struct node *temp, *firstNode, *SecondLast = null;

    temp = head;
    firstNode = head;

    while (temp->next != null)
    {
        SecondLast = temp;
        temp = temp->next;
    }

    SecondLast->next = firstNode;
    temp->next = firstNode->next;
    firstNode->next = null;
    head = temp;
}
void swapM_N(struct node *&head, int m, int n)
{

    if (m == n)
    {
        return;
    }

    struct node *temp, *nodeM = null, *previousOfM = null, *previousOfN = null, *nodeN = null;

    temp = head;
    int cnt = 1;

    while (temp != null)
    {
        if (cnt == m)
        {
            previousOfM = temp;
            nodeM = temp->next;
        }

        if (cnt == n)
        {
            previousOfN = temp;
            nodeN = temp->next;
        }

        temp = temp->next;
        cnt++;
    }

    if (nodeM == nullptr || nodeN == nullptr)
    {
        // One or both of the nodes not found
        return;
    }

    previousOfM->next = nodeN;
    previousOfN->next = nodeM;

    struct node *ttemp = nodeM->next;

    nodeM->next = nodeN->next;
    nodeN->next = ttemp;

    if (head == nodeM)
    {
        head = nodeN;
    }
    else if (head == nodeN)
    {
        head = nodeM;
    }
}

// void swapM_N(struct node *&head, int m, int n)
// {
//     if (m == n)
//     {
//         // No need to swap if m and n are the same
//         return;
//     }

//     struct node *temp = head, *nodeM = nullptr, *previousOfM = nullptr, *nodeN = nullptr, *previousOfN = nullptr;

//     int cnt = 1;

//     while (temp != nullptr)
//     {
//         if (cnt == m)
//         {
//             previousOfM = temp;
//             nodeM = temp->next; // nodeM is the node to be moved
//         }

//         if (cnt == n)
//         {
//             previousOfN = temp;
//             nodeN = temp->next; // nodeN is the node to be moved
//         }

//         temp = temp->next;
//         cnt++;
//     }

//     if (nodeM == nullptr || nodeN == nullptr)
//     {
//         // One or both of the nodes not found
//         return;
//     }

//     // Adjust the next pointers to swap the nodes
//     previousOfM->next = nodeN;
//     previousOfN->next = nodeM;

//     struct node *ttemp = nodeM->next;
//     nodeM->next = nodeN->next;
//     nodeN->next = ttemp;

//     // Update the head if the head is involved in the swap
//     if (head == nodeM)
//     {
//         head = nodeN;
//     }
//     else if (head == nodeN)
//     {
//         head = nodeM;
//     }
// }

void delSecondLast(struct node *&head)
{

    // struct node *temp = head;

    // while (temp->next->next->next)
    // {
    //     temp = temp->next;
    // }

    // struct node *nodeToDel = temp->next;
    // temp->next = nodeToDel->next;
    // nodeToDel->next = null;
    // free(nodeToDel);

    // or

    struct node *last, *secondLast, *thirdLast = null;

    last = head;

    while (last->next != null)
    {
        thirdLast = secondLast;
        secondLast = last;
        last = last->next;
    }

    secondLast->next = null;

    thirdLast->next = last;

    free(secondLast);
}

void insertAtSecond(struct node *&head, int data)
{

    struct node *temp, *newNode = null;
    temp = head;

    newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = null;

    newNode->next = temp->next;
    temp->next = newNode;
}
void insertAtSecondLast(struct node *&head, int data)
{

    struct node *temp, *previous, *newNode = null;

    temp = head;

    newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = null;

    while (temp->next != null)
    {
        previous = temp;
        temp = temp->next;
    }

    newNode->next = temp;
    previous->next = newNode;
}

struct node *reverseLL(struct node *&head)
{
    struct node *prev = NULL;
    struct node *current = head;
    struct node *nextNode = NULL;

    while (current != NULL)
    {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    head = prev;
    return head;
}

int MidofLL(struct node *head)
{

    struct node *temp = head;
    int cnt = 0;
    while (temp != null)
    {
        cnt++;
        temp = temp->next;
    }

    return cnt / 2;
}

void delSecond(struct node *&head)
{

    struct node *temp, *nodeToDelete = null;

    temp = head;
    nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    nodeToDelete->next = null;
    free(nodeToDelete);
}

void print(struct node *head)
{

    // cout << "List elements are:";
    while (head != null)
    {
        cout << head->data << " ";
        head = head->next;
    }

    // or

    // struct node *temp;
    // temp = head;
    // cout << "List elements are:";
    // while (temp != null)
    // {
    //     cout << temp->data << " ";
    //     temp = temp->next;
    // }
}

void SplitInto2LL(struct node *head)
{

    struct node *temp = head, *newListHead = null;

    int mid = MidofLL(head);
    int cnt = 0;

    while (temp != null)
    {

        if (cnt == mid)
        {
            newListHead = temp->next;
            temp->next = null;
        }
        temp = temp->next;
        cnt++;
    }

    // return newListHead;

    cout << "First list elements:";
    print(head);
    cout << endl;
    cout << "Second list elements:";
    print(newListHead);
}

void listSum(struct node *head)
{
    int sum = 0;
    while (head != null)
    {
        sum += head->data;
        head = head->next;
    }
    cout << "link list sum:" << sum;
}

int main()
{
    struct node *head = firstNode(1);

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
//     struct node *head = firstNode(1);
//     insertAtEnd(head, 2);
//     insertAtEnd(head, 3);
//     insertAtHead(head, 0);
//     insertAtEnd(head, 99);
//     insertAtHead(head, -1);

//     insertAtEnd(head, 87);

//     // print(head);
//     // cout << endl;
//     // delFirstNode(head);
//     // delLastNode(head);
//     // delFirstNode(head);
//     insertAfter(head, 6, -1);
//     insertBefore(head, 100, 3);

//     print(head);
//     cout << endl;
//     delafter(head, 99);

//     print(head);

//     delbefore(head, -1);
//     cout << endl;
//     print(head);
//     cout << endl;
//     // listSum(head);
//     swapFirstSecond(head);
//     cout << endl;
//     print(head);
//     // swapLastSecondLast(head);
//     // delSecondLast(head);
//     // delSecond(head);
//     // insertAtSecond(head, 5);
//     // insertAtSecondLast(head, 4);
//     // swapFirstLast(head);
//     // swapM_N(head, 1, 4);
//     cout << endl;

//     // struct node *secondListHead = SplitInto2LL(head);
//     // cout << "second list elements->";
//     // print(secondListHead);
//     // cout << endl;

//     // cout << "first list elements->";
//     // swapFirstLast(head);
//     print(head);

//     // menu

//     // int data, option;
//     // char ch;

//     // cout << "!!create first node!!\n"
//     //      << "enter node data:";
//     // cin >> data;
//     // struct node *head = firstNode(data);
//     // cout << "!!!first node created!!!\n";

//     // while (1)    // {

//     //     cout << "!!!!Menu!!!!\n1.Add node at start.\n2.Add node at end.\n3.Display list.\nEnter options:";
//     //     cin >> option;

//     //     if (option == 1)
//     //     {
//     //         cout << "Enter node data:";
//     //         cin >> data;
//     //         insertAtHead(head, data);
//     //         cout << "!!!node created successfully!!!\nDo you want to add node again: ";
//     //         cin >> ch;
//     //         while (ch == 'y' || ch == 'Y')
//     //         {
//     //             cout << "Enter node data:";
//     //             cin >> data;
//     //             insertAtHead(head, data);
//     //             cout << "!!!node created successfully!!!\nDo you want to add node again: ";
//     //             cin >> ch;
//     //         }

//     // if (ch == 'Y' || ch == 'y')
//     // {
//     //     cout << "Enter node data:";
//     //     cin >> data;
//     //     insertAtHead(head, data);
//     //     cout << "!!!node created successfully!!!\nDo you want to add node again: ";
//     //     cin >> ch;
//     // }
//     //         if (ch == 'N' || ch == 'n')
//     //         {
//     //             break;
//     //         }
//     //     }
//     // }

//     return 0;
// }
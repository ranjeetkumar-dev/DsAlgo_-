#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};

struct node *createNode(int data)
{
    struct node *newNode = (node *)malloc(sizeof(node));

    newNode->data = data;
    newNode->next = newNode;
    return newNode;
}
void insertAtHead(struct node *&head, int data)
{

    struct node *temp = head, *newNode = nullptr, *firstNode = head;

    newNode = createNode(data);

    while (temp->next != firstNode)
    {
        temp = temp->next;
    }

    newNode->next = firstNode;
    temp->next = newNode;
    head = newNode;
}

void insertAtSecond(struct node *&head, int data)
{
    struct node *temp = head, *newNode = nullptr;

    newNode = createNode(data);

    newNode->next = temp->next;
    temp->next = newNode;
}
void insertAtSecondLast(struct node *&head, int data)
{

    struct node *temp = head, *newNode = nullptr, *firstNode = head;

    newNode = createNode(data);

    while (temp->next->next != firstNode)
    {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void insertAtEnd(struct node *&head, int data)
{

    struct node *temp = head;
    struct node *first = head;
    struct node *newNode = createNode(data);

    while (temp->next != first)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
}

void insertBefore(struct node *&head, int data, int key)
{

    struct node *temp = head, *newNode = nullptr, *previous;
    newNode = createNode(data);

    while (temp->data != key)
    {
        previous = temp;
        temp = temp->next;
    }

    newNode->next = temp;
    previous->next = newNode;
}
void insertAfter(struct node *&head, int data, int key)
{

    struct node *temp = head, *newNode = nullptr, *previous;
    newNode = createNode(data);

    while (temp->data != key)
    {
        // previous = temp;
        temp = temp->next;
    }

    // newNode->next = temp;
    // previous->next = newNode;

    newNode->next = temp->next->next;
    temp->next = newNode;
}

void swapFirstLast(struct node *&head)
{

    struct node *temp = head, *first = head, *previous = nullptr;

    while (temp->next != first)
    {

        previous = temp;

        temp = temp->next;
    }

    previous->next = first;

    temp->next = first->next;
    first->next = temp;
    head = temp;
}

void print(struct node *head)
{
    struct node *temp = head;
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;

        if (head == temp)
        {
            break;
        }
    }
}

void delLast(struct node *&head)
{

    struct node *temp = head, *first = head, *previous = nullptr;

    while (temp->next != first)
    {
        previous = temp;
        temp = temp->next;
    }

    struct node *nodeToDel = temp;
    previous->next = first;

    free(nodeToDel);
}

void delFirstNode(struct node *&head)
{

    struct node *temp = head, *lastNode = head;

    struct node *nodeToDel = head;
    temp->next = nodeToDel->next;
    nodeToDel->next = nullptr;

    while (lastNode->next != head)
    {
        head = head->next;
    }

    free(nodeToDel);
    lastNode->next = temp;
    head = temp;
}
void delSecondNode(struct node *&head)
{

    struct node *temp = head, *nodeToDelete = nullptr;
    nodeToDelete = temp->next;

    temp->next = nodeToDelete->next;
    nodeToDelete->next = nullptr;
    free(nodeToDelete);
}
void delBefore(struct node *&head, int key)
{

    struct node *temp = head, *nodeToDelete = nullptr, *previous = nullptr;

    while (temp->next->data != key)
    {
        previous = temp;
        temp = temp->next;
    }

    nodeToDelete = temp;
    previous->next = nodeToDelete->next;
    nodeToDelete->next = nullptr;
    free(nodeToDelete);
}
void delSecondLast(struct node *&head)
{

    struct node *temp = head, *nodeToDelete = nullptr, *previous = nullptr, *firstNode = head;

    while (temp->next->next != firstNode)
    {
        previous = temp;
        temp = temp->next;
    }
    nodeToDelete = temp;
    previous->next = nodeToDelete->next;

    nodeToDelete->next = nullptr;
    free(nodeToDelete);
}
void swapFirstSecond(struct node *&head)
{
    struct node *temp = head, *first = head;

    while (temp != first)
    {
        temp = temp->next;
    }

    struct node *second = first->next;

    first->next = second->next;

    second->next = first;
    temp->next = second;
    head = second;
}
void swapLastSecondLast(struct node *&head)
{
    struct node *temp = head, *previous = nullptr, *firstNode = head;

    while (temp->next->next != firstNode)
    {
        previous = temp;
        temp = temp->next;
    }
    previous->next = temp->next;
    previous->next->next = temp;
    temp->next = firstNode;
}
void listSum(struct node *head)
{

    struct node *firstNode = head;
    int sum = 0;
    while (head->next != firstNode)
    {
        sum += head->data;
        head = head->next;
    }

    cout << "sum of list elements:" << sum << endl;
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
            delLast(head);
            break;

        // case 7:
        //     cout << "Enter key after which to delete: ";
        //     cin >> key;
        //     delAfter(head, key);
        //     break;

        case 8:
            cout << "Enter key before which to delete: ";
            cin >> key;
            delBefore(head, key);
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

        // case 12:
        //     cout << "Enter M and N values to swap: ";
        //     cin >> m >> n;
        //     swapM_N(head, m, n);
        //     break;

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

        // case 16:
        //     reverseLL(head);
        //     cout << "Reversed link list elements:";
        //     print(head);
        //     break;

        // case 17:
        //     // struct node *secondListHead = SplitInto2LL(head);
        //     // cout << "Second list elements: ";
        //     // print(secondListHead);
        //     SplitInto2LL(head);
        //     cout << endl;
        //     break;

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

//     struct node *head = createNode(7);
//     insertAtEnd(head, 9);
//     insertAtEnd(head, 8);
//     insertAtEnd(head, 9);
//     insertAtEnd(head, 1);
//     insertAtEnd(head, 2);
//     insertAtEnd(head, 0);
//     insertAtEnd(head, 4);
//     delLast(head);
//     print(head);
//     // delFirst(head);

//     // swapFirstSecond(head);

//     cout << endl;
//     // swapFirstLast(head);
//     // addBefore(head, 5, 1);
//     // addAfter(head, 6, 9);
//     // insertAtHead(head,6);
//     // insertAtSecond(head,8);
//     // insertAtSecondLast(head, 3);
//     // delLast(head);
//     // delSecond(head);
//     // delBefore(head,2);
//     // delSecondLast(head);
//     // listSum(head);
//     swapLastSecondLast(head);

//     print(head);

//     return 0;
// }
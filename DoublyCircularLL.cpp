#include <iostream>
using namespace std;
struct node
{
    int data;
    node *previous;
    node *next;
};

struct node *createNode(int data)
{
    struct node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = newNode;
    newNode->previous = newNode;

    return newNode;
}

void insertAtEnd(struct node *&head, int data)
{
    struct node *temp = head, *lastNode = temp->previous, *newNode = nullptr;

    newNode = createNode(data);

    lastNode->next = newNode;

    newNode->previous = lastNode;
    newNode->next = temp;

    temp->previous = newNode;
}
void insertAtHead(struct node *&head, int data)
{

    struct node *temp = head, *newNode = nullptr;

    newNode = createNode(data);

    newNode->previous = temp->previous;
    newNode->next = temp;

    temp->previous->next = newNode;
    temp->previous = newNode;

    head = newNode;

    // or

    // struct node *firstNode = head, *lastNode = firstNode->previous, *newNode = nullptr;

    // newNode = createNode(data);

    // newNode->next = firstNode;
    // newNode->previous = lastNode;

    // firstNode->previous = newNode;

    // lastNode->next = newNode;

    // head = newNode;
}

void insertAtSecond(struct node *&head, int data)
{

    struct node *firstNode = head, *newNode = nullptr;

    newNode = createNode(data);

    newNode->next = firstNode->next;
    newNode->previous = firstNode;

    firstNode->next->previous = newNode;

    firstNode->next = newNode;
}
void insertAtSecondLast(struct node *&head, int data)
{

    struct node *firstNode = head, *secondlastNode = firstNode->previous->previous, *newNode = nullptr;

    newNode = createNode(data);

    newNode->previous = secondlastNode;
    newNode->next = secondlastNode->next;

    secondlastNode->next->previous = newNode; // or  // firstNode->previous->previous = newNode;
    secondlastNode->next = newNode;
}
void insertBefore(struct node *&head, int data, int key)
{
    struct node *temp = head, *previous = nullptr, *newNode = nullptr;

    newNode = createNode(data);

    while (temp->data != key)
    {
        previous = temp;
        temp = temp->next;
    }

    previous->next = newNode;

    newNode->previous = previous;
    newNode->next = temp;
    temp->previous = newNode;
}
void insertAfter(struct node *&head, int data, int key)
{
    struct node *temp = head, *newNode = nullptr;

    newNode = createNode(data);

    while (temp->data != key)
    {
        temp = temp->next;
    }

    temp->next->previous = newNode;

    newNode->next = temp->next;
    newNode->previous = temp;

    temp->next = newNode;
}
void delLast(struct node *&head)
{
    struct node *temp = head, *nodeToDelete = temp->previous;

    nodeToDelete->previous->next = nodeToDelete->next;
    temp->previous = nodeToDelete->previous;

    nodeToDelete->next = nullptr;
    nodeToDelete->previous = nullptr;
    free(nodeToDelete);
}
void delFirst(struct node *&head)
{
    struct node *nodeToDelete = head;

    nodeToDelete->previous->next = nodeToDelete->next;
    nodeToDelete->next->previous = nodeToDelete->previous;

    head = nodeToDelete->next;

    nodeToDelete->next = nullptr;
    nodeToDelete->previous = nullptr;
    free(nodeToDelete);
}
void delSecond(struct node *&head)
{

    struct node *temp = head, *nodeToDel = temp->next;

    temp->next = nodeToDel->next;
    nodeToDel->next->previous = temp;

    nodeToDel->next = nullptr;
    nodeToDel->previous = nullptr;

    free(nodeToDel);
}
void delBefore(struct node *&head, int key)
{

    struct node *temp = head, *nodeToDel = nullptr;

    while (temp->data != key)
    {
        temp = temp->next;
    }

    nodeToDel = temp->previous;

    nodeToDel->previous->next = temp;
    temp->previous = nodeToDel->previous;

    nodeToDel->next = nullptr;
    nodeToDel->previous = nullptr;
    free(nodeToDel);
}
void delSecondLast(struct node *&head)
{

    struct node *temp = head, *nodeToDel = temp->previous->previous;

    nodeToDel->previous->next = nodeToDel->next;
    nodeToDel->next->previous = nodeToDel->previous;

    nodeToDel->next = nullptr;
    nodeToDel->previous = nullptr;
    free(nodeToDel);
}
void swapFirstLast(struct node *&head)
{
    struct node *firstNode = head, *lastNode = firstNode->previous;

    firstNode->next->previous = lastNode;

    lastNode->previous->next = firstNode;

    lastNode->next = firstNode->next;
    lastNode->previous = firstNode;

    firstNode->previous = lastNode->previous;

    firstNode->next = lastNode;

    head = lastNode;
}
void swapFirstSecond(struct node *&head)
{
    struct node *firstNode = head, *secondNode = firstNode->next, *lastNode = firstNode->previous;

    secondNode->previous = firstNode->previous;
    firstNode->previous->next = secondNode;

    firstNode->next = secondNode->next;
    firstNode->previous = secondNode;

    secondNode->next->previous = firstNode;

    secondNode->next = firstNode;

    head = secondNode;

    // or
    //  struct node *firstNode = head, *secondNode = firstNode->next, *lastNode = firstNode->previous;

    // firstNode->next = secondNode->next;
    // firstNode->previous = secondNode;

    // secondNode->next->previous = firstNode;

    // secondNode->next = firstNode;

    // secondNode->previous = lastNode;
    // lastNode->next = secondNode;

    // head = secondNode;
}
void swapLastSecondLast(struct node *&head)
{
    struct node *firstNode = head, *lastNode = firstNode->previous, *secondLastNode = lastNode->previous;

    secondLastNode->previous->next = lastNode;

    lastNode->next = secondLastNode;
    lastNode->previous = secondLastNode->previous;

    secondLastNode->next = firstNode;
    secondLastNode->previous = lastNode;
}
void listSum(struct node *head)
{

    struct node *firstNode = head;

    int sum = 0;

    do
    {
        sum += head->data;
        head = head->next;
    } while (head != firstNode);

    cout << "list sum:" << sum;
    cout << endl;
}

void print(struct node *head)
{
    // struct node *first = head, *temp = head;
    // while (temp != nullptr)
    // {
    //     cout << temp->data << " ";
    //     temp = temp->next;

    //     if (temp == first)
    //     {
    //         break;
    //     }
    // }

    if (!head)
    {
        cout << "List is empty." << endl;
        return;
    }

    cout << "Doubly Circular Linked List: ";
    node *temp = head;

    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    cout << endl;
}
int main()
{
    struct node *head = createNode(1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    insertAtEnd(head, 4);
    insertAtEnd(head, 5);
    insertAtEnd(head, 6);
    insertAtEnd(head, 7);
    insertAtHead(head, 0);
    insertAtSecond(head, 9);
    print(head);
    // insertAtSecondLast(head, 6);
    // insertBefore(head, 0, 4); // head case not implemented

    // insertAfter(head, 4, 7);

    // delLast(head);
    // delFirst(head);
    // delSecond(head);
    // delBefore(head, 4);

    // delSecondLast(head);
    // swapFirstLast(head);
    // swapFirstSecond(head);
    swapLastSecondLast(head);

    print(head);
    // listSum(head);

    return 0;
}
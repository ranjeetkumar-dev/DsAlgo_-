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

    struct node *newNode = createNode(data);
    struct node *temp = head;

    temp = temp->previous;

    temp->next = newNode;
    //temp = temp->next;

    newNode->next = temp;
    newNode->previous = temp;
}

void insertAtHead(struct node *&head, int data)
{

    struct node *temp = head->previous, *newNode = nullptr, *first = head;

    newNode = createNode(data);

    newNode->next = first;
    newNode->previous = temp;

    temp->next = newNode;
    temp->previous = newNode;

    head = newNode;
}

void delLastNode(struct node *&head)
{

    struct node *temp = head->previous, *nodeToDelete = nullptr;

    nodeToDelete = temp;
    nodeToDelete->previous->next = nodeToDelete->next;
    nodeToDelete->previous->next = nodeToDelete->next;
    nodeToDelete->next = nullptr;
    nodeToDelete->previous = nullptr;
    free(nodeToDelete);
}
void delLastNode() {}
void swapFirstSecond() {}
void swapLastSecondLast() {}
void swapFirstLast() {}

void print(struct node *head)
{

    struct node *firstNode = head;

    while (head != firstNode)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{
    struct node *head = createNode(6);
    struct node *n2 = createNode(8);
    // n2->next = head;
    // n2->previous = head;
    // head->previous=n2;

    head->next=n2;
    head->previous=n2;
    n2->previous=head;
    n2->next=head;

    // cout<<n2->previous->data;
    // cout<<head->previous->data;
    

    // insertAtEnd(head, 1);
    // insertAtEnd(head, 7);
    // insertAtEnd(head, 8);
    // insertAtEnd(head, 19);
    // insertAtEnd(head, 20);

    // insertAtHead(head, 8);
    print(head);

    return 0;
}
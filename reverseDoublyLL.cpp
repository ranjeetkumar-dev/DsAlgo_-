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

    struct node *newNode = (node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = nullptr;
    newNode->previous = nullptr;

    return newNode;
}

void insertAtEnd(struct node *&head, int data)
{
    struct node *temp = head,
                *newNode = createNode(data);

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->previous = temp;
}

void print(struct node *head)
{

    cout << "List elements are:";
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void reverseLL(struct node *&head)
{
    struct node
        *prevNode = nullptr,
        *currentNode = head,
        *nextNode = nullptr;

    while (currentNode != nullptr)
    {
        nextNode = currentNode->next;
        currentNode->next = currentNode->previous;
        currentNode->previous = nextNode;

        prevNode = currentNode;

        currentNode = nextNode;
    }
    head = prevNode;
}

int main()
{
    struct node *head = createNode(1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    insertAtEnd(head, 4);
    insertAtEnd(head, 5);
    insertAtEnd(head, 6);
    print(head);
    cout << "!!!After reverse!!!" << endl;
    reverseLL(head);
    print(head);

    return 0;
}
#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

struct node *createNode(int data)
{

    struct node *newNode = (node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = nullptr;

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
}

void reverseLL(struct node *&head)
{

    struct node *prev = nullptr, *current = head, *nextNode = nullptr;

    while (current != nullptr)
    {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    head = prev;
}

void print(struct node *head)
{
    cout << "list elements are:";

    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
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
    print(head);
    cout << "reverse:" << endl;
    reverseLL(head);
    print(head);

    return 0;
}
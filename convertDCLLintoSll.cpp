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

void convertInSLL(struct node *&head)
{
    if (head == nullptr)
    {
        return; // Nothing to convert
    }

    struct node *temp = head;

    do
    {
        temp->previous = nullptr;
        temp = temp->next;
    } while (temp != nullptr && temp != head);

    head = temp;
}

int main()
{
    struct node *head = createNode(1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    insertAtEnd(head, 4);
    insertAtEnd(head, 5);
    print(head);
    convertInSLL(head);
    // cout<<head->next->previous->data;
    print(head);

    return 0;
}
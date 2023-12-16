#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
    node *first;
};

struct node *createNode(int data)
{
    struct node *newNode = (node *)malloc(sizeof(node));

    newNode->data = data;
    newNode->next = newNode;
    newNode->first = newNode;
    return newNode;
}

void addNode(struct node *&head, int data)
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
    newNode->first = head;
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
int main()
{
    struct node *head = createNode(7);
    addNode(head, 8);
    addNode(head, 9);

    print(head);
    cout << endl;

    cout << head->next->first->data;
    cout << endl;
    cout << head->next->next->first->next->data;
    // print(head);
    cout << endl;
    cout << head->next->next->first->first->data;

    return 0;
}
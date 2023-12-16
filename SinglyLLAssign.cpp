#include <iostream>
using namespace std;
#define null 0

// node structure
struct node
{
    int data;
    struct node *next;
};

//  node create
struct node *createNode(int data)
{

    struct node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = null;

    return newNode;
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

void print(struct node *head)
{

    // cout << "List elements are:";
    while (head != null)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int MidofLL(struct node *head)
{

    struct node *temp = head;
    int cnt = 1;
    while (temp != null)
    {
        cnt++;
        temp = temp->next;
    }

    return (cnt / 2) - 1;
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

int main()
{
    struct node *head = createNode(1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    insertAtEnd(head, 4);
    insertAtEnd(head, 5);
    insertAtEnd(head, 6);
    cout << "before reverse" << endl;
    print(head);
    cout << endl;
    cout << "after reverse" << endl;
    reverseLL(head);
    print(head);
    cout << endl;
    cout << "before split" << endl;
    print(head);
    cout << endl;
    cout << "after Split" << endl;
    SplitInto2LL(head);

    return 0;
}
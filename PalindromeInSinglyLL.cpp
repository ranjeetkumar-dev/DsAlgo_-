#include <iostream>
using namespace std;
#define null 0

// node structure
struct node
{
    char data;
    struct node *next;
};

// first node create
struct node *createNode(char data)
{
    struct node *newNode = (node *)malloc(sizeof(node));

    newNode->data = data;
    newNode->next = null;

    return newNode;
}

// insert at end
void insertAtEnd(struct node *&head, char data)
{
    struct node *temp = head,
                *newNode = createNode(data);

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

void print(struct node *head)
{
    cout << "list elements:";
    while (head != null)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void reverseLL(struct node *&head)
{

    struct node *temp = head, *nextNode = null, *previousNode = null;

    while (temp != null)
    {
        nextNode = temp->next;
        temp->next = previousNode;
        previousNode = temp;
        temp = nextNode;
    }
    head = previousNode;
}

bool palindrome(struct node *head)
{
    struct node *temp = head;

    string Sbefore;
    while (temp != null)
    {
        Sbefore += temp->data;
        temp = temp->next;
    }
    // cout << Sbefore;

    string Sreverse;

    reverseLL(head);
    temp = head;

    while (temp != null)
    {
        Sreverse += temp->data;
        temp = temp->next;
    }

    if (Sbefore == Sreverse)
    {
        return true;
    }
    else
    {
        return false;
    }

    // cout << Sreverse;
}

int main()
{
    struct node *head = createNode('N');
    insertAtEnd(head, 'A');
    insertAtEnd(head, 'M');
    insertAtEnd(head, 'A');
    insertAtEnd(head, 'N');

    print(head);
    // reverseLL(head);
    // print(head);
    // cout<<palindrome(head);

    if (palindrome(head))
    {

        cout << "!!it is a palindrome!!" << endl;
    }
    else
    {

        cout << "!!not a palindrome!!" << endl;
    }

    return 0;
}
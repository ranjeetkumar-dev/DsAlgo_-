#include <iostream>
using namespace std;
#define null 0

struct node
{
    int data;
    struct node *next;
};

// first node create
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

struct node *SplitOddEvenLL(struct node *&head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return nullptr; // Not enough nodes to split
    }

    struct node *odd = head;
    struct node *even = head->next;
    struct node *evenHead = even; // Save the head of the even list

    while (even != nullptr && even->next != nullptr)
    {
        odd->next = even->next; // Connect odd to the next odd node
        odd = odd->next;        // Move odd to the next odd node

        even->next = odd->next; // Connect even to the next even node
        even = even->next;      // Move even to the next even node
    }

    odd->next = nullptr; // Set the next of the last odd node to null

    head = head; // Update the head of the odd list

    return evenHead;
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
    insertAtEnd(head, 8);
    insertAtEnd(head, 9);
    insertAtEnd(head, 10);

    print(head);

    struct node *even = SplitOddEvenLL(head);
    cout << "odd list:" << endl;
    print(head);
    cout << "even list" << endl;
    print(even);

    return 0;
}
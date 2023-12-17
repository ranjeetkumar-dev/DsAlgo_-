// stack using doubly link list

#include <iostream>
using namespace std;

int cnt = 0;

struct node
{
    int data;
    node *previous;
    node *next;
} *top = nullptr;

struct node *createNode(int data)
{

    struct node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->previous = nullptr;
    newNode->next = nullptr;

    return newNode;
}

int isEmpty()
{
    if (top == nullptr)
    {
        return 1;
    }

    return 0;
}

void push(int data)
{
    struct node *newNode = createNode(data);

    // stack full condition

    if (newNode == nullptr)
    {
        cout << "!!!stack is full can't push!!!" << endl;
        return;
    }

    if (isEmpty())
    {
        top = newNode;
        return;
    }

    top->previous = newNode;
    newNode->next = top;
    top = newNode;
    cnt++;
}

void pop()
{
    if (isEmpty())
    {
        cout << "!!Stack underflow!!" << endl;
        return;
    }

    struct node *nodeToPop = top;

    nodeToPop->next->previous = nullptr;
    top = top->next;

    nodeToPop->next = nullptr;
    free(nodeToPop);
    cnt--;
}

void print()
{
    if (isEmpty())
    {
        cout << "!!Stack is empty!!" << endl;
        return;
    }

    struct node *temp = top;

    cout << "stack elements are:";
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main()
{
    push(6);
    push(7);
    push(8);
    push(9);
    push(10);

    // pop();
    print();

    return 0;
}
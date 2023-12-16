#include <iostream>
using namespace std;

struct node
{

    int data;
    struct node *next;

} *top = nullptr;

struct node *createNode(int data)
{

    struct node *newNode = (node *)malloc(sizeof(struct node));

    newNode->data = data;
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

    struct node *temp = createNode(data);

    if (temp == nullptr)
    {
        cout << "!!!stack overflow!!!" << endl;
        return;
    }

    temp->next = top;
    top = temp;
}

void pop()
{
    if (isEmpty())
    {
        cout << "!!!stack underflow!!!" << endl;
        return;
    }

    struct node *temp = top;

    top = top->next;

    temp->next = nullptr;
    free(temp);
}

void print()
{

    struct node *temp = top;

    if (isEmpty())
    {
        cout << "!!!stack is Empty!!!" << endl;
        return;
    }

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

    push(5);
    push(6);
    push(7);
    push(8);
    push(9);
    pop();
    print();
    print();

    // push(s1, 3);
    // print(s1);
    // print(s);

    return 0;
}
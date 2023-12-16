#include <iostream>
using namespace std;
#define null 0
#define MAX 10

int count = 0;

// Creating a stack
struct stack
{
    int items[MAX];
    int top;
};

void createEmptyStack(struct stack *s)
{
    s->top = -1;
}

// Check if the stack is full
int isfull(struct stack *s)
{
    if (s->top == MAX - 1)
        return 1;
    else
        return 0;
}

// Check if the stack is empty
int isempty(struct stack *s)
{
    if (s->top == -1)
        return 1;
    else
        return 0;
}

// Add elements into stack
void push(struct stack *s, int newitem)
{
    if (isfull(s))
    {
        cout << "STACK FULL";
        cout << endl;
    }
    else
    {
        s->top++;
        s->items[s->top] = newitem;
    }
    count++;
}

// Remove element from stack
int pop(struct stack *s)
{

    int data;
    if (isempty(s))
    {
        cout << "\n STACK EMPTY \n";
    }
    else
    {
        // printf("Item popped= %d", s->items[s->top]);

        data = s->items[s->top];
        s->top--;
    }
    count--;
    // cout<<endl;

    return data;
}

// Print elements of stack
void printStack(struct stack *s)
{
    printf("Stack: ");
    for (int i = 0; i < count; i++)
    {
        cout << s->items[i] << " ";
    }
    cout << endl;
}

struct node
{
    int data;
    struct node *next;
};

// first node create
struct node *createNode(int data)
{
    struct node *newNode = nullptr;

    newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = null;

    return newNode;
}
void insertAtEnd(struct node *&head, int data)
{
    struct node *temp = head, *newNode = null;

    newNode = createNode(data);

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

    cout << "List elements are:";
    while (head != null)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

struct node *linklist(struct node *&head, struct stack *s)
{

    struct node *temp = head;

    while (!isempty(s))
    {
        insertAtEnd(temp, pop(s));
    }

    head = temp;
    return head;
}

int main()
{

    struct stack *s = (stack *)malloc(sizeof(stack));

    createEmptyStack(s);

    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 9);

    printStack(s);

    struct node *head = linklist(head, s);

    print(head);
}

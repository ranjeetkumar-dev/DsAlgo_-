#include <iostream>
using namespace std;
#define max 10

int cnt = 0;

struct stack
{
    int data[max];
    int top;
};

struct stack *createEmptyStack()
{

    struct stack *emptyStack = (stack *)malloc(sizeof(stack));
    emptyStack->top = -1;
    return emptyStack;
}

int isEmpty(struct stack *s)
{

    if (s->top == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(struct stack *s)
{
    if (s->top == max - 1)
    {
        return 1;
    }

    return 0;
}

void push(struct stack *&s, int data)
{

    if (isFull(s))
    {
        cout << "!!Stack is full can't push!!" << endl;
        return;
    }

    s->top++;

    s->data[s->top] = data;
    cnt++;
}

void pop(struct stack *&s)
{

    if (isEmpty(s))
    {
        cout << "!!!Stack underflow!!!" << endl;
        return;
    }

    s->top--;
    cnt--;
}

void print(struct stack *s)
{

    if (isEmpty(s))
    {
        cout << "stack is empty" << endl;
        return;
    }

    int topOfStack = s->top;

    cout << "stack elements are:";

    for (int i = topOfStack; i >= 0; i--)
    {
        cout << s->data[topOfStack] << " ";
        topOfStack--;
    }
    cout << endl;
}

void findMidOfStack(struct stack *s)
{

    int mid = cnt / 2;
    cout << "mid element of stack is:" << s->data[mid]
         << endl;
}

// void delMid(struct stack *&s)
// {

//     int mid = cnt / 2;

//     // for (int i = mid; i <=cnt; i++)
//     // {
//     //     s->data[mid] = s->data[mid++];
//     //    mid++;
//     // }
//     // s->top = mid;

//     while (mid < cnt)
//     {

//         s->data[mid] = s->data[mid++];
//         mid++;
//     }
//     s->top = mid;
// }

int main()
{
    struct stack *s = createEmptyStack();

    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);
    // push(s, 6);
    // pop(s);

    print(s);
    findMidOfStack(s);
    // delMid(s);
    print(s);

    return 0;
}
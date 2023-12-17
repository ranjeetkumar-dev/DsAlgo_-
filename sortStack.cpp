#include <iostream>
#include <string>
using namespace std;

#define max 10

int cnt = 0;

struct stack
{
    int data[max];
    int top;
};

void createEmptyStack(struct stack *&s)
{

    s->top = -1;
}

int isFull(struct stack *&s)
{
    if (s->top == max - 1)
    {
        return 1;
    }

    return 0;
}

int isEmpty(struct stack *&s)
{
    if (s->top == -1)
    {
        return 1;
    }

    return 0;
}

void push(struct stack *&s, int data)
{

    if (isFull(s))
    {
        cout << "!!!Stack overflow!!!" << endl;
        return;
    }

    s->top++;
    s->data[s->top] = data;
    cnt++;
}
int pop(struct stack *&s)
{

    int topItem = s->data[s->top];

    if (isEmpty(s))
    {
        cout << "!!!Stack underflow!!!" << endl;
    }
    else
    {
        s->top--;
        cnt--;
    }

    return topItem;
}

void print(struct stack *s)
{

    if (isEmpty(s))
    {
        cout << "!!Stack is Empty!!" << endl;
        return;
    }

    // print from bottom
    // cout << "Stack elements:";

    // for (int i = 0; i < cnt; i++)
    // {
    //     cout << s->data[i] << " ";
    // }
    // cout << endl;

    // print from top

    cout << "Stack elements:";

    int Stop = s->top;

    while (Stop != -1)
    {
        cout << s->data[Stop] << " ";
        Stop -= 1;
    }
    cout << endl;
}

void sortStack(struct stack *&s)
{

    struct stack *tempStack = (stack *)malloc(sizeof(stack));
    createEmptyStack(tempStack);

    while (!isEmpty(s))
    {
        int poppedFromS = pop(s);

        while (!isEmpty(tempStack) && tempStack->data[tempStack->top] < poppedFromS)
        {
            push(s, pop(tempStack));
        }
        push(tempStack, poppedFromS);
    }

    // after sorting pushing all elements of tempStack in original stack
    while (!isFull(s) && !isEmpty(tempStack))
    {
        push(s, pop(tempStack));
    }
}

int main()
{
    struct stack *s = (stack *)malloc(sizeof(struct stack));

    createEmptyStack(s);

    push(s, 3);
    push(s, 8);
    push(s, 5);
    push(s, 1);
    push(s, 6);
    push(s, 7);
    print(s);

    sortStack(s);

    cout << "after sort" << endl;

    print(s);

    return 0;
}
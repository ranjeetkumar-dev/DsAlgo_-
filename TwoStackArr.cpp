#include <iostream>
using namespace std;
#define null 0
#define max 5

int cntA = 0;
int cntB = 0;

struct stack
{
    int data[max];
    int topA, topB;
};

struct stack *createEmptyStack()
{

    struct stack *s = (stack *)malloc(sizeof(stack));
    s->topA = -1;
    s->topB = max;

    return s;
}

int isFull(struct stack *s)
{

    if (s->topA + 1 == s->topB)
    {
        return 1;
    }

    return 0;
}

int isEmptyA(struct stack *s)
{

    if (s->topA == -1)
    {
        return 1;
    }

    return 0;
}
int isEmptyB(struct stack *s)
{

    if (s->topB == max)
    {
        return 1;
    }

    return 0;
}

void pushA(struct stack *&s, int data)
{
    if (isFull(s))
    {
        cout << "!!stack is full!!" << endl;
        return;
    }

    s->topA++;
    s->data[s->topA] = data;
    cntA++;
}
void pushB(struct stack *&s, int data)
{
    if (isFull(s))
    {
        cout << "!!stack is full!!" << endl;
        return;
    }

    s->topB--;
    s->data[s->topB] = data;
    cntB++;
}
void popA(struct stack *&s)
{
    if (isEmptyA(s))
    {
        cout << "!!stack A is Empty!!" << endl;
        return;
    }
    s->topA--;
    cntA--;
}
void popB(struct stack *&s)
{
    if (isEmptyB(s))
    {
        cout << "!!stack B is Empty!!" << endl;
        return;
    }
    s->topB++;
    cntB--;
}

void printA(struct stack *s)
{

    if (isEmptyA(s))
    {
        cout << "!!stack A is empty!!";
        return;
    }

    cout << "stack A elements are:";

    // print from bottom

    // for (int i = 0; i < cntA; i++)
    // {
    //     cout << s->data[i] << " ";
    // }

    // print from top

    for (int i = s->topA; i > -1; i--)
    {
        cout << s->data[i] << " ";
    }

    cout << endl;
}
void printB(struct stack *s)
{

    if (isEmptyB(s))
    {
        cout << "!!stack B is empty!!" << endl;
        return;
    }

    // print from bottom

    // cout << "stack B elements are:";
    // for (int i = max - 1; i >= s->topB; i--)
    // {
    //     cout << s->data[i] << " ";
    // }

    // print from top

    cout << "stack B elements are:";
    for (int i = s->topB; i < max; i++)
    {
        cout << s->data[i] << " ";
    }

    cout << endl;
}

int main()
{
    struct stack *s1 = createEmptyStack();
    // popB(s1);

    // pushA(s1,1);
    pushB(s1, 7);
    pushB(s1, 8);
    pushB(s1, 9);
    // pushB(s1, 8);
    // pushB(s1, 8);
    // pushB(s1, 8);
    // popB(s1);
    pushA(s1, 9);
    pushA(s1, 1);
    // pushA(s1, 2);
    // pushA(s1, 3);
    // pushA(s1, 4);
    // pushA(s1, 2);

    printB(s1);
    printA(s1);

    // cout << isFull(s1);

    return 0;
}
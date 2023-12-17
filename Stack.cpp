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
char pop(struct stack *&s)
{

    char ch = s->data[s->top];

    if (isEmpty(s))
    {
        cout << "!!!Stack underflow!!!" << endl;
    }
    else
    {
        s->top--;
        cnt--;
    }

    return ch;
}

void print(struct stack *s)
{

    if (isEmpty(s))
    {
        cout << "!!Stack is Empty!!" << endl;
        return;
    }

    // // print from bottom
    cout << "Stack elements:";

    for (int i = 0; i < cnt; i++)
    {
        cout << s->data[i] << " ";
    }
    cout << endl;

    // print from top

    // cout << "Stack elements:";

    // int Stop = s->top;

    // while (Stop != -1)
    // {
    //     cout << s->data[Stop] << " ";
    //     Stop -= 1;
    // }
    // cout << endl;
}

int main()
{
    struct stack *s = (stack *)malloc(sizeof(struct stack));
    struct stack *s1 = (stack *)malloc(sizeof(struct stack));
    struct stack *s2 = (stack *)malloc(sizeof(struct stack));

    createEmptyStack(s);
    createEmptyStack(s1);
    createEmptyStack(s2);

    push(s, 3);
    push(s, 4);
    push(s, 5);

    push(s1, 6);
    push(s1, 7);
    push(s1, 8);
    // push(s1, 2);

    // cout<<"stack1"<<endl;
    // print(s);

    // while (!isEmpty(s))
    // {
    //     push(s1, pop(s));
    // }

    // cout<<"stack1 after pushing in  stack 2"<<endl;

    // print(s);

    // // cout<<
    // print(s1);

    //     char arr[10];

    //     cout << "enter a string:";
    //     gets(arr);

    //     char ch;
    //     int i = 0;
    //     while (arr != NULL)
    //     {
    //         ch = arr[i];
    //         cout<<ch;
    //         // push(s, ch);

    //         i++;
    //     }
    //     cout<<ch<<endl;

    //  //   print(s);
    //     // cout<<arr;

    //     // char reverse[10];

    //     // int cnt1 = 0;

    //     // while (!isEmpty(s))
    //     // {
    //     //     ch = pop(s);
    //     //     reverse[0] = ch;
    //     //     cnt++;
    //     // }

    //     // if (arr == reverse)
    //     // {
    //     //     cout << arr << " is palindrome" << endl;
    //     // }
    //     // else
    //     // {
    //     //     cout << arr << " is not a palindrome" << endl;
    //     // }

    while (!isEmpty(s) || !isEmpty(s1))
    {
        push(s2, pop(s));
        push(s2, pop(s1));
    }

    print(s2);

    return 0;
}
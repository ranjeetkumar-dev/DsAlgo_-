#include <iostream>
#include <string>
using namespace std;

#define max 10

int cnt = 0;

struct stack
{
    char data[max];
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

    // print from bottom
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

bool isPalindrome(char *arr1, char *arr2)
{

    while (*arr1 != '\0' && *arr2 != '\0')
    {
        if (*arr1 != *arr2)
        {
            return false;
        }

        arr1++;
        arr2++;
    }

    return (*arr1 == '\0' && *arr2 == '\0');
    // return true;
}

int main()
{
    struct stack *s = (stack *)malloc(sizeof(struct stack));

    createEmptyStack(s);

    char inputString[15];

    cout << "enter a string:";
    gets(inputString);

    int i = 0;
    while (inputString[i] != '\0')
    {
        push(s, inputString[i]);
        i++;
    }

    // print(s);
    i = 0;

    char reverseArr[15];
    while (!isEmpty(s))
    {
        reverseArr[i] = pop(s);
        i++;
    }

    if (isPalindrome(inputString, reverseArr))
    {
        cout << inputString << " is a palindrome" << endl;
    }
    else
    {
        cout << inputString << " is not a palindrome " << endl;
    }

    return 0;
}
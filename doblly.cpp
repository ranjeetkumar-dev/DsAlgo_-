#include <iostream>
using namespace std;

struct node
{
    int data;
    node *previous;
    node *next;
};

void swapFirstLast(struct node *&head)
{
    struct node *temp, *firstNode = nullptr, *SecondLast = nullptr;

    temp = head;
    firstNode = head;

    while (temp->next != nullptr)
    {
        SecondLast = temp;
        temp = temp->next;
    }

    firstNode->next = temp;
    firstNode->previous = temp->previous;
    temp->next = firstNode->next;
    temp->previous = firstNode->previous;
}

int main()
{

    return 0;
}
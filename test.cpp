// // // #include <iostream>
// // // using namespace std;

// // // int sum(int a,int b){
// // //     return a+b;
// // // }

// // // void check(int *ptr)
// // // {
// // //     int b = 19;
// // //     ptr = &b;

// // //     cout << "inside function address:" << ptr << endl;
// // //     cout << "inside function a:" << *ptr << endl;
// // // }

// // // int main()
// // // {
// // //     // int a = 7;
// // //     // int *ptr = &a;
// // //     // cout << a << endl;
// // //     // cout << "address of a:" << &a << endl;
// // //     // // cout<<"address of a:"<<ptr<<endl;
// // //     // // // cout<<"address of a:"<<*ptr<<endl;
// // //     // // // cout << *&ptr;

// // //     // // check(ptr);

// // //     // // cout << "after function call:" << ptr << endl;
// // //     // // cout << "after function call:" << &a << endl;

// // //     // // cout<<&a<<endl;
// // //     // cout << "before f cal adress of ptr:" << &ptr << endl;
// // //     // check(ptr);
// // //     // cout << "after f cal adress of ptr:" << &ptr << endl;
// // //     // cout << "after f cal data of ptr:" << *ptr << endl;

// // //     // int a = 9;
// // //     // int *ptr = &a;
// // //     // cout << *ptr;
// // //     // check(ptr);
// // //     // cout << *ptr<<endl;
// // //     // cout<<ptr;

// // // //    cout<< sum(5,8);
// // //     return 0;
// // // }

// // #include <iostream>

// // using namespace std;

// // // Node structure for doubly linked list
// // struct Node {
// //     int data;
// //     Node* next;
// //     Node* prev;

// //     Node(int val) : data(val), next(nullptr), prev(nullptr) {}
// // };

// // // Function to insert a node at the end of the doubly linked list
// // void insertEnd(Node*& head, int val) {
// //     Node* newNode = new Node(val);
// //     if (!head) {
// //         head = newNode;
// //     } else {
// //         Node* temp = head;
// //         while (temp->next) {
// //             temp = temp->next;
// //         }
// //         temp->next = newNode;
// //         newNode->prev = temp;
// //     }
// // }

// // // Function to print the doubly linked list
// // void printList(Node* head) {
// //     while (head) {
// //         cout << head->data << " ";
// //         head = head->next;
// //     }
// //     cout << endl;
// // }

// // // Function to swap Mth and Nth nodes in a doubly linked list
// // void swapNodes(Node*& head, int m, int n) {
// //     if (m == n) {
// //         // Nodes are the same, no need to swap
// //         return;
// //     }

// //     // Find the Mth node
// //     Node* mthNode = head;
// //     for (int i = 1; i < m && mthNode; ++i) {
// //         mthNode = mthNode->next;
// //     }

// //     // Find the Nth node
// //     Node* nthNode = head;
// //     for (int i = 1; i < n && nthNode; ++i) {
// //         nthNode = nthNode->next;
// //     }

// //     if (!mthNode || !nthNode) {
// //         // Invalid M or N
// //         cout << "Invalid M or N" << endl;
// //         return;
// //     }

// //     // Swap the data of Mth and Nth nodes
// //     swap(mthNode->data, nthNode->data);
// // }

// // int main() {
// //     Node* head = nullptr;

// //     // Insert nodes at the end of the doubly linked list
// //     insertEnd(head, 1);
// //     insertEnd(head, 2);
// //     insertEnd(head, 3);
// //     insertEnd(head, 4);
// //     insertEnd(head, 5);

// //     cout << "Original doubly linked list: ";
// //     printList(head);

// //     int m, n;
// //     cout << "Enter the positions (M and N) of nodes to swap: ";
// //     cin >> m >> n;

// //     // Swap Mth and Nth nodes
// //     swapNodes(head, m, n);

// //     cout << "Doubly linked list after swapping nodes: ";
// //     printList(head);

// //     return 0;
// // }

// // Stack implementation in C

// #include <stdio.h>
// #include <stdlib.h>

// #define MAX 10

// int count = 0;

// // Creating a stack
// struct stack
// {
//   int items[MAX];
//   int top;
// };
// typedef struct stack st;

// void createEmptyStack(st *s)
// {
//   s->top = -1;
// }

// // Check if the stack is full
// int isfull(st *s)
// {
//   if (s->top == MAX - 1)
//     return 1;
//   else
//     return 0;
// }

// // Check if the stack is empty
// int isempty(st *s)
// {
//   if (s->top == -1)
//     return 1;
//   else
//     return 0;
// }

// // Add elements into stack
// void push(st *s, int newitem)
// {
//   if (isfull(s))
//   {
//     printf("STACK FULL");
//   }
//   else
//   {
//     s->top++;
//     s->items[s->top] = newitem;
//   }
//   count++;
// }

// // Remove element from stack
// void pop(st *s)
// {
//   if (isempty(s))
//   {
//     printf("\n STACK EMPTY \n");
//   }
//   else
//   {
//     printf("Item popped= %d", s->items[s->top]);
//     s->top--;
//   }
//   count--;
//   printf("\n");
// }

// // Print elements of stack
// void printStack(st *s)
// {
//   printf("Stack: ");
//   for (int i = 0; i < count; i++)
//   {
//     printf("%d ", s->items[i]);
//   }
//   printf("\n");
// }

// // Driver code
// int main()
// {
//   int ch;
//   st *s = (st *)malloc(sizeof(st));

//   createEmptyStack(s);

//   push(s, 1);
//   push(s, 2);
//   push(s, 3);
//   push(s, 4);

//   printStack(s);

//   pop(s);

//   printf("\nAfter popping out\n");
//   printStack(s);
// }


#include <stdio.h>
#include <stdlib.h>

// Structure to create a node with data and the next pointer
struct node {
    int info;
    struct node *ptr;
}*top,*top1,*temp;

int count = 0;
// Push() operation on a  stack
void push(int data) {
     if (top == NULL)
    {
        top =(struct node *)malloc(1*sizeof(struct node));
        top->ptr = NULL;
        top->info = data;
    }
    else
    {
        temp =(struct node *)malloc(1*sizeof(struct node));
        temp->ptr = top;
        temp->info = data;
        top = temp;
    }
    count++;
    printf("Node is Inserted\n\n");
}

int pop() {
     top1 = top;
 
    if (top1 == NULL)
    {
        printf("\nStack Underflow\n");
        return -1;
    }
    else
        top1 = top1->ptr;
    int popped = top->info;
    free(top);
    top = top1;
    count--;
    return popped;
}

void display() {
    // Display the elements of the stack
    top1 = top;
 
    if (top1 == NULL)
    {
        printf("\nStack Underflow\n");
        return;
    }
    
    printf("The stack is \n");
    while (top1 != NULL)
    {
        printf("%d--->", top1->info);
        top1 = top1->ptr;
    }
    printf("NULL\n\n");

}

int main() {
    int choice, value;
    printf("\nImplementation of Stack using Linked List\n");
    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("\nEnter the value to insert: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            printf("Popped element is :%d\n", pop());
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nWrong Choice\n");
        }
    }
}


#include <iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

struct node *createNode(int data)
{

    struct node *newNode = (node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

struct node *builTree(struct node *root1)
{

    int data;
    cout << "enter the data: ";
    cin >> data;

    struct node *root = createNode(data);

    if (data == -1)
    {
        return nullptr;
    }

    cout << "enter the data for inserting in left of:" << data << endl;
    root->left = builTree(root->left);
    cout << "enter the data for inserting in right of:" << data << endl;
    root->right = builTree(root->right);

    return root;
}

void inOrder(struct node *root)
{
    if (root != nullptr)
    {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}
int sum = 0;

void sumT(struct node *root)
{

    if (root != nullptr)
    {
        sumT(root->left);
        // cout << root->data << " ";
        // sum = sum + root->data;
        sum += root->data;
        sumT(root->right);
    }

    // return sum;
}

struct node *parent(struct node *root, int data)
{

    if (root != nullptr)
    {
        inOrder(root->left);

        if (root->data == data)
        {
        }

        // cout << root->data << " ";

        inOrder(root->right);
    }
}

int main()
{

    struct node *root = nullptr;

    root = builTree(root);
    // inOrder(root);
    cout << endl;

    sumT(root);
    cout << endl;
    cout << sum;

    return 0;
}
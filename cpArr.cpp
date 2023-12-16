#include <iostream>
using namespace std;
int main()
{
    int arr[5] = {1, 2, 9, 5, 0};

    int a[5];

    cout << "elements of array:";

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << ",";
    }

    for (int i = 0; i < 5; i++)
    {
        a[i] = arr[i];
    }
    cout << endl;

    cout << "Elements of Array a:";

    for (int i = 0; i < 5; i++)
    {
        cout << a[i] << ",";
    }

    return 0;
}
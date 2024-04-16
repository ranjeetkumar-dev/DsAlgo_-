#include <iostream>
using namespace std;

int max(int arr[], int size)
{
    int maxElement = arr[0];
    for (int i = 0; i < size; i++)
    {
        // if (arr[i] > maxElement)
        // {
        //     maxElement = arr[i];
        // }

        // using inbuilt max fun

        maxElement = max(maxElement, arr[i]);
    }

    return maxElement;
}
int min(int arr[], int size)
{
    int minElement = arr[0];
    for (int i = 0; i < size; i++)
    {
        // if (arr[i] < minElement)
        // {
        //     minElement = arr[i];
        // }

        minElement = min(minElement, arr[i]);
    }

    return minElement;
}
int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "max:" << max(arr, 10) << endl
         << "min:" << min(arr, 10);

    return 0;
}
#include <iostream>
using namespace std;
void swapAlternate(int arr[], int size)
{
    int i = 0;
    while (i < size - 1)
    {
        swap(arr[i], arr[i + 1]);
        i += 2;
    }
}
void printArr(int arr[], int size)
{
    cout << "array elements: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << ",";
    }
    cout << endl;
}
int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = 10;
    cout << "!!before swap!!" << endl;
    printArr(arr, size);
    cout << "!!after swap!!" << endl;
    swapAlternate(arr, size);
    printArr(arr, size);

    return 0;
}
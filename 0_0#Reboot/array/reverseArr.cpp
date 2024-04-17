#include <iostream>
using namespace std;
void reverseArr(int arr[], int size)
{
    int start = 0;
    int end = size - 1;
    while (start <= end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
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
    cout << "!!before reverse!!" << endl;
    printArr(arr, size);
    cout << "!!after reverse!!" << endl;
    reverseArr(arr, size);
    printArr(arr, size);

    return 0;
}
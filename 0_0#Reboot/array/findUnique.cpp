#include <iostream>
using namespace std;

int findUnique(int arr[], int size)
{
    int ans = 0;
    for (int i = 0; i < size; i++)
    {
        ans ^= arr[i];
    }
    return ans;
}
int main()
{
    int arr[11] = {1, 2, 1, 4, 2, 4, 9, 8, 9, 8, 12};
    int size = 11;
    cout << findUnique(arr, size);

    return 0;
}
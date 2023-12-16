#include <iostream>
using namespace std;
int main()
{

    int arr1[5] = {1, 2, 3, 4, 5};

    int arr2[6] = {1, 2, 3, 4, 5};

    int sum = 0;

    for (int i = 0; i < 5; i++)
    {
        sum += arr1[i] + arr2[i];
    }

    cout << "sum of two array:" << sum;

    return 0;
}
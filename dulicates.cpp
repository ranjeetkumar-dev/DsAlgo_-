#include <iostream>
using namespace std;
int main()
{

    int arr[5] = {2, 4, 7, 4, 2};
    int dCount = 0;

    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                dCount += 1;
            }
        }
    }

    cout << "no of duplicate:" << dCount;

    return 0;
}
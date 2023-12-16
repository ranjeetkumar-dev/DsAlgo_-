#include <iostream>
using namespace std;
int main()
{

    int arr[5][5];
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> arr[i][j];
        }
    }

    int sum = 0;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (j == 0)
            {
                sum += arr[i][j];
            }
        }
    }

    cout << sum;

    return 0;
}
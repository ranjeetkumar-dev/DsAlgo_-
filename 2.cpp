#include <iostream>
using namespace std;
int main()
{

    int arr[3][3];

    int a[3];
    int b[3];
    int c[3];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {

            if (i == 0)
            {
                a[j] = arr[i][j];
            }

            if (i == 1)
            {
                b[j] = arr[i][j];
            }

            if (i == 3)
            {
                c[j] = arr[i][j];
            }
        }
    }

    return 0;
}
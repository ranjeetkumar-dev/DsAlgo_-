#include <iostream>
using namespace std;
int main()
{
    // arr declaration
    // initialise by 0 at start
    int arr[10000] = {0};

    // int arr[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        cout << arr[i] << " ";
    }
    // cout<<&arr<<endl;
    // cout<<&arr[0]<<endl;
    // cout<<&arr[1]<<endl;
    // cout<<&arr[2]<<endl;
    // cout<<&arr[3]<<endl;
    // cout<<&arr[4];

    return 0;
}
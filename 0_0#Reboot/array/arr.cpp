#include <iostream>
using namespace std;
int main()
{
    // arr declaration

    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << *(arr + 3) << endl
         << arr[3];

    return 0;
}
#include <iostream>
using namespace std;

int fact(int n)
{

    if (n == 0)
    {
        return 1;
    }

    // int fact = n * count(n - 1);
    // // count(n - 1);
    // // return fact;
    // // count(n - 1);
    // cout << fact << endl;
    return n * fact(n - 1);
}

int main()
{
    cout << fact(3);

    return 0;
}
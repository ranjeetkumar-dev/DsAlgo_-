#include <iostream>
using namespace std;

int fact(int n)
{

    int fact = 1;

    for (int i = n; i > 0; i--)
    {
        fact = fact * i;
    }
    return fact;
}

int power(int x, int pow)
{

    int result = x;

    for (int i = 1; i < pow; i++)
    {
        result = result * pow;
    }
    return result;
}
int main()
{

    cout << fact(3);

    // cout << power(5, 2);

    return 0;
}
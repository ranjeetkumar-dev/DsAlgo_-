#include <iostream>
using namespace std;
int main()
{
    // cout << "hello world";



    // Demonstrate if-else statement
    int number;
    cout << "Enter a number: ";
    cin >> number;

    if (number > 0)
    {
         cout << "The number is positive." <<  endl;
    }
    else if (number < 0)
    {
         cout << "The number is negative." <<  endl;
    }
    else
    {
         cout << "The number is zero." <<  endl;
    }

    // Demonstrate switch statement
    char grade;
     cout << "Enter your grade (A, B, C, D, or F): ";
     cin >> grade;

    switch (grade)
    {
    case 'A':
         cout << "Excellent!" <<  endl;
        break;
    case 'B':
         cout << "Good job!" <<  endl;
        break;
    case 'C':
         cout << "Average." <<  endl;
        break;
    case 'D':
         cout << "Needs improvement." <<  endl;
        break;
    case 'F':
         cout << "Fail." <<  endl;
        break;
    default:
         cout << "Invalid grade." <<  endl;
    }

    // Demonstrate ternary operator
    int x, y, max;
     cout << "Enter two numbers: ";
     cin >> x >> y;

    // Using ternary operator to find the maximum of two numbers
    max = (x > y) ? x : y;

     cout << "The maximum of " << x << " and " << y << " is: " << max <<  endl;

    return 0;
}
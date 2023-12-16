#include <iostream>
#include <climits>
using namespace std;

int main()
{
    const int size = 6;
    int array[size] = {12, 5, 8, 10, 7, 3};

    int largest = INT_MIN;
    int secondLargest = INT_MIN;

    for (int i = 0; i < size; ++i)
    {
        if (array[i] > largest)
        {
            secondLargest = largest;
            largest = array[i];
        }
        else if (array[i] > secondLargest && array[i] != largest)
        {
            secondLargest = array[i];
        }
    }

    cout << "Array: [ ";
    for (int i = 0; i < size; ++i)
    {
        cout << array[i];
        if (i < size - 1)
        {
            cout << ", ";
        }
    }
    cout << " ]" << endl;

    cout << "Largest Element: " << largest << std::endl;
    cout << "Second Largest Element: " << secondLargest << std::endl;

    return 0;
}

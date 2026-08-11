#include <iostream>
#include <cstdlib>

using namespace std;

int RandomNumber(int From, int To)
{
    // Calculate random number in range:
    // (To - From + 1) determines the range size.
    // rand() % range_size scales it to [0, range_size - 1].
    // Adding 'From' shifts the range to [From, To].
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

int main()
{
    // Seed the random number generator using the current time
    srand((unsigned)time(NULL));

    // Example 1: Generate numbers between 1 and 10
    cout << "Random numbers between 1 and 10:" << endl;
    cout << RandomNumber(1, 10) << endl;
    cout << RandomNumber(1, 10) << endl;

    cout << "--------------------------------" << endl;

    // Example 2: Generate numbers between 3 and 7
    cout << "Random numbers between 3 and 7:" << endl;
    cout << RandomNumber(3, 7) << endl;
    cout << RandomNumber(3, 7) << endl;

    return 0;
}

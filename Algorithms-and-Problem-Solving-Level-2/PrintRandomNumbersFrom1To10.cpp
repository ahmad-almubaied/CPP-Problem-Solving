#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to generate a random number within a specific range
int RandomNumber(int From, int To)
{
    // Generate a random number from From to To
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

int main()
{
    // Seeds the random number generator in C++, called only once in main
    srand((unsigned)time(NULL));

    // Print 3 random numbers from 1 to 10
    cout << RandomNumber(1, 10) << endl;
    cout << RandomNumber(1, 10) << endl;
    cout << RandomNumber(1, 10) << endl;

    return 0;
}

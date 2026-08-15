#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Read array size from user input
int readSize() {
    int size;
    cin >> size;
    return size;
}

// Generate a random number within a specific range
int RandomNumber(int From, int To) {
    return rand() % (To - From + 1) + From;
}

// Fill the array with random numbers
void fillArrayWithRandomNumbers(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = RandomNumber(1, 100);
    }
}

// Copy elements from source array to destination array
void copyArray(int arrSource[], int arrDestination[], int size) {
    for (int i = 0; i < size; i++) {
        arrDestination[i] = arrSource[i];
    }
}

// Print array elements
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

int main() {
    // Seed the random number generator
    srand((unsigned)time(NULL));

    int arr[100];
    int arr2[100];

    int size = readSize();

    fillArrayWithRandomNumbers(arr, size);
    copyArray(arr, arr2, size);

    cout << "\nArray 1 elements:\n";
    printArray(arr, size);

    cout << "\nArray 2 elements (Copied):\n";
    printArray(arr2, size);

    return 0;
}

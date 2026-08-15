#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int read() {
    int size;
    cout << "Enter array size: ";
    cin >> size;
    return size;
}

int RandomNumber(int From, int To) {
    return rand() % (To - From + 1) + From;
}

// 1. دالة لتعبئة المصفوفة بأرقام عشوائية
void fillArrayWithRandomNumbers(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = RandomNumber(1, 100);
    }
}

// 2. دالة مخصصة فقط للطباعة
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

int main() {
    // تهيئة مولد الأرقام العشوائية
    srand((unsigned)time(NULL));

    int arr[100];
    int size = read();

    fillArrayWithRandomNumbers(arr, size);
    printArray(arr, size);

    return 0;
}

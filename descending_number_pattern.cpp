#include <iostream>

using namespace std;

int readInputNumber() {
    int number;
    cin >> number;
    return number;
}  

void printPattern(int number) {
    for (int i = 0; i < number; ) {
        for (int j = 0; j < number; j++) {
            cout << number;
        }
        number--;
        cout << endl;
    }
}

int main() {
    printPattern(readInputNumber());
    return 0;
}

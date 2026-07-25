#include <iostream>
using namespace std;

int readInput() {
    int num;
    cin >> num;
    return num;
}  

int reverseNumber(int num) {
    int remainder = 0;
    int reversed = 0;
    while (num > 0) {
        remainder = num % 10;
        num = num / 10;
        reversed = 10 * reversed + remainder;
    }
    return reversed;
}

bool isPalindrome(int original, int reversed) {
    return original == reversed;
}

int main() {
    int original = readInput();
    int reversed = reverseNumber(original);
    
    if (isPalindrome(original, reversed)) {
        cout << "yes";
    }
    else {
        cout << "no";
    }

    return 0;
}

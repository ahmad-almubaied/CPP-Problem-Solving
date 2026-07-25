#include <iostream>
using namespace std;

// Read 3 capital letters via pass-by-reference
void readInput(char& c1, char& c2, char& c3) {
    cout << "Enter 3 capital letters (e.g. AAA, BCD, ZZZ): ";
    cin >> c1 >> c2 >> c3;
}

// Search using ASCII values (65 to 90) and return the trial index
void generateCombinationsFrom(char target1, char target2, char target3) {
    int counter = 0;

    // 65 = 'A', 90 = 'Z'
    for (int i = 65; i <= 90; i++) {
        for (int j = 65; j <= 90; j++) {
            for (int k = 65; k <= 90; k++) {
                
                counter++; // Track trial count

                // Compare ASCII integers with target characters
                if (i == int(target1) && j == int(target2) && k == int(target3)) {
                    cout << "\n[MATCH FOUND!]\n";
                    cout << "Combination  : " << char(i) << char(j) << char(k) << "\n";
                    cout << "ASCII Values : " << i << " " << j << " " << k << "\n";
                    cout << "Trial Number : " << counter << " out of 17576\n";
                    return; // Exit as soon as match is found
                }
            }
        }
    }
}

int main() {
    // Fast I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char ch1, ch2, ch3;

    readInput(ch1, ch2, ch3);
    generateCombinationsFrom(ch1, ch2, ch3);

    return 0;
}

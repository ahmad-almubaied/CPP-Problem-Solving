#include <iostream>
#include <string>

using namespace std;

void encryptText(string &text, int key) {
    for (int i = 0; i < text.length(); i++) {
        text[i] = text[i] + key;
    }
}

void decryptText(string &text, int key) {
    for (int i = 0; i < text.length(); i++) {
        text[i] = text[i] - key;
    }
}

int main() {
    string text = "Mohammed";
    int key = 2;

    cout << "Text Before Encryption : " << text << endl;

    encryptText(text, key);
    cout << "Text After Encryption  : " << text << endl;

    decryptText(text, key);
    cout << "Text After Decryption  : " << text << endl;

    return 0;
}

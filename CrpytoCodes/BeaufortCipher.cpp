#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
using namespace std;

string message;
string mappedKey;

/*
Beaufort Cipher - C++ Implementation

- A polyalphabetic cipher like Vigenère, but uses: C = (K - P) mod 26.
- Input: Alphabetic message and key (spaces allowed, preserved).
- Key is cyclically repeated to match message length.
- Same function used for both encryption and decryption.
- More secure than Caesar, less common than Vigenère.

*/

void messageAndKey() {
    string msg;
    cout << "Enter message: ";
    getline(cin, msg);
    cin.ignore();
    for(int i = 0; i < msg.length(); i++) {
        msg[i] = toupper(msg[i]);
    }
    
    string key;
    cout << "Enter key: ";
    getline(cin, key);
    cin.ignore();
    for(int i = 0; i < key.length(); i++) {
        key[i] = toupper(key[i]);
    }
    
    // Mapping key to message
    string keyMap = "";
    for (int i = 0, j = 0; i < msg.length(); i++) {
        if(msg[i] == 32) { // Space
            keyMap += 32; // ASCII for space
        } else {
            if(j < key.length()) {
                keyMap += key[j];
                j++;
            } else {
                j = 0;
                keyMap += key[j];
                j++;
            }
        }
    }
    
    message = msg;
    mappedKey = keyMap;
}

// The Beaufort cipher uses a different formula than Vigenère: C = (K - P) mod 26
string beaufortCipher(string message, string mappedKey) {
    string resultText = "";
    
    for(int i = 0; i < message.length(); i++) {
        if(message[i] == 32) { // Space
            resultText += " ";
        } else {
            // In Beaufort cipher: C = (K - P) mod 26
            // We add 65 to get back to ASCII A-Z range
            int k = mappedKey[i] - 'A';
            int p = message[i] - 'A';
            int c = (k - p + 26) % 26; // +26 ensures positive result
            
            resultText += (char)(c + 'A');
        }
    }
    
    return resultText;
}

int main() {
    cout << "Beaufort Cipher\n";//Its the same as Vignere cipher but enc and dec are the same fun()
    cout << "Message and key can only be alphabetic" << endl;
    
    int choice;
    cout << "1. Encryption\n2. Decryption\nChoose(1,2): ";
    cin >> choice;
    cin.ignore();
    
    if(choice == 1 || choice == 2) {
        // Same operation for both encryption and decryption
        cout << (choice == 1 ? "Encryption" : "Decryption") << endl;
        messageAndKey();
        
        string resultText = beaufortCipher(message, mappedKey);
        cout << (choice == 1 ? "Encrypted" : "Decrypted") << " Text: " << resultText << endl;
    } else {
        cout << "Wrong Choice" << endl;
    }
    
    return 0;
}
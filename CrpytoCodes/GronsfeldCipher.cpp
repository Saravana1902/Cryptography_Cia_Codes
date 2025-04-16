#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
using namespace std;

string message;
string mappedKey;

/*
Gronsfeld Cipher - C++ Implementation

- Variant of the Vigenère cipher using a numeric key (0–9 digits only).
- Each digit in the key determines a Caesar shift for the corresponding letter.
- Key is repeated to match the length of the message.
- Spaces are preserved (mapped as shift 0).
- Encryption: C = (P + K) mod 26
- Decryption: P = (C - K + 26) mod 26

*/


void messageAndKey() {
    string msg;
    cout << "Enter message: ";
    getline(cin, msg);
    
    // Converting message to uppercase
    for(int i = 0; i < msg.length(); i++) {
        msg[i] = toupper(msg[i]);
    }
    
    string key;
    cout << "Enter key (numbers only): ";
    getline(cin, key);
    
    // Validate that key contains only numbers
    for(int i = 0; i < key.length(); i++) {
        if(!isdigit(key[i])) {
            cout << "Error: Key must contain only numbers." << endl;
            exit(1);
        }
    }
    
    // Mapping key to message
    string keyMap = "";
    for(int i = 0, j = 0; i < msg.length(); i++) {
        if(msg[i] == 32) { // Space
            keyMap += '0'; // Using 0 for spaces in key mapping
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

void cipherEncryption(string message, string mappedKey) {
    string encryptedText = "";
    
    for(int i = 0; i < message.length(); i++) {
        if(message[i] == 32) { // Space
            encryptedText += " ";
        } else {
            // Convert the numeric key character to its integer value
            int shift = mappedKey[i] - '0';
            
            // Apply the shift (modulo 26 for wrapping around the alphabet)
            char encChar = ((message[i] - 'A' + shift) % 26) + 'A';
            encryptedText += encChar;
        }
    }
    
    cout << "Encrypted Text: " << encryptedText << endl;
}

void cipherDecryption(string message, string mappedKey) {
    string decryptedText = "";
    
    for(int i = 0; i < message.length(); i++) {
        if(message[i] == 32) { // Space
            decryptedText += " ";
        } else {
            // Convert the numeric key character to its integer value
            int shift = mappedKey[i] - '0';
            
            // Apply the reverse shift (adding 26 to handle negative values)
            char decChar = ((message[i] - 'A' - shift + 26) % 26) + 'A';
            decryptedText += decChar;
        }
    }
    
    cout << "Decrypted Text: " << decryptedText << endl;
}

int main() {
    cout << "Gronsfeld Cipher\n";
    cout << "Message can only be alphabetic and key can only be numeric" << endl;
    
    int choice;
    cout << "1. Encryption\n2. Decryption\nChoose(1,2): ";
    cin >> choice;
    cin.ignore();
    
    if(choice == 1) {
        cout << "Encryption" << endl;
        messageAndKey();
        cipherEncryption(message, mappedKey);
    } 
    else if(choice == 2) {
        cout << "Decryption" << endl;
        messageAndKey();
        cipherDecryption(message, mappedKey);
    } 
    else {
        cout << "Wrong Choice" << endl;
    }
    
    return 0;
}
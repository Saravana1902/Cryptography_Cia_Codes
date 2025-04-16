#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
using namespace std;

string message;
string mappedKey;

/*
Autokey Cipher - C++ Implementation

- Uses a modified Vigenère cipher where the key is extended using the plaintext.
- Input: Alphabetic message and key (spaces allowed, ignored in key extension).
- Encryption: Uses a Vigenère table to map message and key characters.
- Decryption: Reconstructs the key using initial key + decrypted text.
- Preserves spaces, ignores non-alphabetic input.
- More secure than repeating-key Vigenère due to dynamic keying.

*/


void messageAndKey() {
    string msg;
    cout << "Enter message: ";
    getline(cin, msg);
    cin.ignore();
    
    // Converting message to uppercase
    for(int i = 0; i < msg.length(); i++) {
        msg[i] = toupper(msg[i]);
    }
    
    string key;
    cout << "Enter key: ";
    getline(cin, key);
    cin.ignore();
    
    // Converting key to uppercase
    for(int i = 0; i < key.length(); i++) {
        key[i] = toupper(key[i]);
    }
    
    // Generate the autokey by extending the original key with plaintext
    string keyMap = "";
    int j = 0;
    
    for(int i = 0; i < msg.length(); i++) {
        if(msg[i] == 32) { // Space
            keyMap += 32; // ASCII for space
        } else {
            if(j < key.length()) {
                // First use the original key
                keyMap += key[j];
                j++;
            } else {
                // Then use the plaintext characters as key
                // In autokey, we use the plaintext itself (excluding spaces)
                keyMap += msg[i - key.length()]; // Offset by key length to get the right plaintext char
            }
        }
    }
    
    message = msg;
    mappedKey = keyMap;
    
    // For debugging
    cout << "Message: " << message << endl;
    cout << "Mapped Key: " << mappedKey << endl;
}

int tableArr[26][26];

void createVigenereTable() {
    for(int i = 0; i < 26; i++) {
        for(int j = 0; j < 26; j++) {
            int temp;
            if((i+65)+j > 90) {
                temp = ((i+65)+j) - 26;
                tableArr[i][j] = temp;
            } else {
                temp = (i+65)+j;
                tableArr[i][j] = temp;
            }
        }
    }
}

void cipherEncryption(string message, string mappedKey) {
    createVigenereTable();
    string encryptedText = "";
    
    for(int i = 0; i < message.length(); i++) {
        if(message[i] == 32) {
            encryptedText += " ";
        } else {
            int x = (int)message[i] - 65;
            int y = (int)mappedKey[i] - 65;
            encryptedText += (char)tableArr[x][y];
        }
    }
    
    cout << "Encrypted Text: " << encryptedText << endl;
}

void cipherDecryption(string message, string initialKey) {
    createVigenereTable();
    string decryptedText = "";
    string keyStream = initialKey;
    int keyIndex = 0;
    
    for(int i = 0; i < message.length(); i++) {
        if(message[i] == 32) {
            decryptedText += " ";
        } else {
            char currentKey;
            if(keyIndex < initialKey.length()) {
                currentKey = initialKey[keyIndex++];
            } else {
                // Use previously decrypted characters as key
                currentKey = decryptedText[keyIndex - initialKey.length()];
                keyIndex++;
            }
            
            // Find the row in the Vigenere table
            int row = currentKey - 'A';
            
            // Now search for the encrypted letter in this row
            int col = 0;
            for(int j = 0; j < 26; j++) {
                if(tableArr[row][j] == message[i]) {
                    col = j;
                    break;
                }
            }
            
            // The column index plus 'A' gives us the original character
            decryptedText += (char)(col + 'A');
        }
    }
    
    cout << "Decrypted Text: " << decryptedText << endl;
}

int main() {
    cout << "Autokey Cipher\n";
    cout << "Message and key can only be alphabetic" << endl;
    
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
        
        string encryptedMsg;
        cout << "Enter encrypted message: ";
        getline(cin, encryptedMsg);
        cin.ignore();
        
        // Converting message to uppercase
        for(int i = 0; i < encryptedMsg.length(); i++) {
            encryptedMsg[i] = toupper(encryptedMsg[i]);
        }
        
        string key;
        cout << "Enter original key: ";
        getline(cin, key);
        cin.ignore();
        
        // Converting key to uppercase
        for(int i = 0; i < key.length(); i++) {
            key[i] = toupper(key[i]);
        }
        
        cipherDecryption(encryptedMsg, key);
    } 
    else {
        cout << "Wrong Choice" << endl;
    }
    
    return 0;
}
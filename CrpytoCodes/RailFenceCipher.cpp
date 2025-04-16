#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
* Rail Fence Cipher Implementation
* 
* Encryption Method:
* The Rail Fence algorithm encodes text by arranging it in a zigzag pattern
* on multiple rails (rows). The resulting ciphertext is formed by reading
* the characters sequentially from each rail. The rail count is determined
* by the user-provided key value.
* 
* Decryption Process:
* To decode, we first recreate the zigzag structure based on the key,
* place the ciphertext characters in order along the rails, then read
* the message by following the original zigzag pattern.
* 
* Key Definition:
* The key represents the number of rails (or rows) in the zigzag formation.
* This parameter controls the complexity of the encryption pattern.
*/

void decryption(string encrypted_text, int key);

void encryption(string text, int key) {
    string encrypted_text = "";
    // Changing the direction to down or up of the zigzag pattern to put the values.
    bool direction = false;
    int column = text.length();
    int j = 0;
    // Initializing the char array to store the zigzag formation.
    vector<vector<char>> a(key, vector<char>(column, '\0'));
    
    // The for loop which puts the character of the text to railfence form.
    for (int i = 0; i < column; i++) {
        if (j == 0 || j == key - 1) {
            direction = !direction;
        }
        a[j][i] = text[i];
        if (direction) {
            j++;
        } else {
            j--;
        }
    }
    
    for (int i = 0; i < key; i++) {
        for (int k = 0; k < column; k++) {
            if (a[i][k] != '\0') {
                encrypted_text += a[i][k];
            }
        }
    }
    
    cout << "Encrypted text: " << encrypted_text << endl;
    decryption(encrypted_text, key);
}

void decryption(string encrypted_text, int key) {
    string decrypted_text = "";
    // Changing the direction to down or up to put the values.
    bool direction = false;
    int column = encrypted_text.length();
    int j = 0;
    // Initializing the char array to store the zigzag formation.
    vector<vector<char>> a(key, vector<char>(column, '\0'));
    
    // Mark positions in zigzag pattern
    for (int i = 0; i < column; i++) {
        if (j == 0 || j == key - 1) {
            direction = !direction;
        }
        a[j][i] = '*';
        if (direction) {
            j++;
        } else {
            j--;
        }
    }
    
    // Fill the rail matrix
    int index = 0;
    for (int i = 0; i < key; i++) {
        for (int k = 0; k < column; k++) {
            if (a[i][k] == '*' && index < column) {
                a[i][k] = encrypted_text[index++];
            }
        }
    }
    
    // Read in zigzag pattern
    direction = false;
    j = 0;
    for (int i = 0; i < column; i++) {
        if (j == 0 || j == key - 1) {
            direction = !direction;
        }
        decrypted_text += a[j][i];
        if (direction) {
            j++;
        } else {
            j--;
        }
    }
    
    cout << "Decrypted text: " << decrypted_text << endl;
}

int main() {
    string text;
    int key;
    cout << "Rail Fence Cipher\n";
    cout << "Enter the text: ";
    getline(cin, text);
    
    cout << "Enter the key value: ";
    cin >> key;
    
    encryption(text, key);
    
    return 0;
}
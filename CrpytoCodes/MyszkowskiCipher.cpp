

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

/**
* Myszkowski Cipher
* 
* Encryption: Arranges text in grid by rows, reorders columns by key's alphabetical 
* order, then reads column by column.
* 
* Decryption: Fills columns in key order, reads row by row to recover plaintext.
* 
* Key: String determining column arrangement order.
*/


vector<int> generateKeySequence(const string& keyWord) {
    vector<int> sequence(keyWord.length());
    
    // Initialize with original positions
    for (size_t i = 0; i < keyWord.length(); i++) {
        sequence[i] = i;
    }
    
    // Sort based on characters in key
    sort(sequence.begin(), sequence.end(), [&keyWord](int a, int b) {
        return keyWord[a] < keyWord[b];
    });
    
    return sequence;
}

// Encrypts plaintext using Myszkowski transposition
string myszkowskiEncode(const string& keyWord, const string& message) {
    // Get ordered column sequence
    vector<int> columnSequence = generateKeySequence(keyWord);
    
    // Calculate grid dimensions
    size_t columns = keyWord.length();
    size_t rows = ceil(static_cast<double>(message.length()) / columns);
    
    // Create and populate grid with message
    vector<vector<char>> grid(rows, vector<char>(columns, 'X'));
    size_t pos = 0;
    
    for (size_t r = 0; r < rows; r++) {
        for (size_t c = 0; c < columns; c++) {
            if (pos < message.length()) {
                grid[r][c] = message[pos++];
            }
        }
    }
    
    // Create output by reading columns in sequence
    string result;
    for (size_t i = 0; i < columns; i++) {
        int col = columnSequence[i];
        for (size_t r = 0; r < rows; r++) {
            result += grid[r][col];
        }
    }
    
    return result;
}

// Decrypts ciphertext using Myszkowski transposition
string myszkowskiDecode(const string& keyWord, const string& encoded) {
    // Get ordered column sequence
    vector<int> columnSequence = generateKeySequence(keyWord);
    
    // Calculate grid dimensions
    size_t columns = keyWord.length();
    size_t rows = ceil(static_cast<double>(encoded.length()) / columns);
    
    // Create empty grid
    vector<vector<char>> grid(rows, vector<char>(columns, ' '));
    
    // Fill grid with ciphertext by columns in sequence
    size_t pos = 0;
    for (size_t i = 0; i < columns; i++) {
        int col = columnSequence[i];
        for (size_t r = 0; r < rows && pos < encoded.length(); r++) {
            grid[r][col] = encoded[pos++];
        }
    }
    
    // Read plaintext row by row
    string decoded;
    for (size_t r = 0; r < rows; r++) {
        for (size_t c = 0; c < columns; c++) {
            if (grid[r][c] != ' ' && grid[r][c] != 'X') {
                decoded += grid[r][c];
            }
        }
    }
    
    return decoded;
}

int main() {
    string keyWord, inputText;
    cout << "Myszkowski Cipher\n";
    cout << "Enter encryption key: ";
    getline(cin, keyWord);
    
    cout << "Enter text to encrypt: ";
    getline(cin, inputText);
    
    // Remove spaces from input (optional)
    inputText.erase(remove(inputText.begin(), inputText.end(), ' '), inputText.end());
    
    string cipherText = myszkowskiEncode(keyWord, inputText);
    cout << "\nEncrypted message: " << cipherText << endl;
    
    string recoveredText = myszkowskiDecode(keyWord, cipherText);
    cout << "Decrypted message: " << recoveredText << endl;
    
    return 0;
}
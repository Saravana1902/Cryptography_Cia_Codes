
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

/**
 * Route Cipher Implementation
 *
 * Encryption Method:
 * The Route Cipher works by arranging plaintext in a rectangular grid
 * row by row, then reading the text column by column from top to bottom
 * to form the ciphertext. The number of columns is determined by the key.
 *
 * Decryption Process:
 * To decode, we reverse the process by placing ciphertext in the grid
 * column by column, then reading row by row to recover the original message.
 *
 * Key Definition:
 * The key determines the number of columns in the grid, which directly
 * affects the permutation pattern and security of the cipher.
 */


string prepareText(const string& input) {
    string result = input;
    // Remove all whitespace
    result.erase(remove_if(result.begin(), result.end(), ::isspace), result.end());
    // Convert to uppercase
    transform(result.begin(), result.end(), result.begin(), ::toupper);
    return result;
}

// Encryption function - arranges text in rows and reads by columns
string encodeMessage(const string& message, int columnCount) {
    // Clean input text
    string cleanText = prepareText(message);
    
    // Calculate dimensions
    int textLength = cleanText.length();
    int rowCount = ceil(static_cast<double>(textLength) / columnCount);
    
    // Create 2D grid
    vector<vector<char>> grid(rowCount, vector<char>(columnCount));
    
    // Fill grid row by row
    int charIndex = 0;
    for (int r = 0; r < rowCount; r++) {
        for (int c = 0; c < columnCount; c++) {
            if (charIndex < textLength) {
                grid[r][c] = cleanText[charIndex++];
            } else {
                grid[r][c] = 'X'; // Padding character
            }
        }
    }
    
    // Read grid column by column to create ciphertext
    string ciphertext;
    for (int c = 0; c < columnCount; c++) {
        for (int r = 0; r < rowCount; r++) {
            ciphertext += grid[r][c];
        }
    }
    
    return ciphertext;
}

// Decryption function - arranges text in columns and reads by rows
string decodeMessage(const string& ciphertext, int columnCount) {
    // Clean input text
    string cleanCipher = prepareText(ciphertext);
    
    // Calculate dimensions
    int textLength = cleanCipher.length();
    int rowCount = ceil(static_cast<double>(textLength) / columnCount);
    
    // Create 2D grid
    vector<vector<char>> grid(rowCount, vector<char>(columnCount, ' '));
    
    // Fill grid column by column
    int charIndex = 0;
    for (int c = 0; c < columnCount; c++) {
        for (int r = 0; r < rowCount && charIndex < textLength; r++) {
            grid[r][c] = cleanCipher[charIndex++];
        }
    }
    
    // Read grid row by row to recover plaintext
    string plaintext;
    for (int r = 0; r < rowCount; r++) {
        for (int c = 0; c < columnCount; c++) {
            if (grid[r][c] != ' ') {
                plaintext += grid[r][c];
            }
        }
    }
    
    return plaintext; // Could remove trailing Xs if needed
}

int main() {
    string inputText;
    int key;
    cout << "Route Cipher\n";
    // Get user input
    cout << "Enter text to encrypt: ";
    getline(cin, inputText);
    
    cout << "Enter column key (integer): ";
    cin >> key;
    
    // Perform encryption
    string encodedText = encodeMessage(inputText, key);
    cout << "\nEncoded message: " << encodedText << endl;
    
    // Perform decryption to verify
    string decodedText = decodeMessage(encodedText, key);
    cout << "Decoded message: " << decodedText << endl;
    
    return 0;
}
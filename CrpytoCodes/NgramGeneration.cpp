#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

/*
  N-gram Operation:
  
  Working: To split given text into sequence of 'N' units(consecutive/both words & characters)
  Used in NLP
  
  Unigram 1 word  : ["I","love","Cpp"]
  Bigram  2 words : ["I love","love Cpp"]
  .
  .
  .
*/

// Function to split a string into words
vector<string> splitIntoWords(const string& input) {
    vector<string> words;
    istringstream iss(input);
    string word;
    
    while (iss >> word) {
        words.push_back(word);
    }
    
    return words;
}

// Function to generate n-grams from a given input text
vector<string> generateNGrams(const string& input, int n) {
    vector<string> nGrams;
    
    // Split the input text into words
    vector<string> words = splitIntoWords(input);
    
    // Ensure that the length of the text is sufficient to form the desired n-grams
    if (words.size() < n) {
        cout << "Text is too short to generate " << n << "-grams" << endl;
        return nGrams;
    }
    
    // Loop through the words and generate n-grams
    for (size_t i = 0; i <= words.size() - n; i++) {
        string nGram;
        
        // Combine n consecutive words into a single n-gram
        for (int j = 0; j < n; j++) {
            nGram += words[i + j];
            if (j < n - 1) {
                nGram += " ";
            }
        }
        
        // Add the n-gram to the list
        nGrams.push_back(nGram);
    }
    
    return nGrams;
}

// Function to display the generated n-grams
void displayNGrams(const vector<string>& nGrams) {
    cout << "\nGenerated N-grams:" << endl;
    for (const string& nGram : nGrams) {
        cout << nGram << endl;
    }
}

// Main function to demonstrate the usage of the N-gram operations
int main() {
    string text;
    int n;
    
    // Take user input for the text
    cout << "Enter the text:" << endl;
    getline(cin, text);
    
    // Take user input for the size of the N-gram
    cout << "Enter the size of the N-gram (e.g., 1 for unigrams, 2 for bigrams, etc.):" << endl;
    cin >> n;
    
    // Generate and display n-grams
    cout << "\nGenerating N-grams..." << endl;
    vector<string> nGrams = generateNGrams(text, n);
    displayNGrams(nGrams);
    
    return 0;
}
#include <bits/stdc++.h>
#include <iostream>
#include <cmath>

using namespace std;

/*
Atbash Cipher - C++ Implementation

- A monoalphabetic substitution cipher.
- Each letter is mapped to its reverse: A ↔ Z, B ↔ Y, ..., M ↔ N.
- Same logic applies for both encryption and decryption.
- Only uppercase alphabetic characters are used.
- Spaces are preserved as-is.

*/


string cipherEncryption(){
    string message;
    cout << "Enter Message: ";
    getline(cin, message);
    cin.ignore();

    //message to upper case
    for(int i = 0; i < message.length(); i++){
        message[i] = toupper(message[i]);
    }

    string alpa = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string reverseAlpa = "";
    for(int i = alpa.length()-1; i > -1; i--){
        reverseAlpa += alpa[i];
    }

    string encryText = "";
    for(int i = 0; i < message.length(); i++){
        if(message[i] == 32){
            encryText += " ";
        } else {
            for(int j = 0; j < alpa.length(); j++){
                if(message[i] == alpa[j]){
                    encryText += reverseAlpa[j];
                    break;
                }
            } 
        }   
    } 

    return encryText;
}

string cipherDecryption(){
    string message;
    cout << "Enter Encrypted Message: ";
    getline(cin, message);
    cin.ignore();

    //message to upper case
    for(int i = 0; i < message.length(); i++){
        message[i] = toupper(message[i]);
    }

    string alpa = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string reverseAlpa = "";
    for(int i = alpa.length()-1; i > -1; i--){
        reverseAlpa += alpa[i];
    }

    string decryText = "";
    for(int i = 0; i < message.length(); i++){
        if(message[i] == 32){
            decryText += " ";
        } else {
            for(int j = 0; j < reverseAlpa.length(); j++){
                if(message[i] == reverseAlpa[j]){
                    decryText += alpa[j];
                    break;
                }
            } 
        } 
    } 

    return decryText;
}

int main()
{
    int choice;
    cout << "Atbash cipher\n";
    cout << "1. Encryption\n2. Decryption\nChoose(1,2): ";
    cin >> choice;
    cin.ignore();

    if(choice == 1){
        cout << "Encryption" << endl;
        
        string result = cipherEncryption();
        
        cout << "Encrypted Text: " << result;
        
    } 
    else if (choice == 2){
      
        cout << "Decryption" << endl;
        
        string result = cipherDecryption();
        
        cout << "Decrypted Text: " << result;
        
    } 
    else {
        cout << "Wrong Choice" << endl;
    }
    return 0;
}
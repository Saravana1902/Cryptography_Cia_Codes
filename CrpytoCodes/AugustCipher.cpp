#include <bits/stdc++.h>
#include <iostream>
#include <cmath>

using namespace std;

/*
August Cipher - C++ Implementation

- A Caesar cipher variant with a fixed key = 1.
- Encryption: Shifts each letter by 1 position forward.
- Decryption: Shifts each letter by 1 position backward.
- Wraps around A-Z and a-z when limits are crossed.
- Spaces are ignored and preserved.
- Handles both uppercase and lowercase alphabetic characters.

*/


string encrypt(string msg){ //Encryption function with fixed Key Value = 1 for August Cipher
      int key = 1;
      
      string eText = msg;
      
      for (int i = 0; i < msg.size(); i ++){
      
          if(msg[i]==32){
              continue; //32 is ASCII of space character, we will ignore it
          } else {
      
              if((msg[i]+key) > 122) {
                  //after lowercase z move back to a, z's ASCII is 122
                  int temp = (msg[i] + key) - 122;
                  eText[i] = 96 + temp;
              } else if (msg[i] + key > 90 && msg[i] <= 96){
                  //after uppercase Z move back to A, 90 is Z's ASCII
                  int temp = (msg[i] + key) - 90;
                  eText[i] = 64 + temp;
              } else {
                  //in case of characters being in between A-Z & a-z
                  eText[i] += key;
              }
      
          } 
      } 
        
      return eText;
}


string decrypt(string eMsg){//Decryption Function with fixed Key Value = 1 for August Cipher
      int Key = 1;

      string dText = eMsg;

      for (int i = 0; i < eMsg.size(); i++){
          if(eMsg[i]==32){
              continue; //ignoring space
          } else {
              if((eMsg[i] - Key) < 97 && (eMsg[i] - Key) > 90){
                  int temp = (eMsg[i] - Key) + 26;
                  dText[i] = temp;
              } else if((eMsg[i] - Key) < 65){
                  int temp = (eMsg[i] - Key) + 26;
                  dText[i] = temp;
              } else {
                  dText[i] = eMsg[i] - Key;
              }
          }
      }
      
      return dText;
}


int main()
{
    int choice;
    cout << "August Cipher:\n";
    cout << "1. Encryption || 2. Decryption \nFor Choice, enter 1,2 : ";
    cin >> choice;
    cin.ignore();

    if (choice == 1){
        // calls the encryption function
        string msg;
        cout << "Enter message: ";
        getline(cin, msg);
        
        string encryptedText = encrypt(msg);
        
        cout << "Original Message is: " << msg << "\n";
        cout << "Encrypted Message is : " << encryptedText;

    } 
    
    else if (choice == 2){
        //decryption
        string eMsg;

        cout << "Enter encrypted text: ";
        getline(cin, eMsg);
        
        string decryptedText = decrypt(eMsg);

        cout << "Original Message is: " << eMsg << "\n";
        cout << "Decrypted Message: " << decryptedText << endl;

    } 
    
    else {
        cout << "Invalid choice";
    }



    return 0;

}
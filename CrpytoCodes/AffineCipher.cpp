#include <bits/stdc++.h>
#include <iostream>
#include <cmath>

using namespace std;

/*
Affine Cipher - C++ Implementation

- Monoalphabetic cipher with formula:
    Encryption: C = (a * P + b) mod 26
    Decryption: P = a⁻¹ * (C - b) mod 26
- Requires two keys: a (must be coprime with 26) and b.
- Handles both uppercase and lowercase letters.
- Uses modular inverse for decryption.
- Only alphabetic input is supported.

*/


string encrypt(string plaintext, int keyA, int keyB){
        int key1 = keyA;
        int key2 = keyB;
        string ciphertext=" "; 
	    string plain_text = plaintext;
	    int check,inv; 
	    
    	for(int i=0; i<plaintext.size(); i++){
		    if(plaintext[i]>='A' && plaintext[i]<='Z'){
			    ciphertext+= char((key1* int(plaintext[i]-65)+ key2)%26 +65);
		    }
		    else{
			    ciphertext+= char((key1* int(plaintext[i]-97)+ key2)%26 +97);
		    }
	    }
	    
	    return ciphertext;
	
    // 	cout <<"After Encryption \n";
    // 	cout <<"Plain  Text: " << plaintext << "\n";
    // 	cout <<"Cipher Text: " << ciphertext << "\n";
	
}

string decrypt(int keyA, int keyB){
    int key1 = keyA;
    int key2 = keyB;
    string ciphertext; 
	string plain_text =" ";
	int check,inv; 
	
    for(int i=0; i<26; i++){
		check=(i*key1)%26;
		if(check==1){
			inv=i;
			break;
		}
	}
	if(check!=1)
	{
		cout<<"\n Inverse Key don't exist";
		return 0;
	}
	
	cout<<"Enter Cipher Text to be decrypted: ";
	cin>>ciphertext;
	for(int i=0; i<ciphertext.size(); i++){
		if(ciphertext[i]>='A' && ciphertext[i]<='Z'){
			plain_text+= char(((((ciphertext[i]-65- key2)%26+26)%26)*inv)%26+65);
		}
		else{
			plain_text+= char(((((ciphertext[i]-97- key2)%26+26)%26)*inv)%26+97);
		}
	}
	
	return plain_text;
//     cout << "After Decryption\n";
// 	cout << "Cipher Text: "<< ciphertext << "\n";
// 	cout << "Plain Text: "<< plain_text << "\n";
}

int main() {
	string plaintext; 
	int key1, key2,check,inv; 
	cout << "Affine Cipher\n";
	cout << "Enter Plain/Cipher Text : ";
	cin >> plaintext;
	cout << "Enter the key 1: ";
	cin >> key1;
	cout << "Enter the key 2: ";
	cin >> key2;
	
	int choice;
	cout<< "Enter 1 for Encryption, 2 for Decryption.\n";
	cin >> choice;
	
	if(choice == 1){
	    string result = encrypt(plaintext,key1,key2);
	    cout << "Cipher text is: "<< result;
	}
	if(choice == 2){
	    string result = decrypt(key1,key2);
	    cout << "Plain text was: "<< result;
	}
// 	else{
// 	    cout<< "Invalid Input";
// 	}

}

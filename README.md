# Cryptography_Cia_Codes
This repository holds 13 cryptography algorithms implemented in C++, explaining substitution and transposition cipher techniques. These algorithms provide a basic understanding for cryptography and helps the learner to understand how ciphers work

Cryptographic Algorithms Implemented
✨ Substitution Ciphers
Substitution ciphers replace characters in the plaintext with other characters based on specific rules.

✅ Monoalphabetic (Single Substitution)
Atbash Cipher: Reverses the alphabet (e.g., A ⇔ Z, B ⇔ Y).

Caesar Cipher: Shifts letters by a fixed key.

Affine Cipher: Uses the formula (ax + b) mod 26.

August Cipher: Caesar variant with a fixed shift of 1.

✅ Polyalphabetic (Multiple Substitutions)
Vigenère Cipher: Uses a repeated keyword for shifting.

Gronsfeld Cipher: A numeric version of the Vigenère cipher using digits (0-9).

Beaufort Cipher: Similar to Vigenère, but uses reversed logic.

Autoclave / Running Key Cipher: The key is extended using the plaintext or external text (e.g., a book).

🔤 Polygraphic

Hill Cipher: Uses matrix multiplication and modular arithmetic on blocks of letters.

🛋️ Transposition Ciphers
These ciphers rearrange the characters without altering the actual letters.

Rail Fence Cipher: Writes text in a zigzag pattern across multiple rails.

Route Cipher: Text is written in a grid and read in a specific path (e.g., spiral).

Myszkowski Cipher: A columnar transposition cipher using repeated-key characters.

🔎 N-Gram Operations
NGramOperations.cpp: Generates unigrams, bigrams, and trigrams for text analysis, prediction, and preprocessing in natural language tasks.

How to Use
Clone or download the repository:
bash
Copy
Edit
git clone https://github.com/Saravana1902/Cryptography_Cia_Codes.git
cd Cryptography_Cia_Codes
Compile and run:
You can use any C++ IDE or a terminal/command-line interface.

Navigate to the src/cryptography folder.

Compile any of the .cpp files to test the cryptographic algorithms.

For example, to run Caesar Cipher:

bash
Copy
Edit
g++ CaesarCipher.cpp -o CaesarCipher
./CaesarCipher
Each .cpp file contains the implementation of a different cryptographic algorithm. Follow the same steps for other algorithms as well.

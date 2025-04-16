# Cryptography Algorithms Collection

This repository contains 13 cryptography algorithms implemented in C++, explaining substitution and transposition cipher techniques. These algorithms provide a basic understanding of cryptography and help learners understand how ciphers work. Also in addition to ciphers, a N-gram Generator has been added to understand what is a Ngram and how it is useful

---

**Substitution Ciphers:**
Substitution ciphers replace characters in the plaintext with other characters based on specific rules.

**Monoalphabetic (Single Substitution)**
In these ciphers, each letter of the plaintext is replaced with another letter consistently throughout the message.

* **Atbash Cipher:** Reverses the alphabet (e.g., A ⇔ Z, B ⇔ Y).
* **Caesar Cipher:** Shifts letters by a fixed key.
* **Affine Cipher:** Uses the formula (ax + b) mod 26.
* **August Cipher:** A variation of the Caesar Cipher with a fixed shift of 1 (implementation included).


**Polyalphabetic (Multiple Substitutions)**
These ciphers use more than one substitution alphabet to encrypt the message.

* **Vigenère Cipher:** Uses a repeated keyword to shift letters based on the Vigenère square.
* **Gronsfeld Cipher:** A numeric version of the Vigenère cipher using digits (0-9) as the key.
* **Beaufort Cipher:** Similar to the Vigenère cipher but uses reversed logic for encryption.
* **Autoclave / Running Key Cipher:** The key is extended using the plaintext itself or an external text source (e.g., a book).

---

**Polygraphic**

* **Hill Cipher:** Employs matrix multiplication and modular arithmetic on blocks of letters.

---

**Transposition Ciphers**
These ciphers rearrange the characters of the plaintext without changing the letters themselves.

* **Rail Fence Cipher:** Writes the plaintext in a zigzag pattern across a specified number of rails and then reads it off row by row.
* **Route Cipher:** The plaintext is written into a grid, and the ciphertext is obtained by reading the letters in a specific path (e.g., spiral, diagonal).
* **Myszkowski Cipher:** A columnar transposition cipher that uses a keyword with repeating letters; the columns are ordered based on the alphabetical order of the keyword's letters, with repeated letters handled uniquely.

---

**N-Gram Operations**
* **NGramOperations.cpp:** This file provides functionality to generate unigrams, bigrams, and trigrams from text data. These are useful for various natural language processing tasks such as text analysis, language prediction, and preprocessing.

---

## How to Use

**1. Clone or download the repository:**

```bash
git clone [https://github.com/Saravana1902/Cryptography_Cia_Codes.git](https://github.com/Saravana1902/Cryptography_Cia_Codes.git)
cd Cryptography_Cia_Codes
```

**2.Compile and run:**
You can use any C++ IDE or a terminal/command-line interface to compile and execute the code.

**3.Navigate to the src/cryptography folder:**
Compile any of the .cpp files to test the cryptographic algorithms.
For example, to run the Caesar Cipher:

```bash
g++ src/cryptography/CaesarCipher.cpp -o CaesarCipher
./CaesarCipher
```
---

A work by
Saravanakrishnan B
IoT B
22011102092



#include <iostream>
#include <fstream>
#include <string>
#include <limits> 
using namespace std; // Required for clearing input buffer

// --- Core Logic Functions ---

/**
 * Encrypts a string using the Caesar cipher algorithm.
 * Handles character wrap-around for both uppercase and lowercase letters.
 */
string encrypt(const string& text, int shift) {
    string result = "";
    for (char c : text) {
        if (isalpha(c)) { // Check if the character is an alphabet letter
            char base = islower(c) ? 'a' : 'A';
            c = (c - base + shift) % 26 + base;
        }
        result += c; // Add the character (encrypted or original) to our result string
    }
    return result;
}

/**
 * Decrypts a string using the Caesar cipher algorithm.
 * It's the reverse of the encrypt function.
 */
string decrypt(const string& text, int shift) {
    // To decrypt, we simply shift in the opposite direction.
    // We add 26 to ensure the result of the subtraction is not negative.
    return encrypt(text, 26 - shift); 
}


// --- File Process Functions ---

/**
 * Manages the entire file encryption process from user prompts to completion.
 */
void encryptFile() {
     string inputFilename, outputFilename;
    int shiftKey;

     cout << "\n--- Encrypt File ---" <<  endl;
     cout << "Enter the name of the file to encrypt: ";
     cin >> inputFilename;
     cout << "Enter the name for the new encrypted file: ";
     cin >> outputFilename;
     cout << "Enter the encryption key (a number from 1-25): ";
     cin >> shiftKey;

     ifstream inputFile(inputFilename);
     ofstream outputFile(outputFilename);

    if (!inputFile.is_open()) {
         cerr << "Error: Could not open input file '" << inputFilename << "'" <<  endl;
        return;
    }
    if (!outputFile.is_open()) {
         cerr << "Error: Could not create output file '" << outputFilename << "'" <<  endl;
        return;
    }

     string line;
    while ( getline(inputFile, line)) {
         string encryptedLine = encrypt(line, shiftKey);
        outputFile << encryptedLine <<  endl;
    }

     cout << "\nSuccess! File has been encrypted to '" << outputFilename << "'" <<  endl;

    inputFile.close();
    outputFile.close();
}

/**
 * Manages the entire file decryption process.
 */
void decryptFile() {
     string inputFilename, outputFilename;
    int shiftKey;

     cout << "\n--- Decrypt File ---" <<  endl;
     cout << "Enter the name of the file to decrypt: ";
     cin >> inputFilename;
     cout << "Enter the name for the new decrypted file: ";
     cin >> outputFilename;
     cout << "Enter the original encryption key (1-25): ";
     cin >> shiftKey;

     ifstream inputFile(inputFilename);
     ofstream outputFile(outputFilename);

    if (!inputFile.is_open()) {
         cerr << "Error: Could not open input file '" << inputFilename << "'" <<  endl;
        return;
    }
    if (!outputFile.is_open()) {
         cerr << "Error: Could not create output file '" << outputFilename << "'" <<  endl;
        return;
    }

     string line;
    while ( getline(inputFile, line)) {
         string decryptedLine = decrypt(line, shiftKey);
        outputFile << decryptedLine <<  endl;
    }

     cout << "\nSuccess! File has been decrypted to '" << outputFilename << "'" <<  endl;

    inputFile.close();
    outputFile.close();
}


// --- Main Application Menu ---

int main() {
    int choice = 0;

    while (true) {
         cout << "\n===== File Encryptor Menu =====" <<  endl;
         cout << "1. Encrypt a file" <<  endl;
         cout << "2. Decrypt a file" <<  endl;
         cout << "3. Exit" <<  endl;
         cout << "=============================" <<  endl;
         cout << "Enter your choice: ";
        
         cin >> choice;

        // Check if the input is valid
        if ( cin.fail()) {
             cout << "Invalid input. Please enter a number." <<  endl;
             cin.clear(); // Clear the error flag
             cin.ignore( numeric_limits< streamsize>::max(), '\n'); // Discard bad input
            continue; // Skip the rest of the loop and show the menu again
        }

        switch (choice) {
            case 1:
                encryptFile();
                break;
            case 2:
                decryptFile();
                break;
            case 3:
                 cout << "Exiting program. Goodbye!" <<  endl;
                return 0; // Exit the main function, which ends the program
            default:
                 cout << "Invalid choice. Please enter 1, 2, or 3." <<  endl;
                break;
        }
    }

    return 0;
}
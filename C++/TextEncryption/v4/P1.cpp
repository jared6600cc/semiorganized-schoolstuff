/*
 * Jared Bumgardner
 * COP4534 Project 1
 * 16 Sept. 2021
 */



#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "vigenereCipher.hpp"
#include "hashTable.hpp"
using namespace V;
using namespace H;
using namespace std;



int passwordSize = 6;
int numNames = 0;



int readNamesWriteRaw() 
{
    string bufferLine;
    ifstream inFileNames;
    
    // Open names.txt
    inFileNames.open("names.txt", ios::in);
    if (inFileNames.is_open()) 
    {
        // Create rawdata.txt
        ofstream outFileRaw("rawdata.txt");
        if (outFileRaw.is_open()) 
        {
            while (getline(inFileNames, bufferLine)) 
            {
                // Get userID
                stringstream bufferStream(bufferLine);
                getline(bufferStream, bufferLine, ' ');
                outFileRaw << bufferLine << " ";
                // Generate password for userID
                for (int i = 0; i < passwordSize; i++) 
                {
                    char nextChar = ' ';
                    int nextCharCase = rand() % 2;
                    switch (nextCharCase) 
                    {
                    case 1 :
                        nextChar = 'A' + (rand() % 26);
                        break;
                    case 0 :
                        nextChar = 'a' + (rand() % 26);
                        break;
                    }
                    outFileRaw << nextChar;
                }
                outFileRaw << '\n';
                numNames++;
            }
        } else { cout << "Error opening output file: rawdata.txt\n"; return -1; }
        outFileRaw.close();
    }
    inFileNames.close();
    return 0;
}
int readRawWriteEncrypted(vigenereCipher v) 
{
    string bufferLine;
    ifstream inFileRaw;

    // Open rawdata.txt
    inFileRaw.open("rawdata.txt", ios::in);
    if (inFileRaw.is_open()) 
    {
        ofstream outFileEncrypted("encrypteddata.txt");
        if (outFileEncrypted.is_open()) 
        {
            while (getline(inFileRaw, bufferLine)) 
            {
                stringstream bufferStream(bufferLine);
                getline(bufferStream, bufferLine, ' '); // get userID
                outFileEncrypted << bufferLine << ' ';
                getline(bufferStream, bufferLine, ' '); // get userPass
                outFileEncrypted << v.encrypt(bufferLine) << '\n';
            }
        } else { cout << "Error opening output file: encrypteddata.txt\n"; return -1; }
    } else { cout << "Error opening input file: rawdata.txt\n"; return -1; }
    return 0;
}



void test1(int testSet[5], hashTable* h, vigenereCipher v) 
{
    //Output Declarations
    string userID;
    string plainTextPass;
    string encryptedTextPass;
    int hashIndex;
    bool foundT1 = false;

    //Display output labels
    cout << "\tLEGAL:\n";
    cout << "\tuserID\tPassword\tResult\n";
    
    //Find entry in rawdata.txt
    for (int i = 0; i < 6; i++)    // for each digit in pass
    {
        int indexFound = 0;
        string bufferLine;
        ifstream inFileNames;
        inFileNames.open("rawdata.txt", ios::in);
        if (inFileNames.is_open()) 
        {
            while (getline(inFileNames, bufferLine)) 
            {
                indexFound++;
                stringstream bufferStream(bufferLine);
                getline(bufferStream, bufferLine, ' ');
                if (testSet[i] == indexFound) // correct entry found in file
                {
                    userID = bufferLine;
                    hashIndex = h->hashFunc(bufferLine); // hash on userID
                    getline(bufferStream, bufferLine, ' ');
                    plainTextPass = bufferLine;
                    encryptedTextPass = v.encrypt(plainTextPass);   // encrypt plaintext password
                    cout << '\t' << userID << '\t' << encryptedTextPass << "\t";    //TEST 1 RESULTS
                    foundT1 = h->find(userID);
                    if (foundT1) 
                    {
                        foundT1 = true;
                        cout << "match\n";                                          //TEST RESULTS
                    }
                    else
                    {
                        cout << "no match\n";                                       //TEST RESULTS
                    }
                }
            }
        }
    }
}
void test2(int testSet[5], hashTable * h, vigenereCipher v) 
{
    //Output Declarations
    string userID;
    string plainTextPass;
    string encryptedTextPass;
    int hashIndex;
    bool foundT2 = false;

    //Display output labels
    cout << "\n\tIllegal: \n";
    cout << "\tuserID\tPassword\tResult\n";

    //Find entry in rawdata.txt
    for (int i = 0; i < 6; i++)    // for each digit in pass
    {
        int indexFound = 0;
        string bufferLine;
        ifstream inFileNames;
        inFileNames.open("rawdata.txt", ios::in);
        if (inFileNames.is_open())
        {
            while (getline(inFileNames, bufferLine))
            {
                indexFound++;
                stringstream bufferStream(bufferLine);
                getline(bufferStream, bufferLine, ' ');
                if (testSet[i] == indexFound) // correct entry found in file
                {
                    userID = bufferLine;
                    hashIndex = h->hashFunc(bufferLine); // hash on userID
                    getline(bufferStream, bufferLine, ' ');
                    plainTextPass = bufferLine;
                    plainTextPass[0] = rand() % 26;                 // corrupt plaintext password
                    encryptedTextPass = v.encrypt(plainTextPass);   // encrypt plaintext password
                    cout << '\t' << userID << '\t' << encryptedTextPass << "\t";    //TEST 2 RESULTS
                    foundT2 = h->find(userID);
                    if (foundT2)
                    {
                        foundT2 = true;
                        cout << "match\n";                                          //TEST RESULTS
                    }
                    else
                    {
                        cout << "no match\n";                                       //TEST RESULTS
                    }
                }
            }
        }
    }
}


int main()
{
    // Declarations
    srand(time(NULL));                  // Randomizer
    vigenereCipher vc("defghixyz");     // Cipher


    // Read userIDs, generate passwords, & write rawdata.txt
    if (readNamesWriteRaw() == -1)
        return -1;
    else 
    {
        // Read rawdata.txt, encrypt using Vigenere Ciphere, & write encrypteddata.txt
        if (readRawWriteEncrypted(vc) == -1)
            return -1;
        else 
        {
            // Build hash table from encrypteddata.txt
            hashTable* ht = new hashTable();
            ht->build("encrypteddata.txt");

            // Run tests
            int randomHashesToCheck[5];
            randomHashesToCheck[0] = rand() % ht->getSize();
            randomHashesToCheck[1] = rand() % ht->getSize();
            randomHashesToCheck[2] = rand() % ht->getSize();
            randomHashesToCheck[3] = rand() % ht->getSize();
            randomHashesToCheck[4] = rand() % ht->getSize();
            test1(randomHashesToCheck, ht, vc);
            test2(randomHashesToCheck, ht, vc);
        }
    }
    

    return 0;
}

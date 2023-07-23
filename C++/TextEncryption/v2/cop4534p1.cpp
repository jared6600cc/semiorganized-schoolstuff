/*
 * Jared Bumgardner
 * COP4534 Project 1
 * 15 Sept. 2021
 */


#include<iostream>
#include<fstream>
#include<sstream>

using namespace std;

class vigenereCipher{
	private:
		//Attributes
		string alphabet = "abcdefghijklmnopqrstuvwxyz";		// alphabet for cipher
		char cipherTable[26][26];							// facillitates encryption
		string encryptedText;								// encrypted text (result)
		string key;											// encryption key
		
		//Methods
		void buildCipherTable(){
			for(int i=0; i < alphabet.length(); i++){		//y-axis iteration
				for(int j=0; j < alphabet.length(); j++){	//x-axis iteration
					cipherTable[i][j] = alphabet.at( (i+j%alphabet.length()) %26);
				}
			}
		}
		
		//Setters
		void setEncryptedText(string setMe){encryptedText = setMe;}
		void setKey(string setMe){key = setMe;}
		
		
	public:
		//Methods
		void encrypt(string encryptMe){
			int x,y,charCase;
			string encryptedMe;
			for(int i=0; i<encryptMe.length(); i++){	//for every letter in encryptMe
				if(isupper(encryptMe[i])){
					charCase = 1;
				} else {charCase = 0;}
				for(int j=0; j<alphabet.length(); j++){	//find x & y
					if(cipherTable[0][j] == tolower(encryptMe[i]))
						x = j;
					if(cipherTable[j][0] == tolower(key[i]))
						y = j;
				}
				char z = cipherTable[y][x];
				if(charCase == 1){
					z = toupper(z);
				}
				encryptedMe.push_back(z);
			}
			setEncryptedText(encryptedMe);
		}
		
		//Constructor
		vigenereCipher(string givenKey){key = givenKey;buildCipherTable();}
		
		//Getters
		string getEncryptedText(){return encryptedText;}
		string getKey(){return key;}
};

struct node{
	string data;
	node *next;
};

class linkedList{
	public:
		node *position;
		node *head;
		node *tail;
		linkedList(){
			position = NULL;
			head = NULL;
			tail = NULL;
		};
		void insert(node insertMe){
			insertMe.next = head;
			head = &insertMe;
		};
		node *find(string findMe){
			position = head;
			while(position != NULL){
				if(position->data == findMe){
					return position;
				}
				position = position->next;
			}
			return NULL;
		}
};

class hashTable{
	private:		
		//Attributes
		linkedList *bucketTable;	// Table of buckets
		node *position;				// For navigating the linked lists
		
	public:
		//Constructor
		hashTable(string buildMe){
			//Build table of linked lists
			linkedList tb[256];
			for(int i=0; i < 256; i++){
				linkedList ll;
				tb[i] = ll;
			}
			bucketTable = tb;
			//Hash in encrypteddata.txt
			string inLine;
			ifstream inFile;
			inFile.open(buildMe, ios::in);
			if(inFile.is_open()){
				while(getline(inFile, inLine)){
					stringstream buffer(inLine);
					getline(buffer, inLine, ' ');	//get userID
					getline(buffer, inLine, ' ');	//get encrypted password
					int hashedIndex = hashFunc(inLine);
					node nd;
					nd.data = buffer.str();
					bucketTable[hashedIndex].insert(nd);
				}
			} else {cout << "Error opening encrypteddata.txt to build hash table";}
		};
		
		//Methods
		int hashFunc(string hashMe){
			int hashedIndex = 0;
			string alphabet = "abcdefghijklmnopqrstuvwxyz";		// alphabet for encoding
			for(int i=0; i < hashMe.length(); i++){
				for(int j=0; j < alphabet.length(); j++){
					if((tolower(hashMe[i])) == alphabet[j]){
						hashedIndex += j;
					}
				}
			}
			return (hashedIndex % 256);
		};
		
		void insert(node insertMe, int indexOfInsertion){
			bucketTable[indexOfInsertion].insert(insertMe);
		};
		
		node *find(string findMe, int hashIndex){
			return bucketTable[hashIndex].find(findMe);
		}
};

void test1(int testSet[5], hashTable h, vigenereCipher v){
	//Output variables
	string userID;
	string plainTextPass;
	string encryptedTextPass;
	int hashIndex;
	node *dataPtr;
	
	cout << "userID\tPassword\tResult\n";					// OUTPUT TEST LABEL	
	for(int i=0; i < 6; i++){
		//Find entry in rawdata.txt
		int indexFound = 0;
		string inLine;
		ifstream inFileNames;
		inFileNames.open("rawdata.txt", ios::in);
		if(inFileNames.is_open()){
			while(getline(inFileNames, inLine)){
				indexFound++;
				stringstream buffer(inLine);
				getline(buffer, inLine, ' ');
				if(testSet[i] == indexFound){	//Correct entry found in rawdata
					userID = inLine;
					hashIndex = h.hashFunc(inLine);	// hash on userID
					getline(buffer, inLine, ' ');
					plainTextPass = inLine;
					v.encrypt(plainTextPass);		// encrypt plaintext password
					encryptedTextPass = v.getEncryptedText();
					dataPtr = h.find(encryptedTextPass, hashIndex);
					break;
				}
				
			}
		} else {cout << "Error opening rawdata.txt in test 1\n";}
		//Output results
		
		cout << userID << "\t" << plainTextPass << "\t";	// OUTPUT TEST RESULTS
		if(dataPtr != NULL)												// OUTPUT TEST RESULTS
			cout << "match\n";									// OUTPUT TEST RESULTS
		else													// OUTPUT TEST RESULTS
			cout << "no match\n";								// OUTPUT TEST RESULTS
	}
	
};
void test2(int testSet[5], hashTable h, vigenereCipher v){
	//Output variables
	string userID;
	string plainTextPass;
	string encryptedTextPass;
	int hashIndex;
	node *dataPtr;
	
	cout << "userID\tPassword\tResult\n";					// OUTPUT TEST LABEL	
	for(int i=0; i < 5; i++){
		//Find entry in rawdata.txt
		int indexFound = 0;
		string inLine;
		ifstream inFileNames;
		inFileNames.open("rawdata.txt", ios::in);
		if(inFileNames.is_open()){
			while(getline(inFileNames, inLine)){
				indexFound++;
				stringstream buffer(inLine);
				getline(buffer, inLine, ' ');
				if(testSet[i] == indexFound){	//Correct entry found in rawdata
					userID = inLine;
					hashIndex = h.hashFunc(inLine);	// hash on userID
					getline(buffer, inLine, ' ');
					// corrupt data
					if(inLine[0] == 'a' || inLine[0] == 'A')
						inLine[0] = 'b';
					else
						inLine[0] = 'a';
					plainTextPass = inLine;
					v.encrypt(plainTextPass);		// encrypt plaintext password
					encryptedTextPass = v.getEncryptedText();
					dataPtr = h.find(encryptedTextPass, hashIndex);
					break;
				}
				
			}
		} else {cout << "Error opening rawdata.txt in test 1\n";}
		//Output results
		
		cout << userID << "\t" << plainTextPass << "\t";	// OUTPUT TEST RESULTS
		if(dataPtr != NULL)												// OUTPUT TEST RESULTS
			cout << "match\n";									// OUTPUT TEST RESULTS
		else													// OUTPUT TEST RESULTS
			cout << "no match\n";								// OUTPUT TEST RESULTS
	}
	
};

int main(){
	srand(time(NULL));
	string encryptionKey = "abcdefghi";
	vigenereCipher vc(encryptionKey);

	// Read userIDs
	int numInputLines = 0;
	string inLine;
	ifstream inFileNames;
	inFileNames.open("names.txt", ios::in);
	if(inFileNames.is_open()){
		ofstream outFileRaw("rawdata.txt");
		if(outFileRaw.is_open()){
			while(getline(inFileNames, inLine)){
				stringstream buffer(inLine);
				getline(buffer, inLine, ' ');
				// Generate password for each user
				string outLine = "";
				for(int i=0; i < 6; i++){
					char nextChar;
					int nextCharCase = rand()%2;
					if(nextCharCase == 0)	// lowercase
					nextChar = 'a'+rand()%26;
					else					// uppercase
					nextChar = 'A'+rand()%26;
					outLine += nextChar;				
				}
				outFileRaw << inLine << " " << outLine << '\n';
				numInputLines++;
			}
		} else {cout << "Error opening output file: rawdata.txt";}
		outFileRaw.close();			// Close output file: rawdata.txt
		
		// Encrypt raw data using Vigenere cipher
		ifstream inFileRaw;
		inFileRaw.open("rawdata.txt", ios::in);
		if(inFileRaw.is_open()){
			ofstream outFileEncrypted("encrypteddata.txt");
			if(outFileEncrypted.is_open()){
				while(getline(inFileRaw, inLine)){
					stringstream buffer(inLine);
					getline(buffer, inLine, ' ');//get userID
					outFileEncrypted << inLine << ' ';
					getline(buffer, inLine, ' ');//get userPass
					vc.encrypt(inLine);
					outFileEncrypted << vc.getEncryptedText() << '\n';
				}
			} else {cout << "Error opening output file: encrypteddata.txt" << '\n';}
			outFileEncrypted.close();	// Close output file: encrypteddata.txt
		} else {cout << "Error opening input file: rawdata.txt" << '\n';}
		inFileRaw.close();			// Close input file: rawdata.txt
	} else {cout << "Error opening input file: names.txt";}
	inFileNames.close();		// Close input file: names.txt
	
	// Build hash table from encrypteddata.txt
	hashTable ht("encrypteddata.txt");
	
	// Run tests on hash table
	int randomEntries[5];
	randomEntries[0] = rand()%numInputLines;
	randomEntries[1] = rand()%numInputLines;
	randomEntries[2] = rand()%numInputLines;
	randomEntries[3] = rand()%numInputLines;
	randomEntries[4] = rand()%numInputLines;
	cout << "LEGAL: \n";									// OUTPUT TEST LABEL 1
	test1(randomEntries, ht, vc);

	cout << "\nILLEGAL: \n";								// OUTPUT TEST LABEL 2
	test2(randomEntries, ht, vc);
	
	return 0;
}
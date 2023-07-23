#ifndef VIGENERE_CIPHER_H
#define VIGENERE_CIPHER_H

#include <iostream>

namespace V
{
	class vigenereCipher
	{
	public:
		// Constructor(s)
		vigenereCipher(std::string givenKey);
		// Getter(s)
		std::string getKey();
		// Method(s)
		std::string encrypt(std::string encryptMe);
		
	private:
		// Attribute(s)
		std::string key;
		std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
		char cipherTable[26][26];
		// Method(s)
		void buildCipherTable();
	};
}


#endif /* VIGENERE_CIPHER_H*/
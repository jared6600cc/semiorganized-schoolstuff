#include "vigenereCipher.hpp"
#include <iostream>

using namespace V;
using namespace std;

V::vigenereCipher::vigenereCipher(string givenKey)
{
	key = givenKey;
	buildCipherTable();
}

string V::vigenereCipher::getKey()
{
	return key;
}

std::string V::vigenereCipher::encrypt(string encryptMe)
{
	int x = 0;
	int y = 0;
	int z = 0;
	int charCase = 0;
	string encryptedText;
	for (int i = 0; i < encryptMe.length(); i++) 
	{
		if (isupper(encryptMe[i])) 
		{
			charCase = 1;
		}
		else 
		{
			charCase = 0;
		}
		for (int j = 0; j < alphabet.length(); j++) 
		{
			if (cipherTable[0][j] == tolower(encryptMe[i]))
				x = j;
			if (cipherTable[j][0] == tolower(key[i]))
				y = j;
		}
		z = cipherTable[y][x];
		if (charCase == 1)
			z = toupper(z);
		encryptedText.push_back(z);
	}
	return encryptedText;
}

void V::vigenereCipher::buildCipherTable()
{
	for (int i = 0; i < alphabet.length(); i++) 
	{
		for (int j = 0; j < alphabet.length(); j++) 
		{
			cipherTable[i][j] = alphabet.at((i + j % alphabet.length()) % 26);
		}
	}
}
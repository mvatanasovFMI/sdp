// Problem3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <cryptopp/rsa.h>
#include <cryptopp/osrng.h>
#include "RSACryptoManager.h"
using namespace CryptoPP;
using namespace std;

int main() {
	string encryptedText = "";
	string decryptedText = "";
	string plainText = "Abra ka dabra";

	cout << "CRYPT TEST, text to be encrypted: " << plainText << endl;
	
	RSACryptoManager manager;

	encryptedText = manager.EncryptText(plainText);
	cout << "Encrypted text: " << encryptedText << endl;

	////////////////////////////////////////////////////
	////// Generate keys
	//AutoSeededRandomPool rng;

	//InvertibleRSAFunction params;
	//params.GenerateRandomWithKeySize(rng, 3072);

	//RSA::PrivateKey privateKey(params);
	//RSA::PublicKey publicKey(params);
	//
	//////////////////////////////////////////////////
	//// Encryption
	//RSAES_OAEP_SHA_Encryptor e(publicKey);

	//StringSource ss1(plainText, true,
	//	new PK_EncryptorFilter(rng, e,
	//		new StringSink(encryptedText)
	//	) // PK_EncryptorFilter
	//);

	cout << "Encrypted text: "<< encryptedText << endl;

	decryptedText = manager.DecryptText(encryptedText);
	//////////////////////////////////////////////////
	//// Decryption
	//RSAES_OAEP_SHA_Decryptor d(privateKey);

	//StringSource ss2(encryptedText, true,
	//	new PK_DecryptorFilter(rng, d,
	//		new StringSink(decryptedText)
	//	) // PK_DecryptorFilter
	//); // StringSource

	cout << "Decrpyted text: " << decryptedText << endl;

	std::cin.get();
	return 0;
}


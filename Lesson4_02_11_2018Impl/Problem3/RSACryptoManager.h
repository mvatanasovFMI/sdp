#pragma once
#include <string>
#include <cryptopp/rsa.h>
#include <cryptopp/osrng.h>
using namespace CryptoPP;


using namespace std;
class RSACryptoManager
{
private:
	
	AutoSeededRandomPool m_rng;
	RSA::PrivateKey m_privateKey;
	RSA::PublicKey m_publicKey;
	RSAES_OAEP_SHA_Encryptor m_encryptor;
	
public:
	RSACryptoManager();
	string EncryptText(string plainText);
	string DecryptText(string encryptedText);
};


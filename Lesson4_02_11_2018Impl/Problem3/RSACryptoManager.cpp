#include "stdafx.h"
#include "RSACryptoManager.h"

RSACryptoManager::RSACryptoManager()
{
	InvertibleRSAFunction params;
	params.GenerateRandomWithKeySize(m_rng, 3072);

	m_privateKey = RSA::PrivateKey(params);
	m_publicKey = RSA::PublicKey(params);
}

string RSACryptoManager::EncryptText(string plainText)
{
	RSAES_OAEP_SHA_Encryptor e(m_publicKey);
	string encryptedText;
	StringSource ss1(plainText, true,
		new PK_EncryptorFilter(m_rng, e,
			new StringSink(encryptedText)
		) // PK_EncryptorFilter
	);
	return encryptedText;
}

string RSACryptoManager::DecryptText(string encryptedText)
{
	RSAES_OAEP_SHA_Decryptor d(m_privateKey);
	string decryptedText;
	StringSource ss2(encryptedText, true,
		new PK_DecryptorFilter(m_rng, d,
			new StringSink(decryptedText)
		) // PK_DecryptorFilter
	); // StringSource
	return decryptedText;
}

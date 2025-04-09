#include <iostream>
#include "BlumBlumShubGenerator.h"
#include "ConversionUtils.h"
#include "VernamCipherCoder.h"
#include "VernamCipherDecoder.h"

void viewGeneratorProperties(const BlumBlumShubGenerator& generator) {
	std::cout << "Big primaries: p = " <<
		generator.getBigPrimaries().first << ", q = " << generator.getBigPrimaries().second << std::endl;
	std::cout << "p * q = " << generator.getPrimaryNumbersProduct() << std::endl;
	std::cout << "seed = " << generator.getSeed() << std::endl;
	std::cout << "X(0) = " << generator.getLastGeneratedNumber() << std::endl;
}

void showBitVectorContent(const std::vector<bool>& v) {
	for (size_t i = 0; i < v.size(); i++) {
		std::cout << v[i];
	}
	std::cout << std::endl;
}

int main(int argc, char** argv) {
	BlumBlumShubGenerator generator;
	viewGeneratorProperties(generator);

	std::string message;
	std::cin >> message;
	std::cout << "Message to be encrypted: " << message << std::endl << std::endl;
	std::cout << "Message bits: ";
	showBitVectorContent(convertStringToBitsContainer(message));

	VernamCipherCoder coder;
	coder.generateKey(message.size() * 8, generator);
	std::cout << "Generated key size: " << coder.getKey().size() << ", Generated key: ";
	coder.showGeneratedKey();
	std::cout << std::endl;

	auto [encryptedMessageString, encryptedMessageBits] = coder.encryptMessage(message);

	std::cout << "Encrypted message string: " << encryptedMessageString << std::endl;
	std::cout << "Encrypted message bits: ";
	showBitVectorContent(encryptedMessageBits);
	std::cout << std::endl;
	
	VernamCipherDecoder decoder;
	decoder.setKey(coder.getKey());

	auto [decryptedMessageString, decryptedMessageBits] = decoder.decryptMessage(encryptedMessageBits);
	std::cout << "Decrypted message string: " << decryptedMessageString << std::endl;
	std::cout << "Decrypted message bits: ";
	showBitVectorContent(decryptedMessageBits);

	return 0;
}
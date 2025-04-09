#include "VernamCipherCoder.h"
#include "ConversionUtils.h"
#include <iostream>

void VernamCipherCoder::generateKey(size_t messageSize, BlumBlumShubGenerator& generator) {
	for (size_t i = 0; i < messageSize; i++) {
		key.push_back(generator.nextNumber() % 2);
	}
}

std::pair<std::string, std::vector<bool>>  VernamCipherCoder::encryptMessage(const std::string& message) const {
	if (key.empty()) {
		std::cout << "Trying to encrypt message without a key!" << std::endl;
		std::vector<bool> emptyVector;
		return std::make_pair("", emptyVector);
	}

	auto messageBits = convertStringToBitsContainer(message);
	auto encryptedMessageBits = xorBits(messageBits, key);
	auto encryptedMessageString = convertBitsContainerToString(encryptedMessageBits);

	return std::make_pair(encryptedMessageString, encryptedMessageBits);
}

void VernamCipherCoder::showGeneratedKey() const {
	for (size_t i = 0; i < key.size(); i++) {
		std::cout << key[i];
	}
	std::cout << std::endl;
}
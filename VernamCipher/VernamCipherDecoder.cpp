#include "VernamCipherDecoder.h"
#include "ConversionUtils.h"
#include <iostream>

std::pair<std::string, std::vector<bool>> VernamCipherDecoder::decryptMessage(const std::vector<bool>& messageBits) const {
	if (key.empty()) {
		std::cout << "Trying to decrypt message without a key!" << std::endl;
		std::vector<bool> emptyVector;
		return std::make_pair("", emptyVector);
	}

	auto decryptedMessageBits = xorBits(messageBits, key);
	auto decryptedMessageString = convertBitsContainerToString(decryptedMessageBits);

	return std::make_pair(decryptedMessageString, decryptedMessageBits);
}

void VernamCipherDecoder::showKey() const {
	for (size_t i = 0; i < key.size(); i++) {
		std::cout << key[i];
	}
	std::cout << std::endl;
}

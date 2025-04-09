#pragma once
#include "ConversionUtils.h"
#include <bitset>
#include <iostream>

std::vector<bool> convertStringToBitsContainer(const std::string& text) {
	std::vector<bool> bits;

	for (char ch : text) {
		std::bitset<8> characterByte(ch);
		for (int i = 7; i >= 0; --i) {
			bits.push_back(characterByte[i]);
		}
	}

	return bits;
}

std::vector<bool> xorBits(const std::vector<bool>& a, const std::vector<bool>& b) {
	std::vector<bool> xorResult;
	const auto n = std::min(a.size(), b.size());

	for (size_t i = 0; i < n; ++i) {
		xorResult.push_back(a[i] ^ b[i]);
	}

	return xorResult;
}

std::string convertBitsContainerToString(const std::vector<bool>& bits) {
	std::string resultString;

	if (bits.size() % 8 != 0) {
		std::cout << "Number of bits is not a multiple of 8!" << std::endl;
		return resultString;
	}

	for (size_t i = 0; i < bits.size(); i += 8) {
		std::bitset<8> byte;
		for (int j = 0; j < 8; ++j) {
			byte[7 - j] = bits[i + j]; // przywrócenie kolejności bitów
		}
		resultString += static_cast<char>(byte.to_ulong());
	}

	return resultString;
}


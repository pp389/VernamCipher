#pragma once
#include "BlumBlumShubGenerator.h"
#include <vector>
#include <string>

class VernamCipherCoder {
private:
	std::vector<bool> key;

public:
	VernamCipherCoder() {};
	~VernamCipherCoder() {};
	void generateKey(size_t messageSize, BlumBlumShubGenerator& generator);
	std::pair<std::string, std::vector<bool>> encryptMessage(const std::string& message) const;
	void showGeneratedKey() const;
	std::vector<bool> getKey() const { return key; };
};
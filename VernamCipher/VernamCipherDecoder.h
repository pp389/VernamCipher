#pragma once
#include <vector>
#include <string>

class VernamCipherDecoder {
private:
	std::vector<bool> key;

public:
	VernamCipherDecoder() {};
	~VernamCipherDecoder() {};
	void setKey(const std::vector<bool>& key) { this->key = key; };
	std::pair<std::string, std::vector<bool>> decryptMessage(const std::vector<bool>& messageBits) const;
	void showKey() const;
	std::vector<bool> getKey() const { return key; };
};
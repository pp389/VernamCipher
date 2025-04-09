#pragma once
#include <utility> //for std::make_pair()
#include <vector>

class BlumBlumShubGenerator {
private:
	unsigned long long bigPrimary_p, bigPrimary_q; //big primary numbers which must be generated
	unsigned long long pqProduct; //bigPrimary_p * bigPrimary_q
	unsigned long long seed; //seed is in range [1, pqProduct - 1]
	std::vector<unsigned long long> primeNumbers;
	
	void initializeGenerator();
	void chooseSeed();
	void choosePrimeNumbers();

	unsigned long long lastGeneratedNumber;

public:
	BlumBlumShubGenerator();
	~BlumBlumShubGenerator() {};
	unsigned long long nextNumber();
	auto getLastGeneratedNumber() const { return lastGeneratedNumber; };
	auto getBigPrimaries() const { return std::make_pair(bigPrimary_p, bigPrimary_q); };
	auto getSeed() const { return seed;  };
	auto getPrimaryNumbersProduct() const { return pqProduct; };
};
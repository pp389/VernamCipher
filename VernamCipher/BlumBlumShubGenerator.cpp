#include "BlumBlumShubGenerator.h"
#include "PrimeNumbersUtils.h"
#include <random>

BlumBlumShubGenerator::BlumBlumShubGenerator() {
	primeNumbers = generateBigPrimeNumbers<unsigned long long>(3000);
	initializeGenerator();
}

void BlumBlumShubGenerator::chooseSeed() {
	std::random_device randomDevice;
	std::mt19937 generator(randomDevice());
	std::uniform_int_distribution<unsigned long long> distribution(1, pqProduct - 1);

	seed = distribution(generator);
}

void BlumBlumShubGenerator::choosePrimeNumbers() {
	std::random_device randomDevice;
	std::mt19937 generator(randomDevice());
	std::uniform_int_distribution<> distribution(0, 2999);

	bigPrimary_p = primeNumbers[distribution(generator)];
	bigPrimary_q = primeNumbers[distribution(generator)];
}

void BlumBlumShubGenerator::initializeGenerator() {
	choosePrimeNumbers();
	pqProduct = bigPrimary_p * bigPrimary_q;
	chooseSeed();
	lastGeneratedNumber = (seed * seed) % pqProduct;
}

unsigned long long BlumBlumShubGenerator::nextNumber() {
	lastGeneratedNumber = (lastGeneratedNumber * lastGeneratedNumber) % pqProduct;
	return lastGeneratedNumber;
}
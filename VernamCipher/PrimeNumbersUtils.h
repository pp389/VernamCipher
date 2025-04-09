#include <vector>

template<typename T>
bool isPrime(const T& number) {
	if (number < 2) {
		return false;
	}

	for (int i = 2; i * i <= number; i++) {
		if (number % i == 0) {
			return false;
		}
	}

	return true;
}

template<typename T>
std::vector<T> generateBigPrimeNumbers(const T& count) {
	std::vector<T> primeNumbers;
	primeNumbers.reserve(count);
	T number = 7919;

	while (primeNumbers.size() < count) {
		if (isPrime(number)) {
			primeNumbers.push_back(number);
		}
		number++;
	}

	return primeNumbers;
}
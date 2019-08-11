// 29. Divide Two Integers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

int divide(int dividend, int divisor) {
	if (dividend == INT_MIN && divisor == -1) {
		return INT_MAX;
	}

	int sign = (dividend > 0) ^ (divisor > 0) ? -1 : 1;
	long res = 0;
	long ldividend = labs(dividend);
	long ldivisor = labs(divisor);

	while (ldividend >= ldivisor) {
		long sum = ldivisor, count = 1;
		while (sum << 1 <= ldividend) {
			sum <<= 1;
			count <<= 1;
		}
		res += count;
		ldividend -= sum;
	}

	return sign * res;
}

int main() {
	int dividend = -1;
	int divisor = 1;
	int res = divide(dividend, divisor);

    std::cout << res << std::endl;

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

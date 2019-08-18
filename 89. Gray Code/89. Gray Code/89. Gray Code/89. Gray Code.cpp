// 89. Gray Code.cpp
//The gray code is a binary numeral system where two successive values differ in only one bit.
//
//Given a non - negative integer n representing the total number of bits in the code, print the sequence of gray code.A gray code sequence must begin with 0.
//
//Example 1:
//
//Input: 2
//	Output : [0, 1, 3, 2]
//	Explanation :
//	00 - 0
//	01 - 1
//	11 - 3
//	10 - 2
//
//	For a given n, a gray code sequence may not be uniquely defined.
//	For example, [0, 2, 3, 1] is also a valid gray code sequence.
//
//	00 - 0
//	10 - 2
//	11 - 3
//	01 - 1
//	Example 2:
//
//   Input: 0
//	   Output : [0]
//	   Explanation : We define the gray code sequence to begin with 0.
//	   A gray code sequence of n has size = 2n, which for n = 0 the size is 20 = 1.
//	   Therefore, for n = 0 the gray code sequence is[0].

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

int toInt(vector<int> v) {
	int digit = v.size();
	int res = 0;
	for (int i = 0; i < digit; i++) {
		if (v[i] == 1) {
			res += pow(2, i);
		}
	}
	return res;
}

vector<vector<int>> iterate(vector<vector<int>> v) {
	vector<vector<int>> res;
	for (int i = 0; i < v.size(); i++) {
		vector<int> v1 = v[i];
		vector<int> v2 = v[i];
		v1.push_back(0);
		v2.push_back(1);
		if (i % 2 == 0) {
			res.push_back(v1);
			res.push_back(v2);
		}
		else {
			res.push_back(v2);
			res.push_back(v1);
		}
	}
	return res;
}

vector<int> grayCode(int n) {
	if (n == 0) {
		return { 0 };
	}
	vector<vector<int>> v = { {0}, {1}};
	vector<int> res;
	for (int i = 1; i < n; i++) {
		v = iterate(v);
	}
	for (vector<int> d : v) {
		res.push_back(toInt(d));
	}
	return res;
}



int main()
{
	grayCode(2);
    std::cout << "Hello World!\n"; 
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

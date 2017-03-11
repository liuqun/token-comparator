/*
 *
 */

#include <string>
#include <iostream>
using namespace std;

#include "ProblemSolver.h"

void test_1() {
	string a("aaaa.iloveyou.aaaa");
	string b("bbbb.iloveyou.bbbb");
	string expected(".iloveyou.");

	string result = FindLongestCommonToken(a, b);
	if (result.compare(expected) == 0) {
		cout << "Test 1: Pass" << endl;
	} else {
		cout << "Test 1: Failed" << endl;
		cout << "Expected result is \"" << expected << "\"" << endl;
		cout << "Actual result is \"" << result << "\"" << endl;
	}
}

/*
 *
 */

#include <string>
#include <iostream>
using namespace std;

#include <cstring>
#include <cstdio>
#include "ProblemSolver.h"
#include "ProblemSolver_test.h"

int main()
{
	test_1();
	test_1_c_api();
	test_2_recursively_find_longest_common_token();
	return (0);
}

const char a[] = ".iloveyou.";
const char b[] = ".iloveyou.";
const char expected[] = ".iloveyou.";

void test_1() {
	const char *pTestName = "Test 1 (for C++ API)";
	string result;

	result = ProblemSolver::FindLongestCommonToken(a, b);
	if (result.compare(expected) == 0) {
		cout << pTestName << ": Pass" << endl;
	} else {
		cout << pTestName << ": Failed" << endl;
		cout << "Expected result is \"" << expected << "\"" << endl;
		cout << "Actual result is \"" << result << "\"" << endl;
	}
}

void test_1_c_api() {
	const char *pTestName = "Test 1 (for C API)";
	char *result;

	result = FindLongestCommonToken(a, b);
	if (!result) {
		printf("%s: Failed\n", pTestName);
		printf("Expected result is \"%s\"\n", expected);
		printf("Actual result is NULL pointer\n");
	} else if (strlen(result) != strlen(expected)) {
		printf("%s: Failed\n", pTestName);
		printf("Expected result length=%d\n", strlen(expected));
		printf("Actual result length=%d\n", strlen(result));
	} else if (strncmp(expected, result, strlen(expected)) != 0) {
		printf("%s: Failed\n", pTestName);
		printf("Expected result is \"%s\"\n", expected);
		printf("Actual result is \"%s\"\n", result);
	} else {
		printf("%s: Pass\n", pTestName);
	}
	if (result) {
		FreeToken(result);
	}
}

void test_2_recursively_find_longest_common_token() {
	const char *pTestName = "Test 2: Test C++ API RecursivelyFindLongestCommonToken()";
	string result;

	result = ProblemSolver::FindLongestCommonToken_Recursively(a, b);
	if (result.compare(expected) == 0) {
		cout << pTestName << ": Pass" << endl;
	} else {
		cout << pTestName << ": Failed" << endl;
		cout << "Expected result is \"" << expected << "\"" << endl;
		cout << "Actual result is \"" << result << "\"" << endl;
	}
}

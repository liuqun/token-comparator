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

const char a[] = "aaaa.iloveyou.aaaa";
const char b[] = "bbbb.iloveyou.bbbb";
const char expected[] = ".iloveyou.";

void test_1() {
	string result;

	result = ProblemSolver::FindLongestCommonToken(a, b);
	if (result.compare(expected) == 0) {
		cout << "Test 1: Pass" << endl;
	} else {
		cout << "Test 1: Failed" << endl;
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

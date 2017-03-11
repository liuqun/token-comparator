/*
 *
 */

#include <string>
using std::string;
#include <cstring>
#include <cstdlib>
#include <cassert>

#include "ProblemSolver.h"

string ProblemSolver::FindLongestCommonToken(string a, string b) {
	string result;
	string *pShorter;
	string *pLonger;
	size_t resultLength;
	const char *p1;
	const char *p2;

	if (a.length() < b.length()) {
		pShorter = &a;
		pLonger = &b;
	} else {
		pShorter = &b;
		pLonger = &a;
	}

	resultLength = pShorter->length();
	p1 = pShorter->c_str();
	p2 = pLonger->c_str();
	while (resultLength > 0) {
		for (size_t i = (pShorter->length() - resultLength); i > 0; i--) {
			for (size_t j = (pLonger->length() - resultLength); j > 0; j--) {
				if (strncmp(p1 + i, p2 + j, resultLength) == 0) {
					result = pShorter->substr(i, resultLength);
					return result;
				}
			}
		}
		resultLength--;
	}
	result = "";
	return result;
}

/**
 * The following API functions are provided for C applications:
 * See ProblemSolver.h for details
 */

/*
 *
 */
int HasCommonToken(const char a[], const char b[]) {
	return ProblemSolver::FindLongestCommonToken(a, b).length();
}

/*
 *
 */
char *FindLongestCommonToken(const char a[], const char b[]) {
	char *result;
	string token;

	token = ProblemSolver::FindLongestCommonToken(a, b);
	result = static_cast<char *>(malloc(token.length() + 1));
	strncpy(result, token.c_str(), token.length());
	result[token.length()] = '\0';
	return result;
}

/*
 *
 */
void FreeToken(char token[]) {
	assert(token);
	free(token);
}

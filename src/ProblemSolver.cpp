/*
 *
 */

#include <string>
using std::string;
#include <cstring>

#include "ProblemSolver.h"

string FindLongestCommonToken(string a, string b) {
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

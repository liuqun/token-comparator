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
	// 当前已经实现了迭代和递归两种算法, 如果用户不指定, 则替用户选择一种默认算法. (当前实现的递归和迭代算法时间复杂度相同)
	return ProblemSolver::FindLongestCommonToken_Iteratively(a, b);
}

/*
 * 内部函数: _FindLongestCommonToken_Recursively()
 * 功能说明: 已知两个字符串的长短, 取较短的字符串进行拆分, 向较长的字符串进行对比, 查找最大公共字段
 * 参数: string shorter, string longer
 * 返回值: string -- 若找不到公共字段则返回长度为 0 的 C++ 字符串, 否则正常返回找到的字符串
 */
static string _FindLongestCommonToken_Recursively(string shorter, string longer) {
	string result;
	string resultLeftHand;
	string resultRightHand;
	int nLeftHandTokenLen;
	int nRightHandTokenLen;

	if (shorter.length() <= 0) {  // 递归终止条件 1: 字符串 shorter 已经不能继续分割成左右两部分
		result = "";
		return result;
	}

	if ((int) longer.find(shorter) > (int) string::npos) {
		result = shorter;  // 递归终止条件 2: 在字符串 longer 中找到了完整的子字符串 shorter
		return result;
	}

	/* 将字符串 shorter 拆分为左右两半部分: */
	/* 左半部分子字符串是前 n-1 个字符的全部排列组合, 即删除最后一个字母后剩余的左半部分 */
	/* 例如: "iloveu" 的左半部分为 "ilove" */
	const string leftHandToken = shorter.substr(0, shorter.length() - 1);
	resultLeftHand = _FindLongestCommonToken_Recursively(leftHandToken, longer);  // 递归
	nLeftHandTokenLen = resultLeftHand.length();

	/* shorter 右半部分子字符串 */
	/* 注意这里拆出来右半部分字符串是一组共 n-1 个字符串, 所有字符串均以原最后一个字母结尾 */
	/* 最大长度为 len-1, 最小长度为 0 */
	/* 例如: "iloveu"的右半部分为 "loveu", "oveu", "veu", "eu", "u", "" */
	resultRightHand = "";
	nRightHandTokenLen = shorter.length() - 1;
	for (int i = 1; nRightHandTokenLen > nLeftHandTokenLen; i++, nRightHandTokenLen--) {
		const string rightHandToken = shorter.substr(i, nRightHandTokenLen);
		if ((int) longer.find(rightHandToken) > (int) string::npos) {
			resultRightHand = rightHandToken;
			break;
		}
	}

	result = (nLeftHandTokenLen >= nRightHandTokenLen)? resultLeftHand : resultRightHand;
	return result;
}

/*
 *
 */
string ProblemSolver::FindLongestCommonToken_Recursively(string a, string b) {
	string result;
	const string *pShorter;
	const string *pLonger;

	if (a.length() < b.length()) {
		pShorter = &a;
		pLonger = &b;
	} else {
		pShorter = &b;
		pLonger = &a;
	}

	return _FindLongestCommonToken_Recursively(*pShorter, *pLonger);
}

/*
 *
 */
string ProblemSolver::FindLongestCommonToken_Iteratively(string a, string b) {
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

int HasCommonToken_Iteratively(const char a[], const char b[]) {
	return ProblemSolver::FindLongestCommonToken_Iteratively(a, b).length();
}

int HasCommonToken_Recursively(const char a[], const char b[]) {
	return ProblemSolver::FindLongestCommonToken_Recursively(a, b).length();
}

/*
 * 内部函数: _CloneFromString()
 * 功能: 将 C++ 字符串克隆一份至 C 字符串
 */
static char *_CloneFromString(string& token) {
	char *result;

	result = static_cast<char *>(malloc(token.length() + 1));
	strncpy(result, token.c_str(), token.length());
	result[token.length()] = '\0';
	return result;
}

/*
 *
 */
char *FindLongestCommonToken(const char a[], const char b[]) {
	string token;

	token = ProblemSolver::FindLongestCommonToken(a, b);
	return _CloneFromString(token);
}

char *FindLongestCommonToken_Iteratively(const char a[], const char b[]) {
	string token;

	token = ProblemSolver::FindLongestCommonToken_Iteratively(a, b);
	return _CloneFromString(token);
}

char *FindLongestCommonToken_Recursively(const char a[], const char b[]) {
	string token;

	token = ProblemSolver::FindLongestCommonToken_Recursively(a, b);
	return _CloneFromString(token);
}

/*
 *
 */
void FreeToken(char token[]) {
	assert(token);
	free(token);
}

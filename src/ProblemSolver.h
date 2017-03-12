/*
 *
 */

#ifndef PROBLEMSOLVER_H_
#define PROBLEMSOLVER_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * The following API functions are provided for C applications:
 * ----
 *
 * Function: FindLongestCommonToken(), FreeToken()
 * Usage:
 * #indlude <ProblemSolver.h>
 * char *pToken = FindLongestCommonToken("cde", "abcdefg");
 * ...
 * FreeToken(pToken);
 *
 * Function: HasCommonToken()
 * Usage:
 * if (HasCommonToken(a, b)) {
 *     。。。
 * }
 */

/**
 * 函数名: FindLongestCommonToken()
 * 功能: 搜索重复字符串
 * 参数: char a[], char b[]
 * 用法举例:
 *     char *pToken = FindLongestCommonToken("love", "I love you")
 *     。。。
 *     FreeToken(pToken);
 * 返回值类型: char * -- 函数返回一块通过 malloc() 动态分配字符串内存空间, 建议使用附带的 FreeToken(token) 释放内存, 使用 strlen(token)
 *                   即使当 a 和 b 之间不存在重复字符串时, token 也永远不会返回空指针 NULL, 而只会返回一个长度 1 字节、内容为 '\0' 的内存块
 */
char *FindLongestCommonToken(const char a[], const char b[]);  /* C API */
char *FindLongestCommonToken_Iteratively(const char a[], const char b[]);  /* C API */
char *FindLongestCommonToken_Recursively(const char a[], const char b[]);  /* C API */

/**
 * 函数名: FreeToken()
 * 功能: 释放由  FindLongestCommonToken() 自动申请的内存空间
 * 参数: char *pToken
 * 返回值: 无
 */
void FreeToken(char token[]);  /* C API */

/**
 * 函数名: HasCommonToken()
 * 功能: 搜索重复字符串
 * 参数: char a[], char b[]
 * 用法举例: char *pToken = FindLongestCommonToken("love", "I love you")
 * 返回值类型: int -- 当 a 和 b 之间不存在重复字符串时返回值 == 0 代表 false, 其他情况下会返回一个正整数,
 *                这个正整数返回值并不是 a[] 或 b[] 的数组下标, 有可能是 a、b 之间最大重复字符串本身的字节数
 */
int HasCommonToken(const char a[], const char b[]);  /* C API */
int HasCommonToken_Iteratively(const char a[], const char b[]);  /* C API */
int HasCommonToken_Recursively(const char a[], const char b[]);  /* C API */

#ifdef __cplusplus
}  // extern "C"
#endif /* __cplusplus */

#ifdef __cplusplus

#include <string>

namespace ProblemSolver {
/**
 * C++ API:
 * #indlude <ProblemSolver.h>
 * using ProblemSolver::FindLongestCommonToken;
 *
 * Here are some test samples:
 *     cout << FindLongestCommonToken("cde", "abcdefg") << endl;
 * >>>>cde
 *
 *     cout << FindLongestCommonToken("aaailoveyouaaa", "bbbiloveyoubbb") << endl;
 * >>>>iloveyou
 *
 *     cout << FindLongestCommonToken("aaa", "bbb") << endl;
 * >>>>
 *
 * 返回值说明: 当字符串 a 和 b 不存在重复字段时, 函数返回长度为 0 的 C++ string
 */

/**
 * 函数名: FindLongestCommonToken()
 * 功能: 搜索重复字符串
 * 参数: string a, string b
 * 返回值: string result
 */
extern std::string FindLongestCommonToken(std::string a, std::string b);

/**
 * 函数名: FindLongestCommonToken_Iteratively()
 * 功能: 循环迭代方式搜索重复字符串
 * 参数: string a, string b
 * 返回值: string result
 */
extern std::string FindLongestCommonToken_Iteratively(std::string a, std::string b);

/**
 * 函数名: FindLongestCommonToken_Recursively()
 * 功能: 递归方式搜索重复字符串
 * 备注: 参数以及返回值与 IterativelyFindLongestCommonToken() 完全享用, 可以相互替换使用
 */
extern std::string FindLongestCommonToken_Recursively(std::string a, std::string b);

} // end namespace

#endif /* __cplusplus */

#endif /* PROBLEMSOLVER_H_ */

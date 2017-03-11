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
 * FreeToken(Token);
 *
 * Function: HasCommonToken()
 * Usage:
 * if (HasCommonToken(a, b)) {
 *     。。。
 * }
 */
char *FindLongestCommonToken(const char a[], const char b[]);  /* C API */
void FreeToken(char token[]);  /* C API */
int HasCommonToken(const char a[], const char b[]);  /* C API */

#ifdef __cplusplus
}  // extern "C"
#endif /* __cplusplus */

#ifdef __cplusplus

#include <string>

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
 */
namespace ProblemSolver {
extern std::string FindLongestCommonToken(std::string a, std::string b);
}

#endif /* __cplusplus */

#endif /* PROBLEMSOLVER_H_ */

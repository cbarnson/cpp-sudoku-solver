/**
 * @file main.cc
 * @author C. Barnson (cbarnson@outlook.com)
 * @brief Read in an unsolved sudoku (9x9) and produce a solution, if one
 * exists.
 * @version 0.1
 * @date 2019-01-11
 *
 * @copyright Copyright (c) 2019
 *
 */
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

#if __has_include("default_cf.h")
#include "default_cf.h"
#define DEBUG 1
#endif

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

/**
 * @brief Given a grid state, where 0's are unassigned spaces (and allowed),
 * determine if is valid (i.e. no conflicts currently exist).
 *
 * @param g 2D vector of integers, representing digits from 0 to 9, where 0 is
 * unassigned.
 * @return true Grid state is valid, no conflicts.
 * @return false Grid state is invalid, there exists an assigned value that has
 * been used more than once in some row or column.
 */
bool isValid(vvi &g) {
  vvi r(10, vi(10, 0));
  vvi c(10, vi(10, 0));
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      r[i + 1][g[i][j]]++;
      c[j + 1][g[i][j]]++;
    }
  }

  for (int i = 1; i < 10; i++) {
    for (int j = 1; j < 10; j++) {
      if (r[i][j] > 1 || c[i][j] > 1) return false;
    }
  }
  return true;
}

/**
 * @brief Solve the sudoku.
 *
 * @param g 2D vector, representing the grid state.
 * @return true Sudoku can be solved, and has been solved.
 * @return false No solution exists.
 */
bool solve(vvi &g) {
  int a, b;
  for (a = 0; a < 9; a++) {
    for (b = 0; b < 9; b++) {
      if (g[a][b] == 0) {
        goto out;
      }
    }
  }
  return true;

out:
  for (int k = 1; k <= 9; k++) {
    g[a][b] = k;
    if (isValid(g) && solve(g)) {
      return true;
    }
  }
  g[a][b] = 0;
  return false;
}

/**
 * @brief Formats the output to look more pretty in a terminal.
 *
 * @param g_initial Snapshot of the grid state when initially read in.
 * @param g Grid state containing solution.
 */
void prettyPrint(vvi &g_initial, vvi &g) {
  cout << "Solution :\n";
  for (int i = 0; i < g.size(); i++) {
    // initial
    if (i == 3 || i == 6) {
      cout << string(3 * (9 + 2), '-');
      cout << "   =>   ";
      cout << string(3 * (9 + 2), '-');
      cout << "\n";
    }
    for (int j = 0; j < g_initial[i].size(); j++) {
      if (j == 3 || j == 6) {
        cout << setw(3) << "|";
      }
      cout << setw(3) << g_initial[i][j];
    }

    cout << "   =>  ";

    for (int j = 0; j < g[i].size(); j++) {
      if (j == 3 || j == 6) {
        cout << setw(3) << "|";
      }
      cout << setw(3) << g[i][j];
    }

    cout << "\n";
  }
}

int main() {
  vvi g(9, vi(9, 0));
  FR(i, 9) FR(j, 9) cin >> g[i][j];
  vvi g_initial(g);
  if (solve(g)) {
    prettyPrint(g_initial, g);
  } else {
    cout << "no solution exists\n";
  }
}

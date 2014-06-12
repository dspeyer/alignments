#include "common.h"

// The standard dynamic programming approach
int plainalign(string a, string b) {
  vector< vector<int> > m;
  int al = a.length();
  int bl = b.length();
  m.resize(al+1);
  for (auto& i : m) {
    i.resize(bl+1);
  }
  for (int j=0; j<=bl; j++) {
    m[0][j] = INSERTION*j;
  }
  for (int i=1; i<=al; i++) {
    m[i][0] = INSERTION*i;
    for (int j=1; j<=bl; j++) {
      int best = m[i-1][j]+INSERTION;
      int maybebest = m[i][j-1]+INSERTION;
      if (maybebest > best) best = maybebest;
      maybebest = m[i-1][j-1]+(a[i-1]==b[j-1] ? MATCH : MISMATCH);
      if (maybebest > best) best = maybebest;
      m[i][j]=best;
    }
  }
  return m[al][bl];
}

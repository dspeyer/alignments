#ifndef _ALIGNMENTS_COMMON_H_
#define _ALIGNMENTS_COMMON_H_

#include<iostream>
#include<limits>
#include<map>
#include<vector>

using namespace std;

// Throughout this code, the idea of exploring the subsequence alignment matrix is used.
// Therefore we can talk about subsequences to be aligned as "coordinates".
typedef pair<int,int> coords;
inline coords operator+(coords a, coords b) {
  return make_pair(a.first+b.first, a.second+b.second);
}
inline ostream & operator<<(ostream& os, coords c) {
  return os << c.first << "," << c.second;
}

const vector<coords> direc = {{-1,-1},{-1,0},{0,-1}};

// neginf needs to be lower than anything we expect to see, but not so low that we get integer underflow
const int neginf = numeric_limits<int>::min() / 2;

// The alignment scores
const int MATCH=1;
const int MISMATCH=-1;
const int INSERTION=-2;

// The standard dynamic programming approach
int plainalign(string a, string b);

// Implementation in a derived class
class recursiveCullingAligner {
 public:
  virtual int calculateScore() = 0;
};
recursiveCullingAligner* newRecursiveCullingAligner(string s1, string s2);

// Compare the two algorythms for a given string pair
void compare(string s1, string s2, int reps);

#endif // _ALIGNMENTS_COMMON_H_

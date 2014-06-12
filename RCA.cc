#include "common.h"

// This is a class just so that its state does not need to be passed in every recursive call
class recursiveCullingAlignerImplementation : public recursiveCullingAligner {
  map<coords, int> knownexact;
  map<coords, int> knownleq;
  string s1;
  string s2;

  // Returns the alignment, or neginf if it cannot find one
  int align(coords c, int target) {
    int origtarget = target;
    if (c.first<0 || c.second<0) {
      return neginf;
    }
    auto knownit = knownexact.find(c);
    if (knownit!=knownexact.end()) {
      return knownit->second;
    }
    knownit = knownleq.find(c);
    if (knownit!=knownleq.end() && knownit->second<=target) {
      return neginf;
    }
    int opt = MATCH*min(c.first, c.second) + INSERTION*abs(c.first-c.second);
    if (opt<target) {
      return neginf;
    }
    int ismatch = (s1[c.first-1]==s2[c.second-1]) ? MATCH : MISMATCH;
    int best = neginf;
    for (int i=0; i<3; i++) {
      int d = i ? INSERTION : ismatch;
      int pos = align(c+direc[i], target-d);
      if (pos>neginf) {
	int v = pos + d;
	if (v>target) {
	  target=v;
	}
	if (v>best) {
	  best=v;
	}
      }
    }
    if (best>origtarget) {
      knownexact[c] = best;
      return best;
    } else {
      knownleq[c]=origtarget;
      return neginf;
    }
  }

public:
  recursiveCullingAlignerImplementation(string _s1, string _s2) : s1(_s1), s2(_s2) {
    knownexact[{0,0}]=0;
  }  

  virtual int calculateScore() {
    return align({s1.length(), s2.length()}, neginf);
  }
};      

recursiveCullingAligner* newRecursiveCullingAligner(string s1, string s2) {
  return new recursiveCullingAlignerImplementation(s1,s2);
}

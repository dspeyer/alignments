#include "common.h"

#include<sys/time.h>
#include<memory>

int operator-(timeval t1, timeval t2) {
  return 1000000*(t1.tv_sec-t2.tv_sec)+t1.tv_usec-t2.tv_usec;
}

// Compare the two algorythms for a given string pair
void compare(string s1, string s2, int reps) {
  float plainTime=0, recTime=0;
  int plainVal, recVal;
  timeval t1,t2;
  float length = (s1.length()+s2.length()) / 2.0;
  for (int i=0; i<reps; i++) {
    // Test normal algorithm
    gettimeofday(&t1,NULL);
    plainVal=plainalign(s1,s2);
    gettimeofday(&t2,NULL);
    plainTime+=static_cast<float>(t2-t1)/reps;
    if (plainVal < length/2) {
      // These are so bad we do not want to wait for recursiveCulling
      return;
    }
    // Test recursive culling
    gettimeofday(&t1,NULL);
    unique_ptr<recursiveCullingAligner> rca(newRecursiveCullingAligner(s1,s2));
    recVal=rca->calculateScore();
    gettimeofday(&t2,NULL);
    recTime+=static_cast<float>(t2-t1)/reps;
    // Make sure the answers match
    if (recVal!=plainVal) {
      cout << "ERROR: different values!" << endl;
      cout << "s1=" << s1 << endl;
      cout << "s2=" << s2 << endl;
      cout << "recVal=" << recVal << " plainVal=" << plainVal;
      exit(1);
    }
  }
  cout << length << ", " << plainTime/1000 << ", " << recTime/1000 << ", " << recVal << endl;
}

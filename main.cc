#include "common.h"

#include<fstream>
#include<glob.h>

main(int argc, char** argv) {
  if (argc!=2) {
    cout << "Must pass exactly one argument, a glob where the genes can be found.\n"
	 << "Remember not to let the shell expand it." << endl;
    exit(1);
  }
  glob_t glob_result;
  glob(argv[1],GLOB_TILDE,NULL,&glob_result);
  vector<string> strings(glob_result.gl_pathc);
  for(int i=0; i<glob_result.gl_pathc; ++i){
    ifstream ifs(glob_result.gl_pathv[i]);
    ifs >> strings[i];
    ifs.close();
  }
  cout << "length, plain, rec, match" << endl;
  for (int i=0; i<strings.size(); i++) {
    for (int j=0; j<=i; j++) {
      compare(strings[i],strings[j],3);
    }
  }
}

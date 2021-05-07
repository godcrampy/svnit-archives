#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <sys/time.h>
#include <sys/types.h>

using namespace std;
int main(int argc, char *argv[]) {
  int *p, temp, ch;
  stringstream ss;
  ss << argv[1];
  ss >> temp;
  p = (int *)malloc(sizeof(int) * temp);
  for (int i = 0; i < temp; i++)
    p[i] = rand();
  struct timeval tp1, tp2;
  gettimeofday(&tp1, NULL);
  sort(p, p + temp);
  gettimeofday(&tp2, NULL);
  cout << (tp2.tv_sec - tp1.tv_sec) * 1000000 + (tp2.tv_usec - tp1.tv_usec)
       << endl;
  return 0;
}
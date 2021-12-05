#include <cctype>
#include <cstring>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char* argv[]) {
  if (argc != 3) {
    cout << "Usage: a.out <source-file> <destination-file>\n";
    return -1;
  }
  string origText;
  ifstream MyReadFile(argv[1]);
  ofstream MyWriteFile(argv[2]);
  while (getline(MyReadFile, origText)) {
    int length = origText.length();
    for (int i = 0; i < length; ++i) {
      char c = origText[i];
      if (isupper(c)) {
        c = c + 32;
        MyWriteFile << c;
      } else if (islower(c)) {
        c = c - 32;
        MyWriteFile << c;
      } else {
        MyWriteFile << c;
      }
    }
  }
  MyReadFile.close();
  MyWriteFile.close();
  return 0;
}

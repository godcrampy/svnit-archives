#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  string original, next;
  cout << "Enter source file name: ";
  cin >> original;
  cout << "Enter destination file name: ";
  cin >> next;
  string origText;
  ifstream MyReadFile(original);
  ofstream MyWriteFile(next);
  string word = "";
  while (getline(MyReadFile, origText)) {
    int length = origText.length();
    for (int i = 0; i < length; ++i) {
      char c = origText[i];
      if (!isspace(c)) {
        MyWriteFile << c;
      } else {
        if (i != 0 && !isspace(origText[i - 1])) {
          MyWriteFile << c;
        }
      }
    }
  }
  MyReadFile.close();
  MyWriteFile.close();
  return 0;
}

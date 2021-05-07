#include <stdlib.h>

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class File {
 public:
  string name;
  long long size;
};

class Directory {
 public:
  string directory;
  int numDirectory;
  vector<File> files;
};

Directory* directory = new Directory();

void createFile(File file) {
  bool fileExists = false;
  for (int i = 0; i < directory->files.size(); ++i) {
    if (directory->files[i].name == file.name) {
      printf("\x1B[1;31mERROR: File already exists in the directory\033[0m\n");
      fileExists = true;
      break;
    }
  }
  if (!fileExists) {
    ++directory->numDirectory;
    directory->files.push_back(file);
    printf("\x1B[1;32mFile Created\033[0m\n");
  }
}

void displayFiles() {
  printf("\x1B[1;34mDIR: \033[0m");
  cout << directory->directory << endl;
  cout << "|-------|-----------|-----------|\n";
  cout << '|';
  printf("\x1B[1;33m Index \033[0m");
  cout << '|';
  printf("\x1B[1;33m File Name \033[0m");
  cout << '|';
  printf("\x1B[1;33m File Size \033[0m");
  cout << '|' << endl;
  cout << "|-------|-----------|-----------|\n";

  for (auto itr = directory->files.begin(); itr < directory->files.end();
       ++itr) {
    int idx = itr - directory->files.begin();
    File file = directory->files[idx];
    cout << '|' << setw(7) << idx + 1 << '|' << setw(11) << file.name << '|'
         << setw(11) << file.size << '|' << endl;
  }
  cout << "|-------|-----------|-----------|\n";
}

void deleteFile(string fileName) {
  bool found = false;
  for (auto itr = directory->files.begin(); itr < directory->files.end();
       ++itr) {
    int idx = itr - directory->files.begin();
    if (directory->files[idx].name == fileName) {
      directory->files.erase(itr);
      --directory->numDirectory;
      found = true;
    }
  }

  if (!found)
    printf("\x1B[1;31mERROR: File doesn't exist in the directory\033[0m\n");
  else
    printf("\x1B[1;31mFile Deleted\033[0m\n");
}

void searchFile(string fileName) {
  bool found = false;
  File file;
  for (auto itr = directory->files.begin(); itr < directory->files.end();
       ++itr) {
    int idx = itr - directory->files.begin();
    if (directory->files[idx].name == fileName) {
      file = directory->files[idx];
      found = true;
    }
  }

  if (!found)
    printf("\x1B[1;31mERROR: File doesn't exist in the directory\033[0m\n");
  else {
    printf("\x1B[1;34mDIR: \033[0m");
    cout << directory->directory << endl;
    cout << "|-----------|-----------|\n";

    cout << '|';
    printf("\x1B[1;33m File Name \033[0m");
    cout << '|';
    printf("\x1B[1;33m File Size \033[0m");
    cout << '|' << endl;
    cout << "|-----------|-----------|\n";
    cout << '|' << setw(11) << file.name << '|' << setw(11) << file.size << '|'
         << endl;
    cout << "|-----------|-----------|\n";
  }
}

int main() {
  cout << "Root Directory Name: ";
  getline(cin, directory->directory);

  // single level
  int choice = 1;
  bool exit = false;

  while (!exit) {
    cout << "Select Choice: "
         << "\n"
         << "1. Create file"
         << "\n"
         << "2. Display file"
         << "\n"
         << "3. Delete file"
         << "\n"
         << "4. Search file"
         << "\n"
         << "5. Exit" << endl;
    cin >> choice;

    if (choice == 1) {
      File file;
      cout << "Enter filename: ";
      cin >> file.name;
      cout << "Enter size of file: ";
      cin >> file.size;
      cout << endl;
      createFile(file);

    } else if (choice == 2) {
      displayFiles();

    } else if (choice == 3) {
      string fileName;
      cout << "Enter filename: ";
      cin >> fileName;
      cout << endl;
      deleteFile(fileName);

    } else if (choice == 4) {
      string fileName;
      cout << "Enter filename: ";
      cin >> fileName;
      cout << endl;
      searchFile(fileName);

    } else if (choice == 5) {
      exit = true;
    } else {
      printf("\x1B[1;31mERROR: Invalid choice.\033[0m\n");
      exit = true;
    }
  }

  return 0;
}
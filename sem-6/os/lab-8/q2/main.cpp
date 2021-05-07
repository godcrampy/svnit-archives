#include <stdlib.h>
#include <unistd.h>

#include <algorithm>
#include <ctime>
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

class UserFileDirectory {
 public:
  string id;
  string name;
  vector<File> files;
};

class MasterDirectory {
 public:
  string name;
  vector<UserFileDirectory> userDirectories;
};

MasterDirectory* directory = new MasterDirectory();
string userID;

void createUserDirectory(string id) {
  userID = id;
  bool found = false;
  for (int i = 0; i < directory->userDirectories.size(); ++i) {
    if (directory->userDirectories[i].id == id) {
      found = true;
      printf(
          "\x1B[1;31mERROR: User directory already exists with this "
          "id\033[0m\n");
      break;
    }
  }
  if (!found) {
    UserFileDirectory userDirectory;
    userDirectory.id = id;
    userDirectory.name = id;
    userDirectory.files = {};
    directory->userDirectories.push_back(userDirectory);
    printf("\x1B[1;32mNew User Created!\033[0m\n");
  }
}

void changeUserDirectory(string id) {
  bool found = false;
  for (auto itr = directory->userDirectories.begin();
       itr < directory->userDirectories.end(); ++itr) {
    int idx = itr - directory->userDirectories.begin();
    if (directory->userDirectories[idx].id == id) {
      userID = id;
      printf("\x1B[1;32mUser directory has been changed\033[0m\n");
      found = true;
      break;
    }
  }

  if (!found) printf("\x1B[1;31mERROR: No such user directory\033[0m\n");
}

void createFile(File file) {
  bool found = false, fileExists = false;
  for (auto itr = directory->userDirectories.begin();
       itr < directory->userDirectories.end(); ++itr) {
    int idx = itr - directory->userDirectories.begin();
    if (directory->userDirectories[idx].id == userID) {
      UserFileDirectory userDirectory = directory->userDirectories[idx];
      for (int i = 0; i < userDirectory.files.size(); ++i) {
        if (userDirectory.files[i].name == file.name) {
          printf(
              "\x1B[1;31mERROR: File already exists in the directory\033[0m\n");
          found = true;
          fileExists = true;
          break;
        }
      }

      if (!fileExists) {
        userDirectory.files.push_back(file);
        directory->userDirectories[idx] = userDirectory;

        printf("\x1B[1;32mFile Created\033[0m\n");
        found = true;
        break;
      }
    }
  }

  if (!found) printf("\x1B[1;31mERROR: No such user directory exists\033[0m\n");
}

void displayFiles() {
  for (auto itr = directory->userDirectories.begin();
       itr < directory->userDirectories.end(); ++itr) {
    int idx = itr - directory->userDirectories.begin();
    if (directory->userDirectories[idx].id == userID) {
      UserFileDirectory userDirectory = directory->userDirectories[idx];
      printf("\x1B[1;34mDIR: \033[0m");

      cout << userDirectory.name << endl;
      cout << "|-------|-----------|-----------|\n";

      cout << '|';
      printf("\x1B[1;33m Index \033[0m");
      cout << '|';
      printf("\x1B[1;33m File Name \033[0m");
      cout << '|';
      printf("\x1B[1;33m File Size \033[0m");
      cout << '|' << endl;
      cout << "|-------|-----------|-----------|\n";
      for (auto it = userDirectory.files.begin();
           it < userDirectory.files.end(); ++it) {
        int j = it - userDirectory.files.begin();
        File file = userDirectory.files[j];
        cout << '|' << setw(7) << j + 1 << '|' << setw(11) << file.name << '|'
             << setw(11) << file.size << '|' << endl;
      }
      cout << "|-------|-----------|-----------|\n";
    }
  }
}

void deleteFile(string fileName) {
  bool found = false;
  for (auto itr = directory->userDirectories.begin();
       itr < directory->userDirectories.end(); ++itr) {
    int idx = itr - directory->userDirectories.begin();
    if (found) break;
    if (directory->userDirectories[idx].id == userID) {
      UserFileDirectory userDirectory = directory->userDirectories[idx];
      for (auto it = userDirectory.files.begin();
           it < userDirectory.files.end(); ++it) {
        int i = it - userDirectory.files.begin();
        if (userDirectory.files[i].name == fileName) {
          userDirectory.files.erase(it);
          directory->userDirectories[idx] = userDirectory;
          printf("\x1B[1;31mFile Deleted\033[0m\n");
          found = true;
          break;
        }
      }
    }
  }

  if (!found)
    printf(
        "\x1B[1;31mERROR: File doesn't exist in the user directory\033[0m\n");
}

void searchFile(string fileName) {
  bool found = false;
  File file;
  string directoryName;
  for (auto itr = directory->userDirectories.begin();
       itr < directory->userDirectories.end(); ++itr) {
    int idx = itr - directory->userDirectories.begin();
    if (found) break;
    if (directory->userDirectories[idx].id == userID) {
      UserFileDirectory userDirectory = directory->userDirectories[idx];
      for (auto it = userDirectory.files.begin();
           it < userDirectory.files.end(); ++it) {
        int i = it - userDirectory.files.begin();
        if (userDirectory.files[i].name == fileName) {
          file = userDirectory.files[i];
          directoryName = userDirectory.name;
          found = true;
          break;
        }
      }
    }
  }

  if (!found)
    printf("\x1B[31mFile doesn't exist in the user directory\033[0m\n");
  else {
    printf("\x1B[1;34mDIR: \033[0m");
    cout << directoryName << endl;
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
  getline(cin, directory->name);

  // single level
  int choice = 1;
  bool exit = false;

  while (!exit) {
    cout << "Select Choice: "
         << "\n"
         << "1. Create new user directory"
         << "\n"
         << "2. Change user directory"
         << "\n"
         << "3. Create file"
         << "\n"
         << "4. Display file"
         << "\n"
         << "5. Delete file"
         << "\n"
         << "6. Search file"
         << "\n"
         << "7. Exit" << endl;
    cin >> choice;

    if (choice == 1) {
      string id;
      cout << "Enter user id: ";
      cin >> id;
      createUserDirectory(id);

    } else if (choice == 2) {
      string id;
      cout << "Enter user id: ";
      cin >> id;
      changeUserDirectory(id);

    } else if (choice == 3) {
      File file;
      cout << "Enter filename: ";
      cin >> file.name;
      cout << "Enter size of file: ";
      cin >> file.size;
      cout << endl;
      createFile(file);

    } else if (choice == 4) {
      displayFiles();

    } else if (choice == 5) {
      string fileName;
      cout << "Enter filename: ";
      cin >> fileName;
      cout << endl;
      deleteFile(fileName);

    } else if (choice == 6) {
      string fileName;
      cout << "Enter filename: ";
      cin >> fileName;
      cout << endl;
      searchFile(fileName);

    } else if (choice == 7) {
      exit = true;
    } else {
      printf("\x1B[1;31mERROR: Invalid choice.\033[0m\n");
      exit = true;
    }
  }

  return 0;
}
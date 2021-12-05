#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

class ResourcesStatus {
 public:
  vector<vector<int>> processStatus;

  ResourcesStatus() {
    vector<vector<int>> v(3, vector<int>(3, 0));
    processStatus = v;
  }
  void processStatusCount(void) {
    int free = 0, occupied = 0, inaccessible = 0;
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        if (processStatus[i][j] == 0) {
          ++free;
        } else if (processStatus[i][j] == 1) {
          ++occupied;
        } else if (processStatus[i][j] == 2) {
          ++inaccessible;
        }
      }
    }
    cout << "Number of free processes: " << free << endl;
    cout << "Number of occupied processes: " << occupied << endl;
    cout << "Number of inaccessible processes: " << inaccessible << endl;
    try {
      if (occupied <= free) {
        cout << "Process count is ideal. No exception to raise" << endl;
      } else {
        throw "Occupied resources have exceeded free resource";
      }
    } catch (const char* msg) {
      cout << msg << "\n";
      for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
          if (processStatus[i][j] == 2) {
            processStatus[i][j] = 0;
          }
        }
      }
    }
  }

  void displayProcessStatus() {
    cout << "Process status in 3x3 array: " << endl;
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        cout << processStatus[i][j] << " ";
      }
      cout << endl;
    }
  }
};

int main(int argc, char* argv[]) {
  if (argc != 10) {
    cout << "Usage: ./e.out [9 statuses]\n";
    return 1;
  }
  int row = 0, col = 0;
  ResourcesStatus* rs = new ResourcesStatus();
  for (int i = 1; i < argc; ++i) {
    int status = atoi(argv[i]);
    if (status != 0 && status != 1 && status != 2) {
      cout << "status must always be 0, 1 or 2\n";
      return -1;
    }
    if (col == 3) {
      ++row;
      col = 0;
    }
    rs->processStatus[row][col] = status;
    ++col;
  }
  rs->displayProcessStatus();
  rs->processStatusCount();
  rs->displayProcessStatus();
  return 0;
}

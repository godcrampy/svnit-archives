#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
int frames = 3;

// 7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1

bool cmp(pair<string, int> &a, pair<string, int> &b) {
  return a.second < b.second;
}

int foundPair(vector<pair<string, int>> vec, string x) {
  for (int i = 0; i < vec.size(); ++i) {
    if (vec[i].first == x) {
      return i;
    }
  }
  return -1;
}

int findFutureIdx(vector<string> v, string x, int i) {
  for (int j = i; j < v.size(); ++j) {
    if (v[j] == x)
      return j;
  }
  return INT8_MAX;
}

void print(vector<pair<vector<string>, int>> output, int pageFault) {
  printf("\x1B[33mPage Allocation\033[0m\n");
  for (auto j : output[0].first)
    cout << j << endl;
  cout << "Page Fault: " << to_string(output[0].second) << endl;
  cout << endl;

  for (int i = 1; i < output.size(); ++i) {
    auto section = output[i];

    printf("\x1B[33mPage Allocation\033[0m\n");
    for (auto j : section.first)
      cout << j << endl;

    if (section.second != output[i - 1].second) {
      cout << "Page Fault: " << to_string(section.second) << endl;
    } else {
      cout << "No Page Fault Occured" << endl;
    }
    cout << endl;
  }

  cout << "Total Page Faults: " << to_string(pageFault) << endl;
  cout << endl;
}

int OptimalPageReplacement(string refString) {
  vector<string> page = {};
  istringstream iss(refString);
  string item;
  while (getline(iss, item, ' ')) {
    page.push_back(item);
  }

  int count = 0, pageFault = 0;
  vector<string> res(frames);
  vector<pair<vector<string>, int>> output;
  for (string x : page) {
    if (count < 3) {
      res[count] = x;
      ++pageFault;
    } else {
      if (find(res.begin(), res.end(), x) == res.end()) {
        ++pageFault;
        int futureIdx1 = findFutureIdx(page, res[0], count);
        int futureIdx2 = findFutureIdx(page, res[1], count);
        int futureIdx3 = findFutureIdx(page, res[2], count);

        int maxIndex = max(futureIdx1, max(futureIdx2, futureIdx3));
        if (maxIndex == futureIdx1) {
          res[0] = x;
        } else if (maxIndex == futureIdx2) {
          res[1] = x;
        } else if (maxIndex == futureIdx3) {
          res[2] = x;
        }
      }
    }

    output.push_back({res, pageFault});
    ++count;
  }
  print(output, pageFault);
  return pageFault;
}

int LRUPageReplacement(string refString) {
  vector<string> page = {};
  istringstream iss(refString);
  string item;
  while (getline(iss, item, ' ')) {
    page.push_back(item);
  }

  int count = 0, timer = 0, pageFault = 0;
  vector<string> res(frames);
  vector<pair<vector<string>, int>> output;
  vector<pair<string, int>> timerVector = {};

  for (string x : page) {
    if (!timerVector.empty())
      sort(timerVector.begin(), timerVector.end(), cmp);

    if (count < 3) {
      timerVector.push_back({x, timer});
      res[count] = x;
      ++pageFault;
    } else {
      // try to find if the page is there in map already
      // if there update the timer value only
      // if not there, take the least used and then insert the new page there
      if (foundPair(timerVector, x) != -1) {
        // it is present in the map
        int idx = foundPair(timerVector, x);
        timerVector[idx].second = timer;
      } else {
        auto itr = timerVector.begin();
        auto findPage = find(res.begin(), res.end(), itr->first);
        int idx = findPage - res.begin();

        res[idx] = x;
        timerVector.erase(itr);
        timerVector.push_back({x, timer});
        ++pageFault;
      }
    }

    output.push_back({res, pageFault});
    ++timer;
    ++count;
  }
  print(output, pageFault);
  return pageFault;
}

int main() {
  cout << "Enter the page reference string: ";
  string refString;
  getline(cin, refString);

  printf("\x1B[32mLRU Page Replacement\033[0m\n");
  int pageFaultLRU = LRUPageReplacement(refString);

  cout << endl;
  printf("\x1B[32mOptimal Page Replacement\033[0m\n");
  int pageFaultOptimal = OptimalPageReplacement(refString);

  cout << '|' << setw(10) << " LRU Page Faults " << '|' << setw(10)
       << " Optimal Page Faults " << '|' << endl;
  cout << '|' << setw(17) << pageFaultLRU << '|' << setw(21) << pageFaultOptimal
       << '|' << endl;
  cout << endl;
  return 0;
}

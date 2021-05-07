#include <stdio.h>

#include <iostream>
#include <set>
#include <vector>

using namespace std;

const int DISK_SIZE = 256;
const double SEEK_DELAY = 0.05;
const string BLUE_PREFIX = "\033[1;33m";
const string BLUE_POSTFIX = "\033[0m";

multiset<int>::iterator closest_to_head(const multiset<int> &requests,
                                        int head) {
  auto closest = requests.begin();
  int closest_distance = abs(head - *closest);

  for (auto it = requests.begin(); it != requests.end(); ++it) {
    if (abs(head - *it) < closest_distance) {
      closest_distance = abs(head - *it);
      closest = it;
    }
  }

  return closest;
}

void sstf(multiset<int> &requests, int start) {
  int head = start;
  int total_seeks = 0;
  int n = requests.size();
  cout << BLUE_PREFIX << "\nInitial Head Position: " << BLUE_POSTFIX << head
       << "\n";

  cout << BLUE_PREFIX << "Total Requests: " << BLUE_POSTFIX << n << "\n";

  cout << "|---|-----------|---------|---------|\n";
  cout << BLUE_PREFIX << "|No.|Request No.|Seek Wait|Seek Time|\n"
       << BLUE_POSTFIX;
  cout << "|---|-----------|---------|---------|\n";
  int k = 1;

  while (!requests.empty()) {
    auto next = closest_to_head(requests, head);
    total_seeks += abs(head - *next);
    head = *next;

    printf("|%2d |%10d | %7d | %7.2f |\n", k++, head, total_seeks,
           total_seeks * SEEK_DELAY);
    requests.erase(next);
  }
  cout << "|---|-----------|---------|---------|\n";

  cout << endl;

  cout << BLUE_PREFIX << "Total Seeks: " << BLUE_POSTFIX << total_seeks << "\n";
  cout << BLUE_PREFIX << "Total Time: " << BLUE_POSTFIX
       << total_seeks * SEEK_DELAY << "\n";
  cout << BLUE_PREFIX << "Mean Seek Time: " << BLUE_POSTFIX
       << total_seeks * SEEK_DELAY / n << "ms\n";
}

int main(int argc, char const *argv[]) {
  int n;
  cout << "Enter number of requests: ";
  cin >> n;
  multiset<int> requests;
  cout << "Enter requests: ";
  for (int i = 0; i < n; ++i) {
    int temp;
    cin >> temp;
    requests.insert(temp);
  }

  int start;
  cout << "Enter initial head position: ";
  cin >> start;
  sstf(requests, start);
  return 0;
}

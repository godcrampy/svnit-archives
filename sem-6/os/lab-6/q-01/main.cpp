#include <stdio.h>

#include <iostream>
#include <list>
#include <unordered_set>
#include <vector>

#include "best-fit/best-fit.hpp"
#include "first-fit/first-fit.hpp"
#include "node/node.hpp"
#include "worst-fit/worst-fit.hpp"

using namespace std;

const int MEMORY_SIZE = 16;

const string RED_PREFIX = "\033[1;31m";
const string RED_POSTFIX = "\033[0m";

const string BLUE_PREFIX = "\033[1;33m";
const string BLUE_POSTFIX = "\033[0m";

list<Node> first_fit_empty_list;
list<Node> first_fit_filled_list;

int main(int argc, char const *argv[]) {
  FirstFit ff(MEMORY_SIZE);
  BestFit bf(MEMORY_SIZE);
  WorstFit wf(MEMORY_SIZE);

  int first_pid = 1;
  int best_pid = 1;
  int worst_pid = 1;
  while (true) {
    string code;
    while (true) {
      cout << "Enter p to print, q to quit\n"
              "aa to add to all, af to add to first-fit, ab to add to "
              "best-fit,\n"
              "ra to remove from all, af to remove from first-fit, rb to "
              "remove from best-fit\n: ";
      cin >> code;

      if (code == "p") {
        break;
      } else if (code[0] == 'a' && code.length() >= 2) {
        cout << "Enter process size: ";
        int n;
        cin >> n;
        char c;
        if (code[1] == 'f' || code[1] == 'a')
          if (ff.append(n, first_pid)) {
            cout << "FF New process created: Process " << first_pid << "\n";
            ++first_pid;
          } else {
            cout << RED_PREFIX + "FF Error: Not enough space\n" + RED_POSTFIX;
          }

        if (code[1] == 'b' || code[1] == 'a')
          if (bf.append(n, best_pid)) {
            cout << "BF New process created: Process " << best_pid << "\n";
            ++best_pid;
          } else {
            cout << RED_PREFIX + "BF Error: Not enough space\n" + RED_POSTFIX;
          }

        if (code[1] == 'w' || code[1] == 'a')
          if (wf.append(n, worst_pid)) {
            cout << "WF New process created: Process " << worst_pid << "\n";
            ++worst_pid;
          } else {
            cout << RED_PREFIX + "WF Error: Not enough space\n" + RED_POSTFIX;
          }
      } else if (code[0] == 'r' && code.length() >= 2) {
        cout << "Enter process id: ";
        int id;
        cin >> id;
        if (code[1] == 'f' || code[1] == 'a')
          if (!ff.remove(id)) {
            cout << RED_PREFIX + "FF Error: Invalid process Ids\n" +
                        RED_POSTFIX;
          } else {
            cout << "Process removed\n";
          }

        if (code[1] == 'b' || code[1] == 'a')
          if (!bf.remove(id)) {
            cout << RED_PREFIX + "BF Error: Invalid process Ids\n" +
                        RED_POSTFIX;
          } else {
            cout << "Process removed\n";
          }

        if (code[1] == 'w' || code[1] == 'a')
          if (!wf.remove(id)) {
            cout << RED_PREFIX + "WF Error: Invalid process Ids\n" +
                        RED_POSTFIX;
          } else {
            cout << "Process removed\n";
          }
      } else if (code == "q") {
        exit(EXIT_SUCCESS);
      } else {
        cout << RED_PREFIX + "Error: Invalid Code\n" + RED_POSTFIX;
      }
    }

    cout << BLUE_PREFIX;
    printf("\n%s    %s    %s\n", "First First", "Best Fit", "Worst Fit");
    cout << BLUE_POSTFIX;
    auto a = ff.print_lists();
    auto b = bf.print_lists();
    auto c = wf.print_lists();
    for (int i = 0; i < a.size(); ++i) {
      cout << a[i] << "        " << b[i] << "     " << c[i] << "\n";
    }
  }
  return 0;
}

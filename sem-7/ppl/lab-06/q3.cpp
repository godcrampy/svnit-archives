#include <iostream>
#include <string>
#include <vector>

using namespace std;

class student {
  private:
    vector<double> grades;
    int id;
    double spi;
  public:
    student(vector<double> &v, int id): id(id), grades(v) {};

    void calculate_spi() {
      double sum = 0;

      for(auto i: grades) {
        sum += i;
      }

      spi = sum / (double) grades.size();
    }

    void display() {
      calculate_spi();
      cout << "ID: " << id << ", spi: " << spi << "\n";
    }

};

int main() {
  int n;
  cout << "Enter n: ";
  cin >> n;
  for(int i = 0; i < n; ++i) {
    cout << "Student ID: " << i + 1 << "\nEnter grades: ";
    vector<double> v(6);
    for(int j = 0; i < 6; ++i) {
      cin >> v[i];
    }

    student s(v, i + 1);
    s.display();
  }

  return 0;
}
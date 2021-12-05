#include <iostream>
#include <vector>
using namespace std;
template <class T>
class Vector {
 private:
  vector<T> vec;

 public:
  void create();
  void modify(T val, int idx);
  void display();
};
template <class T>
void Vector<T>::create() {
  vector<int> m = {2, 5, 6, 7, 9};
  vec = m;
}
template <class T>
void Vector<T>::modify(T val, int idx) {
  int size = vec.size();
  if (idx >= 0 && idx < size) {
    vec[idx] = val;
  }
}
template <class T>
void Vector<T>::display() {
  int size = vec.size();
  cout << "Vector: ";
  for (int i = 0; i < size; ++i) {
    cout << vec[i] << " ";
  }
  cout << endl;
}
int main() {
  Vector<int> v;
  v.create();
  cout << "Before modifying: " << endl;
  v.display();
  v.modify(8, 2);
  cout << "After modifying: " << endl;
  v.display();
  return 0;
}

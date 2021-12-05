#include <iostream>
using namespace std;
template <class T, class U>
void swap(T& x, U& y) {
  const T tmp = x;
  x = static_cast<T>(y);
  y = static_cast<U>(tmp);
}
int main() {
  float x = 10.5;
  int y = 15;
  cout << "x: " << x << " y: " << y << endl;
  swap(x, y);
  cout << "x: " << x << " y: " << y << endl;
  return 0;
}

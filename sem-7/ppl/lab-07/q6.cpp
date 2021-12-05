#include <deque>
#include <iostream>
using namespace std;
template <class T>
class stack {
 private:
  deque<T> s;

 public:
  void push(T val);
  void pop();
  void display();
};
template <class T>
void stack<T>::push(T val) {
  cout << "Push operation called for value: " << val << endl;
  s.push_back(val);
}
template <class T>
void stack<T>::pop() {
  cout << "Pop operation called for value: " << s[s.size() - 1] << endl;
  s.pop_back();
}
template <class T>
void stack<T>::display() {
  cout << "Stack: ";
  for (T val : s) {
    cout << val << " ";
  }
  cout << endl;
}
int main() {
  stack<int> st;
  st.push(15);
  st.pop();
  st.push(26);
  st.push(39);
  st.display();
  return 0;
}

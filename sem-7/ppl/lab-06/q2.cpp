#include <iostream>
#include <string>

using namespace std;

class rectangle {
  private:
    double width;
    double height;

  public:
    rectangle(): width(0), height(0) {};
    rectangle(double w, double h): width(w), height(h) {};
    
    double getArea() {
      return width * height;
    }

    double getPerimeter() {
      return 2 * (width + height);
    }
};


int main() {
  rectangle a(4, 5);
  rectangle b;

  cout << a.getArea() << "\n";
  cout << b.getArea() << "\n";

  return 0;
}
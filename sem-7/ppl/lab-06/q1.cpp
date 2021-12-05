#include <iostream>
#include <string>

using namespace std;

class author {
 private:
  string author_name;
  string title;

 public:
  author(string name, string title) : author_name(name){};

  virtual void print() {
    cout << "Called in Base Class\n";
    cout << "Author: " << author_name << ", Title: " << title << "\n";
  }
};

class book_publication : public author {
 public:
  book_publication(string name, string title) : author(name, title){};

  void print() { cout << "Called in Book Class\n"; }
};

class paper_publication : public author {
 public:
  paper_publication(string name, string title) : author(name, title){};
  void print() { cout << "Called in Paper Class\n"; }
};

int main(int argc, char **argv) {
  if (argc != 2) {
    cout << "Usage: ./a.out <author-name>\n";
    return 0;
  }

  string query = *(argv + 1);

  author *a = new paper_publication("hawking", "Universe");
  author *b = new book_publication("torvalds", "Linux");

  if (query == "hawking") {
    a->print();
  } else if (query == "torvalds") {
    b->print();
  } else {
    cout << "Error: author not found\n";
  }

  return 0;
}
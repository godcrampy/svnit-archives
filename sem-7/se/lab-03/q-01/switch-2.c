#include <stdio.h>
typedef enum {
  RED,
  YELLOW,
  GREEN,
} color;

int main() {
  color x;
  switch (x) {
    case RED:
      break;
    case YELLOW:
      printf("No!");
      break;
  }
  return 0;
}
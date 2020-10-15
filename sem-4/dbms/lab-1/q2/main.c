#include <stdio.h>

int main(int argc, char const* argv[]) {
  int number_of_students;
  printf("Enter number of students: ");
  scanf("%d", &number_of_students);
  getchar();
  FILE* f = fopen("data", "w");
  char name[50];
  int roll_number;
  for (int i = 0; i < number_of_students; ++i) {
    printf("Enter name and roll number: ");
    scanf("%s %d", name, &roll_number);
    getchar();
    fprintf(f, "%s %d\n", name, roll_number);
  }
  fclose(f);
  return 0;
}

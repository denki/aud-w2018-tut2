#include<stdio.h>

int main() {
  char name[100];

  printf("Name: ");
  scanf("%s", name);
  printf("Hallo %s.\n", name);

  return 0;
}

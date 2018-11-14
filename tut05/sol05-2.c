#include<stdio.h>

void swap(int* x, int* y);
void swap_distinct(int* x, int* y);

int main() {
  int x = 1, y = 2;

  printf("(x, y) = (%d, %d)\n", x, y);
  printf("swapping\n");
  swap_distinct(&x, &x);
  printf("(x, y) = (%d, %d)\n", x, y);

  return 0;
}

void swap(int* x, int* y) {
  int h = *x;

  *x = *y;
  *y = h;
}

// only works for x /= y
void swap_distinct(int* x, int* y) {
  *x = *x ^ *y;
  *y = *x ^ *y;
  *x = *y ^ *x;
}

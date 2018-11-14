#include<stdio.h>

int fib(int);
int fib_good(int);

int main() {
  int n;

  printf("number: ");
  scanf("%i", &n);
  printf("fib(%d) = %d\n", n, fib_good(n));

  return 0;
}

// fib(n) = fib(n - 2) + fib(n - 1) if n ≥ 2, fib(n) = n otherwise
int fib(int n) {
  if (n <= 1) return n;

  return fib(n - 2) + fib(n - 1);
}

int fib_good3(int x, int y, int n) {
  if (n == 0) return x;
  if (n == 1) return y;

  return fib_good3(y, x + y, n - 1);
}

int fib_good(int n) {
  return fib_good3(0, 1, n);
}


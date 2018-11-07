#include<stdio.h>
#include<math.h>

#define LEN 101

// Sieve of Eratosthenes
int main() {
  int numbers[LEN];

  for (int i = 0; i < LEN; ++i)
    numbers[i] = 0;

  numbers[0] = 1;
  numbers[1] = 1;

  for (int i = 2; i < sqrt(LEN); ++i)
    if (numbers[i] == 0)
      for (int j = i * i; j < LEN; j += i)
        numbers[j] = 1;

  for (int i = 2; i < LEN; ++i)
    if (numbers[i] == 0)
      printf("%d ", i);

  printf("\n");

  return 0;
}

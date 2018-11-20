#include <stdio.h>
#include <stdlib.h>

typedef struct element * list;
struct element { int value; list next; };

list cons(int v, list l) {
  list l1 = malloc(sizeof(*l));
  l1->value = v; // (*l1).value = v;
  l1->next = l;
  return l1;
}

void printList(list l) {
  printf("[");
  while (l) {
    printf("%d", l->value);
    if (l->next) printf(", ");
    l = l->next;
  }
  printf("]\n");
}

int sum_it(list l) {
  int acc = 0;
  while (l) {
    acc += l->value;  // AddAssign
    l = l->next;
  }
  return acc;
}

int sum_rec(list l) {
  if (!l) return 0;
  return l->value + sum_rec(l->next);
}

void rmEvens_it(list* l) {
  if (!l) return;
  while (*l) {
    if ((*l)->value % 2 == 0) {
      list tmp = *l;
      *l = (*l)->next;
      free(tmp);
    } else {
      l = &(*l)->next;
    }
  }
}

void rmEvens_rec(list* l) {
  if (!l || !*l) return;
  rmEvens_rec(&(*l)->next);

  if ((*l)->value % 2 == 0) {
    list tmp = *l;
    *l = (*l)->next;
    free(tmp);
  }
}

int main() {
  list l = cons(3, cons(6, cons(7, NULL)));
  printf("l = ");
  printList(l);
  printf("sum_it(l) = %d\n", sum_it(l));
  printf("sum_rec(l) = %d\n", sum_rec(l));
  rmEvens_rec(&l);
  printList(l);
  l = cons(3, cons(6, cons(7, NULL)));
  rmEvens_it(&l);
  printList(l);
  return 0;
}

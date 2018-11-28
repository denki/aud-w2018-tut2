#include <stdio.h>
#include <stdlib.h>

typedef struct node *tree;
typedef struct node { int key; tree left, right; } node;

tree cons(int v, tree left, tree right) {
  tree t = malloc(sizeof(node));
  t->key = v;
  t->left = left;
  t->right = right;

  return t;
}

void print_tree(tree t) {
  if (!t) printf("NULL");
  else if (!t->left && !t->right)
    printf("%d", t->key);
  else {
    printf("%d(", t->key);
    print_tree(t->left);
    printf(", ");
    print_tree(t->right);
    printf(")");
  }
}

int count_value(int v, tree t) {
  if (!t) return 0;
  return (t->key == v) + count_value(v, t->left) + count_value(v, t->right);
}

tree baz(tree s, tree t) {
  if (!s) return NULL;

  return cons(count_value(s->key, t),
              baz(s->left, t),
              baz(s->right, t));
}

int leafprod(tree t) {
  if (!t) return 1;
  if (!t->left && !t->right) return t->key;
  return leafprod(t->left) * leafprod(t->right);
}

int main() {
  tree s = cons(2,
                cons(3,
                     cons(2, NULL, NULL),
                     cons(4, NULL, NULL)
                     ),
                cons(1, NULL, NULL)
                );
  tree t = cons(2,
                cons(2, NULL, NULL),
                cons(3, NULL, NULL)
                );

  print_tree(s); printf("\n");
  printf("count_value(2, t) = %d\n", count_value(2, t));
  print_tree(baz(s, t)); printf("\n");
  printf("leafprod(s) = %d\n", leafprod(s));
  return 0;
}

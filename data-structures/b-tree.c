#include <stdio.h>
#include <stdlib.h>

#define MAX 3
#define MIN 2

typedef struct BTreeNode {
  int val[MAX + 1], count;
  struct BTreeNode *link[MAX + 1];
}BTreeNode;

int main() {
	printf("Size of the struct: %ld\n", sizeof(BTreeNode));
}

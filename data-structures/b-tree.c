#include <stdio.h>
#include <stdlib.h>

#define MAX 3
#define MIN 2

typedef struct BTreeNode {
  int val[MAX + 1], count;
  struct BTreeNode *link[MAX + 1];
}BTreeNode;

struct BTreeNode *createNode(int val, struct BTreeNode *child) {
  struct BTreeNode *newNode;
  newNode = (struct BTreeNode *)malloc(sizeof(struct BTreeNode));
  newNode->val[1] = val;
  newNode->count = 1;
  newNode->link[0] = root;
  newNode->link[1] = child;
  return newNode;
}

int main() {
	printf("Size of the struct: %ld\n", sizeof(BTreeNode));
}

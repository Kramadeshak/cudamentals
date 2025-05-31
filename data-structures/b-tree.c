#include <stdio.h>
#include <stdlib.h>

typedef struct bTree {
	struct bTree* next;
	struct bTree* prev;
	int value;
}bTree;

tree *create_node(int value){
	tree *n = malloc(sizeof(bTree));
	if (!n){
		fprintf(stderr, "Out of Memory\n");
		exit(1);
	}
	n->data = value;
	n->left = NULL;
	n->right = NULL;
	return n;
}

void print_tree_inorder(tree *h) {
	if (h->left != NULL) {
		print_tree_inorder(h->left);
	}
	printf("%d", h->data);
	if (h->right != NULL) {
		print_tree_inorder(h->right);
	}
}

void print_tree_preorder(tree *h) {
	printf("%d", h->data);
	if (h->left != NULL) {
		print_tree_preorder(h->left);
	}
	if (h->right != NULL) {
		print_tree_preorder(h->right);
	}
}

void print_tree_postorder(tree *h) {
	if (h->left != NULL) {
		print_tree_postorder(h->left);
	}
	if (h->right != NULL) {
		print_tree_postorder(h->right);
	}
	printf("%d", h->data);
}


int main(){
	printf("%ld\n", sizeof(struct bTree));
	printf("int - %ld\nchar -  %ld\nfloat -  %ld\ndouble -  %ld\n", sizeof(int), sizeof(char), sizeof(float), sizeof(double));
}

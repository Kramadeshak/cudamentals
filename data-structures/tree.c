#include <stdio.h>
#include <stdlib.h>

typedef struct tree{
	struct tree *left;
	struct tree *right;
	int data;
}tree;

tree *create_node(int value){
	tree *n = malloc(sizeof(tree));
	if (!n){
		fprintf(stderr, "Out of Memory\n");
		exit(1);
	}
	n->data = value;
	n->left = NULL;
	n->right = NULL;
	return n;
}

void add_value(tree *head, int value) {
	tree *h = head;
	if (value < head->data) {
		if (head->left == NULL){
			head->left = create_node(value);
			return;
		} else {
			add_value(head->left, value);
		}
	} else {
		if (head->right == NULL){
			head->right = create_node(value);
			return;
		} else {
			add_value(head->right, value);
		}
	}
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
	printf("Size of the struct: %ld\n", sizeof(tree));
	tree *head;
	head = create_node(4);
	add_value(head, 3);
	add_value(head, 2);
	add_value(head, 1);
	add_value(head, 7);
	add_value(head, 5);
	add_value(head, 6);
	print_tree_inorder(head);
	printf(" - Inorder\n");
	print_tree_preorder(head);
	printf(" - pre-order\n");
	print_tree_postorder(head);
	printf(" - post-order\n");
}

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
	if (head->data < value) {
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
}

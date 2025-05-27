#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	struct node *next;
	int data;
}node;

node *create_node(int value){
	node *n = malloc(sizeof(node));
	if (!n){
		fprintf(stderr, "Out of Memory\n");
		exit(1);
	}
	n->data = value;
	n->next = NULL;
	return n;
}

void add_value_ll(node *head, int value) {
	node *h = head;
	while (h->next!=NULL){
		h=h->next;
	}
	h->next = create_node(value);
}

void print_ll(node *h) {
	while (h != NULL) {
		printf("Value: %d\n", h->data);
		h = h->next;
	}
}

void free_ll(node *head){
	node *tmp;
	while (head){
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

int main(){
	printf("Size of the struct: %ld\n", sizeof(node));
	node *head;
	head = create_node(1);
	add_value_ll(head, 2);
	add_value_ll(head, 3);
	add_value_ll(head, 4);
	add_value_ll(head, 5);
	print_ll(head);
	free_ll(head);
	/*print_ll(head);*/
}

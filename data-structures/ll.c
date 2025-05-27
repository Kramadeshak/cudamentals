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

void init_ll(node **head, int value) {
	(*head) = malloc(sizeof(node));
	node *h = (*head);
	h->next = NULL;
	h->data = value;
}

void add_value_ll(node *head, int value) {
	node *h = head;
	while (h->next!=NULL){
		h=h->next;
	}
	h->next = malloc(sizeof(node));
	h->next->data=value;
}

void print_ll(node *h) {
	while (h != NULL) {
		printf("Value: %d\n", h->data);
		h = h->next;
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
}

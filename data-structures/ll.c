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

void for_each(const node *head, void (*func)(int)) {
	while (head) {
		func(head->data);
		head = head->next;
	}
}

void delete_node(node *head, int val) {
	while (head->next) {
		if (head->next->data == val) {
			node *tmp = head->next;
			head->next = head->next->next;
			free(tmp);
			return;
		}
		head = head->next;
	}
}

void print_val(int data) {
	printf("Value: %d\n", data);
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
	for_each(head, print_val);
	delete_node(head, 3);
	for_each(head, print_val);
	free_ll(head);
}

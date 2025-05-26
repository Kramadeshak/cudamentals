#include <stdio.h>
#include <stdlib.h>

struct ll{
	struct ll *next;
	int data;
};

void init_ll(struct ll **head, int value) {
	(*head) = malloc(sizeof(struct ll));
	struct ll *h = (*head);
	h->next = NULL;
	h->data = value;
}

void add_value_ll(struct ll *head, int value) {
	struct ll *h = head;
	while (h->next!=NULL){
		h=h->next;
	}
	h->next = malloc(sizeof(struct ll));
	h->next->data=value;
}

void print_ll(struct ll *h) {
	while (h != NULL) {
		printf("Value: %d\n", h->data);
		h = h->next;
	}
}

int main(){
	printf("Size of the struct: %ld\n", sizeof(struct ll));
	struct ll *head;
	init_ll(&head,1);
	add_value_ll(head, 2);
	add_value_ll(head, 3);
	add_value_ll(head, 4);
	add_value_ll(head, 5);
	print_ll(head);
}

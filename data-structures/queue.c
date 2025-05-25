#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
  int data[MAX];
  int top;
  int size;
} queue;

void queue_init(queue *s){
	s->top = 0;
	s->size = 0;
}

int push(queue *s, int v) {
	if (s->size < MAX) {
		s->data[(s->top + s->size++) % MAX] = v;
		return 1;
	} else {
		return 0;
	}
}

int pop(queue *s, int *out) {
	int v;
	if (s->size == 0) {
		return 0;
	} else {
		*out = s->data[s->top++];
		s->size--;
		s->top %= MAX;
		return 1;
	}
}

int main(){
	printf("Size of the struct: %ld\n", sizeof(queue));
	queue s;
	queue_init(&s);
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);
	push(&s, 4);
	push(&s, 5);
	push(&s, 6);
	push(&s, 7);
	push(&s, 8);
	push(&s, 9);

	int val;
	while (pop(&s, &val)) {
		printf("Popped: %d\n", val);
	}
	push(&s, 11);
	push(&s, 12);
	push(&s, 13);
	push(&s, 14);
	push(&s, 15);
	push(&s, 16);
	push(&s, 17);
	push(&s, 18);
	push(&s, 19);
	while (pop(&s, &val)) {
		printf("Popped: %d\n", val);
	}
}

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
  int data[MAX];
  int top;
} stack;

void stack_init(stack *s){
	s->top = 0;
}

int push(stack *s, int v) {
	if (s->top < MAX) {
		s->data[s->top++] = v;
		return 1;
	} else {
		return 0;
	}
}

int pop(stack *s, int *out) {
	int v;
	if (s->top == 0) {
		return 0;
	} else {
		*out = s->data[--s->top];
		return 1;
	}
}

int main(){
	printf("Size of the struct: %ld\n", sizeof(stack));
	stack s;
	stack_init(&s);
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);

	int val;
	while (pop(&s, &val)) {
		printf("Popped: %d\n", val);
	}
}

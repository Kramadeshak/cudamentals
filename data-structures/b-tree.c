#include <stdio.h>
#include <stdlib.h>

struct bTree {
	struct bTree* next;
	struct bTree* prev;
	int value;
};

void new_btree(struct bTree *b) {
	b = malloc(sizeof(struct bTree));
}

int main(){
	printf("Here is the size of a bTree-\n");
	printf("%ld\n", sizeof(struct bTree));
	printf("int - %ld\nchar -  %ld\nfloat -  %ld\ndouble -  %ld\n", sizeof(int), sizeof(char), sizeof(float), sizeof(double));
}

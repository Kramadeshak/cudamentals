#include <stdio.h>
#include <stdlib.h>
typedef struct {
    const char* key;
    void* value;
} ht_entry;

struct ht {
    ht_entry* entries;
    size_t capacity;
    size_t length;
};

#define INITIAL_CAPACITY 16

struct ht* ht_create(void) {
    struct ht* table = malloc(sizeof(struct ht));
    if (table == NULL) {
        return NULL;
    }
    table->length = 0;
    table->capacity = INITIAL_CAPACITY;

    table->entries = calloc(table->capacity, sizeof(ht_entry));
    if (table->entries == NULL) {
        free(table);
        return NULL;
    }
    return table;
}

int main() {
	printf("Size of the struct: %ld\n", sizeof(struct ht));
	struct ht *new_ht = ht_create();
	int temp;
	while (1) {
		printf("Please enter a value: ");
		scanf("%d", &temp);
		if (temp == 10)
			break;
		printf("entered value: %d\n", temp);
		arr[temp%10] = temp;
	}
	for (int i=0;i<10;i++) {
		printf("Here is the value for %d: %d\n", i, arr[i]);
	}
}

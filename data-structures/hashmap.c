#include <stdio.h>
#include <stdlib.h>
typedef struct {
    const char* key;  // key is NULL if this slot is empty
    void* value;
} ht_entry;

// Hash table structure: create with ht_create, free with ht_destroy.
struct ht {
    ht_entry* entries;  // hash slots
    size_t capacity;    // size of _entries array
    size_t length;      // number of items in hash table
};

#define INITIAL_CAPACITY 16  // must not be zero

ht* ht_create(void) {
    // Allocate space for hash table struct.
    ht* table = malloc(sizeof(ht));
    if (table == NULL) {
        return NULL;
    }
    table->length = 0;
    table->capacity = INITIAL_CAPACITY;

    // Allocate (zero'd) space for entry buckets.
    table->entries = calloc(table->capacity, sizeof(ht_entry));
    if (table->entries == NULL) {
        free(table); // error, free table before we return!
        return NULL;
    }
    return table;
}
int main() {
	/*printf("Size of the struct: %ld\n", sizeof(hashmap));*/
	// starting a simple implementation first before moving to a complex one
	int arr[10], temp;
	// initializing array to 0
	printf("Size of the hashmap: %ld\n", sizeof(arr));
	for (int i=0;i<10;i++) {
		arr[i]=0;
	}
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

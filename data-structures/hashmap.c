#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
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
#define FNV_OFFSET 14695981039346656037UL
#define FNV_PRIME 1099511628211UL

static uint64_t hash_key(const char* key){
	uint64_t hash = FNV_OFFSET;
	for(const char* p = key; *p; p++){
     		hash ^= (uint64_t)(unsigned char)(*p);
		hash *= FNV_PRIME;
	}
	return hash;
}

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

void ht_destroy(ht* table) {
	for (size_t i = 0; i < table->capacity; i++) {
		free((void*)table->entries[i].key);
	}
	free(table->entries);
	free(table);
}

int main() {
	printf("Size of the struct: %ld\n", sizeof(struct ht));
	struct ht *new_ht = ht_create();
}

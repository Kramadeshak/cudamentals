#include <stdio.h>
#include <stdlib.h>

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

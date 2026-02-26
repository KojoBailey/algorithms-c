#include <stdio.h>
#include <stdlib.h>
#include <time.h>

size_t find_min_index(int* start, size_t size)
{
	size_t result = 0;
	for (size_t i = 1; i < size; i++) {
		if (start[i] < start[result]) {
			result = i;
		}
	}
	return result;
}

void swap(int* a, int* b)
{
	if (a == b) return;
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

void print_arr(char* name, int* arr, size_t size)
{
	printf("%s = { ", name);
	for (int i = 0; i < size; i++) {
		if (i == size - 1) {
			printf("%d", arr[i]);
		} else {
			printf("%d, ", arr[i]);
		}
	}
	printf(" }\n");
}

int main(void)
{
	srand(time(NULL));
	int arr[10];
	size_t arr_size = sizeof(arr) / sizeof(int);

	printf("arr = { ");
	for (size_t  i = 0; i < arr_size; i++) {
		arr[i] = rand();
		
		if (i == arr_size - 1) {
			printf("%d", arr[i]);
		} else {
			printf("%d, ", arr[i]);
		}
	}
	printf(" }\n");

	for (size_t i = 0; i < arr_size; i++) {
		size_t min_index = i + find_min_index(&arr[i], arr_size - i);

		swap(&arr[i], &arr[min_index]);
	}

	print_arr("sorted_arr", arr, arr_size);

	return 0;
}

%:include <stdio.h>
%:include <stdbool.h>
%:include <stdlib.h>
%:include <time.h>

void swap(int* a, int* b)
{
	if (a == b) return;
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

void bubble_sort(int* arr, size_t length)
{
	size_t i, j;
	for (i = 0; i < length - 1; i++) {
		bool was_swap_performed = false;

		for (j = 0; j < length - i - 1; j++) {
			if (arr[j] > arr[j+1]) {
				swap(&arr[j], &arr[j+1]);
				was_swap_performed = true;
			}
		}

		if (!was_swap_performed) break;
	}
}

int main(void)
{
	srand(time(NULL));
	int data[1000];
	size_t data_length = sizeof(data) / sizeof(data[0]);

	for (size_t i = 0; i < data_length; i++) {
		data[i] = rand();
		printf("%d ", data[i]);
	}

	puts("\nPerforming bubble sort...");
	bubble_sort(data, data_length);


	for (size_t i = 0; i < data_length; i++) {
		printf("%d ", data[i]);
	}
}

#include <stdio.h>
#include <stdlib.h>

int main() {
	
	//Assign dynamically memory
	//We cast malloc generic void response to int*, static size of 1
	int* dato1 = (int*) malloc(sizeof(int));

	//We cast malloc generic void response to int*, dynamic size depending user entry
	int integers_count = 0, *integers_list = NULL;

	printf_s("Enter size of the list: ");
	scanf_s("%d", &integers_count);

	integers_list = (int*) malloc(sizeof(int) * integers_count);

	//Print dynamic memory size reserved
	printf_s("Array size: %d\n",(int) sizeof(integers_list) * integers_count);
	for (int listIndex = 0; listIndex < integers_count; listIndex++) {
		printf_s("Enter integer value: ");
		scanf_s("%d", &integers_list[listIndex]);
	}

	//Print all enter values
	for (int listIndex = 0; listIndex < integers_count; listIndex++) {
		printf_s("Integer value: %d\n", integers_list[listIndex]);
	}

	//Free reserved space in memory
	free(integers_list);
	integers_list = NULL;

	return 0;
}
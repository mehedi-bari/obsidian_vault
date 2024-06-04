#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int MAX;

void display(int *intArray) {
  int i;
  printf("[");

  // navigate through all items
  for (i = 0; i < MAX; i++) {
    printf("%d ", intArray[i]);
  }

  printf("]\n");
}

void swap(int *xp, int *yp) {
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}

// A function to implement bubble sort
void bubbleSort(int arr[], int n) {
  int i, j;
  for (i = 0; i < n - 1; i++)
    // Last i elements are already in place
    for (j = 0; j < n - i - 1; j++)
      if (arr[j] > arr[j + 1])
        swap(&arr[j], &arr[j + 1]);
}

int main(int argc, char *argv[]) {
  assert(argc == 2);
  char *tmp = argv[1];
  MAX = atoi(tmp);
  int intArray[MAX];

  for (int i = 0; i < MAX; i++)
    intArray[i] = MAX - i;

  printf("Input Array: \n");
  display(intArray);
  printf("#################################################\n");

  clock_t start = clock();
  bubbleSort(intArray, MAX);
  clock_t end = clock();

  printf("Output Array: \n");
  display(intArray);
  printf("#################################################\n");

  float seconds = (float)(end - start) / CLOCKS_PER_SEC;

  printf("Sorting time: %f\n", seconds);

  return 0;
}

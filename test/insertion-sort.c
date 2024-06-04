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

void insertionSort(int *intArray) {

  int valueToInsert;
  int holePosition;
  int i;

  // loop through all numbers
  for (i = 1; i < MAX; i++) {

    // select a value to be inserted.
    valueToInsert = intArray[i];

    // select the hole position where number is to be inserted
    holePosition = i;

    // check if previous no. is larger than value to be inserted
    while (holePosition > 0 && intArray[holePosition - 1] > valueToInsert) {
      intArray[holePosition] = intArray[holePosition - 1];
      holePosition--;
    }

    if (holePosition != i) {
      // insert the number at hole position
      intArray[holePosition] = valueToInsert;
    }
  }
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
  insertionSort(intArray);
  clock_t end = clock();

  printf("Output Array: \n");
  display(intArray);
  printf("#################################################\n");

  float seconds = (float)(end - start) / CLOCKS_PER_SEC;

  printf("Sorting time: %f\n", seconds);

  return 0;
}

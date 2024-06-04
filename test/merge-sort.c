#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int MAX;

void display(int *a) {
  int i;
  printf("[");

  // navigate through all items
  for (i = 0; i < MAX; i++) {
    printf("%d ", a[i]);
  }

  printf("]\n");
}

void merge(int arr[], int l, int m, int r) {
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;

  /* create temp arrays */
  int L[n1], R[n2];

  /* Copy data to temp arrays L[] and R[] */
  for (i = 0; i < n1; i++)
    L[i] = arr[l + i];
  for (j = 0; j < n2; j++)
    R[j] = arr[m + 1 + j];

  /* Merge the temp arrays back into arr[l..r]*/
  i = 0; // Initial index of first subarray
  j = 0; // Initial index of second subarray
  k = l; // Initial index of merged subarray
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  /* Copy the remaining elements of L[], if there
  are any */
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  /* Copy the remaining elements of R[], if there
  are any */
  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
}

/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r) {
  if (l < r) {
    // Same as (l+r)/2, but avoids overflow for
    // large l and h
    int m = l + (r - l) / 2;

    // Sort first and second halves
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    merge(arr, l, m, r);
  }
}

int main(int argc, char *argv[]) {

  assert(argc == 2);
  char *tmp = argv[1];
  MAX = atoi(tmp);

  int a[MAX];

  for (int i = 0; i < MAX; i++)
    a[i] = MAX - i;

  printf("Input Array: \n");
  display(a);
  printf("#################################################\n");

  clock_t start = clock();
  mergeSort(a, 0, MAX - 1);
  clock_t end = clock();

  printf("Output Array: \n");
  display(a);
  printf("#################################################\n");

  float seconds = (float)(end - start) / CLOCKS_PER_SEC;

  printf("Sorting time: %f\n", seconds);

  return 0;
}

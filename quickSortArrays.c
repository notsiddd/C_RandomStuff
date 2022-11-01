#include <stdio.h>

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(int array[], int low, int high) {
  int pivot = array[high];
  int i = (low - 1);
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
      i++;
      swap(&array[i], &array[j]);
    }
  }
  swap(&array[i + 1], &array[high]);
  return (i + 1);
}

void quickSort(int array[], int l, int h) {
  if (l < h) {
    int pivot = partition(array, l, h);
    quickSort(array, l, pivot - 1);
    quickSort(array, pivot + 1, h);
  }
}


int main() {
  int array[5];
  printf("Enter array elements.\n");
  for(int i = 0; i < 5; ++i) {
     scanf("%d", &array[i]);
  }
  int size = sizeof(array) / sizeof(array[0]);

  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
  
  quickSort(array, 0, size-1);
  
  
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

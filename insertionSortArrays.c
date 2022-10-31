#include <stdio.h>

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
  
  for (int i = 1; i < size; i++) {
    int key = array[i];
    int j = i - 1;
    while (key < array[j] && j >= 0) {
      array[j + 1] = array[j];
      --j;
    }
    array[j + 1] = key;
  }
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

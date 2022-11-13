#include<stdio.h>
#include<stdlib.h>

// Prof. Gupta's pointer swap
void swap( int* p, int* q){
    int temp = *p;
    *p = *q;
    *q = temp;


}

void helper(int a[], int n, int root){
    int max = root;
    int left = 2*root +1, right = 2*root +2;
    if(a[left]>a[max] && left<n){
        max = left;
    }
    if(a[right]>a[max] && right<n){
        max = right;
    }
    if(max!=root){
        swap(&a[root],&a[max]);
        helper(a,n,max);
    }
}
// To just create a heap
//void heaper(int a[], int n){
//    int start = n/2 -1;
//    for(int i = start; i>=0; i--){
//        helper(a,n,i);
//    }
//}

//To Heap Sort
void heapSort(int a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--){
        helper(a, n, i);
    }
 
    for (int i = n - 1; i >= 0; i--) {
        swap(&a[0], &a[i]);
        helper(a, i, 0);
    }
}



void printer(int a[], int n)
{
    printf("Heap:\n");
    for (int i = 0; i < n; ++i)
        printf("%d ",a[i]);
    printf("\n");
}

int main()
{
    int a[] = {2, 4, 12, 3, 6, 13, 17, 9, 8, 15, 21};
    int n = sizeof(a) / sizeof(a[0]);
    heapSort(a, n);
    printer(a, n);
    return 0;
}

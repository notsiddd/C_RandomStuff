#include <stdio.h>

int main() {
    // int* xt;
    // xt = malloc(1000 * sizeof(int));
    int* p = NULL;
    int a = 25;
    int b =23;
    printf("From A to B, we skipped %d bytes!\n", (int)&b - (int)&a);
    p = &a;
    printf("%d\n", a);
    printf("%d\n", b);
    *(p+1) = 100;
    printf("%d\n", b);
    *(p) = 100;
    a++;
    printf("%d\n", a);
    printf("Address of A: %d\n", &a);
    printf("Address of Pointer P: %d\n", p);
    printf("Address of B: %d\n", &b);
    printf("Address of Pointer P +1 : %d", p+1);

    return 0;
}

#include <stdio.h>

int main() {
    printf("Hello world\n");
    int a1 = 7;                 // 2-4 bytes
    unsigned short integer = 8; // 2 bytes
    long integer1 = 8;          // 4 bytes
    short integer2 = 8;         // 2 bytes

    float b1 = 8.0;                    // 4 bytes 
    double myfloat1 = 7.45;            // 8 bytes 
    long double myfloat2 = 7.43453455; // 10 bytes 
    
    const int i = 9; // constant 
    int sid = 7, debG = 10;
    printf("%d\n", sid == debG);
    printf("%d\n", sid != debG);
    printf("%d\n", sid > debG);
    
    //Taking inputs
    int sid2;
    printf("Enter an integer\n");
    scanf("%d",&sid2);
    printf("You entered - %d", sid2);
    
    // For and while loops follow the same format as Java
    
    // Pointers, Structs and Calling functions already known. 
    //strcpy and strcat for copying strings onto variables
    //Change the value at a pointer and the original variable (basically an address) will register the change
    return 0;
}

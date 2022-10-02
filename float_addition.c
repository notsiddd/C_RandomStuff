#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
    float inc = 0.000000001;
    float n = 0.00000001; 
    int c = 1;

    for (float i=0.0; i<n; i+=inc) {
        printf("Loop Number: %d\n", c);
        c++;
    }

    return 0;
}


#include<stdio.h>
#include<stdlib.h>
// Still trying to figure out a bug that is terminating the code.

int main(int argc, char **argv){

    struct node {
        int value;
        struct node *next; 
    };  
    typedef struct node blah;
    int n,val;
    
    blah* head = NULL;
    blah* temp = NULL;
    blah* prevNode = NULL;
    printf("Enter number of nodes!");
    scanf("%d",&n);
    int isFirst=1;

    while(n>0){
        if(isFirst==1){
            isFirst=0;
            scanf("%d", &val);
            head = malloc(sizeof(blah));
            head->value = val;
            head->next = NULL;
            prevNode = head;
            n=n-1;
        }
        else{
            scanf("%d",&val);
            temp = malloc(sizeof(blah));
            temp->value = val;
            temp->next = NULL;
            prevNode->next = temp;
            n=n-1;
        }
    }
    blah* printer = NULL;
    printer = head;
    while (printer!=NULL)
    {
        printf("%d->",printer->value);
        printer = printer->next;
    }

    return 0;
}
    

   

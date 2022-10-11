#include<stdio.h>
#include<stdlib.h>


struct node{
        int val;
        struct node* next;
    };
    typedef struct node blah;


blah* lister(int num){
    blah* head;
    blah* temp;
    blah* nextNode;
    int i, value1;

    head = malloc(sizeof(blah));
    printf("Enter data of head.");
    scanf("%d",&value1);
    head->val = value1;
    head->next = NULL;

    //This way we can assign the next elements address to head.
    temp = head;

    for(i=2;i<=num;i++){
        nextNode = malloc(sizeof(blah));
        printf("Enter value of node %d.",i);
        scanf("%d",&value1);
        nextNode->val = value1;
        nextNode->next = NULL;

        temp->next = nextNode;
        temp = temp->next;
    }

    blah* printer;
    printer = head;

    while(printer!=NULL){
        printf("%d->",printer->val);
        printer = printer->next;
    }
    printf("NULL\n");
    return(head);

}

blah* reverse(blah* head, int chunk){
    blah* prev = NULL;
    blah* current = head;
    blah* nextNode = NULL;
    int c=0;
    while(current!=NULL && c<chunk){
        nextNode  = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
        c++;
    }
    if (nextNode !=  NULL)
        head->next = reverse(nextNode, chunk);
    //prev holds the new head.
    
    return prev;
}

int main(int argc, char **argv){
    int n,value,chunkSize;
    blah* header;
    int flag = 1;
    printf("Enter the number of elements you want in your linked list.");
    scanf("%d",&n);
    
    if(n<=0){
        printf("Wrong Input!");
        flag=0;
    }
    else{
        //This timing taking the address of head 
        header = lister(n);
        printf("Enter the chunk size for reversing!");
        scanf("%d",&chunkSize);
        printf("Reversing the List Now!\n");
        blah* wow;
        wow = reverse(header,chunkSize);
        blah* printer;
        printer = wow;
        while(printer!=NULL){
            printf("%d->",printer->val);
            printer = printer->next;
        }
        printf("NULL\n");
    }
    
}

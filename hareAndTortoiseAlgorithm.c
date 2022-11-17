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

void hareAndTortMiddle(blah* head){
    blah* tortoise = head;
    blah* hare = head;
    if (head!=NULL)
    {
        while (hare != NULL && hare->next != NULL)
        {   
            tortoise = tortoise->next;
            hare = hare->next->next;
        }
        printf("Using the Hare-Tortoise Algorithm, middle: %d\n",tortoise->val);
    }
}


int main(int argc, char **argv){
    int n,value;
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
        hareAndTortMiddle(header);
    }
    
}

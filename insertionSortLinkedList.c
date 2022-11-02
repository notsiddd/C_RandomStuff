#There is a segmentation fault that keeps occuring in my compiler that I will fix before 4/11/22/
#include<stdio.h>
#include<stdlib.h>


struct node{
        int val;
        struct node* next;
    };
    typedef struct node blah;
    blah* temp2 = NULL;
    blah* head2 = NULL;

blah* lister(int num){
    blah* head;
    blah* temp;
    blah* nextNode;
    
    int i, value1;

    head = malloc(sizeof(blah));
    printf("Enter data of head.\n");
    scanf("%d",&value1);
    head->val = value1;
    head->next = NULL;

    //This way we can assign the next elements address to head.
    temp = head;

    for(i=2;i<=num;i++){
        nextNode = malloc(sizeof(blah));
        printf("Enter value of node %d.\n",i);
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
    head2 = head;
    return(head);

}

void insertNode(blah* newNode){
    if(temp2==NULL || temp2->val >= newNode->val){
        newNode->next = temp2;
        temp2 = newNode;
    }
    else{
        blah* current = temp2;
        while(current->next->val < newNode->val){
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void insertionSort(blah* head){
    blah* current = head;
    while(current!=NULL){
        blah* nexter = current->next;
        insertNode(current);
        current = nexter;
    }
    blah* printer;
    printer = head;

    while(printer!=NULL){
        printf("%d->",printer->val);
        printer = printer->next;
    }
}

int main(int argc, char **argv){
    int n, value;
    blah* header;
    printf("Enter the number of elements you want the linked list to have!\n");
    scanf("%d", &n);
    if(n<=0){
        printf("Wrong Input!");
    }
    else{
        header = lister(n);
        insertionSort(header);
    }
}

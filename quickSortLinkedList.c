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
    return head;

}

blah* findLast(blah* head)
{
    blah* temp = head;
    while (temp != NULL && temp->next != NULL) {
        temp = temp->next;
    }
    return temp;
}

blah* partition(blah* first, blah* last){
    blah* pivot;
    blah* front;
    int t = 0;
    while (front != NULL && front != last) {
        if (front->val < last->val) {
            pivot = first;
            t = first->val;
            first->val = front->val;
            front->val = t;
            first = first->next;
        }
        front = front->next;
    }
 
    t = first->val;
    first->val = last->val;
    last->val = t;
    return pivot;
}

void quickSort(blah* first, blah* last){
    if (first == last) {
        return;
    }
    blah* pivot = partition(first, last);
 
    if (pivot != NULL && pivot->next != NULL) {
        quickSort(pivot->next, last);
    } 
    if (pivot != NULL && first != pivot) {
        quickSort(first, pivot);
    }
}

int main(int argc, char **argv){
    int n,value,chunkSize;
    blah* header;
    printf("Enter the number of elements you want in your linked list.\n");
    scanf("%d",&n);
    
    if(n<=0){
        printf("Wrong Input!");
    }
    else{
        //This timing taking the address of head 
        header = lister(n);
        quickSort(header, findLast(header));
        
    }
    return 0;
    
}

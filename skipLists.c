//Trying to implement a skip list

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//Assuming we are looking for a skipList with two pointers (A normal next pointer and one " Express Lines")
//Second assumption: For n nodes , we will have n/2 "stops" on the "express line" 


struct node{
    int val;
    struct node* next;
    struct node* layer2Next; // Node to hold the express line 
};
typedef struct node blah;

blah* skipListerBuild(int n){
    blah* head = (blah*)malloc(sizeof(struct node));
    int val;
    printf("Enter value of head!\n");
    scanf("%d",&val);
    head->val = val;
    int i = 1;
    int x = (int)sqrt(n);
    blah* layer2Holder;
    blah* temp;
    while(i<n){ 
        temp = malloc(sizeof(struct node));
        printf("Enter value of node %d!\n", ++i);
        scanf("%d",&val);
        temp
        //Allocate and assign first
        temp->val = val;
        
        
    }


}

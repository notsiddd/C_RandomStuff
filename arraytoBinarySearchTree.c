#include<stdio.h>
#include<stdlib.h>


struct node{
        int val;
        struct node* pre;
        struct node* post;
    };
    typedef struct node blah;

blah* lister(int val);

blah* treeCreator(int a[], int first, int last){
    if(first>last){
        return NULL;
    }
    int m = (first +last)/2;
    blah* rootNode = lister(a[m]);
    rootNode->pre = treeCreator(a, first, m-1);
    rootNode->post = treeCreator(a, m+1, last);
    return rootNode;
}

blah* lister(int val){
    blah* node = (blah*)(malloc(sizeof(blah)));
    node->val = val;
    node->pre = NULL;
    node->post = NULL;

    return node;
}

void printer(blah* node){
    if(node==NULL)
    return;
    else{
        printf("%d,", node->val);
        printer(node->pre);
        printer(node->post);
    }
}

int main(){
    printf("Enter the number of array elements you want.\n");
    int n;
    scanf("%d", &n);
    int arr[n];
    printf("Enter the array elements in a sorted manner!");
    for(int i=0;i<n;i++){
        printf("Enter element %d.\n", i+1);
        scanf("%d", &arr[i]);
    }
    printf("The array:\n");
    for(int i=0;i<n;i++){
        printf("%d,", arr[i]);
    }
    blah* rootNode = treeCreator(arr,0,n-1);
    printf("\nThe Tree in preoder traversal:\n");
    printer(rootNode);
    return 0;


}

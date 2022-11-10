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

blah* findPredec(blah* root){
    //Left tree's right most child node
    root = root->pre;
    while(root->post != NULL){
        root = root->post;  
    }
    return root;    
}

blah* deleteNode(blah* root, int value){
    blah* predec;
    //base case
    if(root ==NULL){
        return NULL;
    }
    //it is a leaf node
    if(root->pre==NULL && root->post ==NULL){
        //deallocating the memory which was previously allocated by malloc
        free(root);
        return NULL;
    }
   // If it is in left subtree 
    if(value<root->val){
        root->pre= deleteNode(root->pre,value);
    }
    //If it is in right subtree
    else if(value>root->val){
         //We remove the second argument from the subtree from root->post
        //If we do not set root->post we wont get NULL from the deleted node
        root->post = deleteNode(root->post,value);
    }
    //At this point we have the node
    else{
        predec = findPredec(root);
        root->val = predec->val;
        //We delete the node in the left subtree (basically the inorder predec)
        //We remove the second argument from the subtree from root->pre
        //Just like above if case, if we dont set root->pre, we wont get NULL
        root->pre = deleteNode(root->pre, predec->val);
    }
    return root;
}

int main(){
    printf("Enter the number of array elements you want.\n");
    int n;
    scanf("%d", &n);
    int arr[n];
    printf("Enter the array elements in a sorted manner!\n");
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
    printf("Enter which node to delete!\n");
    int del;
    scanf("%d",&del);
    blah* temp = deleteNode(rootNode, del);
    printer(temp);
    return 0;
}

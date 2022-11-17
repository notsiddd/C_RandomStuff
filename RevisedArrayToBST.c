#include <stdio.h>
#include <stdlib.h>
struct node{
    int val;
    struct node* left;
    struct node* right;
};
typedef struct node blah;

blah* newNode(int value) {
  blah* temp = malloc(sizeof(blah));
  temp->val = value;
  temp->left = temp->right = NULL;
  return temp;
}


blah* insertNode(blah* node, int value) {
  if (node == NULL) return newNode(value);

  if (value < node->val)
    node->left = insertNode(node->left, value);
  else
    node->right = insertNode(node->right, value);

  return node;
}

void printPreOrder(blah* node)
{
    if (node == NULL)
        return;
    printf("%d ", node->val);
    printPreOrder(node->left);
    printPreOrder(node->right);
}

int main() {
    printf("Enter number of elements you want in the array!\n");
    int n,j;
    scanf("%d",&n);
    int a[n];
    for(int i =0;i<n;i++){
        j=i+1;
        printf("Element %d:", j);
        scanf("%d\n",&a[i]);
    }
    blah* root = NULL;
    printf("The Binary Search Tree in Preorder Traversal:\n");
    for(int i =0; i<n;i++){
        root = insertNode(root,a[i]);
    }
    printPreOrder(root);

    return 0;
}

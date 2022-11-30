#include <stdio.h>
#include <stdlib.h>


struct node
{
    int val;
    struct node *left;
    struct node *right;
    int height;
};
typedef struct node blah;


int findMax(int x, int y)
{
    return (x > y)?x:y;
}

int findHeight(blah* node)
{
    if (node == NULL)
        return 0;
    return node->height;
}

blah* addNode(int val)
{
    blah* node = (blah*)malloc(sizeof(blah));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; 
    return(node);
}

blah* leftRotation(blah* x)
{
    blah* y = x->right;
    blah* temp = y->left;
    y->left = x;
    x->right = temp;
    x->height = findMax(findHeight(x->left), findHeight(x->right))+1;
    y->height = findMax(findHeight(y->left), findHeight(y->right))+1;

    return y;
}


blah* rightRotation(blah* y)
{
    blah* x = y->left;
    blah* temp = x->right;
    x->right = y;
    y->left = temp;
    y->height = findMax(findHeight(y->left), findHeight(y->right))+1;
    x->height = findMax(findHeight(x->left), findHeight(x->right))+1;
    
    return x;
}
//Helper to find the balance of each node (right and left subtree length difference)
int findBalance(blah* node)
{
    if (node == NULL)
        return 0;
    return findHeight(node->left) - findHeight(node->right);
}

blah* insert(blah* node, int val)
{
    if (node == NULL)
        return(addNode(val));

    if (val < node->val)
        node->left  = insert(node->left, val);
    else if (val > node->val)
        node->right = insert(node->right, val);
    else 
        return node;

    node->height = 1 + findMax(findHeight(node->left),
                           findHeight(node->right));

    int nodeBalance = findBalance(node);

    if (nodeBalance > 1 && val < node->left->val)
        return rightRotation(node);

    if (nodeBalance < -1 && val > node->right->val)
        return leftRotation(node);

    if (nodeBalance > 1 && val > node->left->val)
    {
        node->left =  leftRotation(node->left);
        return rightRotation(node);
    }

    if (nodeBalance < -1 && val < node->right->val)
    {
        node->right = rightRotation(node->right);
        return leftRotation(node);
    }

    return node;
}

blah* minValueNode(blah* node)
{
    blah* current = node;

    while (current->left != NULL)
        current = current->left;

    return current;
}

blah* deleteNode(blah* root, int val)
{
    if (root == NULL)
        return root;
    if ( val < root->val )
        root->left = deleteNode(root->left, val);
    else if( val > root->val )
        root->right = deleteNode(root->right, val);
    else
    {
        if( (root->left == NULL) || (root->right == NULL) )
        {
            blah* temp = root->left ? root->left : root->right;

            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else 
             *root = *temp; 
            free(temp);
        }
        else
        {
            blah* temp = minValueNode(root->right);

            root->val = temp->val;

            root->right = deleteNode(root->right, temp->val);
        }
    }

    if (root == NULL)
      return root;

    root->height = 1 + findMax(findHeight(root->left),findHeight(root->right));

    int nodeBalance = findBalance(root);

    if (nodeBalance > 1 && findBalance(root->left) >= 0)
        return rightRotation(root);
    if (nodeBalance > 1 && findBalance(root->left) < 0)
    {
        root->left =  leftRotation(root->left);
        return rightRotation(root);
    }
    if (nodeBalance < -1 && findBalance(root->right) <= 0)
        return leftRotation(root);
    if (nodeBalance < -1 && findBalance(root->right) > 0)
    {
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }

    return root;
}

void preOrder(blah* root)
{
    if(root != NULL)
    {
        printf("%d ", root->val);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main()
{
    blah* root = NULL;

    root = insert(root, 13);
    root = insert(root, 18);
    root = insert(root, 25);
    root = insert(root, 31);
    root = insert(root, 39);
    root = insert(root, 47);

    printf("Preorder traversal : \n");
    preOrder(root);
    root = deleteNode(root, 25);
    printf("\nPreorder traversal after deletion of 25 : \n");
    preOrder(root);

    return 0;
}

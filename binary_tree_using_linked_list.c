#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create()
{
    int x;
    struct node *nn;
    nn = (struct node *)malloc(sizeof(struct node));
    printf("\n Enter data or (-1) for no node : ");
    scanf("%d", &x);
    if (x == -1)
    {
        return 0;
    }
    else
    {
        nn->data = x;
        printf("\n left child of %d", x);
        nn->left = create();
        printf("\n right child of %d ", x);
        nn->right = create();
    }
    return nn;
}

void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void Inorder(struct node *root)
{
    if (root != NULL)
    {
        Inorder(root->left);
        printf("%d ", root->data);
        Inorder(root->right);
    }
}

void postorder(struct node *root)
{
    if (root != NULL)
    {

        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

void main()
{
    struct node *root;
    root = 0;
    root = create();
    printf("\n Preorder is : \n");
    preorder(root);
    printf("\n Inorder is : \n");
    Inorder(root);
    printf("\n Postorder is : \n");
    postorder(root);
}

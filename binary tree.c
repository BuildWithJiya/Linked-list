#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node node;

/* Search function */
node *search(node *ptr, int key)
{
    if (ptr == NULL)
    {
        return NULL;
    }

    if (ptr->data == key)
    {
        return ptr;
    }

    if (key < ptr->data)
    {
        return search(ptr->left, key);
    }
    else if (key > ptr->data)
    {
        return search(ptr->right, key);
    }

    return NULL;
}

/* Create a new node */
node *createNode(int data)
{
    node *newnode = (node *)malloc(sizeof(node));

    if (newnode == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}

/* Insert an element into the BST */
node *insert(node *ptr, int element)
{
    if (ptr == NULL)
    {
        return createNode(element);
    }

    if (element < ptr->data)
    {
        ptr->left = insert(ptr->left, element);
    }
    else if (element > ptr->data)
    {
        ptr->right = insert(ptr->right, element);
    }

    return ptr;
}

/* Inorder traversal: Left, Root, Right */
void inorderDisplay(node *ptr)
{
    if (ptr == NULL)
    {
        return;
    }

    inorderDisplay(ptr->left);
    printf("%d ", ptr->data);
    inorderDisplay(ptr->right);
}

/* Preorder traversal: Root, Left, Right */
void preorderDisplay(node *ptr)
{
    if (ptr == NULL)
    {
        return;
    }

    printf("%d ", ptr->data);
    preorderDisplay(ptr->left);
    preorderDisplay(ptr->right);
}

/* Postorder traversal: Left, Right, Root */
void postorderDisplay(node *ptr)
{
    if (ptr == NULL)
    {
        return;
    }

    postorderDisplay(ptr->left);
    postorderDisplay(ptr->right);
    printf("%d ", ptr->data);
}

/* Main function */
int main()
{
    node *root = NULL;
    node *result;
    int n, element, key, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &element);

        root = insert(root, element);
    }

    printf("\nInorder traversal: ");
    inorderDisplay(root);

    printf("\nPreorder traversal: ");
    preorderDisplay(root);

    printf("\nPostorder traversal: ");
    postorderDisplay(root);

    printf("\n\nEnter the key to search: ");
    scanf("%d", &key);

    result = search(root, key);

    if (result == NULL)
    {
        printf("%d not found in the BST.\n", key);
    }
    else
    {
        printf("%d found in the BST.\n", key);
    }

    return 0;
}

/*
Enter the number of elements: 7
Enter element 1: 50
Enter element 2: 30
Enter element 3: 70
Enter element 4: 20
Enter element 5: 40
Enter element 6: 60
Enter element 7: 80

Inorder traversal: 20 30 40 50 60 70 80
Preorder traversal: 50 30 20 40 70 60 80
Postorder traversal: 20 40 30 60 80 70 50

Enter the key to search: 40
40 found in the BST.
Enter the key to search: 100
100 not found in the BST.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *rear = NULL;

/* Create a new node */
node *create_node(int data)
{
    node *newnode = (node *)malloc(sizeof(node));

    if (newnode == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newnode->data = data;
    newnode->next = NULL;

    return newnode;
}

/* Insert at beginning */
void insert_at_beg(int data)
{
    node *newnode = create_node(data);

    if (rear == NULL)
    {
        rear = newnode;
        rear->next = rear;
    }
    else
    {
        newnode->next = rear->next;
        rear->next = newnode;
    }

    printf("Node inserted at beginning.\n");
}

/* Insert at end */
void insert_at_end(int data)
{
    node *newnode = create_node(data);

    if (rear == NULL)
    {
        rear = newnode;
        rear->next = rear;
    }
    else
    {
        newnode->next = rear->next;
        rear->next = newnode;
        rear = newnode;
    }

    printf("Node inserted at end.\n");
}

/* Insert at position */
void insert_at_position(int data, int pos)
{
    node *newnode, *temp;
    int i;

    if (pos <= 0)
    {
        printf("Invalid position.\n");
        return;
    }

    if (pos == 1)
    {
        insert_at_beg(data);
        return;
    }

    if (rear == NULL)
    {
        printf("Invalid position.\n");
        return;
    }

    temp = rear->next;

    for (i = 1; i < pos - 1; i++)
    {
        temp = temp->next;

        if (temp == rear->next)
        {
            printf("Invalid position.\n");
            return;
        }
    }

    newnode = create_node(data);
    newnode->next = temp->next;
    temp->next = newnode;

    if (temp == rear)
        rear = newnode;

    printf("Node inserted at position %d.\n", pos);
}

/* Delete from beginning */
void delete_beg()
{
    if (rear == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    node *temp = rear->next;

    if (rear == temp)
    {
        rear = NULL;
    }
    else
    {
        rear->next = temp->next;
    }

    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

/* Delete from end */
void delete_end()
{
    if (rear == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    node *temp = rear->next;

    if (rear == temp)
    {
        printf("Deleted element: %d\n", rear->data);
        free(rear);
        rear = NULL;
        return;
    }

    while (temp->next != rear)
    {
        temp = temp->next;
    }

    node *last = rear;

    temp->next = rear->next;
    rear = temp;

    printf("Deleted element: %d\n", last->data);
    free(last);
}

/* Delete from position */
void delete_at_position(int pos)
{
    node *temp, *del;
    int i;

    if (rear == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    if (pos <= 0)
    {
        printf("Invalid position.\n");
        return;
    }

    if (pos == 1)
    {
        delete_beg();
        return;
    }

    temp = rear->next;

    for (i = 1; i < pos - 1; i++)
    {
        temp = temp->next;

        if (temp == rear->next)
        {
            printf("Invalid position.\n");
            return;
        }
    }

    del = temp->next;

    if (del == rear->next)
    {
        printf("Invalid position.\n");
        return;
    }

    temp->next = del->next;

    if (del == rear)
        rear = temp;

    printf("Deleted element: %d\n", del->data);
    free(del);
}

/* Display list */
void display()
{
    if (rear == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    node *temp = rear->next;

    printf("Circular Linked List: ");

    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != rear->next);

    printf("\n");
}

/* Main function */
int main()
{
    int choice, data, pos;

    while (1)
    {
        printf("\n===== Circular Singly Linked List =====\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Position\n");
        printf("7. Display\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            insert_at_beg(data);
            break;

        case 2:
            printf("Enter data: ");
            scanf("%d", &data);
            insert_at_end(data);
            break;

        case 3:
            printf("Enter data: ");
            scanf("%d", &data);
            printf("Enter position: ");
            scanf("%d", &pos);
            insert_at_position(data, pos);
            break;

        case 4:
            delete_beg();
            break;

        case 5:
            delete_end();
            break;

        case 6:
            printf("Enter position: ");
            scanf("%d", &pos);
            delete_at_position(pos);
            break;

        case 7:
            display();
            break;

        case 8:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}

/*

===== Circular Singly Linked List =====
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete from Position
7. Display
8. Exit
Enter your choice: 1
Enter data: 10
Node inserted at beginning.

===== Circular Singly Linked List =====
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete from Position
7. Display
8. Exit
Enter your choice: 2
Enter data: 20
Node inserted at end.

===== Circular Singly Linked List =====
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete from Position
7. Display
8. Exit
Enter your choice: 2
Enter data: 30
Node inserted at end.

===== Circular Singly Linked List =====
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete from Position
7. Display
8. Exit
Enter your choice: 7
Circular Linked List: 10 20 30

===== Circular Singly Linked List =====
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete from Position
7. Display
8. Exit
Enter your choice: 1
Enter data: 5
Node inserted at beginning.

===== Circular Singly Linked List =====
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete from Position
7. Display
8. Exit
Enter your choice: 7
Circular Linked List: 5 10 20 30

===== Circular Singly Linked List =====
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete from Position
7. Display
8. Exit
Enter your choice: 3
Enter data: 15
Enter position: 3
Node inserted at position 3.

===== Circular Singly Linked List =====
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete from Position
7. Display
8. Exit
Enter your choice: 7
Circular Linked List: 5 10 15 20 30

===== Circular Singly Linked List =====
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete from Position
7. Display
8. Exit
Enter your choice: 4
Deleted element: 5

===== Circular Singly Linked List =====
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete from Position
7. Display
8. Exit
Enter your choice: 7
Circular Linked List: 10 15 20 30

===== Circular Singly Linked List =====
1. Insert at Beginning
2. Insert at End
3. Delete from End
4. Delete from Position
5. Display
6. Exit
Enter your choice: 5
Deleted element: 30

===== Circular Singly Linked List =====
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete from Position
7. Display
8. Exit
Enter your choice: 6
Enter position: 2
Deleted element: 15

===== Circular Singly Linked List =====
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete from Position
7. Display
8. Exit
Enter your choice: 7
Circular Linked List: 10 20

===== Circular Singly Linked List =====
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete from Position
7. Display
8. Exit
Enter your choice: 8
Exiting...
*/
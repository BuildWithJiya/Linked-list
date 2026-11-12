#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} node;

node *head = NULL;
node *rear = NULL;


/* Create a new node */
node *create_node(int data)
{
    node *newnode = (node *)malloc(sizeof(node));

    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = NULL;

    return newnode;
}


/* Insert at beginning */
void insert_at_beg(int data)
{
    node *newnode = create_node(data);

    if (head == NULL)
    {
        head = newnode;
        rear = newnode;
    }
    else
    {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }

    printf("Node inserted at beginning\n");
}


/* Insert at end */
void insert_at_end(int data)
{
    node *newnode = create_node(data);

    if (head == NULL)
    {
        head = newnode;
        rear = newnode;
    }
    else
    {
        newnode->prev = rear;
        rear->next = newnode;
        rear = newnode;
    }

    printf("Node inserted at end\n");
}


/* Insert at a given position */
void insert_at_pos(int data, int pos)
{
    node *newnode;
    node *temp;
    int count = 1;

    /* Position cannot be less than 1 */
    if (pos < 1)
    {
        printf("Invalid position\n");
        return;
    }

    /* Position 1 means insert at beginning */
    if (pos == 1)
    {
        insert_at_beg(data);
        return;
    }

    /* Empty list */
    if (head == NULL)
    {
        printf("Invalid position\n");
        return;
    }

    newnode = create_node(data);
    temp = head;

    /*
       Move temp to the node
       just before the required position.
    */
    while (count < pos - 1 && temp->next != NULL)
    {
        count++;
        temp = temp->next;
    }

    /*
       If position is beyond the next available
       position, it is invalid.
    */
    if (count != pos - 1)
    {
        printf("Invalid position\n");
        free(newnode);
        return;
    }

    newnode->prev = temp;
    newnode->next = temp->next;

    if (temp->next != NULL)
    {
        temp->next->prev = newnode;
    }
    else
    {
        /* New node becomes rear */
        rear = newnode;
    }

    temp->next = newnode;

    printf("Node inserted at position %d\n", pos);
}


/* Delete from beginning */
void delete_beg()
{
    node *temp;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = head;

    if (head == rear)
    {
        head = NULL;
        rear = NULL;
    }
    else
    {
        head = head->next;
        head->prev = NULL;
    }

    printf("Deleted element: %d\n", temp->data);

    free(temp);
}


/* Delete from end */
void delete_end()
{
    node *temp;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = rear;

    if (head == rear)
    {
        head = NULL;
        rear = NULL;
    }
    else
    {
        rear = rear->prev;
        rear->next = NULL;
    }

    printf("Deleted element: %d\n", temp->data);

    free(temp);
}


/* Delete from a given position */
void delete_at_pos(int pos)
{
    node *temp;
    int count = 1;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if (pos < 1)
    {
        printf("Invalid position\n");
        return;
    }

    /* Position 1 */
    if (pos == 1)
    {
        delete_beg();
        return;
    }

    temp = head;

    /*
       Traverse until the required position.
    */
    while (count < pos && temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    /* Position does not exist */
    if (temp == NULL || count != pos)
    {
        printf("Invalid position\n");
        return;
    }

    /*
       If temp is the last node,
       delete from end.
    */
    if (temp == rear)
    {
        delete_end();
        return;
    }

    /*
       Connect the previous node
       with the next node.
    */
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    printf("Deleted element: %d\n", temp->data);

    free(temp);
}


/* Display from beginning to end */
void display_forward()
{
    node *temp;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = head;

    printf("Doubly Linked List: ");

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}


/* Display from end to beginning */
void display_backward()
{
    node *temp;

    if (rear == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = rear;

    printf("Reverse Doubly Linked List: ");

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }

    printf("\n");
}


/* Main function */
int main()
{
    int choice;
    int data;
    int pos;

    while (1)
    {
        printf("\n========== DOUBLY LINKED LIST ==========\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Position\n");
        printf("7. Display Forward\n");
        printf("8. Display Backward\n");
        printf("9. Exit\n");

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

                insert_at_pos(data, pos);
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

                delete_at_pos(pos);
                break;


            case 7:
                display_forward();
                break;


            case 8:
                display_backward();
                break;


            case 9:
                printf("Exiting...\n");
                exit(0);


            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

/*
========== DOUBLY LINKED LIST ==========
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete from Position
7. Display Forward
8. Display Backward
9. Exit
Enter your choice: 1
Enter data: 10
Node inserted at beginning

========== DOUBLY LINKED LIST ==========
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete from Position
7. Display Forward
8. Display Backward
9. Exit
Enter your choice: 2
Enter data: 20
Node inserted at end

========== DOUBLY LINKED LIST ==========
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete from Position
7. Display Forward
8. Display Backward
9. Exit
Enter your choice: 2
Enter data: 30
Node inserted at end

========== DOUBLY LINKED LIST ==========
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete from Position
7. Display Forward
8. Display Backward
9. Exit
Enter your choice: 7
Doubly Linked List: 10 20 30

========== DOUBLY LINKED LIST ==========
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete from Position
7. Display Forward
8. Display Backward
9. Exit
Enter your choice: 8
Reverse Doubly Linked List: 30 20 10

========== DOUBLY LINKED LIST ==========
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete from Position
7. Display Forward
8. Display Backward
9. Exit
Enter your choice: 1
Enter data: 5
Node inserted at beginning

========== DOUBLY LINKED LIST ==========
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete from Position
7. Display Forward
8. Display Backward
9. Exit
Enter your choice: 7
Doubly Linked List: 5 10 20 30

========== DOUBLY LINKED LIST ==========
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete from Position
7. Display Forward
8. Display Backward
9. Exit
Enter your choice: 3
Enter data: 15
Enter position: 3
Node inserted at position 3

========== DOUBLY LINKED LIST ==========
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete from Position
7. Display Forward
8. Display Backward
9. Exit
Enter your choice: 7
Doubly Linked List: 5 10 15 20 30

========== DOUBLY LINKED LIST ==========
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete from Position
7. Display Forward
8. Display Backward
9. Exit
Enter your choice: 4
Deleted element: 5

========== DOUBLY LINKED LIST ==========
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete from Position
7. Display Forward
8. Display Backward
9. Exit
Enter your choice: 5
Deleted element: 30

========== DOUBLY LINKED LIST ==========
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete from Position
7. Display Forward
8. Display Backward
9. Exit
Enter your choice: 6
Enter position: 2
Deleted element: 15

========== DOUBLY LINKED LIST ==========
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete from Position
7. Display Forward
8. Display Backward
9. Exit
Enter your choice: 7
Doubly Linked List: 10 20

========== DOUBLY LINKED LIST ==========
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete from Position
7. Display Forward
8. Display Backward
9. Exit
Enter your choice: 8
Reverse Doubly Linked List: 20 10

========== DOUBLY LINKED LIST ==========
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete from Position
7. Display Forward
8. Display Backward
9. Exit
Enter your choice: 9
Exiting...
*/
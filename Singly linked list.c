#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *head = NULL;

/* Create a new node */
node *CreateNode(int dd)
{
    node *newnode = (node *)malloc(sizeof(node));

    if (newnode == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    newnode->data = dd;
    newnode->next = NULL;

    return newnode;
}

/* Insert at beginning */
void insert_at_beg(int data)
{
    node *newnode = CreateNode(data);

    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        newnode->next = head;
        head = newnode;
    }

    printf("Node inserted at beginning.\n");
}

/* Insert at end */
void insert_at_end(int data)
{
    node *newnode = CreateNode(data);

    if (head == NULL)
    {
        head = newnode;
        printf("Node inserted at end.\n");
        return;
    }

    node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newnode;

    printf("Node inserted at end.\n");
}

/* Insert at a particular position */
void insert_at_pos(int data, int pos)
{
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

    node *newnode = CreateNode(data);
    node *temp = head;

    int count = 1;

    while (count < pos - 1 && temp != NULL)
    {
        temp = temp->next;
        count++;
    }

    if (temp == NULL)
    {
        printf("Invalid position.\n");
        free(newnode);
        return;
    }

    newnode->next = temp->next;
    temp->next = newnode;

    printf("Node inserted at position %d.\n", pos);
}

/* Display the linked list */
void display()
{
    if (head == NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }

    node *temp = head;

    printf("Linked List: ");

    while (temp != NULL)
    {
        printf("%d", temp->data);

        if (temp->next != NULL)
        {
            printf(" -> ");
        }

        temp = temp->next;
    }

    printf(" -> NULL\n");
}

/* Delete from beginning */
void delete_beg()
{
    if (head == NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }

    node *temp = head;

    head = head->next;

    free(temp);

    printf("Node deleted from beginning.\n");
}

/* Delete from end */
void delete_end()
{
    if (head == NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }

    /* Only one node */
    if (head->next == NULL)
    {
        free(head);
        head = NULL;

        printf("Node deleted from end.\n");
        return;
    }

    node *temp = head;
    node *prev = NULL;

    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;

    free(temp);

    printf("Node deleted from end.\n");
}

/* Delete from a particular position */
void delete_pos(int pos)
{
    if (head == NULL)
    {
        printf("Linked list is empty.\n");
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

    int count = 1;

    node *temp = head;
    node *prev = NULL;

    while (count < pos && temp != NULL)
    {
        prev = temp;
        temp = temp->next;
        count++;
    }

    if (temp == NULL)
    {
        printf("Invalid position.\n");
        return;
    }

    prev->next = temp->next;

    free(temp);

    printf("Node deleted from position %d.\n", pos);
}

/* Main function */
int main()
{
    int choice;
    int data;
    int pos;

    while (1)
    {
        printf("\n===== SINGLY LINKED LIST =====\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Display\n");
        printf("5. Delete from beginning\n");
        printf("6. Delete from end\n");
        printf("7. Delete from position\n");
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

                insert_at_pos(data, pos);
                break;

            case 4:
                display();
                break;

            case 5:
                delete_beg();
                break;

            case 6:
                delete_end();
                break;

            case 7:
                printf("Enter position: ");
                scanf("%d", &pos);

                delete_pos(pos);
                break;

            case 8:
                printf("Program terminated.\n");
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}

/*
===== SINGLY LINKED LIST =====
1. Insert at beginning
2. Insert at end
3. Insert at position
4. Display
5. Delete from beginning
6. Delete from end
7. Delete from position
8. Exit

Enter your choice: 4
Linked list is empty.

===== SINGLY LINKED LIST =====
1. Insert at beginning
2. Insert at end
3. Insert at position
4. Display
5. Delete from beginning
6. Delete from end
7. Delete from position
8. Exit

Enter your choice: 1
Enter data: 10
Node inserted at beginning.

===== SINGLY LINKED LIST =====
1. Insert at beginning
2. Insert at end
3. Insert at position
4. Display
5. Delete from beginning
6. Delete from end
7. Delete from position
8. Exit

Enter your choice: 2
Enter data: 20
Node inserted at end.

===== SINGLY LINKED LIST =====
1. Insert at beginning
2. Insert at end
3. Insert at position
4. Display
5. Delete from beginning
6. Delete from end
7. Delete from position
8. Exit

Enter your choice: 2
Enter data: 30
Node inserted at end.

===== SINGLY LINKED LIST =====
1. Insert at beginning
2. Insert at end
3. Insert at position
4. Display
5. Delete from beginning
6. Delete from end
7. Delete from position
8. Exit

Enter your choice: 3
Enter data: 15
Enter position: 2
Node inserted at position 2.

===== SINGLY LINKED LIST =====
1. Insert at beginning
2. Insert at end
3. Insert at position
4. Display
5. Delete from beginning
6. Delete from end
7. Delete from position
8. Exit

Enter your choice: 4
Linked List: 10 -> 15 -> 20 -> 30 -> NULL

===== SINGLY LINKED LIST =====
1. Insert at beginning
2. Insert at end
3. Insert at position
4. Display
5. Delete from beginning
6. Delete from end
7. Delete from position
8. Exit

Enter your choice: 5
Node deleted from beginning.

===== SINGLY LINKED LIST =====
1. Insert at beginning
2. Insert at end
3. Insert at position
4. Display
5. Delete from beginning
6. Delete from end
7. Delete from position
8. Exit

Enter your choice: 4
Linked List: 15 -> 20 -> 30 -> NULL

===== SINGLY LINKED LIST =====
1. Insert at beginning
2. Insert at end
3. Insert at position
4. Display
5. Delete from beginning
6. Delete from end
7. Delete from position
8. Exit

Enter your choice: 6
Node deleted from end.

===== SINGLY LINKED LIST =====
1. Insert at beginning
2. Insert at end
3. Insert at position
4. Display
5. Delete from beginning
6. Delete from end
7. Delete from position
8. Exit

Enter your choice: 4
Linked List: 15 -> 20 -> NULL

===== SINGLY LINKED LIST =====
1. Insert at beginning
2. Insert at end
3. Insert at position
4. Display
5. Delete from beginning
6. Delete from end
7. Delete from position
8. Exit

Enter your choice: 7
Enter position: 2
Node deleted from position 2.

===== SINGLY LINKED LIST =====
1. Insert at beginning
2. Insert at end
3. Insert at position
4. Display
5. Delete from beginning
6. Delete from end
7. Delete from position
8. Exit

Enter your choice: 4
Linked List: 15 -> NULL

===== SINGLY LINKED LIST =====
1. Insert at beginning
2. Insert at end
3. Insert at position
4. Display
5. Delete from beginning
6. Delete from end
7. Delete from position
8. Exit

Enter your choice: 5
Node deleted from beginning.

===== SINGLY LINKED LIST =====
1. Insert at beginning
2. Insert at end
3. Insert at position
4. Display
5. Delete from beginning
6. Delete from end
7. Delete from position
8. Exit

Enter your choice: 4
Linked list is empty.

===== SINGLY LINKED LIST =====
1. Insert at beginning
2. Insert at end
3. Insert at position
4. Display
5. Delete from beginning
6. Delete from end
7. Delete from position
8. Exit

Enter your choice: 6
Linked list is empty.

===== SINGLY LINKED LIST =====
1. Insert at beginning
2. Insert at end
3. Insert at position
4. Display
5. Delete from beginning
6. Delete from end
7. Delete from position
8. Exit

Enter your choice: 8
Program terminated.
*/
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

/* Enqueue */
void enqueue(int data)
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

    printf("Inserted Successfully.\n");
}

/* Dequeue */
void dequeue()
{
    if (rear == NULL)
    {
        printf("\nQueue is Empty!\n");
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

    printf("Deleted Element = %d\n", temp->data);

    free(temp);
}

/* Check Queue Empty */
int isEmpty()
{
    return rear == NULL;
}

/* Display Queue */
void display()
{
    if (rear == NULL)
    {
        printf("\nQueue is Empty!\n");
        return;
    }

    node *temp = rear->next;

    printf("\nQueue Elements: ");

    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != rear->next);

    printf("\n");
}

/* Main Function */
int main()
{
    int choice, data;

    do
    {
        printf("\n===== CIRCULAR QUEUE USING CIRCULAR LINKED LIST =====\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter element: ");
            scanf("%d", &data);
            enqueue(data);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;

        case 4:
            printf("Program Ended.\n");
            break;

        default:
            printf("Invalid Choice!\n");
        }

    } while (choice != 4);

    return 0;
}

/*
===== CIRCULAR QUEUE USING CIRCULAR LINKED LIST =====
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 1
Enter element: 10
Inserted Successfully.

===== CIRCULAR QUEUE USING CIRCULAR LINKED LIST =====
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 1
Enter element: 20
Inserted Successfully.

===== CIRCULAR QUEUE USING CIRCULAR LINKED LIST =====
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 1
Enter element: 30
Inserted Successfully.

===== CIRCULAR QUEUE USING CIRCULAR LINKED LIST =====
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 3

Queue Elements: 10 20 30

===== CIRCULAR QUEUE USING CIRCULAR LINKED LIST =====
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 2
Deleted Element = 10

===== CIRCULAR QUEUE USING CIRCULAR LINKED LIST =====
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 3

Queue Elements: 20 30

===== CIRCULAR QUEUE USING CIRCULAR LINKED LIST =====
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 1
Enter element: 40
Inserted Successfully.

===== CIRCULAR QUEUE USING CIRCULAR LINKED LIST =====
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 3

Queue Elements: 20 30 40

===== CIRCULAR QUEUE USING CIRCULAR LINKED LIST =====
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 2
Deleted Element = 20

===== CIRCULAR QUEUE USING CIRCULAR LINKED LIST =====
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 2
Deleted Element = 30

===== CIRCULAR QUEUE USING CIRCULAR LINKED LIST =====
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 2
Deleted Element = 40

===== CIRCULAR QUEUE USING CIRCULAR LINKED LIST =====
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 3

Queue is Empty!

===== CIRCULAR QUEUE USING CIRCULAR LINKED LIST =====
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 2

Queue is Empty!

===== CIRCULAR QUEUE USING CIRCULAR LINKED LIST =====
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 4
Program Ended.
*/
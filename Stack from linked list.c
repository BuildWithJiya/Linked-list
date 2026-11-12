#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *top = NULL;

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

/* Push operation */
void push(int data)
{
    node *newnode = CreateNode(data);

    newnode->next = top;
    top = newnode;

    printf("Node pushed into stack.\n");
}

/* Pop operation */
void pop()
{
    if (top == NULL)
    {
        printf("Stack is empty.\n");
        return;
    }

    node *temp = top;

    printf("Deleted element: %d\n", temp->data);

    top = top->next;

    free(temp);
}

/* Peek operation */
void peek()
{
    if (top == NULL)
    {
        printf("Stack is empty.\n");
        return;
    }

    printf("Top element: %d\n", top->data);
}

/* Check if stack is empty */
int isEmpty()
{
    return top == NULL;
}

/* Display stack */
void display()
{
    if (top == NULL)
    {
        printf("Stack is empty.\n");
        return;
    }

    node *temp = top;

    printf("Stack elements are: ");

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

/* Main function */
int main()
{
    int choice;
    int data;

    while (1)
    {
        printf("\n===== STACK USING SINGLY LINKED LIST =====\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Is Empty\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);

                push(data);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                if (isEmpty())
                {
                    printf("Stack is empty.\n");
                }
                else
                {
                    printf("Stack is not empty.\n");
                }
                break;

            case 6:
                printf("Program terminated.\n");
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}

/*
===== STACK USING SINGLY LINKED LIST =====
1. Push
2. Pop
3. Peek
4. Display
5. Is Empty
6. Exit
Enter your choice: 1
Enter data: 10
Node pushed into stack.

===== STACK USING SINGLY LINKED LIST =====
1. Push
2. Pop
3. Peek
4. Display
5. Is Empty
6. Exit
Enter your choice: 1
Enter data: 20
Node pushed into stack.

===== STACK USING SINGLY LINKED LIST =====
1. Push
2. Pop
3. Peek
4. Display
5. Is Empty
6. Exit
Enter your choice: 1
Enter data: 30
Node pushed into stack.

===== STACK USING SINGLY LINKED LIST =====
1. Push
2. Pop
3. Peek
4. Display
5. Is Empty
6. Exit
Enter your choice: 4
Stack elements are: 30 20 10

===== STACK USING SINGLY LINKED LIST =====
1. Push
2. Pop
3. Peek
4. Display
5. Is Empty
6. Exit
Enter your choice: 3
Top element: 30

===== STACK USING SINGLY LINKED LIST =====
1. Push
2. Pop
3. Peek
4. Display
5. Is Empty
6. Exit
Enter your choice: 2
Deleted element: 30

===== STACK USING SINGLY LINKED LIST =====
1. Push
2. Pop
3. Peek
4. Display
5. Is Empty
6. Exit
Enter your choice: 4
Stack elements are: 20 10

===== STACK USING SINGLY LINKED LIST =====
1. Push
2. Pop
3. Peek
4. Display
5. Is Empty
6. Exit
Enter your choice: 5
Stack is not empty.

===== STACK USING SINGLY LINKED LIST =====
1. Push
2. Pop
3. Peek
4. Display
5. Is Empty
6. Exit
Enter your choice: 2
Deleted element: 20

===== STACK USING SINGLY LINKED LIST =====
1. Push
2. Pop
3. Peek
4. Display
5. Is Empty
6. Exit
Enter your choice: 2
Deleted element: 10

===== STACK USING SINGLY LINKED LIST =====
1. Push
2. Pop
3. Peek
4. Display
5. Is Empty
6. Exit
Enter your choice: 5
Stack is empty.

===== STACK USING SINGLY LINKED LIST =====
1. Push
2. Pop
3. Peek
4. Display
5. Is Empty
6. Exit
Enter your choice: 2
Stack is empty.

===== STACK USING SINGLY LINKED LIST =====
1. Push
2. Pop
3. Peek
4. Display
5. Is Empty
6. Exit
Enter your choice: 3
Stack is empty.

===== STACK USING SINGLY LINKED LIST =====
1. Push
2. Pop
3. Peek
4. Display
5. Is Empty
6. Exit
Enter your choice: 4
Stack is empty.

===== STACK USING SINGLY LINKED LIST =====
1. Push
2. Pop
3. Peek
4. Display
5. Is Empty
6. Exit
Enter your choice: 6
Program terminated.
*/
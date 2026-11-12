
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

// Insert at beginning
void insertBeginning(int value)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));

    newnode->data = value;

    if (head == NULL)
    {
        head = newnode;
        newnode->next = head;
        newnode->prev = head;
    }
    else
    {
        struct node *last = head->prev;

        newnode->next = head;
        newnode->prev = last;
        last->next = newnode;
        head->prev = newnode;
        head = newnode;
    }

    printf("Node inserted.\n");
}

// Insert at end
void insertEnd(int value)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));

    newnode->data = value;

    if (head == NULL)
    {
        head = newnode;
        newnode->next = head;
        newnode->prev = head;
    }
    else
    {
        struct node *last = head->prev;

        newnode->next = head;
        newnode->prev = last;
        last->next = newnode;
        head->prev = newnode;
    }

    printf("Node inserted.\n");
}

// Insert at a given position
void insertPosition(int value, int pos)
{
    struct node *newnode, *temp;
    int i;

    if (pos < 1)
    {
        printf("Invalid position.\n");
        return;
    }

    if (pos == 1)
    {
        insertBeginning(value);
        return;
    }

    if (head == NULL)
    {
        printf("Invalid position.\n");
        return;
    }

    temp = head;

    for (i = 1; i < pos - 1 && temp->next != head; i++)
    {
        temp = temp->next;
    }

    if (i != pos - 1)
    {
        printf("Invalid position.\n");
        return;
    }

    newnode = (struct node*)malloc(sizeof(struct node));

    if (newnode == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    newnode->data = value;

    newnode->next = temp->next;
    newnode->prev = temp;
    temp->next->prev = newnode;
    temp->next = newnode;

    printf("Node inserted at position %d.\n", pos);
}

// Delete from beginning
void deleteBeginning()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct node *temp = head;

    if (head->next == head)
    {
        head = NULL;
    }
    else
    {
        struct node *last = head->prev;

        head = head->next;
        head->prev = last;
        last->next = head;
    }

    free(temp);
    printf("Node deleted.\n");
}

// Delete from a given position
void deletePosition(int pos)
{
    struct node *temp;
    int i;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    if (pos < 1)
    {
        printf("Invalid position.\n");
        return;
    }

    if (pos == 1)
    {
        deleteBeginning();
        return;
    }

    temp = head;

    for (i = 1; i < pos && temp->next != head; i++)
    {
        temp = temp->next;
    }

    if (i != pos)
    {
        printf("Invalid position.\n");
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    free(temp);

    printf("Node deleted from position %d.\n", pos);
}

// Display the list
void display()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct node *temp = head;

    printf("Circular Doubly Linked List: ");

    do
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    while (temp != head);

    printf("(Head)\n");
}

// Display in reverse
void reverseDisplay()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct node *temp = head->prev;

    printf("Reverse List: ");

    do
    {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    while (temp != head->prev);

    printf("(Tail)\n");
}

int main()
{
    int choice, value, pos;

    while (1)
    {
        printf("\n--- Circular Doubly Linked List ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete from Beginning\n");
        printf("4. Display\n");
        printf("5. Reverse Display\n");
        printf("6. Exit\n");
        printf("7. Insert at Position\n");
        printf("8. Delete from Position\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertBeginning(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(value);
                break;

            case 3:
                deleteBeginning();
                break;

            case 4:
                display();
                break;

            case 5:
                reverseDisplay();
                break;

            case 6:
                printf("Program terminated.\n");
                return 0;

            case 7:
                printf("Enter value: ");
                scanf("%d", &value);
                printf("Enter position: ");
                scanf("%d", &pos);
                insertPosition(value, pos);
                break;

            case 8:
                printf("Enter position: ");
                scanf("%d", &pos);
                deletePosition(pos);
                break;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
/*
--- Circular Doubly Linked List ---
1. Insert at Beginning
2. Insert at End
3. Delete from Beginning
4. Display
5. Reverse Display
6. Exit
7. Insert at Position
8. Delete from Position

Enter your choice: 1
Enter value: 10
Node inserted.

Enter your choice: 2
Enter value: 20
Node inserted.

Enter your choice: 2
Enter value: 30
Node inserted.

Enter your choice: 4
Circular Doubly Linked List: 10 <-> 20 <-> 30 <-> (Head)

Enter your choice: 5
Reverse List: 30 <-> 20 <-> 10 <-> (Tail)

Enter your choice: 7
Enter value: 15
Enter position: 2
Node inserted at position 2.

Enter your choice: 4
Circular Doubly Linked List: 10 <-> 15 <-> 20 <-> 30 <-> (Head)

Enter your choice: 8
Enter position: 3
Node deleted from position 3.

Enter your choice: 4
Circular Doubly Linked List: 10 <-> 15 <-> 30 <-> (Head)

Enter your choice: 3
Node deleted.

Enter your choice: 4
Circular Doubly Linked List: 15 <-> 30 <-> (Head)

Enter your choice: 6
Program terminated.
*/
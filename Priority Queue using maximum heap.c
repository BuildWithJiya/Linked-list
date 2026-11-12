#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct
{
    int arr[MAX];
    int rear;
} Queue;

/* Initialize queue */
void init(Queue *q)
{
    q->rear = -1;
}

/* Check if queue is full */
int isFull(Queue *q)
{
    return q->rear == MAX - 1;
}

/* Check if queue is empty */
int isEmpty(Queue *q)
{
    return q->rear == -1;
}

/* Swap two integers */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Insertion into max heap */
void insert(Queue *q, int data)
{
    int c, p;

    if (isFull(q))
    {
        printf("Priority Queue is Full\n");
        return;
    }

    /* Insert at the last position */
    q->arr[++q->rear] = data;

    c = q->rear;

    /*
       Move the newly inserted element upward
       until the max-heap property is restored.
    */
    do
    {
        p = (c - 1) / 2;

        if (q->arr[c] > q->arr[p])
        {
            swap(&q->arr[c], &q->arr[p]);
        }
        else
        {
            break;
        }

        c = p;

    } while (c != 0);
}

/* Deletion from max heap */
int delete(Queue *q)
{
    int p, c, z;

    if (isEmpty(q))
    {
        printf("Priority Queue is Empty\n");
        return -1;
    }

    p = c = 0;

    /* Store highest-priority element */
    z = q->arr[0];

    /* Replace root with last element */
    q->arr[0] = q->arr[q->rear];

    q->rear--;

    /*
       Move the root downward until
       max-heap property is restored.
    */
    do
    {
        c = 2 * p + 1;       // Left child

        if (c > q->rear)
        {
            break;
        }

        /*
           If right child exists and is greater
           than left child, select right child.
        */
        if (c < q->rear && q->arr[c] < q->arr[c + 1])
        {
            c = c + 1;
        }

        /* Compare parent with larger child */
        if (q->arr[p] < q->arr[c])
        {
            swap(&q->arr[p], &q->arr[c]);
        }
        else
        {
            break;
        }

        p = c;

    } while (c <= q->rear);

    return z;
}

/* Display priority queue */
void display(Queue *q)
{
    int i;

    if (isEmpty(q))
    {
        printf("Priority Queue is Empty\n");
        return;
    }

    printf("Priority Queue: ");

    for (i = 0; i <= q->rear; i++)
    {
        printf("%d ", q->arr[i]);
    }

    printf("\n");
}

/* Return highest-priority element */
int peek(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Priority Queue is Empty\n");
        return -1;
    }

    return q->arr[0];
}

/* Main function */
int main()
{
    Queue q;
    int choice, data, result;

    init(&q);

    while (1)
    {
        printf("\n===== PRIORITY QUEUE USING MAX HEAP =====\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);

                insert(&q, data);
                break;

            case 2:
                result = delete(&q);

                if (result != -1)
                {
                    printf("Deleted element: %d\n", result);
                }
                break;

            case 3:
                result = peek(&q);

                if (result != -1)
                {
                    printf("Highest priority element: %d\n", result);
                }
                break;

            case 4:
                display(&q);
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

/*
===== PRIORITY QUEUE USING MAX HEAP =====
1. Insert
2. Delete
3. Peek
4. Display
5. Exit
Enter your choice: 1
Enter data: 10

===== PRIORITY QUEUE USING MAX HEAP =====
1. Insert
2. Delete
3. Peek
4. Display
5. Exit
Enter your choice: 1
Enter data: 40

===== PRIORITY QUEUE USING MAX HEAP =====
1. Insert
2. Delete
3. Peek
4. Display
5. Exit
Enter your choice: 1
Enter data: 20

===== PRIORITY QUEUE USING MAX HEAP =====
1. Insert
2. Delete
3. Peek
4. Display
5. Exit
Enter your choice: 1
Enter data: 60

===== PRIORITY QUEUE USING MAX HEAP =====
1. Insert
2. Delete
3. Peek
4. Display
5. Exit
Enter your choice: 1
Enter data: 30

===== PRIORITY QUEUE USING MAX HEAP =====
1. Insert
2. Delete
3. Peek
4. Display
5. Exit
Enter your choice: 4
Priority Queue: 60 40 20 10 30

===== PRIORITY QUEUE USING MAX HEAP =====
1. Insert
2. Delete
3. Peek
4. Display
5. Exit
Enter your choice: 3
Highest priority element: 60

===== PRIORITY QUEUE USING MAX HEAP =====
1. Insert
2. Delete
3. Peek
4. Display
5. Exit
Enter your choice: 2
Deleted element: 60

===== PRIORITY QUEUE USING MAX HEAP =====
1. Insert
2. Delete
3. Peek
4. Display
5. Exit
Enter your choice: 4
Priority Queue: 40 30 20 10

===== PRIORITY QUEUE USING MAX HEAP =====
1. Insert
2. Delete
3. Peek
4. Display
5. Exit
Enter your choice: 2
Deleted element: 40

===== PRIORITY QUEUE USING MAX HEAP =====
1. Insert
2. Delete
3. Peek
4. Display
5. Exit
Enter your choice: 2
Deleted element: 30

===== PRIORITY QUEUE USING MAX HEAP =====
1. Insert
2. Delete
3. Peek
4. Display
5. Exit
Enter your choice: 4
Priority Queue: 20 10

===== PRIORITY QUEUE USING MAX HEAP =====
1. Insert
2. Delete
3. Peek
4. Display
5. Exit
Enter your choice: 2
Deleted element: 20

===== PRIORITY QUEUE USING MAX HEAP =====
1. Insert
2. Delete
3. Peek
4. Display
5. Exit
Enter your choice: 2
Deleted element: 10

===== PRIORITY QUEUE USING MAX HEAP =====
1. Insert
2. Delete
3. Peek
4. Display
5. Exit
Enter your choice: 2
Priority Queue is Empty

===== PRIORITY QUEUE USING MAX HEAP =====
1. Insert
2. Delete
3. Peek
4. Display
5. Exit
Enter your choice: 3
Priority Queue is Empty

===== PRIORITY QUEUE USING MAX HEAP =====
1. Insert
2. Delete
3. Peek
4. Display
5. Exit
Enter your choice: 4
Priority Queue is Empty

===== PRIORITY QUEUE USING MAX HEAP =====
1. Insert
2. Delete
3. Peek
4. Display
5. Exit
Enter your choice: 5
*/
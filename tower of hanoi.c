
#include <stdio.h>
#include <stdlib.h>

int count = 0;

// Recursive function for Tower of Hanoi
void tower_of_hanoi(int n, char source, char intermediate, char destination)
{
    // Base condition
    if (n == 0)
    {
        return;
    }

    // Move n-1 disks from source to intermediate
    tower_of_hanoi(n - 1, source, destination, intermediate);

    // Move the largest disk to destination
    printf("Move disk %d from %c to %c\n",
           n, source, destination);

    count++;

    // Move n-1 disks from intermediate to destination
    tower_of_hanoi(n - 1, intermediate, source, destination);
}

int main()
{
    int n;

    printf("Enter number of disks: ");
    scanf("%d", &n);

    // Input validation
    if (n <= 0)
    {
        printf("Please enter a positive number of disks.\n");
        return 0;
    }

    printf("\nSteps to solve Tower of Hanoi:\n");

    tower_of_hanoi(n, 'S', 'I', 'D');

    printf("\nTotal number of moves = %d\n", count);

    return 0;
}
/*

Enter number of disks: 3

Steps to solve Tower of Hanoi:
Move disk 1 from S to D
Move disk 2 from S to I
Move disk 1 from D to I
Move disk 3 from S to D
Move disk 1 from I to S
Move disk 2 from I to D
Move disk 1 from S to D

Total number of moves = 7
Enter number of disks: 4

Steps to solve Tower of Hanoi:
Move disk 1 from S to I
Move disk 2 from S to D
Move disk 1 from I to D
Move disk 3 from S to I
Move disk 1 from D to S
Move disk 2 from D to I
Move disk 1 from S to I
Move disk 4 from S to D
Move disk 1 from I to D
Move disk 2 from I to S
Move disk 1 from D to S
Move disk 3 from I to D
Move disk 1 from S to I
Move disk 2 from S to D
Move disk 1 from I to D

Total number of moves = 15
*/
/*Write a program to input ‘n’ numbers (the value of ‘n’ is specified at runtime) in an array
and display the largest and smallest among them.*/
#include "stdio.h"
#include "stdlib.h"
void main()
{
    int size, *numarray, *i;
    int j, largest, smallest;
    printf("\nHow many numbers do you want to enter: ");
    scanf("%d", &size);
    numarray = (int *)calloc(size, sizeof(int));
    if (numarray == NULL)
    {
        printf("No space is available\n");
        exit(1);
    }
    printf("\nspace allocated for %d integer", size);
    printf("\nEnter %d no. of integers: ", size);
    for (i = numarray; i < numarray + size; i++)
        scanf("%d", i);
    // for largest
    largest = *(numarray + 0);
    for (j = 1; j < size; j++)
    {
        if (*(numarray + j) > largest)
            largest = *(numarray + j);
    }
    // for smallest
    smallest = *(numarray + 0);
    for (j = 1; j < size; j++)
    {
        if (*(numarray + j) < smallest)
        {
            smallest = *(numarray + j);
        }
    }
    printf("\nLargest number in the array %d", largest);
    printf("\n\nSmallest of the array %d", smallest);
}
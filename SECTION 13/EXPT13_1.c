/*Write a program to input ‘n’ numbers (the value of ‘n’ is specified at runtime) in an array and display their sum and average*/
#include "stdio.h"
#include "stdlib.h"
void main()
{
    int size, sum = 0, *numarray, *i;
    float avg;
    printf("\nHow many numbers do you want to enter ?: ");
    scanf("%d", &size);
    numarray = (int *)malloc(size * sizeof(int));
    if (numarray == NULL)
    {
        printf("No space avaliable.\n");
        exit(1);
    }
    printf("\n space allocated for %d integer", size);
    printf("\n Enter %d number of integers: ", size);
    for (i = numarray; i < numarray + size; i++)
        scanf("%d", i);
    // To find sum
    for (i = numarray; i < numarray + size; i++)
    {
        sum = sum + *i;
        printf("%d\t", *i);
    }
    printf("\nSum of the arrray:%d", sum);
    // to find average
    avg = (float)sum / (float)size;
    printf("\nAverage of the array : %g", avg);

    free(numarray);
    free(i);
}
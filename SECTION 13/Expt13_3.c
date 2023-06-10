/*Write a menu-base program that creates two one-dimensional arrays at runtime and
performs the following operations as chosen by the user. Separate functions should be written for each of
the following operations.
1. Insert an element in the 1st array (if size exceeds the allocated size, use ‘realloc()’)
2. Sort the 1st array.
3. Sort the 2nd array.
4. Merge the two arrays.*/
#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
void display(int *arr,int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", *(arr + i));
    }
}
int* insert(int *arr, int size)
{
    int num;
    printf("Enter the inserting element/integer: ");
    scanf("%d", &num);
    arr = (int *)realloc(arr, (size + 1) * sizeof(int));
    if (arr == NULL)
    {
        printf("No space is avaliable");
        exit(1);
    }
    *(arr + size) = num;
    return arr;
}
void sort(int *arr, int size)
{
    int temp;
    for (int i = 0; i < (size - 1); i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (*(arr + i) > *(arr + j))
            {
                temp = *(arr + i);
                *(arr + i) = *(arr + j);
                *(arr + j) = temp;
            }
        }
    }
}
int* merge(int *arr1, int *arr2, int size1, int size2)
{
    int *merge, size;
    size = size1 + size2;
    merge = (int *)calloc(size, sizeof(int));
    if (merge == NULL)
    {
        printf("No space is avaliable");
        exit(1);
    }
    for (int i = 0; i < size1; i++)
    {
        *(merge + i) = *(arr1 + i);
    }
    for (int i = size1, j = 0; (i < size && j < size2); i++, j++)
    {
        *(merge + i) = *(arr2 + j);
    }
    return merge;
}

void main()
{
    int *arr1, *arr2, *i,*result;
    int size1, size2, choice;
    // for 1st array
    printf("How many numbers do you want to enter in 1st array:\n");
    scanf("%d", &size1);
    arr1 = (int *)malloc(size1 * sizeof(int));
    if (arr1 == NULL)
    {
        printf("no space is avaliable");
        exit(1);
    }
    printf("Enter %d no. of integers for arr1\n", size1);
    for (i = arr1; i < arr1 + size1; i++)
        scanf("%d", i);
    // for 2nd array
    printf("How many numbers do you want to enter in 2nd array:\n");
    scanf("%d", &size2);
    arr2 = (int *)malloc(size2 * sizeof(int));
    if (arr2 == NULL)
    {
        printf("No space is avaliable");
        exit(1);
    }
    printf("Enter %d no. of integers for arr2\n", size2);
    for (i = arr2; i < arr2 + size2; i++)
        scanf("%d", i);
    do
    {
        printf("\n---------------------------");
        printf("\n1)Insert an element n the 1st array.\n2)Sort the 1st array.\n3)Sort the 2nd array.\n4)Merge the two arrays.\n5)For exit the program\n");
        printf("\nEnter the choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            // insert an element in 1st arry
        case 1:
            result=insert(arr1, size1);
            display(result,size1+1);
            break;
        // sort 1st array
        case 2:
            sort(arr1, size1);
            display(arr1,size1);
            break;
        // sort 2nd array
        case 3:
            sort(arr2, size2);
            display(arr2,size2);
            break;
        // merge two arrays
        case 4:
            result=merge(arr1, arr2, size1, size2);
            display(result,size1+size2);
            break;
        case 5:
            printf("Exiting the program.\n");
            break;
        default:
            printf("Invalid choice!try again\n");
            break;
            printf("\n------------------------------------------------\n");
        }
    } while (choice != 5);
    {
        free(arr1);
        free(arr2);
        exit(0);
    }
}
//Given a list of integers, write a function that returns the largest sum of non-adjacent numbers. Numbers can be 0 or negative

#include<stdio.h>
#include<stdlib.h>

int findMaxSum(int arr[], int n)
{
    int incl = arr[0];
    int excl = 0;
    int excl_new;
    int i;

    for(i = 1; i < n; i++)
    {
        excl_new = (incl > excl) ? incl : excl;
        incl = excl + arr[i];
        excl = excl_new;
    }
    
    return ((incl>excl) ? incl : excl);
}

int main()
{
    printf("Enter the size of the array you want : ");
    int length;
    scanf("%d", &length);
    int arr[length];
    printf("\nNow enter the elements of the array : \n");
    int i;
    for( i = 0; i < length; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("The maximum sum is - %d", findMaxSum(arr, length));
    return 0;
}


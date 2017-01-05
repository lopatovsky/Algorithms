#include<stdio.h>
#include<stdlib.h>
 
int bitonic(int arr[], int n)
{
    int i;
    int *inc = new int[n];
    int *dec = new int[n];
    int max;
    inc[0] = 1; // The length of increasing sequence ending at first index is 1
    dec[n-1] = 1; // The length of increasing sequence starting at first index is 1
 
    // Step 1) Construct increasing sequence array
    for(i = 1; i < n; i++)
    {
        if (arr[i] > arr[i-1])
            inc[i] = inc[i-1] + 1;
        else
            inc[i] = 1;
    }
 
    // Step 2) Construct decreasing sequence array
    for (i = n-2; i >= 0; i--)
    {
        if (arr[i] > arr[i+1])
            dec[i] = dec[i+1] + 1;
        else
            dec[i] = 1;
    }
 
    // Step 3) Find the length of maximum length bitonic sequence
    max = inc[0] + dec[0] - 1;
    for (i = 1; i < n; i++)
    {
        if (inc[i] + dec[i] - 1 > max)
        {
            max = inc[i] + dec[i] - 1;
        }
    }
 
    // free dynamically allocated memory
    delete [] inc;
    delete [] dec;
 
    return max;
}
 
/* Driver program to test above function */
int main()
{
    int arr[] = {12, 4, 78, 90, 45, 23};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("\n Length of max length Bitnoic Subarray is %d", bitonic(arr, n));
    getchar();
    return 0;
}
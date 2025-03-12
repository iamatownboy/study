#include <stdio.h>

void ABC(int *arr, int k);

int main()
{
    int arr[10];
    int i, k;

    for(i = 0; i < 10; i++)
    {
        scanf("%d", arr + i); 
    }

    for(k = 0; k < 9; k++) 
    {
        ABC(arr, k); 
    }

    for(k = 0; k < 10; k++)
    {
        printf(" %d", arr[k]);
    }

    return 0;
}

void ABC(int *arr, int k)
{
    int i, max_idx = k, tmp;


    for(i = k + 1; i < 10; i++)
    {
        if(arr[i] > arr[max_idx])
        {
            max_idx = i;
        }
    }

    tmp = arr[k];
    arr[k] = arr[max_idx];
    arr[max_idx] = tmp;
}
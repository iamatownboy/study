#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int mostOnes(int **arr, int n);

int main(){
    
    int **arr;
    int i, j ,n;

    scanf("%d", &n);

    arr = (int**)malloc(sizeof(int*) * n);

    for(i = 0; i < n; i++)
    {
        arr[i] = (int*)malloc(sizeof(int) * n);
    }

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }

    printf("%d\n",mostOnes(arr, n));

    for(i = 0; i < n; i++)
    {
        free(arr[i]);
    }

    free(arr);

    return 0;
}

int mostOnes(int **arr, int n)
{
    int i , j, max_idx = -1;

    for (i = 0, j = 0 ; i < n && j < n; )
    {
        if(arr[i][j] == 1)
        {
            max_idx = i;
            j++;
        }

        else
        {
            i++;
        }
    }

    return max_idx;

}

/*
8
1 1 1 1 0 0 0 0 
1 1 1 1 1 0 0 0
1 0 0 0 0 0 0 0
1 1 1 1 1 1 0 0
1 1 1 1 0 0 0 0
0 0 0 0 0 0 0 0
1 1 1 1 1 1 1 0
1 1 1 1 1 0 0 0
*/
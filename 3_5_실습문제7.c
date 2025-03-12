#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int N, i;

    scanf("%d",&N);

    int *ar1 = (int*)malloc(sizeof(int) * N);
    int *ar2 = (int*)malloc(sizeof(int) * N);

    for(i=0; i<N; i++)
    {
        scanf("%d", &ar1[i]);
    }

    for(i=0; i<N; i++)
    {
        scanf("%d", &ar2[i]);
    }

    for(i =0; i<N; i++)
    {
        ar1[i] += ar2[N-1 - i];
    }

    for(i=0; i<N; i++)
    {
        printf(" %d", ar1[i]);
    }

    free(ar1);
    free(ar2);


    return 0;
}
#include <stdio.h>

#define MAX_SIZE 50

void swap(int *ar1, int *ar2);

int main()
{
    int ar[MAX_SIZE];
    int i, N;
    int a,b;

    scanf("%d", &N);

     if (N > MAX_SIZE || N <= 0)
    {
        return 1;
    }

    for(i = 0; i < N; i++)
    {
        scanf("%d", &ar[i]);
    }

    scanf("%d %d", &a, &b);

    if (a < 0 || a >= N || b < 0 || b >= N)
    {
        return 1;
    }

    swap(ar+a, ar+b);

    for(i = 0; i < N; i++)
    {
        printf(" %d",ar[i]);
    }

    return 0;
}

void swap(int *ar1, int *ar2)
{
    int tmp;

    tmp = *(ar1);
    *(ar1) = *(ar2);
    *(ar2) = tmp;
}
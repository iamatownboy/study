#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


int prefixAverages1(int *arr, int n);
int prefixAverages2(int *arr, int n);

int main()
{
    int N , i;
    int *arr;

    scanf("%d", &N);

    arr = (int*)malloc(sizeof(int) * N);

    for(i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }

    for(i = 0; i < N; i++)
    {
        printf("%d ", prefixAverages1(arr, i));
    }

    printf("\n");

    for(i = 0; i < N; i++)
    {
        printf("%d ", prefixAverages2(arr, i));
    }

    printf("\n");

}

int prefixAverages1(int *arr, int n)
{
    float sum = 0;
    int i;
    int avg = 0;

    for (i =0; i < n; i++)
    {
        sum += arr[i];
    }

    avg = sum / (n + 1);

    return avg;

}

int prefixAverages2(int *arr, int n)
{
    int *sum;
    int i;

    
    for(i = 0; i < n; i++)
    {

    }
}
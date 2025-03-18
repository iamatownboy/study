#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int findmissing(int *arr, int N);

int main()
{
    int i, N;
    int *arr;
    int result;

    scanf("%d", &N);

    arr = (int*)malloc(sizeof(int) * N);

    for(i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }

    result = findmissing(arr, N);

    printf(" %d", result);

    return 0;
}

int findmissing(int *arr, int N)
{
    int i;

    int sum = (N + 1) * ( N + 2) / 2; // 수학적 배경 : 1부터 N+1까지의 합을 구함


    for(i =0; i < N; i++) // 합에서 배열의 원소들을 하나씩 빼다보면 남은 값은 빠진 정수가 됨.
    {
        sum -= arr[i]; 
    }

    return sum;

}

/*

6
3 2 7 1 4 6

11
11 9 5 8 1 4 12 2 3 6 7

*/
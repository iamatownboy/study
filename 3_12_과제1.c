#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>


int *prefixAverages1(int *arr, int N);
int *prefixAverages2(int *arr, int N);

int main()
{
    int N , i;
    int *arr, *p;
    int result = 0;

    LARGE_INTEGER ticksPerSec;
    LARGE_INTEGER start, end, diff;

    srand(time(NULL));

    scanf("%d", &N);

    arr = (int*)malloc(sizeof(int) * N);

    if (arr == NULL)
        return -1;

    for(i = 0; i < N; i++)
    {
        arr[i] = rand() % 10001;
    }


    // 1번 방법 시간 측정 시작
    QueryPerformanceFrequency(&ticksPerSec); // 함수를 통해 타이머의 주파수를 변수에 저장
    QueryPerformanceCounter(&start); 
    int *A1 = prefixAverages1(arr, N); // 1번 방법 함수 호출
    QueryPerformanceCounter(&end);

    diff.QuadPart = end.QuadPart - start.QuadPart; // 쿨럭 차이 계산, quadpart는 64비트 정수로 저장
    printf("time: %.12f ms\n", ((double)diff.QuadPart/(double)ticksPerSec.QuadPart) * 1000);

    free(A1);

    // 2번 방법 시간 측정 시작
    QueryPerformanceFrequency(&ticksPerSec); // 함수를 통해 타이머의 주파수를 변수에 저장
    QueryPerformanceCounter(&start); 
    int *A2 = prefixAverages2(arr, N); // 2번 방법 함수 호출
    QueryPerformanceCounter(&end);

    diff.QuadPart = end.QuadPart - start.QuadPart; // 쿨럭 차이 계산, quadpart는 64비트 정수로 저장
    printf("time: %.12f ms\n", ((double)diff.QuadPart/(double)ticksPerSec.QuadPart) * 1000);

    free(A2);

    free(arr);

    return 0;
}


int *prefixAverages1(int *arr, int N) // 누적평균의 1번 방법은 just n개의 배열을 다 더해서 n개로 나누는 방법
{
    int i, j, avg;
    int sum = 0;

    int *A1 = (int*)malloc(sizeof(int) * N); 


    for (i = 0; i < N ; i++)
    {
        sum = 0;

        for(j = 0; j < i + 1; j++)
        {
            sum += arr[j];
        }

        avg = ( sum + (i + 1) / 2  ) / (i + 1);

        A1[i] = avg;
    }

    return A1;
}



int *prefixAverages2(int *arr, int N) // 누적평균의 2번 방법은 배열의 합을 저장해두고 
{
    int *A2 = (int*)malloc(sizeof(int) * N);   
    int i;
    int sum = 0;

    A2 = (int*)malloc(sizeof(int) * N);

    for (i = 0; i < N ; i++)
    {
        sum += arr[i];

        A2[i] = ( sum + (i + 1) / 2  ) / (i + 1);
    }

    return A2;

}

/*
1번 예시 - 100,000
2번 예시 - 200,000
3번 예시 - 500,000
*/
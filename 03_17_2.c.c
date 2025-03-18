#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int countOnes(int **arr, int N);

int main()
{
    
    int **arr;
    int i, j ,N;
    int sum_result = 0;

    scanf("%d", &N);

    arr = (int**)malloc(sizeof(int*) * N);

    for(i = 0; i < N; i++)
    {
        arr[i] = (int*)malloc(sizeof(int) * N);
    }

    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }

    sum_result = countOnes(arr, N);

    printf("%d",sum_result);

    for(i = 0; i < N; i++)
    {
        free(arr[i]);
    }

    free(arr);

    return 0;
}

int countOnes(int **arr, int N)
{
    int i, j;
    int sum = 0;

    for (i = N - 1, j = 0 ; i >= 0 && j < N; )
    {
        if(arr[i][j] == 1)
        {
            sum++;
            j++;
        }

        else //ar[i][j] == 0
        {
            i--;
            if(i >= 0)
                sum += j;
        }
    }

    return sum;
}


/*

8 
1 1 1 1 1 1 1 0 
1 1 1 1 1 1 0 0
1 1 1 1 1 1 0 0
1 1 1 1 1 0 0 0
1 1 1 1 0 0 0 0
1 1 1 1 0 0 0 0
1 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0

8
1 1 1 1 1 1 1 0
1 1 1 1 1 1 0 0
1 1 1 1 1 1 0 0
1 1 1 1 1 0 0 0
1 1 1 1 0 0 0 0
1 1 1 1 0 0 0 0
1 0 0 0 0 0 0 0
1 0 0 0 0 0 0 0
-> 풀이

a[7][0] == 1 찾음 -> i=7, j=1, sum=1
a[7][1] == 0이니까 -> i=6, j=1, sum=2 -> a[6][1]
a[6][1] == 0이니까 -> i=5, j=1, sum=3 -> a[5][1]
a[5][1] == 1 찾음 -> j=2, sum=4
a[5][2] == 1 찾음 -> j=3, sum=5
a[5][3] == 1 찾음 -> j=4, sum=6
a[5][4] == 0이니까 -> i=4, j=4, sum=10 -> a[4][4]
a[4][4] == 0이니까 -> i=3, j=4, sum=14 -> a[3][4]
a[3][4] == 1 찾음 -> j=5, sum=15 -> a[3][5]
a[3][5] == 0이니까 -> i=2, j=5, sum=20 -> a[2][5]
a[2][5] == 1 찾음 -> i=2, j=6, sum=21 -> a[2][6]
a[2][6] == 0이니까 -> i=1, j=6, sum=21 -> a[1][6]
a[1][6] == 0이니까 -> i=0, j=6, sum=27 -> a[0][6]
a[0][6] == 1 찾음 -> i=0, j=7, sum= 34 -> a[0][7]
a[0][7] == 0이니까 -> i=-1, j=7, sum=34 끝

*/
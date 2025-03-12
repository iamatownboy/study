#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int modulo(int a, int b);

int main()
{
    int a, b;
    int result ;

    scanf("%d %d", &a, &b);

    result = modulo(a, b);

    printf("%d", result);

    return 0;
}

int modulo(int a, int b)
{   
    
    while(1)
    {
        if (a == 0 || a < b)
            break;

        a -= b;
    }

    return a;
}

/*
srand(time(NULL));
printf(“%d\n”, rand());
return 0;



clock_t_start = clock();
clock_t end = clock();
printf("Execution time %.5f sec\n", (double)(end-start)/CLOCKS_PER_SEC);


시간 재기
Query Performance Frenquency() : 타이머의 주파수(초당 진동수)를 얻는 함수 -> clock per sec
Query Performance Counter() : 타이머의 cpu 클럭수를 얻는 함수 -< clock


Query Performance Frenquency(&tickPerSec);
Query Performance Counter(&start); // 시간을 측정하고 싶은 작업
Query Performance Counter(&end)
*/


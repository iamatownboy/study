#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct 
{
    int hour;
    int min;
    int sec;
}Time;

int main()
{
    Time x,y;
    int hour, min, sec;

    scanf("%d %d %d",&x.hour, &x.min, &x.sec);
    scanf("%d %d %d",&y.hour, &y.min, &y.sec);

    hour = y.hour - x.hour;
    min = y.min - x.min;
    sec = y.sec - x.sec;

    if (sec < 0)
    {
        sec += 60;
        min -= 1;
    }

    if (min < 0)
    {
        min += 60;
        hour -= 1;
    }

    printf("%d %d %d\n", hour, min , sec);


    return 0;
}
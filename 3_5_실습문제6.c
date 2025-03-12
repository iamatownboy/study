#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct 
{
    char name[10];
    int score;
}test;

int main()
{
    test list[5];
    float sum = 0;
    int i;

    for(i = 0; i < 5; i++)
    {
        scanf("%s",list[i].name);
        scanf("%d", &list[i].score);

        sum += list[i].score;
    }

    float avg = sum / 5;

    for(i = 0; i < 5; i++)
    {
        if (avg > list[i].score)
        {
            printf("%s\n",list[i].name);
        }
    }

    return 0;
}
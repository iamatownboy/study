#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct
{
    char name[8];
    int kor;
    int eng;
    int math;
    float avg;

}student;


int main()
{
    int N, i;
    float sum = 0;

    scanf("%d",&N);

    student *list = (student*)malloc(sizeof(student) * N );

    for(i=0; i<N; i++)
    {
        scanf("%s", list[i].name);
        scanf("%d %d %d", &list[i].kor,&list[i].eng, &list[i].math);
    }

    for(i=0; i<N; i++)
    {
        sum = 0;
        sum += list[i].kor;
        sum += list[i].eng;
        sum += list[i].math;

        list[i].avg = sum /3;

    }

    for(i=0; i<N; i++)
    {
        printf("%s %.1lf ",list[i].name, list[i].avg);

        if(list[i].kor >= 90 ||list[i].eng >= 90 || list[i].math >= 90)
        {
            printf("GREAT ");
        }

        if(list[i].kor < 70 ||list[i].eng <70 || list[i].math < 70)
        {
            printf("BAD ");
        }

        printf("\n");
    }
    
    free(list);

    return 0;
}
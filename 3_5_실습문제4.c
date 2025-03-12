#include <stdio.h>
#include <string.h>

#define MAX_SIZE 101

int main()
{
    char str[MAX_SIZE];
    char tmp[MAX_SIZE];

    int len = 0;
    int i,j;

    scanf("%s", str);

    getchar();

    len = strlen(str);

    for(i=0; i<len; i++)
    {
        printf("%s", str + i);

        strcpy(tmp, str);
        tmp[i] = '\0';

        printf("%s\n",tmp);

    }

    return 0;
}


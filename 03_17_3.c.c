#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 21

int calculation(int A, int B, int sign);

int main()
{
    int i, len;
    char str[MAX_SIZE], a[MAX_SIZE], b[MAX_SIZE];
    int sign, location_sign;
    int A, B;
    int result;
    
    scanf("%s", str);

    len = strlen(str);

    for(i = 0; i < len; i++)
    {
        if( str[i] == '+')
        {
            sign = 1;
            location_sign = i;
        }

        else if( str[i] == '-')
        {
            sign = 2;
            location_sign = i;
        }

        else if( str[i] == '*')
        {
            sign = 3;
            location_sign = i;
        }
    }

    strncpy(a,str,location_sign);
    a[location_sign] = '\0';

    strncpy(b,str+location_sign+1, len - location_sign - 1);
    b[len - location_sign] = '\0';

    A = atoi(a);
    B = atoi(b);

    result = calculation(A, B, sign);

    printf("%d", result);

    return 0;
}


int calculation(int a, int b, int sign)
{
    if (sign == 1)
        return (a + b);

    else if (sign == 2)
        return (a - b);

    else if (sign == 3)
        return (a * b);

    else
        return 0;
}

/*

123+456
4*64
3-16

*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int sum(int n);

int main()
{

    int i, n, result = 0;
    
    scanf("%d",&n);

    for(i=1; i<= n; i++)
    {
        result += sum(i);
    }

    printf("%d",result);

    return 0;
}

int sum(int n)
{
    int i, s=0;

    for(i=0; i <= n; i++)
    {
        s += i;
    }

    return s;
}
#define _crt_secure_no_warnings
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct StackType
{
    int arr[100];
    int top;

} StackType;

void init(StackType *s)
{
    s->top = -1; // 배열은 인덱스가 0부터 시작
}

//empty : return 1 , !empty : retun 0

int check_empty(StackType *s)
{
    if(s->top == -1)
        return 1;
    return 0;
}

// occupied : return 1 , !occupied : return 0

int check_occupied(StackType *s)
{
    if(s->top == 99)
        return 1;
    return 0;

}

void push(StackType *s, int value)
{
    if (check_occupied(s))
    {
        printf("Stack is full");
        exit(1);
    }
    printf("\npushed: %d\n", value);
    s->arr[++(s->top)] = value;
}

int pop(StackType *s)
{
    if(check_empty(s))
    {
        printf("Stack is empty");
        exit(1);
    }
    return s->arr[(s->top)--];
}

int peek(StackType *s) 
{
    if(check_empty(s))
    {
        printf("Stack is empty");
        exit(1);
    }
    return s->arr[(s->top)];
    
}

int main()
{
    StackType s;
    init(&s); // 스택이 초기화됨

    push(&s, 3);
    push(&s, 2);
    push(&s, 1);

    printf("\npeek : %d\n", peek(&s));
    printf("\npop : %d\n", pop(&s));
    printf("\npop : %d\n", pop(&s));
    printf("\npop : %d\n", pop(&s));


    return 0;
}
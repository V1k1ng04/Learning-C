#include<stdio.h>
#include<stdlib.h>

#define MAX 5

struct stack{

    int top;
    int items[MAX];
};

void init(struct stack* stk)
{
    stk->top = -1;
}

void push(struct stack* stk)
{
    int ele;
    printf("\nEnter element you want to push: ");
    scanf("%d", &ele);

    if(stk->top == MAX-1)
    {
        printf("Overflow");
        return;
    }
    stk->top++; // Increment the top index first
    stk->items[stk->top] = ele;
    printf("\n%d pushed to stack.", ele);
}

void pop(struct stack* stk)
{
    if(stk->top == -1)
    {
        printf("\nUnderflow");
        return;
    }

    printf("\n%d popped from stack", stk->items[stk->top]);
    --stk->top;
}

void display(struct stack* stk)
{
    if (stk->top == -1)
    {
        printf("\nStack empty");
        return;
    }
    for(int i=stk->top; i>-1; i--)
    {
        printf("%d\t", stk->items[i]);
    }

}

void main()
{
    struct stack* stk;
    int ch;
    stk = (struct stack*)malloc(sizeof(struct stack));
    init(stk);
    while(1)
    {
        printf("\nStack operations:");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\n");
        printf("\nEnter choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                push(stk);
                break;
            case 2:
                pop(stk);
                break;
            case 3:
                display(stk);
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid");
        }
    }
}
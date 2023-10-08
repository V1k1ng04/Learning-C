#include <stdio.h>
#include <stdlib.h>

int stack[];
int top = -1;

void push(int value) {
    if (top == 9) {
        printf("Error: Stack overflow!\n");
        return;
    }
    stack[++top] = value;
}

int pop() {
    if (top == -1) {
        printf("Error: Stack underflow!\n");
        return -1;
    }
    return stack[top--];
}

void show()
{
    int i;
    for (i=top;i>=0;i--)
    {
        printf("%d\n",stack[i]);
    }
    if(top == -1)
    {
        printf("Stack is empty");
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("1. Push\n2. Pop\n3. Show\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                value = pop();
                if (value != -1) {
                    printf("Popped value: %d\n", value);
                }
                break;

            case 3:
                show();
                break;

            case 4:
                exit(0);
                break;

            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

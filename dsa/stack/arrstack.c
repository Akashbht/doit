#include <stdio.h>
#include <stdlib.h>

struct stack {
    int *arr;
    int capacity, size, top;
};

void initialise(struct stack *s1, int cap) {
    s1->capacity = cap;
    s1->size = 0;
    s1->top = -1;
    s1->arr = (int *)malloc(sizeof(int) * cap);
}

void push(struct stack *s1, int val) {
    if (s1->size == s1->capacity) {
        printf("stack Overflow\n");
        return;
    }
    s1->top++;
    s1->arr[s1->top] = val;
    s1->size++;
}

int pop(struct stack *s1) {
    if (s1->top == -1) {
        printf("stack Underflow\n");
        return -1;
    }
    int val = s1->arr[s1->top];
    s1->top--;
    s1->size--;
    return val;
}

void printstack(struct stack *s1) {
    if (s1->top == -1) {
        printf("Empty stack\n");
        return;
    }
    for (int i = 0; i <= s1->top; i++) {
        printf("%d ", s1->arr[i]);
    }
    printf("\n");
}

int top(struct stack *s1) {
    if (s1->top == -1) {
        printf("Empty stack\n");
        return -1;
    }
    return s1->arr[s1->top];
}

struct stack* reverse(struct stack* s){
    if(s->top==-1){
        printf("empty stack");
        return NULL;
    }
    struct stack* temp = (struct stack*)malloc(sizeof(struct stack));
    initialise(temp, 10);
    while(s->top != -1){
        push(temp,pop(s));
    }

    return temp;
}

int main() {
    struct stack s1;
    initialise(&s1, 10);
    printstack(&s1);
    for (int i = 1; i < 11; i++) {
        push(&s1, i);
    }
    printstack(&s1);
    int val = pop(&s1);
    printf("Popped val: %d\n", val);
    printstack(&s1);

    struct stack* s2 = reverse(&s1);
    printstack(s2);

    return 0;
}



#include <stdio.h>
#include <stdlib.h>

struct arrstack {
    int *arr;
    int capacity, size, top;
};

void initialisearr(struct arrstack *s1, int cap) {
    s1->capacity = cap;
    s1->size = 0;
    s1->top = -1;
    s1->arr = (int *)malloc(sizeof(int) * cap);
}

void pusharr(struct arrstack *s1, int val) {
    if (s1->size == s1->capacity) {
        printf("arrstack Overflow\n");
        return;
    }
    s1->top++;
    s1->arr[s1->top] = val;
    s1->size++;
}

int poparr(struct arrstack *s1) {
    if (s1->top == -1) {
        printf("arrstack Underflow\n");
        return -1;
    }
    int val = s1->arr[s1->top];
    s1->top--;
    s1->size--;
    return val;
}

void printstackarr(struct arrstack *s1) {
    if (s1->top == -1) {
        printf("Empty arrstack\n");
        return;
    }
    for (int i = 0; i <= s1->top; i++) {
        printf("%d ", s1->arr[i]);
    }
    printf("\n");
}

int toparr(struct arrstack *s1) {
    if (s1->top == -1) {
        printf("Empty arrstack\n");
        return -1;
    }
    return s1->arr[s1->top];
}

int main() {
    struct arrstack s1;
    initialisearr(&s1, 10);
    printstackarr(&s1);
    for (int i = 1; i < 11; i++) {
        pusharr(&s1, i);
    }
    printstackarr(&s1);
    int val = pop(&s1);
    printf("Popped val: %d\n", val);
    printstackarr(&s1);
    return 0;
}



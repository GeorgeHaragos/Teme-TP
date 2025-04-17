#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct { //structura de date tip stiva
    int arr[MAX];
    int top; //indexul valorii care a fost adaugata ultima
} Stack;

void initStack(Stack* s) { //initializare stiva
    s->top = -1;
}

int isEmpty(Stack* s) { //functia de verificare daca este goala
    return s->top == -1;
}

int isFull(Stack* s) { //functia de verificare daca este plina
    return s->top == MAX - 1;
}

void push(Stack* s, int value) { //adaugam in stiva
    if (isFull(s)) {
        printf("Stiva este plina!\n");
        return;
    }
    s->arr[++s->top] = value;
}

int pop(Stack* s) { //scoatem din stiva
    if (isEmpty(s)) {
        printf("Stiva este goala!\n");
        return -1;
    }
    return s->arr[s->top--];//"scoatem" elementul din stiva 
}

int peek(Stack* s) { //verificam elementul pe care il putem scoate din stiva
    if (isEmpty(s)) {
        printf("Stiva este goala!\n");
        return -1;
    }
    return s->arr[s->top];
}

int main() {
    Stack *s=(Stack *)malloc(sizeof(Stack));
    initStack(s);
    int x;
    for(int i=0;i<5;i++){ //introducem decat 5 elemente ca sa verificam daca functioneaza cum ne-am dori
    printf("Introduce-ti element in stiva: \n");
    scanf("%d",&x);
    push(s,x);
    }
    printf("Varful stivei: %d\n", peek(s));
    while(!isEmpty(s)){//golim stiva
    printf("Element scos din stiva: %d\n", pop(s));
    }
    free(s);
    return 0;
}
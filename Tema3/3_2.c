#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE 100

typedef struct { //structura de date de tip coada
    int arr[MAX_QUEUE];
    int front, rear; //salvam pozitia primului din coada si a ultimului
} Queue;

void initQueue(Queue* q) { //functie de initializare coada
    q->front = 0;
    q->rear = -1;
}

int isQueueEmpty(Queue* q) { //functie care verifica daca coada este goala
    return q->front > q->rear;
}

int isQueueFull(Queue* q) { //functie care verifica daca coada este plina
    return q->rear == MAX_QUEUE - 1;
}

void enqueue(Queue* q, int value) { //functie pentru a introduce in coada un element
    if (isQueueFull(q)) {
        printf("Coada este plina!\n");
        return;
    }
    q->arr[++q->rear] = value; //daca introducem inca un element in coada atunci trebuie sa "marim" coada adica indexul pentru ultimul din coada (rear)
}

int dequeue(Queue* q) { //functie pentru a scoate un element din coada
    if (isQueueEmpty(q)) {
        printf("Coada este goala!\n");
        return -1;
    }
    return q->arr[q->front++]; //daca am scos un element din coada atunci urmatorul va deveni primul in coada
}

int main() {
    Queue *q=(Queue *)malloc(sizeof(Queue));
    initQueue(q);
    int elem;
    for(int i=0;i<5;i++){ //iarasi am introdus 5 elemente in coada ca sa verific daca face ce imi doream
        printf("Introduceti un element in coada:\n");
        scanf("%d",&elem);
        enqueue(q, elem);
    }
    
    while (!isQueueEmpty(q)){ //golim coada
        printf("Element scos din coada: %d\n", dequeue(q));
    }
    free(q);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 100

typedef struct { //structura pentru salvarea fiecarui "mesaj" din coada
    int id;
    char message[256];
} BufferItem;

typedef struct { //structura de tip coada
    BufferItem items[MAX_BUFFER];
    int front, rear;
} BufferQueue;

void initBuffer(BufferQueue* q) {//initializare coada
    q->front = 0;
    q->rear = -1;
}

int isBufferEmpty(BufferQueue* q) {//functie de verificare daca coada este goala
    return q->front > q->rear;
}

int isBufferFull(BufferQueue* q) {//functie de verificare daca coada este plina
    return q->rear == MAX_BUFFER - 1;
}

void addMessage(BufferQueue* q, int id, const char* message) {//enqueue
    if (isBufferFull(q)) {
        printf("Buffer-ul este plin!\n");
        return;
    }
    q->rear++;
    q->items[q->rear].id = id;
    strcpy(q->items[q->rear].message, message);
}

BufferItem getMessage(BufferQueue* q) {//dequeue
    if (isBufferEmpty(q)) {
        printf("Buffer-ul este gol!\n");
        BufferItem empty = {-1, ""};
        return empty;
    }
    return q->items[q->front++];
}

int main() {
    BufferQueue *q=(BufferQueue *)malloc(sizeof(BufferQueue));
    initBuffer(q);

    addMessage(q, 1, "Mesaj de la transmitatorul 1");//introducem mesaje in coada
    addMessage(q, 2, "Mesaj de la transmitatorul 2");

    BufferItem item = getMessage(q);
    printf("Mesaj primit de la %d: %s\n", item.id, item.message);//mesajele sunt scoase din coada

    item = getMessage(q);
    printf("Mesaj primit de la %d: %s\n", item.id, item.message);

    return 0;
}

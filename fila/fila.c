#include "fila.h"

void initFila(Fila* fila) {
    fila->front = 0;
    fila->rear = 0;
    fila->size = 0;
}

int isFilaEmpty(Fila* fila) {
    return fila->size == 0;
}

int isFilaFull(Fila* fila) {
    return fila->size == QUEUE_SIZE;
}

int enqueue(Fila* fila, Peca peca) {
    if (isFilaFull(fila)) {
        return 0; // Fila cheia
    }
    fila->items[fila->rear] = peca;
    fila->rear = (fila->rear + 1) % QUEUE_SIZE;
    fila->size++;
    return 1; // Sucesso
}

int dequeue(Fila* fila, Peca* peca) {
    if (isFilaEmpty(fila)) {
        return 0; // Fila vazia
    }
    *peca = fila->items[fila->front];
    fila->front = (fila->front + 1) % QUEUE_SIZE;
    fila->size--;
    return 1; // Sucesso
}

void printFila(Fila* fila) {
    if (isFilaEmpty(fila)) {
        printf("Fila vazia.\n");
        return;
    }
    for (int i = 0; i < fila->size; i++) {
        int index = (fila->front + i) % QUEUE_SIZE;
        printPeca(&fila->items[index]);
    }
}
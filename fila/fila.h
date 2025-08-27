#ifndef FILA_H
#define FILA_H

#include "../peca/peca.h"
#include <stdio.h>

#define QUEUE_SIZE 10

typedef struct {
    Peca items[QUEUE_SIZE];
    int front;
    int rear;
    int size;
} Fila;

void initFila(Fila* fila);
int isFilaEmpty(Fila* fila);
int isFilaFull(Fila* fila);
int enqueue(Fila* fila, Peca peca);
int dequeue(Fila* fila, Peca* peca);
void printFila(Fila* fila);

#endif // FILA_H
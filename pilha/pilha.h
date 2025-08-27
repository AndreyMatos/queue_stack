#ifndef PILHA_H
#define PILHA_H

#include "../peca/peca.h"
#include <stdio.h>

#define STACK_SIZE 5

typedef struct {
    Peca items[STACK_SIZE];
    int top;
} Pilha;

void initPilha(Pilha* pilha);
int isPilhaEmpty(Pilha* pilha);
int isPilhaFull(Pilha* pilha);
int push(Pilha* pilha, Peca peca);
int pop(Pilha* pilha, Peca* peca);
void printPilha(Pilha* pilha);

#endif // PILHA_H
#include "pilha.h"

void initPilha(Pilha* pilha) {
    pilha->top = -1;
}

int isPilhaEmpty(Pilha* pilha) {
    return pilha->top == -1;
}

int isPilhaFull(Pilha* pilha) {
    return pilha->top == STACK_SIZE - 1;
}

int push(Pilha* pilha, Peca peca) {
    if (isPilhaFull(pilha)) {
        return 0; // Pilha cheia
    }
    pilha->items[++pilha->top] = peca;
    return 1; // Sucesso
}

int pop(Pilha* pilha, Peca* peca) {
    if (isPilhaEmpty(pilha)) {
        return 0; // Pilha vazia
    }
    *peca = pilha->items[pilha->top--];
    return 1; // Sucesso
}

void printPilha(Pilha* pilha) {
    if (isPilhaEmpty(pilha)) {
        printf("Pilha vazia.\n");
        return;
    }
    printf("(Topo -> base): ");
    for (int i = pilha->top; i >= 0; i--) {
        printPeca(&pilha->items[i]);
    }
}
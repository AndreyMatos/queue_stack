#include "menu.h"

void exibeMenu() {
    printf("Menu de Opcoes:\n");
    printf("1. Jogar peça da frente da fila\n");
    printf("2. Enviar peça da fila para a pilha de reserva\n");
    printf("3. Usar peça da pilha de reserva\n");
    printf("4. Trocar peça da frente da fila com o topo da pilha\n");
    printf("5. Trocar os 3 primeiros da fila com as 3 peças da pilha\n");
    printf("0. Sair\n");
}

int leOpcao() {
    int opcao;
    scanf("%d", &opcao);
    return opcao;
}

void processaOpcao(int opcao, Fila* fila, Pilha* pilha) {
    Peca peca;
    switch (opcao) {
        case 1:
            dequeue(fila, &peca);
            break;
        case 2:
            dequeue(fila, &peca);
            push(pilha, peca);
            break;
        case 3:
            pop(pilha, &peca);
            break;
        case 4:
            swapFrontWithTop(fila, pilha);
            break;
        case 5:
            swapFirstThree(fila, pilha);
            break;
        case 0:
            break;
        default:
            printf("Opcao invalida. Tente novamente.\n");
    }
    printEstado(fila, pilha);
}

void swapFrontWithTop(Fila* fila, Pilha* pilha) {
    if (isFilaEmpty(fila) || isPilhaEmpty(pilha)) {
        printf("Nao e possivel trocar: fila ou pilha vazia.\n");
        return;
    }
    Peca frontPeca, topPeca;
    dequeue(fila, &frontPeca);
    pop(pilha, &topPeca);
    enqueue(fila, topPeca);
    push(pilha, frontPeca);
}

void swapFirstThree(Fila* fila, Pilha* pilha) {
    if (fila->size < 3 || pilha->top < 2) {
        printf("Nao e possivel trocar: fila ou pilha nao possuem pecas suficientes.\n");
        return;
    }
    for(int i = 0; i < 3; i++) {
        Peca filaPeca = fila->items[(fila->front + i) % QUEUE_SIZE];
        Peca pilhaPeca = pilha->items[pilha->top - i];
        Peca temp = filaPeca;
        fila->items[(fila->front + i) % QUEUE_SIZE] = pilhaPeca;
        pilha->items[i] = temp;
    }
}

void printEstado(Fila* fila, Pilha* pilha) {
    printFila(fila);
    printf("\n");
    printPilha(pilha);
    printf("\n");
}
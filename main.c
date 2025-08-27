#include "../menu/menu.h"

int main() {
    Fila fila;
    Pilha pilha;
    initFila(&fila);
    initPilha(&pilha);
    srand(time(NULL));
    for(int i = 0; i < QUEUE_SIZE; i++) {
        Peca peca = geraPeca();
        enqueue(&fila, peca);
    }
    int opcao = -1;
    printEstado(&fila, &pilha);
    while (opcao != 0) {
        exibeMenu();
        opcao = leOpcao();
        processaOpcao(opcao, &fila, &pilha);
    }
    return 0;
}
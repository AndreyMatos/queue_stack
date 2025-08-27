#include "../menu/menu.h"

int main() {
    Fila fila;
    Pilha pilha;
    initFila(&fila);
    initPilha(&pilha);
    srand(time(NULL));
    char codigos[] = {'I', 'L', 'T', 'O', 'I'};
    int ids[] = {0, 1, 2, 3, 4};
    for(int i = 0; i < 5; i++) {
        Peca peca;
        peca.tipo = codigos[i];
        peca.id = ids[i];
        enqueue(&fila, peca);
    }
    char codigosPilha[] = {'T', 'L', 'O'};
    int idsPilha[] = {6, 7, 8};
    for(int i = 0; i < 3; i++) {
        Peca peca;
        peca.tipo = codigosPilha[i];
        peca.id = idsPilha[i];
        push(&pilha, peca);
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
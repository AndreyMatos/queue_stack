#include "peca.h"

Peca geraPeca() {
    Peca novaPeca;
    novaPeca.id = rand() % 1000;
    novaPeca.tipo = 'A' + (novaPeca.id % 26);
    return novaPeca;
}

void printPeca(const Peca* peca) {
    printf("[%c %d] ", peca->tipo, peca->id);
}
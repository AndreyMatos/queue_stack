#ifndef PECA_H
#define PECA_H

#include <stdlib.h>
#include <time.h>
#include <stdio.h>

typedef struct {
    int id;
    char tipo;
} Peca;

Peca geraPeca();
void printPeca(const Peca* peca);

#endif // PECA_H

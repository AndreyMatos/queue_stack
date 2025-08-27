#ifndef MENU_H
#define MENU_H

#include <stdio.h>
#include "../fila/fila.h"
#include "../pilha/pilha.h"

void exibeMenu();
int leOpcao();
void processaOpcao(int opcao, Fila* fila, Pilha* pilha);
void printEstado(Fila* fila, Pilha* pilha);
void swapFrontWithTop(Fila* fila, Pilha* pilha);
void swapFirstThree(Fila* fila, Pilha* pilha);

#endif // MENU_H

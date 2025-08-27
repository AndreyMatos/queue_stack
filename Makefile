CC=gcc
CFLAGS=-Wall -Wextra -std=c99

SRC=main.c fila/fila.c peca/peca.c menu/menu.c pilha/pilha.c
INC=-Ipeca -Ifila -Imenu -Ipilha

main: $(SRC)
	$(CC) $(CFLAGS) $(INC) -o main $(SRC)

clean:
	rm -f main *.o fila/*.o peca/*.o menu/*.o pilha/*.o

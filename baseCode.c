// Trabalho de CLP, codigo base, sem paralelizacao.
#include<stdio.h>
#include<stdlib.h>

void fullVet(int *vet, int sizeVet, int valueMod, int numberTeamThreads);
int fibonacci(int num);

int main(int argc, char *argv[]){
	// Pego por linha de comando as informacoes
	int sizeVet = atoi(argv[1]);
	int valueMod = atoi(argv[2]);
	int numberTeamThreads = atoi(argv[3]);
	int *vet;

	vet = (int*)malloc(sizeVet*sizeof(int));
	if(vet == NULL){
		printf("Erro ao alocar Memoria");
		exit(1);
	}
	// Tal funcao contera a paralelizacao.
	// Func encarregado de preencher o vator e chamar o fibonacci
	fullVet(vet, sizeVet, valueMod, numberTeamThreads);

	// printa os valores contidos no vetor
	for(int i=0; i<sizeVet; ++i)
		printf("Vetor[%d] = %d;\n", i, vet[i]);

	free(vet);
	return 0;
}

void fullVet(int *vet, int sizeVet, int valueMod, int numberTeamThreads){
	for(int i=0; i<sizeVet; ++i){
		vet[i]= fibonacci(i%valueMod+1);		}
	}
}

int fibonacci(int num){
	if(num==1 || num==2)
		return 1;
	else
		return fibonacci(num-1)+fibonacci(num-2);
}

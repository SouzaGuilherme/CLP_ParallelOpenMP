// Trabalho de CLP, codigo base, sem paralelizacao.
#include<stdio.h>
#include<stdlib.h>

void funcFatorial(int *vet, int sizeVet, int valueMod, int numberTeamThreds);

int main(int argc, char *argv[]){
	// Pego por linha de comando as informacoes
	int sizeVet = atoi(argv[1]);
	int valueMod = atoi(argv[2]);
	int numberTeamThreds = atoi(argv[3]);
	int *vet;

	vet = (int*)malloc(sizeVet*sizeof(int));
	if(vet == NULL){
		printf("Erro ao alocar Memoria");
		exit(1);
	}
	// Incova a funcao encarregada de realizar o fatorial.
	// Tal funcao contera a paralelizacao.
	funcFatorial(vet, sizeVet, valueMod, numberTeamThreds);

	// printa os valores contidos no vetor
	for(int i=0; i<sizeVet; ++i)
		printf("Vetor[%d] = %d;\n", i, vet[i]);

	free(vet);
	return 0;
}

void funcFatorial(int *vet, int sizeVet, int valueMod, int numberTeamThreds){
	for(int i=0; i<sizeVet; ++i){
		int n =  i%valueMod;
		int resultFat = 1;
		for(int j=1; j<=n; ++j)
			resultFat *= j;
		vet[i]=resultFat;
	}
}

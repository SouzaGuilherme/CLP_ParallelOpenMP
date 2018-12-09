// Trabalho de CLP, codigo base, sem paralelizacao.
// PARA COMPILAR USE $gcc -fopenmp baseCodeParallel.c -o nomeExecutavel
#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

void fullVet(int *vet, int sizeVet, int valueMod, int numberTeamThreads);
int fibonacci(int num);

int main(int argc, char *argv[]){
	// Pego por linha de comando as informacoes.
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
	// Func encarregada de preencher o vetor  e chamar a fibonacci.
	fullVet(vet, sizeVet, valueMod, numberTeamThreads);

	// printa os valores contidos no vetor.
	// for(int i=0; i<sizeVet; ++i)
	// 	printf("Vetor[%d] = %d;\n", i, vet[i]);

	free(vet);
	return 0;
}

void fullVet(int *vet, int sizeVet, int valueMod, int numberTeamThreads){
	int chunk = sizeVet/numberTeamThreads; // Julgo que para funcionar o sizeVet e NumberThreads sejam par.
	#pragma omp parallel num_threads(numberTeamThreads)
	//#pragma omp parallel shared(vet, sizeVet, valueMod, chunk){ //NAO SEI SE HA NECESSIDADE TEM QUE VERIFICAR
	#pragma omp parallel for schedule(static, chunk) 
		for(int i=0; i<sizeVet; ++i){
			vet[i]= fibonacci(i%valueMod+1);
		}
	//}
}
// Nao se tem ganho ao paralelilar o fibonacci pois ha um gasto enorme em questao de  criar as threads e dar suas funcoes (algo assim)
int fibonacci(int num){
	int i, j;
	if(num<2)
		return 1;
	else{
		#pragma omp task shared(i)
		i=fibonacci(num-1);
		#pragma omp task shared(j)
		j=fibonacci(num-2);
		#pragma omp taskwait
		return i+j;
	}
}

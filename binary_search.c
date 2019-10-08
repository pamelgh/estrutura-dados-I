/******** UNIVERSIDADE FEDERAL DA FRONTEIRA SUL *******
*****  CIÊNCIA DA COMPUTAÇÃO, 2º FASE
***  ALUNA:  Pâmela Gheno
** ESTRUTURA DE DADOS I

******************************************************
Busca Binária */

#include <stdio.h>
#include <stdlib.h>

#define TAM 10

void ordenaInsert(int vet[], int size){
	int i, j, aux;
	for(j = 1; j < TAM; j++){
		aux = vet[j];
		i = j-1;

		while (i>=0 && vet[i]>aux){
			vet[i+1] = vet[i];
			i--;
		}
		vet[i+1] = aux;
	}
}

int BinarySearch(int min, int max, int vet[], int chave){
	int meio;
	if(min>max)
		return -1;
	else{
		meio = (min+max)/2;
		if(vet[meio] == chave){
			return meio;
		}
		else if(vet[meio] < chave){
			return BinarySearch(meio+1, max, vet, chave);
		}
		else if(vet[meio] > chave){
			return BinarySearch(min, meio-1, vet, chave);
		}
	}
}


int main(){

	int vet[TAM],i, chave, x;
	
	printf("Digite o valor de cada posição do vetor :\n");

		for(i=0; i<TAM; i++){
			printf("%dº :  ", i+1);
			scanf("%d", &vet[i]);
		}

	ordenaInsert(vet, TAM);
	printf("Numeros odenados teste:\n");

		for(i=0; i<TAM; i++){
				printf("%d  ", vet[i]);
		}

	printf("\n");
	printf("Qual numero deseja buscar?? \n");
	scanf("%d", &chave);

	x = BinarySearch(0,TAM, vet, chave);

	if(x == -1)
		printf("Valor nao encontrado !\n");
	else 
		printf("Valor %d está na posição %d\n", chave, x);

}







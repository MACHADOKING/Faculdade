#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprimir(int *v, int t){
  for (int i = 0; i < t; i++)
    printf("%d ", *(v + i));
  printf("\n");
}

int main(void) {
  int i, tam, *vet;

  printf("Digite o tamanho do vetor: ");
  scanf("%d", &tam);
  srand(time(NULL));

  vet = malloc(tam * sizeof(int));

  if(vet){
    printf("Memória alocada com sucesso.\n");
    for(i = 0; i < tam; i++)
      *(vet + i) = rand() % 100;
    
    imprimir(vet, tam);

    printf("Digite o novo tamanho do vetor: ");
    scanf("%d", &tam);

    vet = realloc(vet, tam);

    imprimir(vet, tam);
  }else
    printf("Erro ao alocar memória.\n");
}
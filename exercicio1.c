#include <stdio.h>
#include <stdlib.h>

struct diagonal {
    int ordem;
    int *v;
};
typedef struct diagonal Diagonal;

Diagonal cria_matriz(){
    Diagonal matriz;
    printf("\nDigite a dimensão da Matriz Diagonal:\n");
    int ordem;
    scanf("%d", &ordem);

    int* vetor = (int *)malloc(sizeof(int)*ordem);
    if (vetor == NULL){
        printf("Erro na alocacao.\n");
        exit(1);
    }
    matriz.ordem = ordem;
    matriz.v = vetor;

    return matriz;

}
Diagonal preenche_matriz (Diagonal matriz) {
    for (int i = 0; i < matriz.ordem; i++){
        printf("Digite o valor de [%d][%d]:\n", i, i);
        scanf("%d", &matriz.v[i]);
    }
    return matriz;
}

void imprime_matriz(Diagonal matriz) {
    int zero = 0;
    printf("\n======== MATRIZ FINAL ========\n\n");
    for (int i = 0; i < matriz.ordem; i++){
        for (int j = 0; j < matriz.ordem; j++){
            if (i == j){
                printf(" %5d", matriz.v);
            } else {
                printf(" %5d", zero);
            }
        }
        printf("\n");
    }
}

void consulta (Diagonal matriz) {
    printf("Digite duas coordenadas para buscar na matriz \"x y\", ou \"-1\" para sair:\n");
    int num1, num2, result;
    while (scanf("%d", &num1) != -1) {
        scanf("%d", &n2);
        if (num1 != num2){
            result = 0;
        } else {
            
        }
        for (int i = 0; i )
    }
}
int main() {
    Diagonal matriz;
    matriz = cria_matriz();
    matriz = preenche_matriz(matriz);
    imprime_matriz(matriz);
    consulta_matriz(matriz);
}
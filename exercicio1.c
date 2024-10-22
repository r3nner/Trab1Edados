#include <stdio.h>
#include <stdlib.h>

struct diagonal {
    int ordem;
    int *v;
};
typedef struct diagonal Diagonal;

Diagonal menu_programa(Diagonal matriz);

Diagonal cria_matriz(){
    Diagonal matriz;
    printf("\nDigite a dimensão da Matriz Diagonal:\n");
    size_t ordem;
    scanf("%zu", &ordem);

    int* vetor = (int *)malloc(sizeof(int) * ordem);
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
    
    printf("\n\n  MATRIZ FINAL: \n==============================\n\n");
    
    for (int i = 0; i < matriz.ordem; i++){
        for (int j = 0; j < matriz.ordem; j++){
            if (i == j){
                printf(" %5d", matriz.v[i]);
            } else {
                printf(" %5d", zero);
            }
        }
        printf("\n");
    }
}

void consulta_matriz (Diagonal matriz) {
    
    int num1, num2, result;
    printf("\n\n========= CONSULTA MATRIZ ==========\n");
    do {
        printf("\nDigite duas coordenadas para buscar na matriz \"x y\", ou \"-1 -1\" para sair:\n");
        scanf("%d %d", &num1, &num2);
        if (num1 == -1 && num2 == -1){

            break;
        }
        if (num1 >= 0 && num2 >= 0 && num1 < matriz.ordem && num2 < matriz.ordem) {
            if (num1 != num2){
                result = 0;
            } else {
                result = matriz.v[num1];
            }
            printf("==========\nNumero na posicao [%d][%d]: %d\n\n", num1, num2, result);
        } else {
            printf("===========\nEntrada invalida. Tente novamente.\n\n");
        }
        
    } while (1);
    menu_programa(matriz);
}
Diagonal menu_programa(Diagonal matriz) {
    
    while (1) {
        int n; 

        printf("\n================\nO que você deseja fazer agora?\n\n");
        printf("[1] Inserir nova matriz\n");
        printf("[2] Imprimir matriz\n");
        printf("[3] Consultar matriz\n");
        printf("[0] Sair\n\n");
        
        scanf("%d", &n);

        switch(n) {
            case 0:
                printf("\n================\nFim do Programa.\n\n");
                exit(0);
            case 1:
                matriz = cria_matriz();
                matriz = preenche_matriz(matriz);
                imprime_matriz(matriz);
                break;

            case 2:
                imprime_matriz(matriz);
                break;

            case 3:
                consulta_matriz(matriz);
                break;

            default:
                printf("\nOpção inválida. Tente novamente.\n");
                break;
        }
    }
    return matriz;
}


int main() {
    Diagonal matriz;
    matriz = cria_matriz();
    matriz = preenche_matriz(matriz);
    imprime_matriz(matriz);
    consulta_matriz(matriz);
}
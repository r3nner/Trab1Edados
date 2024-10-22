#include <stdio.h>
#include <stdlib.h>


int*** aloca_matriz (int m, int n, int z){
    int*** linhas = (int*** )malloc(sizeof(int**)* m);

    for (int i = 0; i < m; i++){

        linhas[i] = (int** )malloc(sizeof(int *)* n);

        for (int j = 0; j < n; j++){

            linhas[i][j] = (int *)malloc(sizeof(int )* z);

        }
    }

    return linhas;
}

void preenche_matriz(int m, int n, int z, int ***mat) {

    printf("\n=============\nDigite o valor da posicao [%d][%d][%d]: (profundidade, linha, coluna) \n", m, n, z);
    int valor;
    scanf("%d", &valor);

    mat[m][n][z] = valor;
}

void imprime_matriz(int m, int n, int z, int ***mat){

    printf("\n\n====== MATRIZ FINAL ======\n");
    for (int linha = 0; linha < m; linha++){
        printf("========== \nProfundidade %d :\n", linha);
        for (int col = 0; col < n; col++){
            for (int prof = 0; prof < z; prof++){

                printf(" %5d", mat[linha][col][prof]);
            }
            printf("\n");
        }
        printf("\n");
    }
}


int main () {

    printf("======== MATRIZ TRIDIMENSIONAL ========\n\n");
    int m, n, z;

    printf("Digite a profundidade da matriz:\n");
    scanf("%d", &m);

    printf("Digite o numero de linhas:\n"); 
    scanf("%d", &n);

    printf("Digite o numero de colunas:\n");
    scanf("%d", &z);

    

    int*** matriz = aloca_matriz(m, n, z);

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0; k < z; k++){
                preenche_matriz(i, j, k, matriz);
            }
        }
    }

    imprime_matriz(m, n, z, matriz);
}
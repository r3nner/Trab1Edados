#include <stdio.h>
#include <stdlib.h>

struct lista{
    int linha;
    int coluna;
    int info;
    struct lista* prox;
};typedef struct lista Lista;

Lista* lst_insere(Lista* l, int linha, int coluna, int valor){
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->info = valor;
    novo->linha= linha;
    novo->coluna= coluna;
    novo->prox = l;
    return novo;
}

int buscaLista(Lista *l, int linha, int coluna){
    Lista *p;
    for (p=l; p!=NULL; p=p->prox){
        if ((p->coluna==coluna) && (p->linha==linha)){
            return p->info;
        }
    }
    return 0;
}

Lista* listainsere(Lista* lista, int tammatriz){
    int linha, coluna, valor, escolha;
    do{
        printf("\nEscolha uma linha para adicionar um valor: ");
        scanf("%d", &linha);
        printf("\nEscolha uma coluna para adicionar um valor: ");
        scanf("%d", &coluna);

        if ((linha<0) || (linha>tammatriz-1) || (coluna<0) || (coluna>tammatriz-1)){
            printf("\nValor invalido!");
        }
        else{
            printf("\nEscolha um valor para completar a matriz: ");
            scanf("%d", &valor);
            lista=lst_insere(lista, linha, coluna, valor);
        }
        printf("\nDeseja continuar adicionando? \n[1] Sim\n[2] Nao\n");
        scanf("%d", &escolha);
    }while(escolha!=2);
    return lista;
}

void imprimematriz(Lista* lista, int tammatriz){
    int i, j, numero;
    for (i=0; i<tammatriz; i++){
        for (j=0; j<tammatriz; j++){
            numero= buscaLista(lista, i, j);
            printf(" %d ", numero);
        }
        printf("\n");
    }
}

void elementos_errados(Lista* lista, int tammatriz){
    int i, j, numero, cont=0;
    for (i=0; i<tammatriz; i++){
        for (j=0; j<tammatriz; j++){
            numero= buscaLista(lista, i, j);
            if (((i!=j) && (numero!=0)) || ((i==j) && (numero!=1))){
                printf("\nNumero fora da matriz identidade:\nLinha: %d\nColuna: %d\nNumero: %d\n", i, j, numero);
                cont++;
            }
        }
    }
    if (cont==0){
        printf("\nMatriz eh identidade!\n");
    }
}

int main(){
    int tammatriz, escolha;
    Lista* lista= NULL;

    printf("\nDigite o tamanho da matriz quadrada: ");
    scanf("%d", &tammatriz);

    do{
        printf("\nEscolha uma opcao: \n[1] Adicionar elementos \n[2] Imprimir matriz \n[3] Verificar elementos errados \n[0] Sair \n");
        scanf("%d", &escolha);
        switch (escolha){
        case 1:
            lista= listainsere(lista, tammatriz);
            break;
        case 2:
            imprimematriz(lista, tammatriz);
            break;
        case 3:
            elementos_errados(lista, tammatriz);
            break;
        default:

            break;
        }
    }while(escolha!=0);
}

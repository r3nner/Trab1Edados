#include <stdio.h>
#include <stdlib.h>

struct lista //lista de valores não nulos da matriz esparsa. Os elementos não nulos da matriz são armazenados nesta lista. Os valores restantes, q são nulos, não são armazenados em nenhum lugar.
{
    int linha; // linha onde se encontra o elemento não nulo
    int coluna; // coluna onde se encontra o elemento não nulo
    int info; // valor do elemento não nulo
    struct lista* prox; // apontador para o proximo elemento não nulo da matriz
};typedef struct lista Lista;

struct esparsa
{
    int linhas; //numero de linhas da matriz
    int colunas; //numero de colunas da matriz
    struct lista* prim; //apontador para o primeiro noh não nulo da matriz
};typedef struct esparsa Esparsa;

Lista* lstcria(void){
    return NULL;
}

Lista* lst_insere(Esparsa* esparsa, int linha, int coluna, int valor){
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->info = valor;
    novo->linha= linha;
    novo->coluna= coluna;
    novo->prox = esparsa->prim;
    return novo;
}

int buscaLista(Esparsa* esparsa, int linha, int coluna){
    Lista *p;
    for (p=esparsa->prim; p!=NULL; p=p->prox){
        if ((p->coluna==coluna) && (p->linha==linha)){
            return p->info;
        }
    }
    return 0;
}

Lista* listainsere(Esparsa* esparsa){
    int linha, coluna, valor, escolha;
    do{
        printf("\nEscolha uma linha para adicionar um valor: ");
        scanf("%d", &linha);
        printf("\nEscolha uma coluna para adicionar um valor: ");
        scanf("%d", &coluna);

        if ((linha<0) || (linha>esparsa->linhas-1) || (coluna<0) || (coluna>esparsa->colunas-1)){
            printf("\nValor invalido!");
        }
        else{
            printf("\nEscolha um valor para completar a matriz: ");
            scanf("%d", &valor);
            if (valor!=0){
                esparsa->prim=lst_insere(esparsa, linha, coluna, valor);
            }
        }
        printf("\nDeseja continuar adicionando? \n[1] Sim\n[2] Nao\n");
        scanf("%d", &escolha);
    }while(escolha!=2);
    return esparsa->prim;
}

void imprimematriz(Esparsa* esparsa){
    int i, j, numero;
    for (i=0; i<esparsa->linhas; i++){
        for (j=0; j<esparsa->colunas; j++){
            numero= buscaLista(esparsa, i, j);
            printf(" %d ", numero);
        }
        printf("\n");
    }
}

void consultarElemento(Esparsa* esparsa){
    int lin, col, valor;
    printf("\nDigite a linha que deseja consultar: ");
    scanf(" %d", &lin);
    printf("\nDigite a coluna que deseja consultar: ");
    scanf(" %d", &col);
    if ((lin<0) || (lin>esparsa->linhas-1) || (col<0) || (col>esparsa->colunas-1)){
            printf("\nValor invalido!");
            return;
        }
    valor= buscaLista(esparsa, lin, col);
    printf("\nO elemento na linha %d e coluna %d e o: %d\n", lin, col, valor);
}

void somatorioLinha(Esparsa* esparsa){
    int lin, valor=0, j;
    printf("\nDigite uma linha valida para obter o somatorio: ");
    scanf(" %d", &lin);
    if ((lin<0) || (lin>esparsa->linhas-1)){
        printf("\nValor invalido!");
        return;
    }
    for (j=0; j<esparsa->colunas; j++){
        valor+=buscaLista(esparsa, lin, j);
    }
    printf("\nA soma dos elementos da linha e: %d\n", valor);
}

void percentualnaonulos(Esparsa* esparsa){
    Lista* p;
    float percentual, cont=0, total;
    for (p=esparsa->prim; p!=NULL; p=p->prox){
            cont++;
    }
    total=esparsa->colunas*esparsa->linhas;
    percentual=(cont/total)*100;
    printf("\nO percentual de valores nao nulos e %.2f %%\n", percentual);
}

void libera_lista(Lista* lst) {
    Lista* p= lst;
    while (p!= NULL) {
        Lista* t= p->prox;
        free(p);
        p= t;
    }
}

int main()
{
    Esparsa* esparsamatriz;
    esparsamatriz= (Esparsa*)malloc(sizeof(Esparsa));
    if (esparsamatriz== NULL) {
        printf("Erro ao alocar memória para a matriz esparsa.\n");
        return 1;
    }
    esparsamatriz->prim= NULL;

    int lin, col, escolha=5;

    printf("\nDigite o numero de linhas da matriz: ");
    scanf(" %d", &lin);
    printf("\nDigite o numero de colunas da matriz: ");
    scanf(" %d", &col);
    esparsamatriz->linhas=lin;
    esparsamatriz->colunas=col;

    while (escolha!=0){
    printf("\nVoce deseja: \n[1] Preencher matriz\n[2] Consultar elemento\n[3] Obter somatorio da linha\n[4] Percentual de elementos nao nulos\n[5] Imprimir matriz\n[0] Sair\n");
    scanf("%d", &escolha);
    switch (escolha){
        case 1:
            listainsere(esparsamatriz);
        break;

        case 2:
            consultarElemento(esparsamatriz);
        break;

        case 3:
            somatorioLinha(esparsamatriz);
        break;

        case 4:
            percentualnaonulos(esparsamatriz);
            break;

        case 5:
            imprimematriz(esparsamatriz);
        break;

        default:

            break;
    }
    }

    libera_lista(esparsamatriz->prim);
    free(esparsamatriz);
    return 0;
}

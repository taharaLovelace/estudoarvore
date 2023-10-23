#include <stdio.h>
#include <stdlib.h>

typedef struct NoArvore
{
    int info;
    struct NoArvore *esq;
    struct NoArvore *dir;
} NoArv;

typedef struct Arvore
{
    NoArv *raiz;
} Arv;

Arv *CriaArvore()
{
    Arv *aux = (Arv*)malloc(sizeof(Arv));

    aux->raiz = NULL;
    return aux;
}

NoArv *InsereNo (NoArv *no, int num)
{
    int flag;
    NoArv *pai;
    NoArv *novo = (NoArv*)malloc(sizeof(NoArv));

    novo->info = num;
    novo->esq = NULL;
    novo->dir = NULL;

    if (no == NULL)
    {
        return novo;
    }
    else
    {
        pai = no;
        flag = 0;

        while (flag == 0)
        {
            if (pai->info < num)
            {
                if (pai->dir == NULL)
                {
                    pai->dir = novo;
                    flag = 1;
                }
                else
                {
                    pai = pai->dir;
                }
            }
            else
            {
                if (pai->info > num)
                {
                    if (pai->esq == NULL)
                    {
                        pai->esq = novo;
                        flag = 1;
                    }
                    else
                    {
                        pai = pai->esq;
                    }
                }
            }
        }
    }
    return no;
}

void InsereArvore (Arv *arvore, int num)
{
    arvore->raiz = InsereNo(arvore->raiz, num);
}

int VerificarVazia(Arv* arvaux) {
    if (arvaux->raiz == NULL) {
        return 1; // �rvore est� vazia
    } else {
        return 0; // �rvore n�o est� vazia
    }
}

NoArv* buscarArvore(NoArv* raiz, int valor)
{


    if (raiz == NULL || raiz->info == valor) {
        return raiz;
    }

    if (valor < raiz->info) {
        return buscarArvore(raiz->esq, valor); // Busca na subárvore esquerda
    } else {
        return buscarArvore(raiz->dir, valor); // Busca na subárvore direita
    }
}

int contarNosInternos(NoArv* raiz) {
    if (raiz == NULL || (raiz->esq == NULL && raiz->dir == NULL)) {
        return 0;
    }

    return 1 + contarNosInternos(raiz->esq) + contarNosInternos(raiz->dir);
}

int encontrarMenorValor(NoArv* raiz) {
    if (raiz == NULL) {
        printf("A árvore está vazia.\n");
        return -1; // Indicando que a árvore está vazia
    }

    while (raiz->esq != NULL) {
        raiz = raiz->esq;
    }

    return raiz->info; // O nó mais à esquerda contém o menor valor
}

int verificaEstritamenteBinaria(NoArv* no) {
    if (no == NULL) {
        return 1; // Uma árvore vazia é estritamente binária
    }

    // Verifica se o nó atual possui exatamente 2 filhos, caso contrário, a árvore não é estritamente binária
    if (no->esq == NULL && no->dir == NULL) {
        return 1; // Nó folha
    } else if (no->esq != NULL && no->dir != NULL) {
        return verificaEstritamenteBinaria(no->esq) && verificaEstritamenteBinaria(no->dir);
    } else {
        return 0; // Nó com 1 filho (não é estritamente binário)
    }
}


int main() {
    Arv *arv1 = CriaArvore();

    int number = 1;
    while (number != 0) {
        printf("Digite valores para inserir na arvore (0 para sair): ");
        scanf("%d", &number);
        if (number != 0) {
            InsereArvore(arv1, number);
        }
    }

    int aux = VerificarVazia(arv1);

    if (aux == 0) {
        printf("A arvore nao esta vazia. Valor da raiz: %d\n", arv1->raiz->info);
    } else {
        printf("A arvore esta vazia.\n");
    }

    int valor;
    printf("\nQual valor inteiro deseja buscar?: ");
    scanf("%d", &valor);
    NoArv* busca = buscarArvore(arv1->raiz, valor);

    if (busca != NULL)
    {
        printf("O valor buscado esta presente na arvore.\n");
    }
    else
    {
        printf("O valor nao foi encontrado na arvore.\n");
    }

    int contnos = contarNosInternos(arv1->raiz);
    printf("\nQuantidade de nos internos: %d\n", contnos);

    int menorvalor = encontrarMenorValor(arv1->raiz);
    printf("\nO menor valor desta arvore e: %d\n", menorvalor);

    if (verificaEstritamenteBinaria(arv1->raiz))
    {
        printf("Esta arvore e estritamente binaria.");
    }
    else
    {
        printf("Esta arvore nao e estritamente binaria");
    }

    return 0;
}

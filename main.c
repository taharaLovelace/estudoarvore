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
        return 1; // Árvore está vazia
    } else {
        return 0; // Árvore não está vazia
    }
}

void BuscaNumero (Arv* arvaux)
{
    int busca;
    printf("Digite o numero que quer buscar: ");
    scanf("%d", &busca);


}

int main() {
    Arv *arv1 = CriaArvore();

    int number = 1;
    while (number != 0) {
        printf("Digite valores para inserir na árvore (0 para sair): ");
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

    return 0;
}

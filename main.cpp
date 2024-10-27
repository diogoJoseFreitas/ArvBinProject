#include <stdio.h>
#include "no.cpp"

void status(NO*);
void menu(NO*);
void insercao(NO*);

int main(){
    NO* raiz = criaNo_ArvBin(NULL);

    insercao(raiz);

    limpaTela(50);
    menu(raiz);

    return(1);
}

void insercao(NO* raiz){
    int opt = 0;
    do{
        printf("Insira um valor natural (-1 para sair): ");
        scanf("%d", &opt);
        if (opt!=-1)        
            insereValor_ArvBin(raiz, opt);
            imprimePorNivel_ArvBin(raiz, 0);
    } while (opt!=-1);
}

void status(NO* raiz){
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\nPré Ordem: ");
    preOrdem_ArvBin(raiz);
    printf("\nEm Ordem: ");
    emOrdem_ArvBin(raiz);
    printf("\nPós Ordem: ");
    posOrdem_ArvBin(raiz);
    printf("\nAltura da Árvore: %d\n\n", treeSize_ArvBin(raiz));
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
}

void menu(NO* raiz){
    int opt = 0;
    do{
        status(raiz);
        printf("\n1 - Visualizar Árvore\n2 - Consulta nó\n3 - Inserir itens\n0 - Sair\nEscolha uma opção: ");
        scanf("%d", &opt);
        switch (opt){
        case 1:
            printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
            printf("Árvore: \n");
            imprimePorNivel_ArvBin(raiz, 0);
            printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
            break;
        case 2:
            int val;
            printf("Informe o Valor a ser Consultado: ");
            scanf("%d", &val);
            if (consulta_ArvBin(raiz, val))
                printf("\n\nValor encontrado!\n\n");
            else
                printf("\n\nValor não encontrado!\n\n");
            break;
        case 3:
            insercao(raiz);
        break;
        case 0:
            break;
        default:
            printf("\n\nOpção não encontrada, tente um dos números presentes no menu.\n\n");
            break;
        }
    } while (opt != 0);   
}
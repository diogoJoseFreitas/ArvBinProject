#include <stdio.h>
#include <stdlib.h>

struct NO
{
    NO* esq;
    NO* dir;
    int valor;
};
typedef struct NO NO;

void setFolha_ArvBin(NO* no, int valor){
    no->esq = NULL;
    no->dir = NULL;
    no->valor = valor;
}

NO* criaNo_ArvBin(int valor){
    NO* novo_no = (NO*)malloc(sizeof(NO));
    if (!novo_no){
        exit(1);
    }
    setFolha_ArvBin(novo_no, valor);
    return novo_no;    
}

int insereValor_ArvBin(NO* no, int valor){
    if (no->valor == valor){
        printf("Valor já existente! tente outro.\n");
        return 0;
    }
    if (no->valor == NULL){
        no->valor = valor;
        return 1;
    }
    if (valor > no->valor){
        if (!no->dir){
            no->dir = criaNo_ArvBin(valor);
        }else{
            insereValor_ArvBin(no->dir, valor);
        }     
        return 1;   
    }
    if (valor < no->valor){
        if (!no->esq){
            no->esq = criaNo_ArvBin(valor);
        }else{
            insereValor_ArvBin(no->esq, valor);
        }  
        return 1;      
    }
}

int consulta_ArvBin(NO* no, int valor){
    if (no == NULL)
        return 0;
    if (no->valor == valor)
        return 1;
    return(consulta_ArvBin(no->esq, valor) + consulta_ArvBin(no->dir, valor));    
}

int treeSize_ArvBin(NO* no){
    if (no == NULL)
        return -1;

    int size_esq = treeSize_ArvBin(no->esq);
    int size_dir = treeSize_ArvBin(no->dir);

    return (size_esq > size_dir ? size_esq : size_dir) + 1;
}

NO* maiorItem_ArvBin(NO* no){
    if(no->esq == NULL)
        return NULL;
    
    NO* val = no->esq;
    while (val->dir != NULL){
        val = val->dir;
    }
    return val;
}

void preOrdem_ArvBin(NO* no){
    printf("%d, ", no->valor);
    if (no->esq != NULL){
        preOrdem_ArvBin(no->esq);
    }
    if (no->dir != NULL){
        preOrdem_ArvBin(no->dir);
    }
}

void emOrdem_ArvBin(NO* no){
    if (no->esq != NULL){
        emOrdem_ArvBin(no->esq);
    }
    printf("%d, ", no->valor);
    if (no->dir != NULL){
        emOrdem_ArvBin(no->dir);
    }
}

void posOrdem_ArvBin(NO* no){
    if (no->esq != NULL){
        posOrdem_ArvBin(no->esq);
    }
    if (no->dir != NULL){
        posOrdem_ArvBin(no->dir);
    }
    printf("%d, ", no->valor);
}

void imprimePorNivel_ArvBin(NO* no, int spc){
    if (no == NULL){
        return;
    }
    spc += 5;

    imprimePorNivel_ArvBin(no->dir, spc);

    for (int i = 0; i < spc; i++){
        printf(" ");
    }
    printf("%d\n", no->valor);

    imprimePorNivel_ArvBin(no->esq, spc);
}

void limpaTela(int linhas){
    for (int i = 0; i < linhas; i++)
        printf("\n");    
}
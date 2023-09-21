#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//DECLARACAO DE ESTRUTURAS

struct no {
    int numero;
    struct no *esquerda;
    struct no *direita;
};

//funcao quue insere um no na arvore

struct no *inserir(struct no *raiz, int numero){
    if (raiz == NULL){
        //caso facil, a arvore está vazia
        raiz = (struct no *) malloc(sizeof(struct no));
        raiz -> numero = numero;
        raiz -> esquerda = NULL;
        raiz -> direita = NULL;
    } else{
        //caso dificil, arvore NÃO está vazia
        if ((rand()%2)==0){
            raiz -> esquerda = inserir(raiz -> esquerda, numero);
        } else{
            raiz -> direita = inserir(raiz -> direita, numero);
        }
    }
    return raiz;
};

//navegaçao pre ordem

void navegarPreOrdem(struct no *raiz){
    if (raiz != NULL){
        printf("%d\t", raiz -> numero);
        navegarPreOrdem(raiz -> esquerda);
        navegarPreOrdem(raiz -> direita);
    }
}
//navegacao EM ordem
void navegarEmOrdem(struct no *raiz){
    if (raiz != NULL){
        navegarEmOrdem(raiz -> esquerda);
        printf("%d\t", raiz -> numero);
        navegarEmOrdem(raiz -> direita);
    }
}

//navegacao POS ordem
void navegarPosOrdem(struct no *raiz){
    if (raiz != NULL){
        navegarPosOrdem(raiz -> esquerda);
        navegarPosOrdem(raiz -> direita);
        printf("%d\t", raiz -> numero);
    }
}

//func principal

int main(){
//declaracao da arvore
    struct no *raiz = NULL;

    //inicializacao da aleatoriedade
    time_t t;
    srand((unsigned)time(&t));

    //preenchimento da arvore
    int i =0;
    for (i = 0; i < 10; i++){
        raiz = inserir(raiz, i);
    }
    //navegaçoes
    printf("\n =================================== PRE-ORDEM ==================================\n");
    navegarPreOrdem(raiz);
    printf("\n =================================== EM-ORDEM ==================================\n");
    navegarEmOrdem(raiz);
    printf("\n =================================== POS-ORDEM ==================================\n");
    navegarPosOrdem(raiz);
}

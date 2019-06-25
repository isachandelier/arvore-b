#include "arvoreb.h"

/*Caso 1 - A função remove a chave que tem o índice "index", que é uma folha, da árvore*/
Arvore* remover_de_folha (Arvore *a, int index){
    /*Move todas as chaves maiores que index um espaço para trás*/
    for(int i=index+1;i<a->n;i++){
        a->chaves[i-1]=a->chaves[i];
    }
    /*Diminui o número de chaves*/
    a->n--;

    return a;
}


/*A função remove a chave que tem o índice "index", que não é uma folha, da árvore*/
Arvore* remover_de_nao_folha (Arvore *a, int index){
    TIPO k = a->chaves[index];
    TIPO predecessor, sucessor;

    /*Caso 2A - Se o filho que precede k tem, ao menos, T chaves, acha o predecessor de k*/
    if (a->filhos[index]->n >= T){
        Arvore* anterior=a->filhos[index];
        while(anterior->folha!=TRUE){
            anterior=anterior->filhos[anterior->n];
        }
        predecessor=anterior->chaves[anterior->n-1];
        a->chaves[index]=predecessor;
        anterior->n--;
    }
    /*Caso 2B - Se o filho de a tem menos de T chaves, */
    else if (a->filhos[index+1]->n >= T){
        sucessor=a->filhos[index]->chaves[0];
        a->chaves[index]=sucessor;
        remover(a->filhos[index],sucessor);
    }
    /*Descrição ...*/
    else{

    }

    return a;
}


//Função para verificar se raiz ficou vazia
Arvore *verificar_raiz_vazia (Arvore *raiz){
    /*Se após a remoção a raiz tiver 0 chaves, tornar o primeiro filho a nova raiz se existir filho; caso contrário ajustar a raiz para NULL. Liberar a raiz antiga*/

    /*Completar!!!! */
    printf("Completar\n");

    return raiz;
}



/*Função que retorna o index da primeira chave maior ou igual à chave*/
int buscar_index_remocao (Arvore *a, TIPO chave) {

    int i = 0;

    /*Procurando a chave no vetor de chaves */
    while ((i < a->n) && (chave > a->chaves[i])) {
     i = i + 1;
    }

    return i;
}

/*Descrição: ????*/
Arvore *remover (Arvore *a, TIPO k){
    int index;

    /*Completar!!!!!!!!!!!!!!*/
    if (a == NULL) {
      /*Completar!!!*/
      printf("Completar\n");
    }

    index = buscar_index_remocao (a, k);


    //A chave a ser removida está presente neste nó
    if ( index >= 0 && a->chaves[index] == k){
      if (a->folha){
         a = remover_de_folha (a, index);
      }
      else{
         a = remover_de_nao_folha (a, index);
      }
    }
    else{
      //Se este nó é um nó folha, então a chave não está na árvore
      if (a->folha){
     printf("\nA chave %c não está na árvore.\n",k);
     //printf("\nA chave %d não está na árvore.\n",k);
         return a;
      }

      /*Completar!!!*/
      printf("Completar\n");


    }
    a = verificar_raiz_vazia(a);

    return a;
}


#include "arvoreb.h"

/*Função que divide y em dois de modo que x, após ser ajustado, ganhe um filho*/
Arvore* dividir_no (Arvore *x, int i, Arvore *y) {
    /*Criação de um novo nó que armazenará t-1 chaves de y*/
    Arvore* z=criar();
    z->folha=y->folha;
    z->n=T-1;
    /*Cópia das últimas t-1 chaves de y para z*/
    for(int j=1;j<=T-1;j++){
        z->chaves[j]=y->chaves[j+T];
    }
    /*Faz a cópia dos últimos t filhos de y para z*/
    if(y->folha == 0){
        for(int j=0;j<T;j++){
            z->filhos[j]=y->filhos[j+T];
        }
    }
    /*Diminui o número de chaves em y*/
    y->n=T-1;
    /*Cria espaço para o novo filho de x*/
    for(int j=x->n;j>=i+1;j--){
        x->filhos[j+1]=x->filhos[j];
    }
    /*Relaciona o nó x ao seu novo filho z*/
    x->filhos[i+1]=z;
    /*Acha a chave média de y e move todas as chaves maiores que ela um espaço para frente*/
    for(int j=x->n;j>=i;j--){
        x->chaves[j+1]=x->chaves[j];
    }
    /*Copia a chave média de y*/
    x->chaves[i]=x->chaves[T-1];
    /*Incrementa o número de chaves de x*/
    x->n=x->n+1;

    return x;
}

/*A função insere uma nova chave em um nó se o nó não estiver cheio*/
Arvore* inserir_arvore_nao_cheia (Arvore *x, TIPO k) {
    int i=x->n-1;
    /*Checa se o nó é um nó folha*/
    if(x->folha==TRUE){
        /*Localiza onde a nova chave deve ser inserida e move todas as chaves maiores um espaço para frente*/
        while(i>=0 && x->chaves[i]>k){
            x->chaves[i+1]=x->chaves[i];
            i--;
        }
        /*Move a chave para a nova localização*/
        x->chaves[i+1]=k;
        x->n=x->n+1;
    }
    else{/*Se o nó não for uma folha*/
        /*Localiza o filho que receberá a nova chave*/
        while(i>=0 && x->chaves[i]>k){
            i--;
        }
        i++;
        /*Checa se o filho achado está cheio*/
        if(x->filhos[i]->n==(2*T-1)){
            /*Se o filho estiver cheio divide esse filho em dois não-cheios*/
            dividir_no(x,i,x->filhos[i]);
            /*Depois da divisão, testa qual das duas metades de x receberá a nova chave*/
            if(x->chaves[i+1]<k){
                i++;
            }
        }
        /*Chama a função recursivamente, para inserir k no filho correto*/
        inserir_arvore_nao_cheia(x,k);
    }
    return x;
}

/*Função para inserir uma chave em uma árvore B:*/
Arvore *inserir (Arvore *raiz, TIPO chave) {
    Arvore *r = raiz;
    if (r->n == (2*T - 1)) {
      Arvore *s = criar();
      s->folha = FALSE;
      s->filhos[0] = r;
      s = dividir_no (s, 0, r);
      s = inserir_arvore_nao_cheia (s, chave);
      return s;
    }
    else{
      return inserir_arvore_nao_cheia (r, chave);
    }
}





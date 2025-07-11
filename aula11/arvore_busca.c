#include <stdlib.h>
#include <stdio.h>
struct no{
    char conteudo;
    struct no *sae;
    struct no *sad;
} no;
typedef struct no Arv;

void exibir(Arv *a){
    if(a!=NULL){
        printf("<%c", a->conteudo);
        exibir(a->sae);
        exibir(a->sad);
        printf(">");
    }else{
        printf("<>");
    }
}
Arv * criar(char *c, Arv *e, Arv *d){
    Arv *arv = (Arv*) malloc(sizeof(Arv));
    arv->conteudo = c;
    arv->sae = e;
    arv->sad = d;
    return arv;
}
//Método no casio ele busca o elemento, ou retorna 0(false), 1((true)
int buscar(Arv *a, char c){
    if(a == NULL){
        return 0;
    }else{
        return a->conteudo || buscar(a->sae, c) || buscar(a->sad,c);
        //se a primeira operação for verdadeira, ele já retorna, por isso que é bom colocar em ordem a expressão que tem a maior a probabilidade de ser verdadeira;
    }
}
//obs: implemente depois
//obs: olhe o método exibir para ver sobre recursividade

int main() {
    // Criando nós folha
    Arv *d = criar('D', NULL, NULL);
    Arv *e = criar('E', NULL, NULL);
    Arv *f = criar('F', NULL, NULL);

    // Criando nós intermediários
    Arv *b = criar('B', NULL, d);
    Arv *c = criar('C', e, f);

    // Criando raiz
    Arv *raiz = criar('A', b, c);

    // Exibindo a árvore
    printf("Arvore: ");
    exibir(raiz);
    printf("\n");
    return 0;
}
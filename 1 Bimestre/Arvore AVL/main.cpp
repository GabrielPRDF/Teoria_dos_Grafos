#include<stdio.h>
#include<stdlib.h>
#include<iostream>
/*
    Gabriel Pinto Ribeiro da Fonseca
    Teoria de Grafos
    Arvore AVL

    Obs.
    Rotacao funcionando parcialmente, nao encontrei o erro
    Exclusao funcionando, apenas quando tem 2 filhos nao funciona.
    Todos estao implementados, mas possue estes doi bugs.

*/

using namespace std;
struct Arvore{
    int valor;
    struct Arvore *esq, *dir;
};
typedef struct Arvore arv;
arv *cria();
arv *criaNoh(int numero, arv *arvRaiz);
arv* BuscaMenor(arv *n);
arv* BuscaEsq(arv *n);
arv* removeElemento(arv *n, int numero);
arv* rsd (arv* n);
arv* rdd (arv* n);
arv* rde (arv* n);
arv* rse (arv* n);
arv* balanceNode(arv *n);

void liberaArv(arv *raiz);
void liberaNoh(arv *n);
void opcoes();
void imprimiEmOrdem(arv *n);
void imprimiPosOrdem(arv *n);
void imprimiPreOrdem(arv *n);
void msgDeleta(int n);
void msgNumeroExiste(int n);
void balanceTree(arv *raiz);
int fatorAltura(arv *n);
int contaAltura(arv *n);

int main(){
    arv* x = cria();
    int y = 0, i = 0;
    while(i == 0){
        opcoes();
        scanf(" %i", &y);
        switch(y){
            case 1:
                system("cls");
                cout << "Digite o valor para inserir:\t";
                scanf(" %i", &y);
                x = criaNoh(y, x);
                y = 0;
                break;
            case 2:
                system("cls");
                cout << "Impressao EM ORDEM :\t";
                imprimiEmOrdem(x);
                cout << endl;
                system("pause");
                break;
            case 3:
                system("cls");
                cout << "Impressao PRE ORDEM :\t";
                imprimiPreOrdem(x);
                cout << endl;
                system("pause");
                break;
            case 4:
                system("cls");
                cout << "Impressao POS ORDEM :\t";
                imprimiPosOrdem(x);
                cout << endl;
                system("pause");
                break;
            case 5:
                system("cls");
                cout << "Digite o valor para ser DELETADO:\t";
                scanf(" %i", &y);
                removeElemento(x, y);
                cout << endl;
                system("pause");
                break;
            default:
                liberaArv(x);
                i = 1;
                break;
        }
    }
    return 0;
}

void liberaArv(arv *raiz){
    if(raiz == NULL)
        return;
    liberaNoh(raiz);
    free(raiz);
}

void liberaNoh(arv *n){
    if(n == NULL)
        return;
    liberaNoh(n -> esq);
    liberaNoh(n -> dir);
    free(n);
    n = NULL;
}

void imprimiEmOrdem(arv *n){
    if(n){
        imprimiEmOrdem(n -> esq);
        cout << n->valor;
        imprimiEmOrdem(n -> dir);
    }
}

void imprimiPreOrdem(arv *n){
    if(n){
        cout << n->valor;
        imprimiPreOrdem(n -> esq);
        imprimiPreOrdem(n -> dir);
    }
}

void imprimiPosOrdem(arv *n){
    if(n){
        imprimiPosOrdem(n -> esq);
        imprimiPosOrdem(n -> dir);
        cout << n->valor;
    }
}

void opcoes (){
    system("cls");
    printf("Digite 1 para adicionar na Arvore \n");
    printf("Digite 2 para imprimir a Arvore em EM Ordem \n");
    printf("Digite 3 para imprimir a Arvore em PRE Ordem \n");
    printf("Digite 4 para imprimir a Arvore em POS Ordem \n");
    printf("Digite 5 para deletar um valor da Arvore \n");
    printf("Digite 6 para destruir a Arvore e sair!! \n");
}

void msgDeleta(int x){
    system("cls");
    cout << "O numero que foi deletado e:\t" << x << endl;
}

void msgNumeroExiste(int x){
    system("cls");
    cout << "Valor ja existe na arvore!!!" << endl;
}

int fatorAltura(arv *n){
    int alturaAux = 0;
    if(n->esq)
        alturaAux += contaAltura(n->esq);
    if(n->dir)
        alturaAux -= contaAltura(n->dir);
    return alturaAux;
}

int contaAltura(arv *n){
    int altEsq = 0, altDir = 0;
    if(n->esq)
        altEsq = contaAltura(n->esq);
    if(n->dir)
        altDir = contaAltura(n->dir);

    return max(altDir,altEsq) + 1;
}

void balanceTree(arv *raiz){
    arv* novaArv = NULL;
    novaArv = balanceNode(raiz);
    //teste para verificar se mudou a raiz
    if (raiz != novaArv){
        raiz = novaArv;
    }
}

arv* balanceNode(arv *n){
    arv * nodeBalance = NULL;
    if(n->esq){
        n->esq = balanceNode (n->esq);
    }if(n->dir){
        n->dir = balanceNode (n->dir);
    }
    int fator = fatorAltura(n);
    if(fator >= 2){
        //Pendendo para a esquerda
        if (fatorAltura(n->esq) <= -1){
            nodeBalance = rdd(n);
        }else{
            nodeBalance = rsd(n);
        }
    }else if(fator <= -2){
        //Pendendo para a direita
        if(fatorAltura(n->dir) >= 1){
            nodeBalance = rde(n);
        }else{
            nodeBalance = rse(n);
        }
    }else{
        nodeBalance = n;
    }
    return nodeBalance;
}

arv* rsd(arv* n){
	arv* aux = n;
	arv* esquerda = aux->esq;

	aux->esq = esquerda->dir;
	esquerda->dir = aux;

	return esquerda;
}

arv* rdd (arv* n){
	arv* aux = n;
	arv* esquerda = aux->esq;
	arv* direita = esquerda->dir;

	aux->esq = direita->dir;
	esquerda->dir = direita->esq;
	direita->esq = esquerda;
	direita->dir = aux;

	return direita;
}

arv* rde (arv* n){
	arv* aux = n;
	arv* direita = aux->dir;
	arv* esquerda = direita->esq;

	aux->dir = esquerda->esq;
	direita->esq = esquerda->dir;
	esquerda->dir = direita;
	esquerda->esq = aux;

	return esquerda;
}

arv* rse (arv* n){
	arv* aux = n;
	arv* direita = aux->dir;

	aux->dir = direita->esq;
	direita->esq = aux;

	return direita;
}

arv* removeElemento(arv* n, int numero){
    if(n == NULL){
        cout << "Arvore nao possue este numero!!!" << endl;
    }else{
        if(numero < n->valor){
                n->esq = removeElemento(n->esq, numero);
        }else{
            if(numero > n->valor){
                n->dir = removeElemento(n->dir, numero);
            }else{
                arv *aux = n;
                if(n->dir == NULL && n->esq == NULL){
                    free(aux);
                    n = NULL;
                    msgDeleta(numero);
                }else{
                    if(n->dir == NULL && n->esq != NULL){
                        arv *aux = n;
                        n = aux->esq;
                        aux->esq = NULL;
                        free(aux);
                        aux = NULL;
                        msgDeleta(numero);
                    }else{
                        if(n->dir != NULL && n->esq == NULL){
                            arv *aux = n;
                            n = aux->dir;
                            aux->dir = NULL;
                            free(aux);
                            aux = NULL;
                            msgDeleta(numero);
                        }else{
                            arv* aux = BuscaMenor(n->dir);
                            cout << "Valor selecionado para Substituir:\t" << aux->valor << endl;
                            /*aux->esq = n->esq;
                            aux->dir = n->dir;
                            n->dir = n->esq = NULL;
                            free(n);
                            n = aux;
                            aux = NULL*/
                            cout << "Este tem filhos!!" << endl;
                            cout << "Obs:Com Bug. Nao encontrei o erro, ja implementado" << endl;
                        }
                    }
                }
            }
        }
    }
    //Com bug
    //balanceTree(n);
    return n;
}

arv* cria(){
    return NULL;
}

arv* criaNoh(int numero, arv *arvRaiz){
    if(arvRaiz == NULL){
        arvRaiz = new arv;
        arvRaiz -> valor = numero;
        arvRaiz -> esq = cria();
        arvRaiz -> dir = cria();
        return arvRaiz;
    }else{
        arv *p, *pai;
        p = arvRaiz;
        int aux = 0;
        while(p != NULL){
            pai = p;
            //Verifica se o numero e maior que a raiz para ir para esquerda
            if(numero < p->valor){
                aux=0;
                if(p->esq == NULL){
                    break;
                }
                p = p->esq;
            }else{
                //Verifica se o numero e menor que a raiz para ir para direita
                if(numero > p->valor){
                    aux=1;
                    if(p->dir == NULL){
                    break;
                    }
                p = p->dir;
                }else{
                    //Caso ja tenha o valor na arvore, apenas volta a raiz sem inerilo novamente.
                    msgNumeroExiste(numero);
                    return arvRaiz;
                }
            }
        }
        p = new arv;
        p ->valor = numero;
        p ->esq = cria();
        p ->dir = cria();
        if(aux){
            pai->dir = p;
        }else{
            pai->esq = p;
        }
        balanceTree(arvRaiz);
        return arvRaiz;
    }
}

arv* BuscaMenor(arv *n){
    if(n->esq != NULL){
        return BuscaMenor(n->esq);
    }else{
        arv* aux = n;
        if(n->dir != NULL){
            n = n->dir;
        }else{
            //free(n);
            n = NULL;
        }
        return aux;
    }
}

#include <stdio.h>
#include <stdlib.h>



//Criacao de uma struct do tipo no com um elemento do tipo inteiro um contador para contar os nos da arvore e tres ponteiros do struct no(esq,dir e pai);
typedef struct _no{
	int info;
	int cont;

	struct _no *esq, *dir, *pai;
}no;

no* auxPai = NULL; //inicializa a arvore com o ponteiro auxiliar pai apontando pra null;

//Rotina para verificar se a arvore esta ou nao vazia
void vaziaArvore(no *raiz){
	if (raiz == NULL){
		printf("   A arvore esta vazia\n\n");
	}
	else {
		printf("   A arvore nao esta vazia\n\n");
	}
}

//Rotina para inserir elementos na arvore;
void insere (int info2, no **p){

	if (*p==NULL){                    
		*p=(no *)malloc(sizeof(no)); 
		(*p)->info=info2;            
		(*p)->dir=NULL;
		(*p)->esq=NULL;
		(*p)->pai = auxPai;
		(*p)->cont=0;
		(*p)->cont++;
	}
	else{
		if (info2<(*p)->info){
			if((*p)->esq == NULL)
				auxPai = *p;
			insere(info2, &(*p)->esq);
		}
		if(info2>(*p)->info){
			if((*p)->dir == NULL)
				auxPai = *p;
			insere(info2, &(*p)->dir);
		}
		if(info2 == (*p)->info){
			if((*p)->dir == NULL)
				auxPai = *p;
			insere(info2, &(*p)->dir);
		}
	}
}


int contarNos(no *p){
	if(p == NULL)
		return 0;
	else
		return 1 + contarNos(p->esq) + contarNos(p->dir);
}

no* busca(no *arvore, int info2){
	if (arvore == NULL)
		return NULL;
	if (info2 == arvore->info)
		return arvore;
	if (info2 < arvore->info)
		return busca(arvore->esq, info2);
	else
		return busca(arvore->dir, info2);
}

/*rotina para consultar se determinado elemento esta ou nao na arvore, se estiver e for repetido, informa quantas vezes ele se repetiu, se o valor nao foi encontrado
exibe uma mensagem informando que o mesmo nao foi encontrado*/
void consultarValor(no* raiz){
	int num;
	no* aux;
	printf("Digite o numero procurado: ");
	scanf("%d", &num);

	aux = busca(raiz, num);
	if (aux == NULL)
		printf("Nao encontrado!\n");
	else{
		printf("Encontrado!\n");
		printf("O numero %d foi repetido %d vezes\n", num, aux->cont);
	}
}
/*rotina para consultar detalhes, como qual no eh a raiz da arvore, qual o valor contido no No filho da esquerda e da direita para nos pais
e quais sao os nos internos da arvore*/
void consultarDetalhes(no* raiz){
	int num;
	no* aux;
	printf("Digite o numero procurado: ");
	scanf("%d", &num);
	aux = busca(raiz, num);
	if (aux == NULL)
		printf("Valor Nao encontrado!\n");
	else{
		printf("Valor Encontrado!\n");
		if(aux->pai == NULL){
			printf("O No que contem o valor %d e a raiz da arvore.\n", num);
			if(aux->esq != NULL)
				printf("Valor contido no No filho a esquerda: %d\n", aux->esq->info);
			if(aux->dir != NULL)
				printf("Valor contido no No filho a direito: %d\n", aux->dir->info);
		}
		if((aux->esq == NULL)&&(aux->dir == NULL)&&(aux->pai != NULL)){
			printf("O No que contem o valor %d e uma folha da arvore.\n", num);
			printf("Valor contido no No pai: %d\n", aux->pai->info);
		}
		if(((aux->esq != NULL)||(aux->dir != NULL))&&(aux->pai != NULL)){
			printf("O No que contem o valor %d e um no interno a arvore.\n", num);
			printf("Valor contido no No pai: %d\n", aux->pai->info);
			if(aux->esq != NULL)
				printf("Valor contido no No filho a esquerda: %d\n", aux->esq->info);
			if(aux->dir != NULL)
				printf("Valor contido no No filho a direita: %d\n", aux->dir->info);
		}
	}
}

//rotina para consultar o nivel do no
void consultaNivel(no *p){
	int i, nivel;
	if(p == NULL)
		return;
	
	for(i=0;i<nivel;i++)
		printf("      ");
	printf("%6d\n\n",p->info);
	
}


//rotina para  exibir a arvore em ordem visitando sempre a raiz entre os percursos pelas subarvores;
void emordem(no *arvore){
	if(arvore != NULL){
		emordem(arvore->esq);
		printf("%d\n",arvore->info);
		emordem(arvore->dir);
	}
}

//menu interativo para aplicacao das funcoes 
int menu(){
	int op;
	printf("\nMENU\n\n");
	printf("1 - Inserir valor\n");
	printf("2 - Imprimir in-ordem\n");
	printf("3 - Consulta detalhada\n");
	printf("4 - Quantidades de nos da arvore\n");
	printf("Digite sua opcao: ");
	scanf("%d", &op);
	return op;
}

//main
int main(){
	int n,a,b;  
	no *raiz, *aux;
	raiz = NULL;
	int opcao; 

	while(opcao!=4){

		opcao = menu();
		switch(opcao){

			case 1:

			printf("\n>>>>>>>>>>>>><<<<<<<<<<<<<\n\n");
			printf("Digite -1 para terminar\n");
			printf("\n>>>>>>>>>>>>><<<<<<<<<<<<<\n\n");
			do{
				printf("Digite um numero: ");
				scanf("%d", &n);
				if(n!=-1){
					insere(n, &raiz);
				}
			}while (n!=-1);

			break;
			
			case 2:

			printf("\n>>>>>>>>>>>>><<<<<<<<<<<<<\n\n");
			printf("------> Em-Ordem <------\n");
			printf("\n>>>>>>>>>>>>><<<<<<<<<<<<<\n\n");
			emordem(raiz);

			break;
		
			case 3:

			consultarDetalhes(raiz);

			break;

			case 4:

			b=contarNos(raiz);
			printf("\n>>>>>>>>>>>>><<<<<<<<<<<<<\n\n");
			printf("  A arvore possui %d nos!\n",b);
			printf("\n>>>>>>>>>>>>><<<<<<<<<<<<<\n\n");

			break;
			
			
		
			default :

			printf("opcao nao existe! tente novamente");

			break;
		}

	}


	return 0;

}

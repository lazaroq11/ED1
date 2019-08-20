

#include <stdio.h>
#include <stdlib.h>
//Criacao de um tipo struct Node com um inteiro e um ponteiro prox
struct Node{
 int num;
 struct Node *prox;
}; 
typedef struct Node node;

int tam;
//assinatura das funcoes;
void inicia(node *LISTA);
int menu(void);
void opcao(node *LISTA, int op);
node *criaNo();
void Inserir(node *LISTA);
void exibe(node *LISTA);
node *retira(node *LISTA);


int main(void)
//Inicia a lista alocando memoria se o ponteiro lista for diferente de nulo, sendo igual a nulo exibe uma mensagem sem memoria disponivel
{
 node *LISTA = (node *) malloc(sizeof(node));
 if(!LISTA){
  printf("Sem memoria disponivel!\n");
 }else{
 inicia(LISTA);
 int sel;
 
 do{
  sel=menu();
  opcao(LISTA,sel);
 }while(sel);

 free(LISTA);
 return 0;
 }
}

void inicia(node *LISTA)
{
 LISTA->prox = NULL;
 tam=0;
}

int menu(void)
{
 int opc;
 
 printf("Escolha a opcao\n");
 printf("1 -- Exibir lista\n");
 printf("2 -- Adicionar Elemento\n");
 printf("3 -- Retirar Elemento\n");
 printf("0 -- Sair\n");
 printf("\n--->: "); 
 scanf("%d", &opc);
 
 return opc;
}
//Menu
void opcao(node *LISTA, int op)
{
 node *tmp;
 switch(op){
 

  
  case 1:
   exibe(LISTA);
   break;
  
 
  case 2:
   Inserir(LISTA);
   break;
   
  
  case 3:
   tmp= retira(LISTA);
   if(tmp==NULL){
   	printf("\nLista vazia!\n\n");
   }else{
   printf("Retirado: %3d\n\n", tmp->num);
   }
   break;
   
   case 0:
   	
   	break;
  
  default:
   printf("Comando invalido\n\n");
 }
}

int vazia(node *LISTA)
{
 if(LISTA->prox == NULL)
  return 1;
 else
  return 0;
}
//rotina que verifica se eh possivel fazer a alocacao dinamica de memoria, se sim pede-se um elemento ao usuario
node *aloca()
{
 node *novo=(node *) malloc(sizeof(node));
 if(!novo){
  printf("Memória indisponível!\n");
  exit(1);
 }else{
  printf("Novo elemento: "); scanf("%d", &novo->num);
  return novo;
 }
}

//rotina que insere o elemento digitado pelo usuario na funcao aloca e incrementa o tamanho da lista
void Inserir(node *LISTA)
{
 node *novo=aloca();
 novo->prox = NULL;
 
 if(vazia(LISTA))
  LISTA->prox=novo;
 else{
  node *tmp = LISTA->prox;
  
  while(tmp->prox != NULL)
   tmp = tmp->prox;
  
  tmp->prox = novo;
 }
 tam++;
}


//rotina para exibicao da lista
void exibe(node *LISTA)
{
 if(vazia(LISTA)){
  printf("Lista vazia!\n\n");
  return ;
 }
 
 node *tmp;
 tmp = LISTA->prox;
 printf("Lista:");
 while( tmp != NULL){
  printf("%5d", tmp->num);
  tmp = tmp->prox;
 }
 printf("\n\n");
}



//rotina que retira um elemento da lista a partir da posicao que o usuario deseje fazer a remocao;
node *retira(node *LISTA)
{
	if(vazia(LISTA)){
		return NULL;
	}else{
 int sel,
  count;
 printf("Que posicao, [de 1 ate %d] voce deseja retirar: ", tam);
 scanf("%d", &sel);
 
 if(sel>0 && sel <= tam){
  
   node *atual = LISTA->prox,
     *anterior=LISTA; 
     
   for(count=1 ; count < sel ; count++){
    anterior=atual;
    atual=atual->prox;
   }
   
  anterior->prox=atual->prox;
  tam--;
  return atual;
  }
 }
}



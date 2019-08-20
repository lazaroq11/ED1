#include <stdio.h>
#include <stdlib.h>
//Criacao de um tipo struct Node, que possui um inteiro, e um ponteiro do tipo struct Node prox; 
struct Node{
 int num;
 struct Node *prox;
};
typedef struct Node node;
//variavel inteira que define o tamanho da FILA;
int tam;
//assinatura das funcoes;
int menu(void);
void opcao(node *FILA, int op);
void inicia(node *FILA);
int vazia(node *FILA);
node *aloca();
void insere(node *FILA);
node *retira(node *FILA);
void exibe(node *FILA);



int main(void)
{
//ALOCACAO DINAMICA DO NODE *FILA PARA INICIALIZACAO DAS ROTINAS, SE FILA FOR DIFERENTE DE NULO;
 node *FILA = (node *) malloc(sizeof(node));
 if(FILA == NULL){
  printf("Sem memoria disponivel!\n");
  exit(1);
 }else{
 inicia(FILA);
 int opt;
//chamada do menu para a execucao das rotinas de FILA;
 do{
  opt=menu();
  opcao(FILA,opt);
 }while(opt);

 free(FILA);
 return 0;
 }
}


int menu(void)
{
 int opt;
 printf("\n**************************************\n");
 printf("Escolha a opcao\n");
 printf("**************************************\n");
 printf("0. Sair\n");
 printf("1. Exibir fila\n");
 printf("2. Adicionar Elemento na Fila\n");
 printf("3. Retirar Elemento da Fila\n");
 printf("Opcao: "); scanf("%d", &opt);

 return opt;
}
//MENU
void opcao(node *FILA, int op)
{
 node *tmp;
 switch(op){


  case 1:
   exibe(FILA);
   break;

  case 2:
   insere(FILA);
   break;

  case 3:
   tmp= retira(FILA);
   if(tmp != NULL){
    printf("Retirado: %3d\n\n", tmp->num);
    free(tmp);
}
	break;

 

  default:
   printf("Comando invalido\n\n");
 }
}
//INICIALIZACAO DA FILA COM O PONTEIRO PROX, APONTANDO PRA NULO E TAMANHO IGUAL A 0;
void inicia(node *FILA)
{
 FILA->prox = NULL;
 tam=0;
}
//ROTINA PARA VERIFICAR SE A FILA ESTA OU NAO VAZIA;
int vazia(node *FILA)
{
 if(FILA->prox == NULL)
  return 1;
 else
  return 0;
}
/*ROTINA PARA ALOCACAO DINAMICA DE MEMORIA E INSERCAO DE UM VALOR POR PARTE DO USUARIO AINDA NAO NA FILA,  SE POSSIVEL, E PARA ISSO O PONTEIRO NOVO TEM QUE SER DIFERENTE DE NULO,A PARTIR DISSO UM NOVO ELEMENTO SERA INSERIDO 
PELO USUARIO NA FILA*/
node *aloca()
{
 node *novo=(node *) malloc(sizeof(node));
 if(novo==NULL){
  printf("Sem memoria disponivel!\n");
  exit(1);
 }else{
  printf("Novo elemento: "); scanf("%d", &novo->num);
  return novo;
 }
}
//ROTINA PARA VALIDACAO E INSERCAO DO VALOR DADO PELO USUARIO NA ROTINA ALOCA, ONDE ESSE VALOR SERA INSERIDO NO INICIO  DA FILA E OCORRE UM INCREMENTO DO TAMANHO DA MESMA;
void insere(node *FILA)
{
 node *novo=aloca();
 novo->prox = NULL;

 if(vazia(FILA))
  FILA->prox=novo;
 else{
  node *tmp = FILA->prox;

  while(tmp->prox != NULL)
   tmp = tmp->prox;

  tmp->prox = novo;
 }
 tam++;
}

//ROTINA PARA REMOVER ELEMENTOS DA FILA, SE A MESMA NAO ESTIVER VAZIA 
node *retira(node *FILA)
{
 if(FILA->prox == NULL){
  printf("Fila ja esta vazia\n");
  return NULL;
 }else{
  node *tmp = FILA->prox;
  FILA->prox = tmp->prox;
  tam--;
  return tmp;
 }

}

//ROTINA PARA EXIBIR A FILA SE A MESMA ESTIVER VAZIA A MENSAGEM FILA VAZIA EH EXIBIDA;
void exibe(node *FILA)
{
 if(vazia(FILA)){
  printf("Fila vazia!\n\n");
  return ;
 }

 node *tmp;
 tmp = FILA->prox;
 printf("Fila : \n");
 while( tmp != NULL){
  printf("%5d", tmp->num);
  tmp = tmp->prox;
 }

 
}



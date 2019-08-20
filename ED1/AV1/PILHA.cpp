#include<stdio.h>
#include<stdlib.h>
//criacao de um tipo struct pilha com um inteiro, e um ponteiro do tipo struct pilha proximo
 typedef struct pilha{
	int numero;
	struct pilha *proximo;
} pilha;


//rotina para insercao de elementos na pilha
void inserir(pilha **topo){  //passagem de um ponteiro duplo chamado topo que armazenara o topo da pilha 
	pilha *novo; //ponteiro que recebera o proximo elemento da pilha;
	novo = (pilha *)malloc(sizeof(pilha)); 
	if(novo==NULL){ //se o ponteiro novo for nulo, nao sera possivel alocar memoria
		printf("Sem memoria!!!");
		exit(1);
	}else{  //caso contrario informa-se o valor de novo que aponta pra numero;
		printf("Informe o numero: "); 
		scanf("%d",&novo->numero);
		
		if(*topo==NULL){ //se topo for nulo;
			novo->proximo = NULL;  //novo que aponta proximo sera nulo;
		}else{
			novo->proximo= *topo;  //caso contrario o proximo elemento inserido assumira o topo da pilha
		}
		*topo = novo; //ponteiro topo recebe o valor de novo;
	}
}

//rotina para exibir a pilha, caso ela tenha pelo menos um elemento, se nao sera informado que a pilha esta vazia
void exibir(pilha *topo){

	pilha *aux;
	if(topo==NULL){
		printf("Pilha esta vazia!!!!");
		
	}else{
		aux = topo;
		while(aux!=NULL){
			printf("%d ",aux->numero);
			aux = aux->proximo;
		}
	}
}

/*rotina para remover elementos da pilha sempre do topo,utilizando um ponteiro auxiliar que recebe o valor do proximo elemento da pilha, desaloca-se entao o topo,
e o ponteiro auxliar assume o topo;*/
void remover(pilha **topo){
	pilha *aux;
	aux = (*topo)->proximo;
	free(*topo);
	*topo = aux;
}



//main
int main(){
	pilha *topo = NULL; //inicializacao da pilha com o topo apontando pra nulo no main;
	int opc; //MENU INTERATIVO PARA EXECUCAO DAS ROTINAS DE PILHA;
	do{
	printf("Escolha uma opcao:");
	printf("\n1 Inserir um elemento na pilha: \n");
	printf("2 Exibir o(s) elemento(s)da pilha: \n");
	printf("3 Remover um elemento da pilha: \n");
	printf("4 Sair \n");
	printf("Opcao:");
	scanf("\n\n %d",&opc);
	
	
	switch(opc){
		case 1:
			printf("\n ********************************* \n");
			inserir(&topo);
			break;
		case 2:
			printf("\n **************PILHA******************* \n");
		    exibir(topo);
		   	printf("\n ************************************** \n");
			break;
		case 3:
		     remover(&topo);
			 break;			 	
}
	}while(opc!=4);	
      


}

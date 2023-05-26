#include <iostream>
using namespace std;

struct No {
    int element;
    No * prox;
};
struct Fila{
	No * ini;
    No * fim;
};

int inserir(Fila &, int);
int remover(Fila &, int&);
void imprimir(Fila &);
int conta(Fila &);

int main(void){
	Fila intPositivo;
	intPositivo.ini = intPositivo.fim = NULL;
	int element=1;
	
    //Digitar valores inteiros positivos
	while((element > 0)&&(element != NULL)){
		cout << "Digite: ";
		cin>>element;
		if(element > 0)inserir(intPositivo, element);
	}
	
    //Imprime valores na fila
    cout<<"\nNumeros na lista: ";
    imprimir(intPositivo);

    //Desenfilera um valor
   if(remover(intPositivo, element)!=0){
		cout<<"\nFila vazia";
	}else{
		cout<<"\nNumeros interio positivo desenfileirado: "<<element;
	}

    //Conta os a quatidade de numeros na fila
    cout<<"\nQuatidade de numeros na lista: ";
    cout<<conta(intPositivo);

    //Desenfilera tudo imprimindo os pares
	if(remover(intPositivo, element)!=0){
		cout<<"\nFila vazia";
	}else{
		cout<<"\nNumeros interios positivos pares: ";
		do{
			if(element % 2 == 0)cout<<element; //Define par
		}while(remover(intPositivo, element)==0);	
	}
    cout<<endl;
    system("pause");
}

int inserir(Fila &some, int element){
	No *temp;
	temp = new No;
	temp->element = element;
    temp->prox = NULL;
    
    if (some.ini == NULL) {
        some.ini = some.fim = temp;
    }else {
        some.fim->prox = temp;
        some.fim = temp;
    }
    return 0;
}

int remover(Fila &some, int &element) {
    No * temp;
    if (some.ini == NULL) return 1;
    element = some.ini->element;
    temp = some.ini;
    some.ini = some.ini->prox;
    delete temp;
    if (some.ini == NULL) some.fim = NULL;
    return 0;
}

void imprimir(Fila &some){
    No * temp;
    temp = some.ini;
    while(temp != NULL) {
        cout << temp->element;
        temp = temp->prox;
    }
}

int conta(Fila &some){
    No * temp;
    temp = some.ini;
    int i = 0;
	while(temp!=NULL){
		i++;
		temp = temp->prox;
	}
	return i;
}
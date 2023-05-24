#include <iostream>
using namespace std;

struct no {
    int element;
    no * prox;
};

no * inserirFrente(no * , int );
void imprimir(no *);
void substituir(no *, int , int);
no * removerInicio(no * );
no * busca(no *, int);
int contaNos(no *); 
no * inserirFim(no * , int );
no * removerFim(no * );

int main(void) {
    no *lista = NULL;
	no *lista1 = NULL; 
    int n, m, i=0, element, j;

    /*cout << "Quantidade de valores? ";
    cin >> n;

	while(i!=n){
		cout << "Element " 
		<< i+1 << ": ";
        cin >> element;
        lista = inserirFrente(lista, element);
		i++;
	}
	cout << "\n Valores da lista: ";
    imprimir(lista);
	cout <<endl;
	
	while(j <= 0 || j > n){
		cout << "Digite posição: ";
    	cin >> j;
		cout << "\nDigite novoValor: ";
    	cin >> element;
		if(j<=n)substituir(lista, j, element);
	}
	cout << "\n Valores da lista: ";
	imprimir(lista);
	cout <<endl;

	lista = removerInicio(lista);
	cout << "\n Valores da lista: ";
	imprimir(lista);
	cout <<endl;

	if(busca(lista, 2) == NULL){
		cout<<"Elemento nao encontrado";
	}else{
		cout<<"Endereco: "<<busca(lista, 2);
	}
	cout <<endl;
	
	cout << "Quantidades de nós: "<<contaNos(lista);*/

	i = 0;
	cout << "\nQuantidade de valores? ";
    cin >> m;

	while(i!=m){
		cout << "Element " 
		<< i+1 << ": ";
        cin >> element;
        lista1 = inserirFim(lista1, element);
		i++;
	}
	cout << "\n Valores da lista: ";
	imprimir(lista1);
	cout <<endl;

	lista1 = removerFim(lista1);
	cout << "\n Valores da lista: ";
	imprimir(lista1);
	cout <<endl;
}

no * inserirFrente(no * somelista, int valor) {
    no * temp;
    temp = new no;
    temp->element = valor;
    temp->prox = NULL;
    if (somelista == NULL){
		somelista = temp;
	} else {
        temp->prox = somelista;
        somelista = temp;
    }
    return somelista;
}

void imprimir(no * inicio) {
    no * temp;
    temp = inicio;
    while(temp != NULL) {
        cout << temp->element;
        temp = temp->prox;
    }
}

void substituir(no * inicio, int valor, int novoValor) {
    no * temp;
	int i;
    if (valor < 1) return;
    temp = inicio;
    i = 1;
    while(temp != NULL) {
        if (i==valor) {
            temp->element = novoValor;
            break;
        }
        temp = temp->prox;
        i++;
    }
}

no * removerInicio(no * inicio) {
    no * temp;
    if (inicio == NULL) {
		cout<<"Lista vazia!";
		return inicio;
	}
    temp = inicio;
    inicio = temp->prox;
    delete temp;
    return inicio;
}

no * busca(no * inicio, int valor){
	no * temp;
	temp = inicio;
	while(temp!=NULL){
		if(temp->element == valor){
			return inicio;
		}
		temp = temp->prox;
	}
	return NULL;
}

int contaNos(no * inicio){
	no * temp;
	temp = inicio;
	int i = 0;
	while(temp!=NULL){
		i++;
		temp = temp->prox;
	}
	return i;
}

no * inserirFim(no * somelist, int valor){
	no * temp, *aux;
    temp = new no;
	aux = new no;
    temp->element = valor;
    temp->prox = NULL;
    if (somelist == NULL){
		somelist = temp;
	}else{
        aux = somelist;
		while(aux->prox)aux=aux->prox; //Percorre até o fim da lista
		aux->prox=temp;
    }
    return somelist;
}

no * removerFim(no *inicio){
	no *temp, *aux;
    if (inicio == NULL) {
		cout<<"Lista vazia!";
		return inicio;
	}
	aux = inicio->prox;
	temp = inicio;
	while(aux->prox){//Percorre até o fim da lista
		temp = aux;
		aux=aux->prox;
	}
    inicio = temp->prox;
    delete temp;
    return inicio;
}
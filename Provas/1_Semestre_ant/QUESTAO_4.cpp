#include <iostream>
#include <cctype>
#define MAX 5
using namespace std;

int enfileirar(char[], int&, char);
int desenfileirar(char[], int&, int, char&);
int empilhar(char[], int&, char);
int desempilhar(char[], int&, char&);

int main(void){
    char vetor[MAX];
    char fila[MAX];
    char pilha[MAX];
    int ifila = 0;
    int ffila = -1;
    int topo = -1;
    char element;
    int contador;

    cout<<"digite: ";
    cin.getline(vetor, MAX);

    while(vetor[contador] != '\0'){
        enfileirar(fila, ffila, vetor[contador]);
        contador++;
    }
    while(desenfileirar(fila, ifila, ffila, element) != 1){
        if(isalpha(element)){
            empilhar(pilha, topo, toupper(element));
        }else{
            empilhar(pilha, topo, element);
        }
    }
}
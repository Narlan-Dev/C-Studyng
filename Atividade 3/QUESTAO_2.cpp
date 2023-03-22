#include <iostream>
#include <string>
#include <ctype.h>
#include <algorithm>
#include <cstdlib>
#define MAXIMUN 10
using namespace std;

int empilhar(char[], int &, char);
int desempilhar(char[], int &, char &);
int enfileirar(char[], int &, char);
int desenfileirar(char[], int &, int, char &);

int main(void){
    string word;
    char element;
    char pilha[MAXIMUN];
    char fila[MAXIMUN];
    int topo = -1;
    int ifila = 0;
    int ffila = -1;

    cout<<"Digite a palavra: ";
    getline(cin, word);

    //Enfilera os caracters
    for(int i=0; i < word.length(); i++){
        enfileirar(fila, ffila, word.at(i));
    }

    //Desenfilera os caracteres e empilhar
    while(desenfileirar(fila, ifila, ffila, element)!=1){
        empilhar(pilha, topo, tolower(fila[ifila - 1]));
    }

    cout<<endl<<"Lista de caracteres;"<<endl;

    //Desempilhando tudo
    while(desempilhar(pilha, topo, element)!=1){
        cout<<element<<endl;
    }
}

int empilhar(char someList[], int &top, char element){
    if(top>=MAXIMUN + 1){
        return 1;
    }
    top +=1;
    someList[top] = element;
    return 0;
}

int desempilhar(char someList[], int &top, char &element){
    if(top<0){
        return 1;
    }
    element = someList[top];
    top--;
    return 0;
}

int enfileirar(char fila[], int &ffila, char element){
    if(ffila >= MAXIMUN - 1)return 1;
    ffila++;
    fila[ffila] = element;
    return 0;
}

int desenfileirar(char fila[], int &ifila, int ffila, char &element){
    if(ffila < ifila)return 1;
    element = fila[ifila];
    ifila++;
    return 0;
}
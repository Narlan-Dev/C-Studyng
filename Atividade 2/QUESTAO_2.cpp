#include <iostream>
#include <string>
#include <ctype.h>
#include <algorithm>
#define MAXIMUN 20
using namespace std;

void verifica(char[], int &);
int empilhar(char[], int &, char);
int remover(char[], int &, char);
int buscaNormal(char [], int, char);

int main(void){
    string word;
    char string[MAXIMUN];
    int topo = -1;
    
    cout<<"Digite os parenteses: ";
    getline(cin, word);
    
    //preenche a fila
    for(int i=0; i < word.length(); i++){
        empilhar(string, topo, word.at(i));
    }
    verifica(string, topo);
}

void verifica(char someList[], int &top){
    int aux = 0;
    int teste;
    
    do{
        teste = remover(someList, top, ')');
        aux++;
    }while(teste != 2);

    if(aux == top){
        cout<<"Numero de abre parenteses igual ao numero de fecha parenteses!"<<endl;
    }else{
        cout<<"Numero de abre parenteses diferente do numero de fecha parenteses!"<<endl;
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

int remover(char someList[], int &top, char element){
    int posicao;
   
    if(top<0){
        return 1;
    }
    posicao = buscaNormal(someList, top, element);
    if(posicao < 0){
        //cout << "ERRO: Elemento nao encontrado!" << endl;
        return 2;
    }
    for(int i=posicao; i < top - 1; i++)someList[i] = someList[i+1];
    top--;
}

int buscaNormal(char someList[], int n, char element){
    int inicio = 0;
    int fim = n - 1;

    while(inicio <= fim){
        if(someList[inicio] == element) return inicio;
        inicio++;
    }
    return -1;
}

#include <iostream>
#include <string>
#include <ctype.h>
#include <algorithm>
#define MAXIMUN 45
using namespace std;

void verifica(char[], int, string);
int empilhar(char[], int &, char);

int main(void){
    string word;
    int topo = -1;
    char primeiraMetade[MAXIMUN];
    
    cout<<"Digite a palavra: ";
    getline(cin, word);
    transform(word.begin(), word.end(), word.begin(), ::toupper);
    for(int i=0; i < word.length()/2; i++){
        empilhar(primeiraMetade, topo, word.at(i));
    }
    verifica(primeiraMetade, topo, word);
}

void verifica(char someList[], int top, string words){
    int contador = 0;

    for(int i=0; i < top; i++){
        if(someList[i] == words.at((words.length() - 1) - i)){
            contador++;
        }
    }
    
    if(contador == top){
        cout<<words<<" eh um palindromo"<<endl;
    }else{
        cout<<words<<" nao eh um palindromo"<<endl;
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
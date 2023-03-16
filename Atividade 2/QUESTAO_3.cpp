#include <iostream>
#include <string>
#include <ctype.h>
#include <algorithm>
using namespace std;

void verifica(string);

int main(void){
    string word;
    cout<<"Digite a palavra: ";
    getline(cin, word);
    transform(word.begin(), word.end(), word.begin(), ::toupper);
    verifica(word);
}

void verifica(string words){
    int contador = 0;

    for(int i=0; i < words.length()/2; i++){
        if(words.at(i) == words.at((words.length() - 1) - i)){
            contador++;
        }
    }
    
    if(contador == words.length()/2){
        cout<<words<<" eh um palindromo"<<endl;
    }else{
        cout<<words<<" nao eh um palindromo"<<endl;
    }
}
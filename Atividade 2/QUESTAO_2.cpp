#include <iostream>
using namespace std;

void verifica(char []);
int MAXIMUN = 20;

int main(void){
    char string[MAXIMUN];
    
    cout<<"Digite os parenteses: ";
    cin.getline(string, MAXIMUN);
    verifica(string);
}

void verifica(char someList[]){
    int contador1 = 0;
    int contador2 = 0;
    
    for(int i=0; i < MAXIMUN; i++){
        if(someList[i] == '('){
            contador1++;
        }else if(someList[i] == ')'){
            contador2++;
        }
    }

    if(contador1 == contador2){
        cout<<"Numero de parenteses iguais"<<endl;
    }else{
        cout<<"Numero de parenteses diferentes"<<endl;
    }
}

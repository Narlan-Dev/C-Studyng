#include <iostream>
#define MAXIMUN 50
using namespace std;

int empilhar(int [], int &, int);
void showList(int[], int);

int main(void){
    int topo = -1;
    int binario[MAXIMUN] = {0};
    int input = 0;
    int result = 1;
    int resto = 0;
    cout<<"Enter the number: ";
    cin>>input;
    
    do{
        result = input/2;
        resto = input % 2;
        empilhar(binario, topo, resto);
        input = result;
    }while(result != 0);
    
    showList(binario, topo);
}

int empilhar(int someList[], int &top, int element){
    if(top>=MAXIMUN + 1){
        return 1;
    }
    top +=1;
    someList[top] = element;
    return 0;
}

void showList(int someList[], int topo){
    for(int i=topo; i>=0; i--){
        cout<<someList[i];
    }
}
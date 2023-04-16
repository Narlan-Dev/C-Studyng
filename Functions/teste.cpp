#include "mergesort.h"
#include <iostream>
#define MAX 4
using namespace std;

int main(void){
    //Algoritimo de teste
    int vetor[MAX] = {9,7,6,8};
    
    //Antes de ordenar
    cout<<"\nVetor original: ";
    for(int i=0; i<MAX; i++){
        cout<<"["<<vetor[i]<<"]";
    }
    mergeSort(vetor, 0, MAX-1); //Ordena crescente
    cout<<"\nVetor ordenado crescentemente: ";
    for(int j=0; j<MAX; j++){
        cout<<"["<<vetor[j]<<"]";
    }
    cout<<"\n";
    return 0;
}
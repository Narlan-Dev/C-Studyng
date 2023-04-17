#include "mergesort.h"
#include "quicksort.h"
#include <iostream>
#define MAX 8
using namespace std;

int main(void){
    //Algoritimo de teste
    int vetor[MAX] = {9,7,6,8,1,2,1,3};
    
    //Antes de ordenar
    cout<<"\nVetor original: ";
    for(int &i: vetor){
        cout<<"["<<i<<"]";
    }
    mergeSort(vetor, 0, MAX-1); //Ordena crescente
    //quicksort(vetor, 0, MAX-1); //Ordena crescente
    cout<<"\nVetor ordenado crescentemente: ";
    for(int &i: vetor){
        cout<<"["<<i<<"]";
    }
    cout<<"\n";
    return 0;
}
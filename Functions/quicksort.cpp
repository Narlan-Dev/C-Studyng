#include "quicksort.h"
using namespace std;

int partition(int*, int, int);

void quicksort(int *list, int inicio, int fim){
    if(inicio<fim){
        int p = partition(list, inicio, fim);
        quicksort(list, inicio, p-1);
        quicksort(list, p+1, fim);
    }
}

int partition(int *list, int inicio, int fim){
    int pivot = list[fim];
    int i = inicio;
    int j = inicio;
    
    while(j <= fim){
        if(list[j] <= pivot){
            swap(list[j++],list[i++]);
        }else{
            j++;
        }
    }
    return i-1;
}
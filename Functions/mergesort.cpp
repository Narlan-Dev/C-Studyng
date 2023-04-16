#include "mergesort.h"
#define size(list) (sizeof(list) / sizeof(*(list))) // Macro que retorna tamanho de qualquer array inicializado
using namespace std;

void merge(int[], int, int, int);

void mergeSort(int ordenado[], int inicio, int fim){
    if(inicio < fim){
        int meio = floor((inicio + fim)/2);
        mergeSort(ordenado, inicio, meio);
        mergeSort(ordenado, meio+1, fim);
        merge(ordenado, inicio, meio, fim);
    }
}

void merge(int ordenado[], int inicio, int meio, int fim){
    int left[meio-inicio+1], right[fim-meio];
    int top_left = 0, top_right = 0;
    int i = inicio;

    copy(ordenado + (inicio), ordenado + (inicio+size(left)), left);
    copy(ordenado + (meio+1), ordenado + (meio+1+size(right)), right);

    while(top_left < size(left) && top_right < size(right)){
        if(left[top_left] <= right[top_right]){
            ordenado[i++] = left[top_left++];
        }else{
            ordenado[i++] = right[top_right++];
        }
    }
    while(top_left < size(left)){
        ordenado[i++] = left[top_left++];
    }
    while(top_right < size(right)){
        ordenado[i++] = right[top_right++];
    }
}
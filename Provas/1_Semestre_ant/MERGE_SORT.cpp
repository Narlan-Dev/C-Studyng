#include <iostream>
#include <cctype>
#include <cmath>
#define MAX 8
using namespace std;

void mergeSort(int[], int, int);
void merge(int[], int, int, int);

int main(void){
    //algoritimo principal
}

void mergeSort(int ordenado[], int inicio, int fim){
    int meio;
    if(inicio < fim){
        meio = floor((inicio+fim)/2);
        mergeSort(ordenado, inicio, meio);
        mergeSort(ordenado, meio, fim);
        merge(ordenado, inicio, meio, fim);
    }
}

void merge(int ordenado[], int inicio, int meio, int fim){
    int *temp;
}
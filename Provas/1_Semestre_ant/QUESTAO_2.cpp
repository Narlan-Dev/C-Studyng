#include <iostream>
#include <cctype>
#define MAX 5
using namespace std;

int enfileirar(char[], int&, char);
int desenfileirar(char[], int&, int, char&);
int enfileirarCircular(int[], int&, int&, int);
int desenfileirarCircular(int[], int&, int&, int&);

int main(void){
    char vetor[MAX];
    char filaA[MAX];
    int filaB[MAX];
    int ifila = 0;
    int ffila = -1;
    int num = 0;
    int contador = 0;
    int number;
    char element;

    cout<<"Digite: ";
    cin.getline(vetor, MAX);

    while(vetor[contador] != '\0'){
        if(isalpha(vetor[contador]))enfileirar(filaA, ffila, vetor[contador]);
        if(isdigit(vetor[contador]))enfileirarCircular(filaB, num, ffila, atoi(&vetor[contador]));
        contador++;
    }
    cout<<endl;
    while(desenfileirarCircular(filaB, num, ifila, number) != 1)cout<<"["<<number<<"]";
    cout<<endl;
    while(desenfileirar(filaA, ifila, ffila, element) != 1)cout<<"["<<element<<"]";
}

/*int enfileirarCircular(int fila[], int &num, int &ffila, int number){
    if(num < MAX){
        ffila++;
        if(ffila == MAX)ffila -= MAX;
        fila[ffila] = number;
        num++;
        return 0;
    }
    //fila cheia
    return 1;
}

int desenfileirarCircular(int fila[], int &num, int &ifila, int &number){
    if(num > 0){
        number = fila[ifila];
        ifila++;
        if(ifila >= MAX)ifila -= MAX;
        num--;
        return 0;
    }
    //fila vazia
    return 1;
}*/
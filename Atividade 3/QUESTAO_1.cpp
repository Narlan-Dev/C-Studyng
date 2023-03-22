#include <iostream>
#include <string>
#include <ctype.h>
#include <algorithm>
#include <cstdlib>
#define MAXIMUN 3
using namespace std;

int menu(int, int[], int&, int&);
void design(int);
int enfileirar(int[], int &, int);
int desenfileirar(int [], int &, int, int &);

int main(void){
    int resposta;
    int fila[MAXIMUN];
    int ifila = 0;
    int ffila = -1;

    do{
        design(0);
        ifila = 0;
        cin>>resposta;
    }while(menu(resposta, fila, ifila, ffila) != 3);

}

int menu(int resposta, int fila[], int &ifila, int &ffila){
    int element;
    int contador = 0;
    
    //Chama função enfileirar
    if(resposta == 1){
        design(1);
        cin>>element;
        //Se o numero for positivo
        if(element > 0){
            //Se a fila estiver cheia
            if(enfileirar(fila, ffila, element) == 1){
                design(4);
                system("pause");
                return 0;
            }else{
                design(6);
                system("pause");
                return 0;
            }
        }else{
            design(3);
            system("pause");
            return 0;
        }
        system("pause");
        return 1;

     //Chama função desenfileirar
    }else if(resposta == 2){
        //Se a fila estiver vazia
        if(desenfileirar(fila, ifila, ffila, element) == 1){
            design(5);
            system("pause");
            return 0;
        }else{
            design(2);
            do{ 
                //Se o numero for multiplo de 2
                if(element % 2 == 0){
                    cout<<element<<endl;
                    contador++;
                }
            }while(desenfileirar(fila, ifila, ffila, element) == 0);
            //Se não houver numeros multiplos de 2
            if(contador == 0)design(7);
        }
        system("pause");
        return 2;

     //Encerra o programa
    }else if(resposta == 3)return 3;
   
    return 0;
}

void design(int print){
    switch (print)
    {
    case 0:
        system("cls");
        cout << endl
        << " 1 - ENFILEIRAR UM NUMERO INTEIRO/POSITIVO.\n"
        << " 2 - DESENFILEIRAR(MULTIPLOS DE 2).\n"
        << " 3 - ENCERRAR.\n"
        << " Digite sua resposta: ";
        break;
    
    case 1:
        system("cls");
        cout <<endl<< " Digite o numero: ";
        break;
    
    case 2:
        system("cls");
        cout <<endl<< " Valores multiplos de 2 da lista; "<<endl;
        break;

     case 3:
        system("cls");
        cout <<endl<< " Apenas valores inteiros positivos! "<<endl;
        break;

     case 4:
        system("cls");
        cout <<endl<< " Lista cheia! "<<endl;
        break;
    
     case 5:
        system("cls");
        cout <<endl<< " Lista vazia! "<<endl;
        break;

     case 6:
        system("cls");
        cout <<endl<< " Enfileirado com sucesso! "<<endl;
        break;

     case 7:
        system("cls");
        cout <<endl<< " Sem numeros multiplos de 2! "<<endl;
        break;
    
    default:
        break;
    }

}

int enfileirar(int fila[], int &ffila, int element){
    if(ffila >= MAXIMUN - 1)return 1;
    ffila++;
    fila[ffila] = element;
    return 0;
}

int desenfileirar(int fila[], int &ifila, int ffila, int &element){
    if(ffila < ifila)return 1;
    element = fila[ifila];
    ifila++;
    return 0;
}
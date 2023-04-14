#include <iostream>
#include <string>
#include <ctype.h>
#include <algorithm>
#include <cstdlib>
#define MAXIMUN 4
using namespace std;

int backEnd(int, int[], int&, int&, int&);
void design(int);
int enfileirar(int[], int&, int &, int);
int desenfileirar(int[], int&, int &, int &);
int empilhar(int[], int&, int);
int desempilhar(int[], int&, int&);
int inverteElementos(int[], int&, int&, int&, int&);
int elementosImpares(int[], int&, int&);
int elementosPares(int[], int&, int&);
int show(int[], int&, int &, int &);

int main(void){
    int resposta;
    int fila[MAXIMUN];
    int ifila = 0;
    int ffila = -1;
    int num = 0;
    do{
        design(0);
        cin>>resposta;
    }while(backEnd(resposta, fila, num, ifila, ffila) != 7);
}

int backEnd(int resposta, int fila[], int &num, int &ifila, int &ffila){
    int element;
    int result;
    //Chama função enfileirar
    if(resposta == 1){
        design(1);
        cin>>element;
        //Se o numero for positivo
        if(element > 0){
            //Se a fila estiver cheia
            if(enfileirar(fila, num, ffila, element) == 1){
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
        if(inverteElementos(fila, num, ifila, ffila, element) == 1){
            design(5);
            system("pause");
            return 0;
        }
        design(2);
        system("pause");
        return 2;
     //Chama mostrar os valores da fila
    }else if(resposta == 3){
        //Se a fila estiver fazia
        design(7);
        if(show(fila, num, ifila, element) == 1){
            design(5);
            system("pause");
            return 0;
        }
        system("pause");
        return 3;
     //Chama mostrar elementos impares
    }else if(resposta == 4){
        design(8);
        result = elementosImpares(fila, num, ifila);
        //Se a fila estiver fazia
        if(result == 1){
            design(5);
            system("pause");
            return 0;
         //Se nao tiver elementos impares
        }else if(result == 2){
            design(10);
            system("pause");
            return 0;
        }
        system("pause");
        return 4;
    }else if(resposta == 5){
        design(9);
        result = elementosPares(fila, num, ifila);
        //Se a fila estiver fazia
        if(result == 1){
            design(5);
            system("pause");
            return 0;
         //Se nao tiver elementos pares
        }else if(result == 2){
            design(11);
            system("pause");
            return 0;
        }
        system("pause");
        return 5;
     //Chama funcao desenfileirar
    }else if(resposta == 6){
        design(12);
        //Se a fila estiver fazia
        if(desenfileirar(fila, num, ifila, element) == 1){
            design(5);
            system("pause");
            return 0;
        }
        cout<<element<<endl;
        system("pause");
        return 6;
     //Finaliza a execucao
    }else if(resposta == 7)return 7;
    return 0;
}

int inverteElementos(int fila[], int &num, int &ifila, int &ffila, int &element){
    int pilha[MAXIMUN];
    int topo = -1;
    //inverte a ordem
    if(num > 0){
        while(desenfileirar(fila, num, ifila, element) != 1){
            empilhar(pilha, topo, element);
        }
        while(desempilhar(pilha, topo, element) != 1){
            enfileirar(fila, num, ffila, element);
        }
        return 0;
    }
    return 1;
}

int elementosImpares(int fila[], int &num, int &ifila){
    int auxNum = num;
    int auxIfila = ifila;
    int element;
    int contador = 0;
    if(auxNum > 0){
        while(desenfileirar(fila, auxNum, auxIfila, element) != 1){
            if(element % 2 != 0){
                cout<<"["<<element<<"]";
                contador++;
            }
        }
        cout<<endl;
        if(contador == 0)return 2;
        return 0;
    }
    return 1;
}

int elementosPares(int fila[], int &num, int &ifila){
    int auxNum = num;
    int auxIfila = ifila;
    int element;
    int contador = 0;
    if(auxNum > 0){
        while(desenfileirar(fila, auxNum, auxIfila, element) != 1){
            if(element % 2 == 0){
                cout<<"["<<element<<"]";
                contador++;
            }
        }
        cout<<endl;
        if(contador == 0)return 2;
        return 0;
    }
    return 1;
}

int show(int fila[], int &num, int &ifila, int &element){
    int auxNum = num;
    int auxIfila = ifila;
    if(auxNum > 0){
        while(desenfileirar(fila, auxNum, auxIfila, element) != 1){
            cout<<"["<<element<<"]";
        }
        cout<<endl;
        return 0;
    }
    return 1;
}

int enfileirar(int fila[], int &num, int &ffila, int element){
    if(num < MAXIMUN){
        ffila++;
        if(ffila == MAXIMUN)ffila -= MAXIMUN;
        fila[ffila] = element;
        num++;
        return 0;
    }
    return 1;
}

int desenfileirar(int fila[], int &num, int &ifila, int &element){
   if(num > 0){
        element = fila[ifila];
        ifila++;
        if(ifila >= MAXIMUN) ifila -= MAXIMUN;
        num--;
        return 0;
    }
    return 1;
}

int empilhar(int someList[], int &top, int element){
    if(top>=MAXIMUN - 1){
        return 1;   
    }
    top++;
    someList[top] = element;
    return 0;
}

int desempilhar(int someList[], int &top, int &element){
    if(top<0){
        return 1;
    }
    element = someList[top];
    top--;
    return 0;
}

void design(int print){
    switch (print)
    {
    case 0:
        system("cls");
        cout << endl
        << " ____________________________________________\n"
        << "|                                            |\n"
        << "|              CUSTOMIZAR FILAS              |\n"
        << "|____________________________________________|\n"
        << "| 1 - ENFILEIRAR UM NUMERO INTEIRO/POSITIVO. |\n"
        << "|____________________________________________|\n"
        << "| 2 - INVERTER ORDEM DOS ELEMENTOS.          |\n"
        << "|____________________________________________|\n"
        << "| 3 - MOSTRAR VALORES NA FILA.               |\n"
        << "|____________________________________________|\n"
        << "| 4 - ELEMENTOS IMPARES DA FILA.             |\n"
        << "|____________________________________________|\n"
        << "| 5 - ELEMENTOS PARES DA FILA.               |\n"
        << "|____________________________________________|\n"
        << "| 6 - DESENFILEIRAR ELEMENTO.                |\n"
        << "|____________________________________________|\n"
        << "| 7 - FINALIZAR EXECUCAO.                    |\n"
        << "|____________________________________________|\n"
        << "\n"
        << " Digite sua resposta: ";
        break;
    
    case 1:
        system("cls");
        cout <<endl<< " Digite o numero: ";
        break;
    
    case 2:
        system("cls");
        cout <<endl<< " Valores trocados com sucesso!"<<endl;
        break;

    case 3:
        system("cls");
        cout <<endl<< " Apenas valores inteiros positivos! "<<endl;
        break;

    case 4:
        system("cls");
        cout <<endl<< " Fila cheia! "<<endl;
        break;
    
    case 5:
        system("cls");
        cout <<endl<< " Fila vazia! "<<endl;
        break;

    case 6:
        system("cls");
        cout <<endl<< " Enfileirado com sucesso! "<<endl;
        break;

    case 7:
        system("cls");
        cout <<endl<< " Elementos da fila: ";
        break;

    case 8:
        system("cls");
        cout <<endl<< " Elementos impares da fila: ";
        break;
    
    case 9:
        system("cls");
        cout <<endl<< " Elementos pares da fila: ";
        break;

    case 10:
        system("cls");
        cout <<endl<< " Sem elementos impares na fila..."<<endl;
        break;

    case 11:
        system("cls");
        cout <<endl<< " Sem elementos pares na fila..."<<endl;
        break;
    
    case 12:
        system("cls");
        cout <<endl<< " Elemento desenfileirado: ";
        break;
    
    default:
        break;
    }

}
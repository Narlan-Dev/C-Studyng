#include <iostream>
using namespace std;

void inserirSemRepetir(int[], int, int &, int);
void removeByIndex(int[], int &, int );
void showList(int[], int);
int totality = 0;
int maximum = 3;
bool full = false;
bool loop = false;
bool state = false;

int main(void){
    int list1[maximum];
    int list2[maximum];
    int list3[2*maximum];
    int list4[maximum];
    int list5[2*maximum];
    int amount = 0;
    int equals = 0;
    int input;
    
    while(!loop){
        if((!full)){
            cout<<"Enter the number: ";
            cin>>input;
            inserirSemRepetir(list1, input, amount,  maximum);
        }else if(full&&!loop){
            cout<<"Enter the number: ";
            cin>>input;
            inserirSemRepetir(list2, input, amount,  maximum);
        }
    }
    cout<<"lista1:"<<endl;
    showList(list1, maximum);
    cout<<"lista2:"<<endl;
    showList(list2, maximum);

    full = false;

    while(!full){
        int par = 0;
        int impar = 1;
        for(int i=0; i<maximum; i++){
            list3[par] = list1[i];
            list3[impar] = list2[i];
            par+=2;
            impar+=2;
        }
        full = true;
    }
    cout<<"lista3:"<<endl;
    showList(list3, 2*maximum);

    full =  false;
    
    while(!full){
        for(int out=0; out < maximum; out++){
            for(int into=0; into < maximum; into++){
                if(list1[out]==list2[into]){
                    list4[equals] = list1[out];
                    equals++;
                }
            }
        }
        full = true;
    }
    cout<<"lista 4:"<<endl;
    showList(list4, equals);

    full = false;

    while(!full){
        for(int i=0; i<2*maximum; i++){
            if(i<maximum){
                list5[i] = list1[i];
            }else{
                list5[i] = list2[i - 3];
            }
        }
        full = true;
    }
    cout<<"lista5:"<<endl;
    showList(list5, 2*maximum);
    
    amount = 2*maximum;
    removeByIndex(list5, amount, 9);
}

void inserirSemRepetir(int someList[], int element, int &amount, int max){
    for(int i=0; i<=amount; i++){
        if(someList[i]==element){
            cout<<"Equal element"<<endl;
            return;
        }
    }
    someList[amount] = element;
    amount++;
    totality++;
    if(amount == max){
        cout<<"List full"<<endl;
        full = true;
        amount = 0;
        if(totality == 2*max){
            full = true;
            loop = true;
            amount = 0;
            return;
        }
        return;
    }
}

void removeByIndex(int someList[], int &amount, int element){
	if(amount == 0){
        cout<<"List empty"<<endl;
        state = false;
        return;
    }else{
        for(int i=0; i<amount; i++){
            if(someList[i]==element){
                someList[i] = someList[amount - 1];
                someList[amount - 1] = 0;
                amount--;
                state = true;
            }
        }
        if(!state){
            cout<<"Element not found"<<endl;
        }else{
            cout<<"Deleted element"<<endl;
            showList(someList, amount);
        }
    }
    state = false;
}

void showList(int someList[], int max){
    for(int i=0; i<max; i++){
        cout<<someList[i]<<endl;
    }
}
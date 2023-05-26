#include <iostream>
#include <cctype>
using namespace std;

struct Aluno {
    int matricula;
    float media; 
    Aluno * prox;
};
struct Fila{
	Aluno * ini;
    Aluno * fim;
};

int inserir(Fila &, int, float);
int remover(Fila &, int&, float&);
void imprimir(Fila &);

int main(void){
	Fila alunos;
	alunos.ini = alunos.fim = NULL;
	int matricula = 1;
    float media = 1;
    int qtd = 0;
    int i = 0;
	
    //Quantidade de alunos
    do{
        cout << "\nDigite numeros de alunos: ";
	    cin>>qtd;
    }while(qtd<=0);

    //Insere aluno com sua matricula e media
    while(i<qtd){
        if((matricula  > 0)){
            cout << "\nDigite matricula: ";
            cin>>matricula;
            cout << "\nDigite media: ";
            cin>>media;
            inserir(alunos, matricula, media);
            i++;
        } 
    }

    //Imprime matrículas e médias na lista
    cout<<"\nMatriculas//Media -> alunos: ";
    imprimir(alunos);

    //Desenfilera tudo imprimindo media maiores iguais ou maiores que 5
	if(remover(alunos, matricula, media)!=0){
		cout<<"\nSem alunos";
	}else{
		cout<<"\nMedias maiores ou iguais a 5: ";
		do{
			if(media >= 5)cout<<"["<<media<<"]" ; //Define par
		}while(remover(alunos, matricula, media)==0);	
	}
    cout<<endl;
    system("pause");
}

int inserir(Fila &some, int matricula, float media){
	Aluno *temp;
	temp = new Aluno;
	temp->matricula  = matricula;
	temp->media = media;
    temp->prox = NULL;
    
    if (some.ini == NULL) {
        some.ini = some.fim = temp;
    }else {
        some.fim->prox = temp;
        some.fim = temp;
    }
    return 0;
}

int remover(Fila &some, int &matricula, float &media) {
    Aluno * temp;
    if (some.ini == NULL) return 1;
    matricula  = some.ini->matricula;
    media = some.ini->media;
    temp = some.ini;
    some.ini = some.ini->prox;
    delete temp;
    if (some.ini == NULL) some.fim = NULL;
    return 0;
}

void imprimir(Fila &some){
    Aluno * temp;
    temp = some.ini;
    while(temp != NULL) {
        cout <<"["<<temp->matricula<<"]"<<"//"<<"["<<temp->media<<"]"<<" -> ";
        temp = temp->prox;
    }
}
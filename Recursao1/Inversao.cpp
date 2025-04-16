#include <bits/stdc++.h>
using namespace std;

void MergeSort(int[], int, int);
void Merge(int[], int, int, int);
void Imprime(int[],int);
void Copy (int[],int[],int,int);

long long int inversoes;
int num;

void Funcao (){
	int x;
	int * vet;
  cin >> num;
  

	vet = (int*)(malloc(num*sizeof(int)));

	for (int i=0;i<num;i++){
			cin >> vet[i];	
	}
	inversoes=0;
	//Imprime(vet,num);
	MergeSort(vet,0,num-1);
	cout <<inversoes<<endl;
	inversoes=0;
	free(vet); 
}

void Imprime (int vet[], int tam){
	for(int i=0;i<tam;i++){
		printf("%d",vet[i]);
		if (i==tam-1){
		 cout<<" +"<<inversoes << endl;
		} else {
			printf(" -> ");
		}
	}
}


void MergeSort(int vet[],int inicio,int fim){
	if (inicio < fim){
		int meio;
		meio = (inicio + fim)/2;
		MergeSort(vet,inicio,meio);
		MergeSort(vet,meio+1,fim);
		Merge(vet,inicio,meio,fim);
		//Imprime(vet,num);
	}	
}

void Merge(int vet[],int inicio,int meio,int fim){
	int vet_temp[fim-inicio+1];
	int topo_ant = inicio;
	int topo_pos = meio+1;
	for (int indice=0; indice<=fim-inicio;indice++){
		if (topo_pos>fim || (topo_ant<=meio && vet[topo_ant]<=vet[topo_pos])){
			vet_temp[indice] = vet[topo_ant++]; 
		} else {
		  int distanciaMeio = topo_pos - (meio+1);
		  if (vet[topo_ant]>vet[topo_pos]){
		    inversoes+=(topo_pos-distanciaMeio)-topo_ant;
		  }
			vet_temp[indice] = vet[topo_pos++];
			
		}
	}
	Copy(vet,vet_temp,inicio,fim);
}

void Copy (int A[],int B[], int inicio,int fim){
	for (int i=inicio;i<=fim;i++){
	A[i] = B[i-inicio];	
	}
}

int main() {
    int iteracao=0;
    int iteracaoMaxima;
    cin >> iteracaoMaxima;
    do {
        Funcao();
        iteracao++;
    } while (iteracao < iteracaoMaxima);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

class Membro {
  public:
    int id;
    int v;
    int e;
    int d;
};


Membro* arvore;
int membroMaisRico;
int maiorPatrimonio= -101;
int * patrimonioMembro;
bool * Percorrido;
int n;

int max (int v[]){
  int maxi=-101;
  for (int i=1;i<n+1;i++){
    maxi = maxi > v[i]? maxi: v[i];
  }
  return maxi;
}



int Patrimonio(int id){
  
  if (id == 0){
    return 0;
  }
  if (patrimonioMembro[id] !=-101){
    return patrimonioMembro[id];
  }
  else {
   int patrimonioDireita = Patrimonio(arvore[id].d);
   int patrimonioEsquerda = Patrimonio(arvore[id].e);
   int patrimonio = arvore[id].v + patrimonioEsquerda + patrimonioDireita;
   patrimonioMembro[id]=patrimonio;
   //cout <<id << " "<< maiorPatrimonio <<" "<< patrimonio<< endl;
   if (patrimonio > maiorPatrimonio){
      membroMaisRico = id;
      maiorPatrimonio = patrimonio;
   }
   if (patrimonio ==maiorPatrimonio && id < membroMaisRico){
      membroMaisRico = id;
      maiorPatrimonio = patrimonio;
     }
   Percorrido[id]=true;
   return patrimonio;
 }
}

void Funcao(){
  maiorPatrimonio=-101;
  cin >> n;
  int i=1;
  int id;
  arvore = (Membro*)malloc(n*sizeof(Membro));
  patrimonioMembro = (int*)malloc((n+1)*sizeof(int));
  Percorrido = (bool*)malloc((n+1)*sizeof(bool));
  while (i<n+1){
    cin >> id;
    arvore[id].id=id;
    cin >> arvore[id].v;
    cin >> arvore[id].e;
    cin >> arvore[id].d;
    patrimonioMembro[id]=-101;
    Percorrido[id]=false;
    i++;
    //arvore[i].imprime();
  }
  
  for (int i=1;i<n+1;i++){
    //cout <<endl <<i<<endl;
    if (!Percorrido[i]){
 
    Patrimonio(i);
    }
  }
  
  
  //cout <<endl;
  cout <<membroMaisRico<<endl;
  //cout <<endl;
  //cout <<maiorPatrimonio<<endl;
  //cout <<endl;
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
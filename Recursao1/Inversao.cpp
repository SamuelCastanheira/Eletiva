#include <bits/stdc++.h>
using namespace std;

int * vetor;
int n;
int Inversao (int i){
  if (i==n-1)
    return 0;
  if (vetor[i])
    return n;
  else {
    return (Retangulos(n-1,m);
  }
  
  
}


void Funcao(){
  cin >> n;
  vetor = (int*)(malloc(n*sizeof(int)));
  for (inti=0;i<n;i++){
    cin >> vetor[i];
  }
  cout << Inversao(0) <<endl;
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
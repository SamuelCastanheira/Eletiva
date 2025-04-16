#include <bits/stdc++.h>
using namespace std;

int n,m;
long long int quant=0;


long long int Retangulos (int n, int m){
  if (m==0)
    return 0;
  if (m == 1)
    return n;
  else {
    return Retangulos(n,m-1) + n*m;
  }
  
  
}


void Funcao(){
  cin >> n;
  cin >> m;

  for(int i=n;i>=1;i--){
  quant+=Retangulos(i,m);
  }
  
  cout << quant<<endl;;
  quant=0;
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
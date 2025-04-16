#include <bits/stdc++.h>
using namespace std;


long long int Combinacao(int n, int p){
  if (p==0||(n-p)==0){
    return 1;
  }
  return Combinacao(n-1,p-1)*((n)/p);
}

void Funcao(){
  int n,p;
  cin >> n;
  cin >> p;
  cout << Combinacao(n,p) <<endl;
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
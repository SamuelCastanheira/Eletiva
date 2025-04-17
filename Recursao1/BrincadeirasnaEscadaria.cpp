#include <iostream>
using namespace std;

int * memo;
int * pontoDegrau;
int n;
int k;


int max(int x, int y){
  if (x>y)
    return x;
  else
    return y;
}

int maxPlacar(int degrau, int passoMax){
  //cout <<"oi"<<endl;
  if (memo[degrau]==-1){
    if (degrau==1){
      memo[degrau] = pontoDegrau[degrau];
    }
    else {
      int maxi = -101;
      for (int i=max(degrau-passoMax,1);i<degrau;i++){
        maxi = max(maxi,maxPlacar(i,passoMax));
      }
      if (degrau <= passoMax){
        memo[degrau] = max(maxi + pontoDegrau[degrau],pontoDegrau[degrau]);
      }
      else {
        memo[degrau] = maxi + pontoDegrau[degrau];
      }
    }
  }
  return memo[degrau];
}

void Funcao(){
  //cout <<"oi"<<endl;
  cin >> n;
  cin >> k;
  memo = (int*)malloc((n+1)*sizeof(int));
  pontoDegrau = (int*)malloc((n+1)*sizeof(int));
  for (int i=1;i<=n;i++){
    cin >> pontoDegrau[i];
    memo[i]=-1;
  }
  cout << maxPlacar(n,k)<<endl;
}


int main() {
  //cout <<"oi"<<endl;
    int iteracao=0;
    int iteracaoMaxima;
    cin >> iteracaoMaxima;
    do {
        Funcao();
        iteracao++;
    } while (iteracao < iteracaoMaxima);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;


class Arvore {
  public:
    int x;
    int y;
    void imprime(){
      cout <<"("<< x << ";"<< y<<")" << endl;
    }
};

class LadoX {
  public:
    int x0;
    int x1;
    LadoX(int a,int b){
     x0=a;
     x1=b;
   }
    int tamanho(){
      return x1-x0;
    }
};


class LadoY {
  public:
    int y0;
    int y1;
    LadoY(int a, int b){
     y0=a;
     y1=b;
   }
    int tamanho(){
      return y1-y0;
    } 
};

class Ponto{
  public:
   int x;
   int y;
   Ponto(int a, int b){
     x=a;
     y=b;
   }
};

int max (int a, int b, int c, int d){
  int maxi = a;
  int num[4]={a,b,c,d};
  for (int i=0;i<4;i++){
    if (num[i]>maxi){
      maxi = num[i];
    }
  }
  return maxi;
}

int L,A,qtd;
Arvore * arvores;

long long int Area(Ponto p0, Ponto p1, int n){
  LadoX ladox(p0.x, p1.x);
  LadoY ladoy(p0.y, p1.y);
  if (n==0){
    return ladox.tamanho()*ladoy.tamanho();
  }
  
  if ((arvores[n].x > ladox.x0 && arvores[n].x <ladox.x1) &&  (arvores[n].y > ladoy.y0 && arvores[n].y <ladoy.y1)){
    
  cout <<"oi" <<endl;
  Arvore arvore = arvores[n];
  Ponto cima_p0(p0.x,arvores[n].y+1);
  Ponto cima_p1(p1.x,p1.y);
  Ponto baixo_p0(p0.x,p0.y);
  Ponto baixo_p1(p1.x-1,arvores[n].y-1);
  Ponto esquerda_p0(p0.x,p0.y);
  Ponto esquerda_p1(arvores[n].x-1,p1.y);
  Ponto direita_p0(arvores[n].x+1,p0.y);
  Ponto direita_p1(p1.x,p1.y);
  
  int AreaCima = Area(cima_p0,cima_p1, n);
  int AreaBaixo = Area(baixo_p0,baixo_p1, n);
  int AreaEsquerda = Area(esquerda_p0,esquerda_p1, n);
  int AreaDireita = Area(direita_p0,direita_p1, n);
  
  int MaiorArea = max(AreaCima,AreaBaixo,AreaDireita,AreaDireita);
  }
  else {
    cout <<"oi2" <<endl;
   return Area(p0,p1,n-1);
  }
}

void Funcao (){
  cin >> L;
  cin >> A;
  cin >> qtd;
	arvores = (Arvore*)(malloc((qtd+1)*sizeof(Arvore)));

	for (int i=1;i<qtd;i++){
			cin >> arvores[i].x;
			cin >> arvores[i].y;
			//arvores[i].imprime();
	}
	
	Ponto p0(0,0);
	Ponto p1(L,A);
	cout << Area(p0,p1,qtd) <<endl;;
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

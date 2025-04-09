#include <iostream>
using namespace std;

int Origami(){
  int a,b;
  int lado=0;
  bool lado_encontrado =false;
  long long int area;
  scanf ("%d %d",&a,&b);
  area = (long long int)a*b;
  
  while (!lado_encontrado){
    if ((lado)*(lado)*4 > area){
      lado--;
      lado_encontrado=true;
    }
    else if ((lado)*(lado)*4 == area){
      lado_encontrado=true;
    } else if ((lado)*(lado)*4 < area){
      lado++;
    }
  }
  return lado;
}

int main() {
    int iteracao=0;
    int iteracaoMaxima;
    scanf("%d", &iteracaoMaxima);
    do {
        printf("%d\n",Origami());
        iteracao++;
    } while (iteracao < iteracaoMaxima);
    return 0;
}
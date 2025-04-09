#include <stdio.h>
#include <cstdlib>
using namespace std;

int count(long long int candidato, long long int * votos, int quant_votos){
  int contador = 0;
  for (int i=0;i<quant_votos;i++){
    if (votos[i]==candidato){
      contador++;
    }
  }
  return contador;
}

char ehSegundoTurno(){
  int quant_votos;
  scanf("%d",&quant_votos);
  long long int * votos = (long long int*)malloc(quant_votos*sizeof( long long int));
  
  for (int i=0;i<quant_votos;i++){
    scanf("%d",&votos[i]);   
  }
  
  for (int i=0;i<quant_votos;i++){
    float porcentagem_candidato = count(votos[i],votos,quant_votos)/(float)quant_votos;
    if (porcentagem_candidato > 0.50){
      return 'N';
    }
  }
  return 'S';

}

int main() {
    int iteracao=0;
    int iteracaoMaxima;
    scanf("%d", &iteracaoMaxima);
    do {
        printf("%c\n",ehSegundoTurno());
        iteracao++;
    } while (iteracao < iteracaoMaxima);
    return 0;
}
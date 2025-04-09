#include <stdio.h>
#include <cstdlib>
using namespace std;


void vizinhos_Max(){
  int quant_casas;
  scanf("%d",&quant_casas);
  long long int * casas = (long long int*)malloc(quant_casas*sizeof(long long int));
  for (int i=0;i<quant_casas;i++){
    scanf("%lld",&casas[i]);

 }


  long long int * inicio = &casas[0];
  long long int * final = &casas[1];
  while (inicio <= &casas[quant_casas-1]){
   //printf("%d %d\n",*inicio,*final);
    if (final > &casas[quant_casas-1]){
      *inicio = -1;
      inicio++;
      final = inicio+1;
    }
    else if (*inicio <= *final){
      *inicio = *final;
      inicio++;
      final = inicio+1;
    }
    else {
      final++;
    }
  }
 for (int i=0;i<quant_casas;i++){
   if (i<quant_casas-1)
   printf("%d ",casas[i]);
   else
   printf("%d",casas[i]);
 }
 printf("\n");
}

int main() {
    int iteracao=0;
    int iteracaoMaxima;
    scanf("%d", &iteracaoMaxima);
    do {
        vizinhos_Max();
        iteracao++;
    } while (iteracao < iteracaoMaxima);
    return 0;
}
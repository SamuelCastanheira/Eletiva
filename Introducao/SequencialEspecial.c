#include <stdio.h>
#include <stdlib.h>
 
int SequenciaEspecial()
{
    int k=1;
    int fk=1;
    int c=1;
    int f=1;
    scanf("%d",&k);
    for (int i=1; i<=k;i++){
      
    }
    
   
   
}
 
int main() {
    int iteracao=0;
    int iteracaoMaxima;
    scanf("%d", &iteracaoMaxima);
    do {
        printf("%d\n",SequenciaEspecial());
        iteracao++;
    } while (iteracao < iteracaoMaxima);
    return 0;
}

//f[i++]=fk[i]+c[i]-1
//c[i++]=c[i]+fk[i]
//fk[i++]=
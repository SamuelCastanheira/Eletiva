#include <stdio.h>
#include <stdlib.h>
 
int QuantidadeDeSomas()
{
    int quantDeNumeros;
    int somaDesejada;
    scanf("%d %d",&quantDeNumeros,&somaDesejada);
    int * numeros;
    numeros = malloc(quantDeNumeros*sizeof(int));
    for (int i=0;i<quantDeNumeros;i++){
        scanf("%d",&numeros[i]);
    }
    int quantDeSomas=0;;
    int * posInferior = &numeros[0];
    int ultimoNumeroMenorQueASoma;
    for (int i=0;i<quantDeNumeros;i++){
        if (numeros[i]<somaDesejada){
          ultimoNumeroMenorQueASoma = i;
        } 
    }
    int * posSuperior = &numeros[ultimoNumeroMenorQueASoma];
    int somaDaIteracao = somaDesejada +1;
    
    while (posInferior < posSuperior){
            somaDaIteracao = *posInferior + *posSuperior;
            //printf("%d+%d=%d",*posInferior,*posSuperior,somaDaIteracao);
            if (somaDaIteracao == somaDesejada)
            {
                quantDeSomas++;
                posInferior++;
                //printf(" Ok");
            } 
            else if (somaDaIteracao > somaDesejada){
                posSuperior--;
            }
            else {
                posInferior++;
            }
            //printf("\n");
    }
    free(numeros);
    return quantDeSomas;
}
 
int main() {
    int iteracao=0;
    int iteracaoMaxima;
    scanf("%d", &iteracaoMaxima);
    do {
        printf("%d\n",QuantidadeDeSomas());
        iteracao++;
    } while (iteracao < iteracaoMaxima);
    return 0;
}
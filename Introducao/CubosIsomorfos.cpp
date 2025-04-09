#include <iostream>
using namespace std;

class Grafo {
  public:
    int vertices[6];
    int Matriz[6][6];
  
    Grafo(){
      for (int i=0;i<6;i++){
        for (int j=0;j<6;j++){
          if (i!=j)
            Matriz[i][j]=0;
          else
            Matriz[i][j]=1;
        }  
      }
    }

    void adicionarAresta(int i, int j){
      Matriz[i][j]= 1;
      Matriz[j][i]=1;
    }

    bool verificarAresta(int i, int j){
      return Matriz[i][j];
    }
    void imprimir(){
      for (int i=0;i<6;i++){
        for (int j=0;j<6;j++){
         // printf("%d",Matriz[i][j]);
        }
       // printf("\n");
      }
    }
};


class Cubo {
  public:
    char cores[6];
    Grafo FacesVizinhas;
  
  Cubo(char cores[]){
    this->adicionarCores(cores);
    FacesVizinhas.adicionarAresta(0,1);
    FacesVizinhas.adicionarAresta(0,2);
    FacesVizinhas.adicionarAresta(0,3);
    FacesVizinhas.adicionarAresta(0,4);

    FacesVizinhas.adicionarAresta(1,2);
    FacesVizinhas.adicionarAresta(1,3);
    FacesVizinhas.adicionarAresta(1,5);
    
    FacesVizinhas.adicionarAresta(2,4);
    FacesVizinhas.adicionarAresta(2,5);

    FacesVizinhas.adicionarAresta(3,5);
    FacesVizinhas.adicionarAresta(3,4);

    FacesVizinhas.adicionarAresta(4,5);
    
  }

  void adicionarCores(char cores[]){
    for (int i=0;i<6;i++){
      this->cores[i]=cores[i];
    }
  }
};

bool verifica(bool visitado[]){
  for (int i=0;i<6;i++){
    if (visitado[i]==false){
      return  false;
    }
  }
  //printf("passou\n");
  return true;
}

bool verifica(Cubo & cubo1, Cubo & cubo2, bool visitado[],int i,int cor){
  if (verifica(visitado)){
    return true;
  } 
  else 
  {
    for (int j=0;j<6;j++){
      printf("---%d %d\n",i,j);
      if (!visitado[j] && cubo1.FacesVizinhas.verificarAresta(i,j) && cubo1.cores[j]==cubo2.cores[cor]){
        visitado[j]=true;
       // for(int i=0;i<6;i++){
        //  printf("%d",visitado[i]);
       // }
        //printf("\n");
        printf("%d %d %c \n",j,cor,cubo2.cores[cor]);
        verifica(cubo1,cubo2,visitado,j,cor+1);
        if (verifica(visitado)){
         // printf("terminou\n");
          return true;
        }
      }
    }
    visitado[i]=false;
   // printf("saiu do loop\n");
    return false;
  }
}

bool verifica(Cubo& cubo1, Cubo & cubo2){
  bool visitado[6];
  for (int i=0;i<6;i++){
    visitado[i] = false;
  }
  return verifica(cubo1,cubo2,visitado,0,0)||verifica(cubo1,cubo2,visitado,1,0)||verifica(cubo1,cubo2,visitado,2,0)||verifica(cubo1,cubo2,visitado,3,0)||verifica(cubo1,cubo2,visitado,4,0)||verifica(cubo1,cubo2,visitado,5,0);
}

char Funcao(){
  char coresCubo1[7];
  char coresCubo2[7];
  scanf("%s",coresCubo1);
  scanf("%s",coresCubo2);
  Cubo cubo1(coresCubo1);
  Cubo cubo2(coresCubo2);
  //cubo1.FacesVizinhas.imprimir();
  if (verifica(cubo1,cubo2)){
    return 'S';
  } else {
    return 'N';
  }
}
 
int main() {
    int iteracao=0;
    int iteracaoMaxima;
    scanf("%d", &iteracaoMaxima);
    do {
        printf("%c\n",Funcao());
        iteracao++;
    } while (iteracao < iteracaoMaxima);
    return 0;
}
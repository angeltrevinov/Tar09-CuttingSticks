/*
  Angel Odiel Treviño Villanueva
  A01336559
  Tarea: Tar09 - Cutting Sticks Fecha:26/feb  Materia: Analisis y Diseño de Algoritmos
*/

#include <iostream>
#include <climits>

using namespace std;

//saves the minimum value of the cost
int minimo(int i, int j, int D[100][100], int d[100]){
  int Min = INT_MAX; //initialize the min
  for(int k = i; k < j; k++){
    if(D[i][k] + D[k+1][j] < Min){//comparison to see which way is cheaper
      Min = D[i][k] + D[k+1][j];
    }
  }
  return Min +(d[j]-d[i-1]); //returns the min value
}


int MultiplicacionM(int d[100], int D[100][100], int n){
  for(int diag = 1; diag<=n+1; diag++){//to move from 1 to N+1
    for(int i = 1; i <= n+1-diag; i++){//to move with the principal diagonal
      int j = i + diag;// the position for the box
      D[i][j] = minimo(i, j, D, d); //find the minimun cost and save it in the position
    }
  }
  return D[1][n+1];
}

int main(){

  int N; //the length of the stick
  int Cut; //how many cuts there are gonna be
  int Tabla[100];
  int Adyacentes[100][100];
  while(true){
    cin >> N;
    if(N == 0){ // the user doesnt want to do more inputs
      break;
    }
    cin >> Cut;
    Tabla[0] = 0;
    for(int i = 1; i <= Cut; i++){// to store where the cuts are gonna be
      cin >> Tabla[i];
    }
    Tabla[Cut+1] = N; //store the lenght of the stick;

    // para llenar la diagonal principal
    for(int i = 1; i <= Cut; i++){
      Adyacentes[i][i] = 0;
    }
    cout  << "The minimum cutting is " <<MultiplicacionM(Tabla, Adyacentes, Cut) << "."<<endl;
  }
  return 0;
}

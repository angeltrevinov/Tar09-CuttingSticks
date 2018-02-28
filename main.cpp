/*
  Angel Odiel Treviño Villanueva
  A01336559
  Tarea: Tar09 - Cutting Sticks Fecha:26/feb  Materia: Analisis y Diseño de Algoritmos
*/

#include <iostream>

using namespace std;

int minimo(int i, int j, int D[100][100], int d[100], int n){

  /*Esta función calcula el valor mínimo entre los diversos valores de:
		D[i][k] + D[k+1][j] + d[i-1]*d[k]*d[j]
		para k desde i hasta j-1 */
}


int MultiplicacionM(int d[100], int D[100][100], int n){
  int j = 0;
  for(int diag = 1; diag<=n-1; diag++){
    for(int i = 1; i <= n-diag; i++){
      j = i + diag;
      D[i][j] = minimo(i, j, D, d, n);
    }
  }
  return D[1][n];
}

int main(){

  int N; //the length of the stick
  int Cut; //how many cuts there are gonna be

  cin >> N;
  cin >> Cut;
  int Tabla[100];
  int Adyacentes[100][100];
  Tabla[0] = 0;
  for(int i = 1; i <= Cut; i++){// to store where the cuts are gonna be
    cin >> Tabla[i];
  }
  Tabla[Cut+1] = N; //store the lenght of the stick;

  // para llenar la diagonal principal
  for(int i = 0; i <= Cut+1; i++){
    Adyacentes[i][i] = 0;
  }

  return 0;
}

/*
 * main.c
 *
 *  Created on: 25/08/2014
 *      Author: utnso
 */
#include <stdio.h>

#define CELDAS  8
#define N_SALTOS   8
#define CIERTO 1
#define FALSO  0

static int tablero_virtual[CELDAS+4][CELDAS+4];
static int dx[N_SALTOS]={ 2, 1,-1,-2,-2,-1, 1, 2};
static int dy[N_SALTOS]={ 1, 2, 2, 1,-1,-2,-2,-1};

static void crearMatriz(void);
void mostrar(void);
static int mover(int n,int x,int y);


int main(void)
{

  crearMatriz();
  if(mover(1,2,2))
    printf("Aca ta");
  else
    printf("deadlock jaja");
  mostrar();
  return 0;
}

static void crearMatriz(void)
{
  int i,j;
  for(i=0;i<CELDAS+4;i++) {
    for(j=0;j<CELDAS+4;j++) {
      if(i>1 && i<CELDAS+2 && j>1 && j<CELDAS+2 )
           tablero_virtual[i][j]=0;
      else
           tablero_virtual[i][j]=-1;
    }
  }

}

void mostrar(void)
{
  int i,j;

  for(i=0;i<CELDAS+4;i++) {
     printf("\n");
     for(j=0;j<CELDAS+4;j++) {
        if(tablero_virtual[i][j]!=-1)
         printf("%4d",tablero_virtual[i][j]);
     }
  }
  return;
}

static int mover(int n,int x,int y)
{
  int i,u,v;
  tablero_virtual[x][y]=n;
  if(n==(CELDAS*CELDAS))
      return CIERTO;
  else {
    for(i=0;i<N_SALTOS;i++) {
      u=x+dx[i];
      v=y+dy[i];
      if(tablero_virtual[u][v]==0) {
        if(mover(n+1,u,v))
          return CIERTO;
      }
   }
  }
  tablero_virtual[x][y]=0;
  return FALSO;
}


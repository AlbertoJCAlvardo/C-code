#include<stdio.h>
#include<stdlib.h>
#define true 1
#define false 0
char ***crearSoluciones(int,int,int);
void liberarMatriz(char**,int);
void liberarSoluciones(char***,int,int);
int atacar(char**,int,int);
int ochoReinas(char***,char**,int,int*);
char **crearTablero(int,int);
int verificarExistencia(int***,int**);
void imprimirSolucion(char**);
int Existencia(char***,char**);
char **

int main(void){
  char **tablero=NULL, ***soluciones=NULL;
  int reinas=0,conta=0;	
  printf("\tOCHO REINAS\n\n");
  soluciones=crearSoluciones(8,8,100);
  tablero=crearTablero(8,8);
  for(int i=0;i<8;i++)   
   for(int j=0;j<8;j++)
    tablero[i][j]='0';
   imprimirSolucion(tablero);
  ochoReinas(soluciones,tablero,reinas,&conta);
  return 636; 	
}

int ochoReinas(char ***soluciones,char **tablero,int reinas,int *conta){
	int i=0,j=0;
	if(reinas==8){
	 reinas=0;	
	 (*conta)++;
     	 printf("\n%d. Solucion encontrada   \n",*conta);

	 }
         

	for(i=0;i<8;i++){
	   if(atacar(tablero,reinas,i)==false){
	    tablero[reinas][i]='R';
	    int bandera=ochoReinas(soluciones,tablero,reinas+1,conta);
              if(bandera==true)
	      return true;
	      tablero[reinas][i]='0';
             }
             
	 
         }
	
}
char ***crearSoluciones(int m,int n,int k){
	int i=0,j=0;
	char ***cubo=NULL;
	if(cubo!=NULL)
	 return NULL;
	cubo=(char***)malloc(k*sizeof(char**));
	
	for(i=0;i<n;i++){
	  cubo[i]=(char**)malloc(n*sizeof(char*));
	  for(j=0;j<m;j++){
	    cubo[i][j]=(char*)malloc(m*sizeof(char));	
	  }	
	}
    printf("\nCubo creado");
    return cubo;
    	
}
int atacar(char **matriz,int fila,int columna){

   int i=0,j=0;
   
   for(i=0;i<8;i++){
     if(matriz[fila][i]!='0')
      return true; 
    }
   for(i=0;i<8;i++){
   
    if(matriz[i][columna]!='0')
     return true;
     }
     
    for(i=fila, j=columna;i>=0&&j>=0;i--, j--){	
     if(matriz[i][j]!='0')
      return true;
     }
      
     for(i=fila, j=columna;i<8 && j <8;i++, j++){	
     if(matriz[i][j]!='0')
      return true;
      }
      
       for(i=fila, j=columna; i>=0&&j<8;i--, j++){	
       if(matriz[i][j]!='0')
      return true;
      }
     
      
      for(i=fila, j=columna; i<8&&j>=0 ;i++, j--){
       if(matriz[i][j]!='0'){
         return true;        
       }
      }
     return false; 
}

void liberarMatriz(char** mat,int m){
   int i=0;
  if(mat!=NULL){
   for(i=0;i<m;i++)
   free(mat[i]);
   free(mat);	
}
}
void liberarSoluciones(char ***volumen,int m,int k){
   int i=0,j=0;
  if(volumen!=NULL){
   for(i=0;i<k;i++){
    for(j=0;j<m;j++)
     free(volumen[i][j]);	
   free(volumen[i]);
   }
   free(volumen);
}
}
char** crearTablero(int m,int n){
    char **Matriz=NULL;
    int i=0;
    Matriz=(char**)malloc(m*sizeof(char*));
    for(i=0;i<n;i++)
     Matriz[i]=(char*)malloc(n*sizeof(char));
     
    return Matriz;
    
    	
}
void imprimirSolucion(char **mat){
  int i=0,j=0;
  for(i=0;i<8;i++){
    for(j=0;j<8;j++)
     printf("   %c",mat[i][j]);	
  printf("\n\n");	
  }
}
int Existencia(char ***soluciones,char **mat){
	
}

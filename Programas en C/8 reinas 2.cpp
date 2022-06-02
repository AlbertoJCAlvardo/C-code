#include<stdio.h>
#include<stdlib.h>
#define true 1
#define false 0

char ***crearSoluciones(int,int,int);
void liberarMatriz(char**,int);
int igualarMatrices(int,char***,char**);
void liberarSoluciones(char***,int,int);
int atacar(char**,int,int);
int ochoReinas(char***,char**,int,int*);
char **crearTablero(int,int);
int verificarExistencia(char***,char**);
void imprimirSolucion(char**);
int igualdad(char**,char**);

int main(void){
  char **tablero=NULL, ***soluciones=NULL;
  int reinas=0,conta=0;	
  printf("\tOCHO REINAS\n\n");
  soluciones=crearSoluciones(100,8,8);
  tablero=crearTablero(8,8);
  
  
   for(int l=0;l<100;l++)
    for(int i=0;i<8;i++)   
   for(int j=0;j<8;j++)
    soluciones[l][i][j]='0';
  for(int i=0;i<8;i++)   
   for(int j=0;j<8;j++)
    tablero[i][j]='0';
    
  ochoReinas(soluciones,tablero,reinas,&conta);
  for(int i=0;i<8;i++)   
   for(int j=0;j<8;j++)
    tablero[i][j]='0';
  for(int i=0;i<100;i++){
   if(igualdad(soluciones[i],tablero)==false){
    printf("Solucion  %d.\n\n",i+1);
    imprimirSolucion(soluciones[i]);
    printf("\n---------------------------------------\n");
    }
  }
  int laca=0;
  printf("Algo más?  ");
  scanf("%d",&laca);
  if(laca==1)
   return 636; 	
}

int ochoReinas(char ***soluciones,char **tablero,int reinas,int *conta){
	int i=0,j=0,x=0;
	if(reinas==8){
	 reinas=0;
	 if(verificarExistencia(soluciones,tablero)==false){
	  for(i=0;i<8;i++)
	   for(j=0;j<8;j++)
	    soluciones[*conta][i][j]=tablero[i][j];
	 
	   (*conta)++;       
            }
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
	cubo=(char***)malloc(100*sizeof(char**));
	
	for(i=0;i<100;i++){
	  cubo[i]=(char**)malloc(8*sizeof(char*));
	  for(j=0;j<8;j++){
	    cubo[i][j]=(char*)malloc(8*sizeof(char));	
	  }	
	}
   
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
int verificarExistencia(char ***soluciones,char **mat){
  char **tr=NULL;
  tr=crearTablero(8,8);

  int i=0,j=0,l=0,k=0,x=1;
 printf("\nlvl  %d",x);
    x++;
    //1
  for(i=0;i<100;i++){
      if(igualdad(mat,soluciones[i])==true)
      return true;	
    }  
    for(i=7;i>=0;i--){
    l=0;
    for(j=7;j>=0;j--){
     tr[j][i]=mat[i][j];
       l++;
      }
      k++;
     }
     

     k=0;
     printf("\nlvl  %d",x);
    x++;
    //2
     for(i=0;i<100;i++){
      if(igualdad(tr,soluciones[i])==true)
      return true;	
    } 
    //3 
     for(i=7;i>=0;i--){
    l=0;
    for(j=7;j>=0;j--){
     tr[k][l]=mat[i][j];
       l++;
      }
      k++;
     }
      

     k=0;
     printf("\nlvl  %d",x);
    x++;
     for(i=0;i<100;i++){
      if(igualdad(tr,soluciones[i])==true)
      return true;	
    }  
    //4
    for(i=7;i>=0;i--){
    l=0;
    for(j=7;j>=0;j--){
     tr[l][k]=mat[i][j];
       l++;
      }
      k++;
     }
 
    
      k=0;
    for(i=0;i<100;i++){
      if(igualdad(tr,soluciones[i])==true)
      return true;	
    } 
    printf("\nlvl  %d",x);
    x++; 
    //5
    for(i=7;i>=0;i--){
    l=0;
    for(j=7;j>=0;j--){
     tr[l][l]=mat[i][j];
       l++;
      }
      k++;
     }
     k=0;
     for(i=0;i<100;i++){
      if(igualdad(tr,soluciones[i])==true)
        return true;	
    }  
    
    printf("\nlvl  %d",x);
    x++;
    for(i=7;i>=0;i--){
    l=0;
    for(j=7;j>=0;j--){
     tr[k][k]=mat[i][j];
       l++;
      }
      k++;
     }
     for(i=0;i<100;i++){
      if(igualdad(tr,soluciones[i])==true)
      return true;
      
    } 
   
     k=7;
       l=7;
     for(i=0;i<4;i++){
      k=7;	
      for(j=0;j<8;j++){
       tr[l][j]=mat[i][j];
       tr[i][j]=mat[i][j];    
       k--;
      }
      l--;
     }
     for(i=0;i<100;i++){
      if(igualdad(tr,soluciones[i])==true)
      return true;
      
    } 
     k=7;
       l=7;
     for(i=0;i<4;i++){
      k=7;	
      for(j=0;j<8;j++){
       tr[j][l]=mat[i][j];
       tr[j][i]=mat[i][j];    
       k--;
      }
      l--;
     }
     for(i=0;i<100;i++){
      if(igualdad(tr,soluciones[i])==true)
      return true;
      
    } 
     
   return false;
  	
}
int igualdad(char **m1,char **m2){
   int i=0,j=0,count=0;
   for(i=0;i<8;i++){
     for(j=0;j<8;j++)
      if(m1[i][j]==m2[i][j])
       count++; 
      	
   }
   if(count==64){
    
    return true;
    }
 
   return false;	
}

int igualarMatricies(int x,char ***solu,char **m1){
   int i=0,j=0;
   if(solu==NULL||m1==NULL)
    return false;
  for(i=0;i<8;i++)
    for(j=0;j<8;j++)
     
     solu[x][i][j]=m1[i][j]; for(i=0;i<8;i++)
    for(j=0;j<8;j++)
     
     solu[x][i][j]=m1[i][j];
    return true; 


}

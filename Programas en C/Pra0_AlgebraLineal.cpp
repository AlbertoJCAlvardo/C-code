#include<stdio.h>
#include<stdlib.h>
int** sumaMatrices(void);
int* sumaVectores(void);
int** productoMatrices(void);
int  productoPuntoVectores(void);
int* productoPuntoMatrizVector(void);
int* crearVector(int);
int* leerVector(int*,int);
int** crearMatriz(int ,int);
int** leerMatriz(int**,int ,int);
void imprimirMatriz(int**,int,int,int);
void liberarMatriz(int**,int);
void liberarVector(int*);
int main(void){
 int opcion=0,iterar=0,**mat,*vec;
 do{
  printf("Libreria de Algebra Lineal\n");
  printf("Que desea hacer?\n1)Sumar Vectores\n2)Sumar Matrices\n3)Producto de Vectores\n4)Producto de Matrices\n5)Producto Matriz-Vector Producto Punto\n");
  scanf("%d",&opcion);
  system("cls");
  switch(opcion){
    case 1:
           vec=sumaVectores();
           liberarVector(vec);
    break;
    case 2:
        	 mat=sumaMatrices();
        	 
    break;
    case 3:
          productoPuntoVectores();
    break;
    case 4:
          mat=productoMatrices();

    break;
    case 5: 
           vec=productoPuntoMatrizVector();
           liberarVector(vec);
    break;
    default:
   	printf("\nOpcion Incorrecta, vuelva a intentarlo.");
   	iterar=1;
    break;
   }
   printf("\nDesea finalizar?\n 0)Si\t1)No");
   scanf("%d",&iterar);
   system("cls");
  }
  while(iterar==1); 
}
int** sumaMatrices(void){
    int **Matriz1=NULL,**Matriz2=NULL,**MatrizResultado=NULL,i=0,j=0,filas=0,columnas=0;
    printf("Inserte las dimensiones de Ambas Matrices:\n");
    printf("Filas:");
    scanf("%d",&filas);
    printf("Columnas:");
    scanf("%d",&columnas);
    Matriz1=crearMatriz(columnas ,filas);
    Matriz1=leerMatriz(Matriz1,filas,columnas);
    Matriz2=crearMatriz(filas,columnas);
    Matriz2=leerMatriz(Matriz2,filas,columnas);
    MatrizResultado=crearMatriz(filas,columnas);
    
    system("cls");
    if(Matriz1==NULL||Matriz2==NULL||MatrizResultado==NULL)
    return NULL;
    imprimirMatriz(Matriz1,filas,columnas,1);
    printf("            +\n");
    imprimirMatriz(Matriz2,filas,columnas,2);
    printf("Resultado:\n");
    for(i=0;i<filas;i++){
      for(j=0;j<columnas;j++){
      	MatrizResultado[i][j]=Matriz1[i][j]+Matriz2[i][j];
      	printf("%d     ",MatrizResultado[i][j]);
      }
      printf("\n");	
    }
    liberarMatriz(Matriz1,filas);
    liberarMatriz(Matriz2,filas);
    return MatrizResultado;	
}
int* sumaVectores(void){
     int *Vector1=NULL,*Vector2=NULL,*VectorResultado=NULL,i=0,filas=0;
    printf("Inserte las dimensiones de Ambos Vectores:\n");
    scanf("%d",&filas);
    Vector1=crearVector(filas);
    Vector1=leerVector(Vector1,filas);
    Vector2=crearVector(filas);
    Vector2=leerVector(Vector2,filas);
    VectorResultado=crearVector(filas);
    system("cls");
    if(Vector1==NULL||Vector2==NULL||VectorResultado==NULL)
    return NULL;
    printf("Vector Resultado:\n");
    for(i=0;i<filas;i++){
      	VectorResultado[i]=Vector1[i]+Vector2[i];
      	printf("%d     ",VectorResultado[i]);
      	
    }
    liberarVector(Vector1);
    liberarVector(Vector2);
    return VectorResultado;	
}
int** productoMatrices(void){
 int **Matriz1=NULL,**Matriz2=NULL,**MatrizResultado=NULL,i=0,j=0,fc=0,columnas2=0,filas1=0;
    printf("Inserte las dimensiones de Ambas Matrices:\n");
    printf("Filas de la Matriz 2 y Columnas de la Matriz 1:");
    scanf("%d",&fc);
    printf("Columnas de la Matriz 2:");
    scanf("%d",&columnas2);
    printf("Filas de la Matriz 1:");
    scanf("%d",&filas1);
    Matriz1=crearMatriz(columnas2,fc);
    Matriz1=leerMatriz(Matriz1,columnas2,fc);
    Matriz2=crearMatriz(fc,filas1);
    Matriz2=leerMatriz(Matriz2,fc,filas1);
    MatrizResultado=crearMatriz(filas1,columnas2);
    system("cls");
    imprimirMatriz(Matriz1,columnas2,fc,1);
    imprimirMatriz(Matriz2,fc,filas1,2);
    if(Matriz1==NULL||Matriz2==NULL||MatrizResultado==NULL)
     return(NULL);
    int aux=0,l=0,k=0;
    printf("\nResultado:\n");
    for(i=0;i<filas1;i++){
     for(j=0;j<columnas2;j++){
     	for(k=0;k<fc;k++){
     	  aux=((Matriz1[i][k])*(Matriz2[k][j]))+aux;
	}
     	MatrizResultado[i][j]=aux;
     	printf("%d    ",MatrizResultado[i][j]);
     	aux=0;
      }
     printf("\n\n");	
    }
    liberarMatriz(Matriz1,filas1);
    liberarMatriz(Matriz2,fc);
    	
}
int productoPuntoVectores(void){
  int *Vector1=NULL,*Vector2=NULL,escalar=0,i=0,filas=0;
    printf("Inserte las dimensiones de Ambos Vectores:\n");
    scanf("%d",&filas);
    Vector1=crearVector(filas);
    Vector1=leerVector(Vector1,filas);
    Vector2=crearVector(filas);
    Vector2=leerVector(Vector2,filas);
    system("cls");
    if(Vector1==NULL||Vector2==NULL)
    return NULL;
    for(i=0;i<filas;i++){
      	escalar =Vector1[i]*Vector2[i]+escalar;
      	
    }
    printf("\nEscalar: %d",escalar);
    liberarVector(Vector1);
    liberarVector(Vector2);
    return escalar;
}
int* productoPuntoMatrizVector(void){
  int **Matriz=NULL,*Vector=NULL,*VectorResultado=NULL,i=0,j=0,fc=0,columnas=0;
    printf("Inserte las dimensiones de la Matriz y el Vector:\n");
    printf("Columnas de la Matriz  y Filas del Vector:");
    scanf("%d",&fc);
    printf("Filas de la Matriz:");
    scanf("%d",&columnas);
    Matriz=crearMatriz(columnas,fc);
    Matriz=leerMatriz(Matriz,columnas,fc);
    Vector=crearVector(fc);
    Vector=leerVector(Vector,fc);
    VectorResultado=crearVector(columnas);
    system("cls");
    if(Matriz==NULL||Vector==NULL||VectorResultado==NULL)
     return(NULL);
    int aux=0,k=0;
    for(i=0;i<columnas;i++){
         for(k=0;k<fc;k++)
     	aux=(Matriz[i][k]*Vector[k])+aux;
     	VectorResultado[i]=aux;
     	printf("%d    ",VectorResultado[i]);
     	aux=0;
    }
    liberarMatriz(Matriz,columnas);
    liberarVector(Vector);
    return VectorResultado;
}
int* crearVector(int largo){
  int *vector=NULL,i=0;
  vector=(int*)malloc(largo*sizeof(int));
  return vector;
}
int* leerVector(int* vec, int largo){
 for(int i=0;i<largo;i++){
   printf("Posicion %d:",i+1);
   scanf("%d",&vec[i]);
   printf("\n");	
  }
  system("cls");
  return vec;	
}
int** crearMatriz(int fil ,int col){
  int **mat=NULL,i=0,j=0;
  mat=(int**)malloc(fil*sizeof(int*));
  for(i=0;i<fil;i++){
    mat[i]=(int*)malloc(col*sizeof(int));	
   }
  return mat;
}
int** leerMatriz(int** mat,int fil, int col){
  for(int i=0;i<fil;i++){
    for(int j=0;j<col;j++){
      printf("\nPosicion (%d,%d):",i+1,j+1);
      scanf("%d",&mat[i][j]);	
    }
    system("cls");	
  }	
  system("cls");
  return mat;	
}
void liberarMatriz(int **mat,int filas){
 int i=0;
  if(mat!=NULL){
   for(i=0;i<filas;i++)
   free(mat[i]);
   free(mat);	
  }
}
void liberarVector(int* vec){
   if(vec!=NULL)
   free(vec);	
}
void imprimirMatriz(int** mat,int a,int b,int c){
   int i=0,j=0;
   printf("Matriz %d:\n",c);
  for(i=0;i<a;i++){
   for(j=0;j<b;j++){
     printf("%d  ",mat[i][j]);	
   }
   printf("\n\n");
   	
}
}

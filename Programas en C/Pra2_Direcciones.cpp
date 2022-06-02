#include<stdio.h>
#include<stdlib.h>
int* crearVector(int);
int* llenarVector(int*,int);
int* direccionVector(int*);
int* direccionCelda(int*,int);
void destruirVector(int*);
int main(void){
  int *vector=NULL,nN=0,*y=NULL;	
  printf("Esta practica tiene un uso meramente didactico :^).\n");
  printf("Dimension del vector didactico:");
  scanf("%d",&nN);
  printf("1) Direccion de memoria del apuntador: %X\n\n",&vector);
  vector=crearVector(nN);
  vector=llenarVector(vector,nN);
  y=direccionVector(vector);
  printf("2) Direccion de memoria del Vector:  %X\n\n",y);
  printf("3) Direccion de memoria de cada celda:\n\n\n");
  y=direccionCelda(vector,nN);
  destruirVector(vector);
  printf("\nFin del programa didactico");
  return 0;
}
int* crearVector(int nN){
  int *vector,i=0;
  vector=(int*)malloc(nN*sizeof(int));
  return vector;	
}
int* llenarVector(int* vector,int nN){
  int i=0;
  if(vector==NULL)
  return NULL;
  for(i=0;i<nN;i++){
    vector[i]=i;	
  }
  return vector;	
}
int* direccionVector(int* vector){
  int y=NULL;
  y=*vector;
  return &y;	
}
int* direccionCelda(int* vector,int nN){
  int *y=NULL,i=0;
  for(i=0;i<nN;i++){
    y=&(vector[i]);
    printf("\nDireccion de la celda %d:  %X",i+1,y);	
  }
  return y;	
}
void destruirVector(int* vector){
  if(vector==NULL)
  return;
  free(vector);
  printf("\n\nMemoria liberada adecuadamente.\n");	
}

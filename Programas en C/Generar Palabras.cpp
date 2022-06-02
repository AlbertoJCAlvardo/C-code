#include<stdio.h>
#include<stdlib.h>
char *crearVector(int);
void destruirVector(char*);
char *generarPalabra(int,int,char*,char*,int*);
void imprimirPalabra(char*,int);
int main(void){
  int i=0,l=0,nivel=0,iter=1;
  char *letras=NULL,*palabra=NULL;
  printf("\tGENERADOR DE PALABRAS SIN COHERENCIA Y ALGUNAS CON COHERENCIA\n");
  letras=crearVector(6); 
  for(i=0;i<6;i++){
   printf("\nIngrese letra %d:",i+1);
   scanf(" %c",&letras[i]);	
  }
  
  printf("\nIngrese la longitud de la palabra (Mayor o igual a 6):   ");
  scanf("%d",&l);
   system("cls");
   imprimirPalabra(letras,6);
  printf("\n");
  palabra=crearVector(l);
  palabra=generarPalabra(l,nivel,letras,palabra,&iter);
  destruirVector(letras);
  destruirVector(palabra);	
  return 666;
}
char *generarPalabra(int l,int nivel,char *letras,char *palabra,int *iter){
   int i=0;
   char letra;
   if(nivel==l){
     (*iter)++;
     printf("\n\n%d.",*iter);
     imprimirPalabra(palabra,l);
     return palabra;	
   }
   for(i=0;i<6;i++){
     letra=letras[i];
     palabra[nivel]=letra;
     generarPalabra(l,nivel+1,letras,palabra,iter);	
   }
   	
}
char *crearVector(int l){
  int i=0;
  char *vector=NULL;
  vector=(char*)malloc(l*sizeof(char));
  return vector;	
}
void destruirVector(char *vector){
  if(vector==NULL)
   return;
   free(vector);
   return;
}
void imprimirPalabra(char *palabra,int l){
  int i=0;
  for(i=0;i<l;i++){
   printf("  %c",palabra[i]);	
  }
  return;	
}


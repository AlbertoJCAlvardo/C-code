#include<math.h>
#include<stdio.h>
int arbolRecursivo(int,int,int,int);

int main(void){
   int ramas=0,nodo=0,profundidad=0,point=0;
   printf("Dime cuantas ramas quieres en tu arbol:\n");
   scanf("%d",&ramas);
   point=0;
   printf("\Profundidad:\n");
   scanf("%d",&profundidad);
   
   printf("\nRamas: %d  \nProfundidad %d",ramas,profundidad);
   arbolRecursivo(ramas,nodo,profundidad,0);
   
}
int arbolRecursivo(int ramas,int nodo,int profundidad,int l){
  if(l==profundidad)
   return 0;
  printf("\nNodo:%d  Nivel:%d\n",nodo,Nivel); 
  
  
}



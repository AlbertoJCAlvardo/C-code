#include<stdio.h>
#include<stdlib.h>
void iteraciones(int,int*);
int main(void){
  int n=0,d=0;	
  printf("Hola:\n");
  scanf("%d",&n);
  iteraciones(n,&d);	
}
void iteraciones(int n,int* i){
  int x=0,y=*i;
  if(x==n)
   return;
   y++;
  printf("%d. Hola\n",y);
  iteraciones(n-1,&y);
}

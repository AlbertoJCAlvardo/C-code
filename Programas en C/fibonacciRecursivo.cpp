#include<stdio.h>
int fibonacci(int);
int main(void){
  int nN=0,res=0;
  printf("Numero de la serie que se desea conocer:");
  scanf("%d",&nN);
  res=fibonacci(nN);
  printf("\nNumero: %d\n",res);
  for(int i=0;i<=nN;i++){
    printf("%d  ",fibonacci(i));	
  }	
}
int fibonacci(int nN){
  int i=0,res=0;
  if(nN==0)
    return 0;
 if(nN==1){
  return 1;	
 }
 return res=(fibonacci(nN-1)+fibonacci(nN-2));
 	
}

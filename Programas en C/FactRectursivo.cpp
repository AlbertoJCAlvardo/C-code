#include<stdio.h>
int fact(int);
int main(void){
  int nN=0,res=0;
  printf("Numero que deseamos saber su factorial:");
  scanf("%d",&nN);
  res=fact(nN);
  printf("\nFactorial: %d",res);
  	
}
int fact(int nN){
  long int res=nN;
  if(nN==1)
  return res;
 res=fact(nN-1)*res;	
}

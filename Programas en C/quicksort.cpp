#include<stdio.h>
int main(void){
 int arr[10],i,j,piv,der,izq;
 for(i=0;i<10;i++){
 	printf("%d: ",i+1);
 	scanf("%d",&arr[i]);
 }
 j=9;
 int k=0;
 piv=arr[i];
 piv=arr[0];
 for(i=0;i<10;i++){
   der=arr[i];
   izq=arr[j];
   if(piv<izq){
     piv=der;
     j--;	
   }
   if(piv>izq){
     piv=izq;
     arr[i]=arr[j];
     arr[j]=piv;
   }
   if(i==j){
   	
    for(int m=0;m<j;m++){
     der=arr[m];
   izq=arr[j];
   if(der<izq){
     piv=der;
     j--;	
   }
   if(der>izq){
     piv=izq;
     arr[j]=arr[m];
     arr[m]=piv;
   }
   	
    }
    j=10;
    for(int m=i;m<10;m++){
     der=arr[m];
   izq=arr[j];
   if(der<izq){
     piv=der;
     j--;	
   }
   if(der>izq){
     piv=izq;
     arr[j]=arr[m];
     arr[m]=piv;
   }
   	
    }	
   }
 }
 printf("\nOrdenados:\n");
 for(i=0;i<10;i++){
   printf("%d ",arr[i]);
 }
}

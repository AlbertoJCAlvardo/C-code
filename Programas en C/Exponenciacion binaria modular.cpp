#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main(void){
	int x,a,m,i=0,l=0,num,nox,b,conv,bina[40];
	char n[10];
	printf("Numero a:\n");
	scanf("%d",&a);
	printf("Potencia n:\n");
	scanf("%s",&n);
	fflush(stdin);
	printf("Numero del modulo:\n");
	scanf("%d",&m);
	num=atof(n);
	nox=num;
	
	while(b!=1){	
	 conv=(num/2);
	 if(conv==0){
	 	b=1;
	 }
	 bina[i]=num-(conv*2);
	 num=conv;
	 	
	 i++;
	 l++;
	}
	x=1;
	i=l-1;
	while(b!=0){
	  if(i==0){
	  	b=0;
	  }	
	  switch(bina[i]){
	  	case 0:
		  x=(x*x)%m;
		break;
		case 1:
		  x=(x*x)%m;
		  x=(a*x)%m;
		 break;    
	  }
	  i--;
   }
		printf("(%d)^%d mod %d= %d",a,nox,m,x);
		
		
		
}

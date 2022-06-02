#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int convierte(char ala){
	int num,re;
	switch(ala){
	case 'A':
		re=10;
	break;
	case 'a':
		re=10;
	break;
	case 'B':
		re=11;
	break;
	case 'b':
		re=11;
	break;
	case 'C':
		re=12;
	break;
	case 'c':
		re=12;
	break;
	case 'D':
		re=13;
	break;
	case 'd':
		re=13;
	break;
	case 'E':
		re=14;
	break;
	case 'e':
		re=14;
	break;
	case 'F':
		re=15;
	break;
	case 'f':
		re=15;
	break;
	case 'G':
		re=16;
	break;
	case 'g':
		re=16;
	break;
	case 'H':
		re=17;
	break;
	case 'h':
		re=17;
	break;
	case 'I':
		re=18;
	break;
	case 'i':
		re=18;
	break;
	case 'J':
		re=19;
	break;
	case 'j':
		re=19;
	break;
	case 'K':
		re=20;
	break;
	case 'k':
		re=20;
	break;
	case 'L':
		re=21;
	break;
	case 'l':
		re=22;
	break;
	case 'M':
		re=23;
	break;
	case 'm':
		re=23;
	break;
	case 'N':
		re=24;
	break;
	case 'n':
		re=24;
	break;
	case 'P':
		re=25;
	break;
	case 'p':
		re=25;
	break;
	case 'Q':
		re=26;
	break;
	case 'q':
		re=26;
	break;
	case 'R':
		re=27;
	break;
	case 'r':
		re=27;
	break;
	case 'S':
		re=28;
	break;
	case 's':
		re=28;
	break;
	case 'T':
		re=29;
	break;
	case 't':
		re=29;
	break;
	case 'U':
		re=30;
	break;
	case 'u':
		re=30;
	break;
	case 'V':
		re=31;
	break;
	case 'v':
		re=31;
	break;
	case 'W':
		re=32;
	break;
	case 'w':
		re=32;
	break;
	case 'X':
		re=33;
	break;
	case 'x':
		re=33;
	break;
	case 'Y':
		re=34;
	break;
	case 'y':
		re=34;
	break;
	case 'Z':
		re=35;
	break;
	case 'z':
		re=35;
	break;
	case '1':	
	num=ala;
	re=num-48;
	break;
	case '2':	
	num=ala;
	re=num-48;
	break;
	case '3':	
	num=ala;
	re=num-48;
	break;
	case '4':	
	num=ala;
	re=num-48;
	break;
	case '5':	
	num=ala;
	re=num-48;
	break;
	case '6':	
	num=ala;
	re=num-48;
	break;
	case '7':	
	num=ala;
	re=num-48;
	break;
	case '8':	
	num=ala;
	re=num-48;
	break;
	case '9':	
	num=ala;
	re=num-48;
	break;
	default:
		exit(0);
	break;	
    }
	return re;
}
char nchar(int v){
   char re;
   switch(v){
   	 case 1:
   	 	re='1';
   	 break;
		case 2:
   	 	re='2';
   	 break;	
   	 case 3:
   	 	re='3';
   	 break;
   	 case 4:
   	 	re='4';
   	 break;
   	 case 5:
   	 	re='5';
   	 break;
   	 case 6:
   	 	re='6';
   	 break;
   	 case 7:
   	 	re='7';
   	 break;
   	 case 8:
   	 	re='8';
   	 break;
   	 case 9:
   	 	re='9';
   	 break;
   	 case 10:
   	 	re='A';
   	 break;
   	 case 11:
   	 	re='B';
   	 break;
   	 case 12:
   	 	re='C';
   	 break;
   	 case 13:
   	 	re='D';
   	 break;
   	 case 14:
   	 	re='E';
   	 break;
   	 case 15:
   	 	re='F';
   	 break;
   	 case 16:
   	 	re='G';
   	 break;
   	 case 17:
   	 	re='H';
   	 break;
   	 case 18:
   	 	re='I';
   	 break;
   	 case 19:
   	 	re='J';
   	 break;
   	 case 20:
   	 	re='K';
   	 break;
   	 case 21:
   	 	re='L';
   	 break;
   	 case 22:
   	 	re='M';
   	 break;
   	 case 23:
   	 	re='N';
   	 break;
   	 case 24:
   	 	re='O';
   	 break;
   	 case 25:
   	 	re='P';
   	 break;
   	 case 26:
   	 	re='Q';
   	 break;
   	 case 27:
   	 	re='R';
   	 break;
   	 case 28:
   	 	re='S';
   	 break;
   	 case 29:
   	 	re='T';
   	 break;
   	 case 30:
   	 	re='U';
   	 break;
   	 case 31:
   	 	re='V';
   	 break;
   	 case 32:
   	 	re='W';
   	 break;
   	 case 33:
   	 	re='X';
   	 break;
   	 case 34:
   	 	re='Y';
   	 break;
   	 case 35:
   	 	re='Z';
   	 break;
   	 
   }
   return re;
}
int main(void){
	long int i=0,j,largo2=0,num=0,base,b1,largo,x,a,b=0,c=0,var;
	char numero[30],digitos[200];
	printf("Dame tu numero:\n");
	scanf("%s",&numero);
	fflush(stdin);
	printf("Dime la base en la que esta:\n");
	scanf("%d",&b1);
	printf("Dime la base a la que quieres cambiarlo:\n");
	scanf("%d",&base);
	if(b1<37&& b1>1 && base>1 &&base<37){

	largo=strlen(numero);
	j=largo-1;
	while(c!=1){
	 if(j==0){
	 	c=1;
	 }
	 a=convierte(numero[j]);
	 if(a>b1){
	 	printf("Error");
	 	exit(0);
	 }
	 var=a*pow(b1,i);
	 num=num+var;
	 j--;
	 i++;	
	}
	i=0;
	while(b!=1){	
	 x=(num/base);
	 if(x==0){
	 	b=1;
	 }
	 c=num-(x*base);
	 digitos[i]=nchar(c);
	 num=x;	
	 i++;
	 largo2++;
	 
	}
	printf("\nEn base %d el valor absoluto de su numero es:\n",base);
	
	i=largo2-1;
	while(b!=0){
	  if(i==0)
	{
		b=0;
	}	
	 printf("%c",digitos[i]);
	 i=i-1;
	}
  }
  else{
  	printf("Solo bases de 2 a 36\nVuelva a intentarlo");
  	exit(0);
  }
  
}

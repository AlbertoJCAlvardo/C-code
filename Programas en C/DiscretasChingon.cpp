#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int ReadInt(){
  int n, i = 0;
  char *end;
  char buf[11];

  do {
      if (i > 0)
       printf("(ERROR: Ingrese solo enteros. Intentelo nuevamente)\n");

       if (!fgets(buf, sizeof buf, stdin))
          break;
       // remove \n
       buf[strlen(buf) - 1] = 0;

       n = strtol(buf, &end, 10);

      i++;
  } while (end != buf + strlen(buf));
  return n;
}

//Algoritmo division
void AlgoritmoDivision(){
  int a, b, q, r;
	char *e;
	char buf[12];

  q = 0;
		printf("a = ");
		a = ReadInt();
		printf("b = ");
		b = ReadInt();

		if (b != 0){
		if(a>=0){
			if(b>0){//caso 1
				r=a;
				while(r>=b){
					r=r-b;
					q++;
				}
				printf("q=%d\n",q);
				printf("r=%d\n",r);
			}
			else{//caso 2
				b=b*-1;
				r=a;
				while(r>=b){
					r=r-b;
					q--;
				}
				printf("q=%d\n",q);
				printf("r=%d\n",r);
				b *= -1;
			}
			if(b==0){
				printf("se indetermina");
			}
		}
		else{
			if(b>0){//caso 3
				r=a;
				while(r<0){
					r=r+b;
					q--;
				}
				printf("q=%d\n",q);
				printf("r=%d\n",r);
			}
			else{//caso 4
				b=b*-1;
				r=a;
				while(r<0){
					r=r+b;
					q++;
				}
				printf("q=%d\n",q);
				printf("r=%d\n",r);
				b *= -1;
			}
		}

		printf("%d = %d(%d) + %d\n",  a, b, q, r);
		printf("Comprobacion: a = %d | R = %d\n\n", a, b*q+r);


		}
		else
			printf("ERROR: Indeterminacion\n\n");
}

//Cambio Base
int minBase(int no){
  int max, cur = 0, num = no;
  int des[11];

  while (num != 0){
      num /= 10;
      cur++;
  }

  int numberArray[cur];
  cur = 0;
  num = no;

  while (num != 0){
      numberArray[cur] = num % 10;
      num /= 10;
      cur++;
  }

  max = numberArray[0];
  for (int i = 0; i < cur; i++)
    if (max <= numberArray[i])
      max = numberArray[i];

  return max++;
}
int convierte(char ala){
	int num,re;
	num=ala;
	re=num-48;
	return re;
}
void CambioBase(){
  long int i=0,j,largo2=0,num=0,base,b1,digitos[200],largo,x,a,b=0,c=0,var, res, cen = 0;
	char numero[30];
	printf("Dame tu numero:\n");
    res = ReadInt();
	sprintf(numero, "%d", res);
	fflush(stdin);
	printf("Dime la base en la que esta:\n");
  do{
    if (cen > 0)
      printf("La base debe ser mayor a %d. Intentelo nuevamente: ", minBase(res));

	   b1 = ReadInt();
     cen = 1;
  } while (b1 <= minBase(res));
	printf("Dime la base a la que quieres cambiarlo:\n");
	base = ReadInt();
	largo=strlen(numero);
	j=largo-1;
	while(c!=1){
	 if(j==0){
	 	c=1;
	 }
	 a=convierte(numero[j]);
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
	 digitos[i]=num-(x*base);
	 num=x;
	 i++;
	 largo2++;

	}
	printf("\nEn base %d su numero es:\n",base);

	i=largo2-1;
	while(b!=0){
	  if(i==0)
	{
		b=0;
	}
	 printf("%d",digitos[i]);
	 i=i-1;
	}
}

//Euclides y Bezout
int coef1(int,int);
int coef2(int,int);
int coef1(int a, int b)
{
    if (a%b==0) return (0);
    else return (coef2(b,a%b));
}
int coef2(int a, int b)
{
    if (a%b==0) return(1);
    else return (coef1(b,a%b)- a/b *coef2(b,a%b));
}
void AlgoritmoEuclidesBezout(){
  int o, a, b, q=0, r=0,a1=0,b1=0,s,t;
		q = 0;
		printf("Inserte numero a = ");
		a = ReadInt();
		printf("Inserte numero b = ");
		b = ReadInt();

		if (b != 0){
		if(a>=0){
			if(b>0){//caso 1
				r=a;
				while(r>=b){
					r=r-b;
					q++;
				}
			}
		}
	}
		a1=b;
		b1=r;

	while(b1!=0){

		if (b1 != 0){
		if(a1>=0){
			if(b1>0){//caso 1
				r=a1;
				while(r>=b1){
					r=r-b1;
					q++;
				}
				a1=b1;
				b1=r;
			}
		}
	}


	}
	s=coef1(a,b);
    t=coef2(a,b);

	printf("\n El mcd= %d",a1);
	printf("\n Teorema Bezout = %d*(%d)+ %d*(%d) \n Donde s= %d y t= %d", a,s,b,t,s,t );
}

//Exponenciacion Binaria
void ExponenciacionBinaria(){
  int x,a,m,i=0,l=0,num,nox,b,conv,bina[40];
	char n[10];
	printf("Numero a:\n");
	a = ReadInt();
	printf("Potencia n:\n");
	scanf(" %s", &n);
	fflush(stdin);
	printf("Numero del modulo:\n");
	m = ReadInt();
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

int main(){
  int o;
  
  do{
    printf("\nElija una opcion\n");
    printf("-----------------------\n");
    printf("1)Algoritmo de la division\n2)Cambio de Base\n3)Algoritmo de Euclides y Bezout\n4)Exponenciacion Binaria Modular\n5)Salir\n");
    o = ReadInt();
    printf("\n");

    switch (o) {
      case 1:
      	system("cls");
        AlgoritmoDivision();
        break;
      case 2:
      	system("cls");
        CambioBase();
        break;
      case 3:
      	system("cls");
        AlgoritmoEuclidesBezout();
        break;
      case 4:
      	system("cls");
        ExponenciacionBinaria();
        break;
      case 5:
      default:
        break;
    }
  } while(o != 5);
}

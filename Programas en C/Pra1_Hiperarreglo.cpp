#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int***** crearHiperarreglo(int,int,int,int,int);
int***** llenarHiperarreglo(int*****,int,int,int,int,int);
void destruirHiperarreglo(int*****,int,int,int,int,int);
int main(void){
  int a=0,b=0,c=0,d=0,e=0,*****hiper=NULL;
  system("color a");
  printf("Hiperarreglo 3000\n");
  printf("Primera dimension del arreglo:");
  scanf("%d",&a);
  printf("Segunda dimension del arreglo:");
  scanf("%d",&b);
  printf("Tercera dimension del arreglo:");
  scanf("%d",&c);
  printf("Cuarta dimension del arreglo:");
  scanf("%d",&d);
  printf("Quinta dimension del arreglo:");
  scanf("%d",&e);
  hiper=crearHiperarreglo(a,b,c,d,e);
  printf("Arreglo Creado!\nArreglo con numeros aleatorios:\n\n");
  
  llenarHiperarreglo(hiper,a,b,c,d,e);
  destruirHiperarreglo(hiper,a,b,c,d,e);					
  	
}
int***** crearHiperarreglo(int a,int b,int c,int d,int e){
   int *****hiper=NULL,i=0,j=0,l=0,k=0;
   hiper=(int *****)malloc(e*sizeof(int****));
   for(i=0;i<e;i++){
     hiper[i]=(int****)malloc(d*sizeof(int***));
     for(j=0;j<d;j++){
       hiper[i][j]=(int***)malloc(c*sizeof(int**));
       for(k=0;k<c;k++){
       	hiper[i][j][k]=(int**)malloc(b*sizeof(int*));
       	for(l=0;l<b;l++){
       	 hiper[i][j][k][l]=(int*)malloc(a*sizeof(int));	
	}
       }	
     }
   }
   return hiper;	
}
int***** llenarHiperarreglo(int *****hyper,int a,int b,int c,int d,int e){
  int i=0,j=0,k=0,l=0,m=0,num=0;
    srand(time(NULL));	
  if(hyper==NULL)
   return NULL;
  for(i=0;i<e;i++){ 	
    for(j=0;j<d;j++){
    	
       for(k=0;k<c;k++){
    	 for(l=0;l<b;l++){
    	   for(m=0;m<a;m++){
    	     num=rand()%100;	
    	     hyper[i][j][k][l][m]=num;
    	     printf("%d    ",hyper[i][j][k][l][m]);
             }
    printf("\n");
         }
         printf("\n\n");
    }
    printf("\n\n\n");
    }
    printf("\n\n\n\n");	
  }
  return hyper; 	
}
void destruirHiperarreglo(int *****hiper,int a,int b,int c,int d,int e){
   int i,j,k,l;
  if(hiper==NULL||*hiper==NULL||**hiper==NULL||***hiper==NULL||****hiper==NULL||*****hiper==NULL)
   return;
   for(i=0;i<e;i++){
    for(j=0;j<d;j++){
    	for(k=0;k<c;k++){
    	 for(l=0;l<b;l++)	
    	    free(hiper[i][j][k][l]);
    	 free(hiper[i][j][k]);   
         }
        free(hiper[i][j]); 
    }
    free(hiper[i]);
    }
    free(hiper);
    printf("Memoria Liberada con exito");	
  } 		

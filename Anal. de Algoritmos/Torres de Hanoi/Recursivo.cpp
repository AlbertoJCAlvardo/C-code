#include<stdio.h>
#include<stdlib.h>
#include <time.h>

void torresHanoi(char,char,char,int,int *);



int main(void){
	
  clock_t tiempo_inicio, tiempo_final;
  double segundos;
  int discos=0,step=1;
  
  tiempo_inicio = clock();
  printf("\tTORRES DE HANOI\nNumero de discos:\n");
  scanf(" %d",&discos);
  fflush(stdin);
  torresHanoi('C','A','B', discos, &step);	
  
  tiempo_final = clock();

  segundos = (double)(- tiempo_inicio  + tiempo_final) / CLOCKS_PER_SEC; /*según que estes midiendo el tiempo en segundos es demasiado grande*/

	printf("\nTiempo : %f seg",segundos);
}




void torresHanoi(char destino,char fuente,char auxiliar,int nN,int *paso){
	
	
   if(nN==1){
      printf("\n%d. Disco %d de palo %C a palo %C",*paso,nN,fuente,destino);
      *paso=*paso+1;      	
   }
   
   else{
   	torresHanoi(auxiliar,fuente,destino,nN-1,paso);
    printf("\n%d. Disco %d de palo %C a palo %C",*paso,nN,fuente,destino);
    *paso=*paso+1;       
    torresHanoi(destino,auxiliar,fuente,nN-1,paso);
   
  }
}

#include<stdio.h>
#include<stdlib.h>
void torresHanoi(char,char,char,int,int *);
int main(void){
  int discos=0,step=1;
  printf("\tTORRES DE HANOI\nNumero de discos:\n");
  scanf(" %d",&discos);
  fflush(stdin);
  torresHanoi('C','A','B', discos, &step);	
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

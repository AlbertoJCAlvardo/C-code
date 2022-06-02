#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main(void){
FILE *alu_archivo;
int contal=0,contad=0,x=0,n=0,y=0,z=0,k=0,m=0,l=0,w=0;	
char *pch,cad[1000],alumnos[100][100];
alu_archivo= fopen("eltona.csv","r");
	if(alu_archivo!=NULL){
		do{
			cad[k]=fgetc(alu_archivo);
			if(cad[k]==','&& cad[k]!='\n'){
				contad++;
			}
			if('\n'==cad[k]) {
				contal++;
			}
			k++;
		} while(cad[k]!=EOF);
		fclose(alu_archivo);
	}
	else{
		printf("No se pudo abrir el archivo ??");
	}
	contal=contal+1;
	contad=contad/contal;
	printf("Numero de alumnos: %d 	Numero de dimensiones: %d\n",contal,contad);
	pch=strtok(cad,";");
	while(pch!=NULL){
		//printf("%s",pch);
		cad[m]=*pch;
		
		m++;
		pch=strtok(NULL,";,");
	}
	while(l<(contal*(contad+1))){
		alumnos[w][0]=1;
		alumnos[w][1]=x;
		alumnos[w][n]=cad[z]-'0';
		if(n==contad+1){
			n=1;
			w++;
			z=z+1;
			x++;
			//w=w+1;
		}
		z++;
		l++;
		n++;
	}
}

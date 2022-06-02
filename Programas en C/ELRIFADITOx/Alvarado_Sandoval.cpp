#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(void){
	int base[80][15],valores[80][20],i=0,j,dim=0,alumnos=0,c,k=1;
	char chorizo[1500],Nombres[80][20],aux[10];
	char *apu;
	FILE *archivo;
	archivo=fopen("eltona.csv","r");
	if(archivo != NULL){
		do{
		c=getc(archivo);
		chorizo[i]=c;
		if(chorizo[i]=='\n'){
			alumnos++;
			if(alumnos==1){
				j=i;
				while(j>0){
					if(chorizo[j]==','){
						dim++;
					}
				j--;	
				}
			}
		}
		i++;
	 }
	 while(c!=EOF);
	 fclose(archivo);
	}
	
	else{
			printf("Archivo Danado");
		}
		fflush(stdin);	
		apu=strtok(chorizo,",\n");
		strcpy(Nombres[i],apu);
		printf("%s",Nombres[i]);
		while(apu!=NULL){
		if(chorizo[k-1]=='\n'){
			apu=strtok(NULL,",\n");
			strcpy(Nombres[i],apu);
			
			printf("%s\n",Nombres[i]);
			k++;
		}
		else{
			for(j=0;j<dim;j++){
9			  
			   strcpy(aux, apu);
			   valores[i][j]=atoi(aux);
			   printf("%d",valores[i][j]);
			   k++;
			}
		}
		i++;
              }
		
			
		
	
	
}

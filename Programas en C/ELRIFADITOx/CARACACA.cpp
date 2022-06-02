#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main(void){
  int i,j,base[100][20],distancias[3160],alumnos=0,dim=0,lcadena;
  char *pch,chorizo[1000],nombres[100][40],c;
  FILE *archivo;
  archivo=fopen("milmil.csv","r");
  	if(archivo != NULL){
		do{
		c=getc(archivo);
		chorizo[i]=c;
		printf("%c",chorizo[i]);
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
	printf("\nAlumnos: %d Dimensiones:%d",alumnos,dim);	
	i=0;
	j=0;	
	pch=strtok(chorizo,",\t\n;");
	strcpy(nombres[0],pch);
	printf("%s",nombres[i]);
	while(pch!= NULL){
	  pch=strtok(NULL,",\t\n;");	
	  lcadena=strlen(pch);
	  if(lcadena==1&&j<dim)
	  {
	    base[i][j]=atoi(pch);
	    printf(" %d",base[i][j]);
	    j++;	 
	  }
	  else{
	     if(i<alumnos){
	     j=0;	
	     i++;	
	     strcpy(nombres[i],pch);
	     printf("\n%d-%s",i,nombres[i]);
             }
	  }
	  if(i==27){
	  	*pch='\0';
	  }
         }
	 
}

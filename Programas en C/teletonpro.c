//autor jorge luis marquez
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int main(void){
	
	int alumnos[100][100],distancias[100][100], Filas, Columnas,Col,Row,Dist,Gay;
    int i,j;
    Col=0;
    Row=0;
	FILE *apu_archivo;
	apu_archivo = fopen("alumnosgay.txt", "r");
	char cad[100], *pch;
	
	if(apu_archivo== NULL){
		perror("Error al abrir el archivo");
		return -1;
	}
	
	
	i = 0;
	while(!feof(apu_archivo)){
		fscanf(apu_archivo, "%s" , cad);
		pch = strtok(cad, ",");		
		j = 0;
		while(pch != NULL){
			alumnos[i][j] = atoi(pch);
      		pch = strtok(NULL, ",");
      		j++;
		}
	   i++;
	}
	
	
	Filas = i;
	Columnas = j;

	for(i=0 ; i<Filas; i++){
	 for(j=0 ;j<Columnas; j++){
		 printf("%d\t puto teleton",alumnos[i][j]);
	  }
	 printf("\n");
    }   
    printf("%d\n",Filas);
    printf("%d\n",Columnas);
    while(Col<=Columnas)
    {
    	Gay=alumnos[Row][Col]-alumnos[Row+1][Col];
    	distancias[Row][Row+1]=sqrt(Dist+=pow(Gay,2));
    	Col++;
    	printf("%d\t",distancias[Row][Row+1]);
    }
    fclose(apu_archivo);
	return 0;
	
	
	



}//fin del main







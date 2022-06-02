#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int main(void){
	char nombres [5][30];
	int valores [5][5],i,j=0,z=0,ngrupos,grupos[5][3],dmax=0,uno,dos,suma=0,cuad,k,m=0,dab=0,aux[5],dist,identificadores[5];
	for(i=0;i<5;i++){
		printf("Nombre: ");
		scanf("%[^\n]",nombres[i]);
		fflush(stdin);
		fflush(stdin);
		valores[i][0]=i+1;
		;
		
	}
	printf("\nCuantos grupos formo?");
	scanf("%d",&ngrupos);
	for(i=0;i<5;i++){
		for(j=1;j<5;j++){
			printf("%s Dime que tanto de gusta el gusto %d del 1 al 5:",nombres[i],j);
			scanf("%d",&valores[i][j]);
		}
		system("cls");
    }
    for(i=0;i<5;i++){
    	for(j=i+1;j<5;j++){
    	 for(k=1;k<5;k++){
    	    suma=pow((valores[i][k]-valores[j][k]),2)+suma;	
	     }
	     cuad=suma;
	     suma=0;
	     dist=sqrt(cuad);
	     printf("\nDistancia %d-%d = %d",valores[i][0],valores[j][0],dist);
	     if(dist>dmax&&dist>0){
	     	dmax=dist;
	     	uno=valores[i][0];
	     	dos=valores[j][0];
	     	for(m=0;m<5;m++){
	     	if(valores[0][m]!=valores[i][m]){	
	     	aux[m]=valores[1][m];     	
		valores[0][m]=valores[i][m];
		valores[i][m]=aux[m];
	         }  
		}
		for(dab=0;dab<5;dab++){
	           if(valores[j][dab]!=valores[4][dab]){
		  
		  aux[dab]=valores[4][dab];
		 valores[4][dab]=valores[j][dab];
		  valores[j][dab]=aux[dab];
	          }
		}   
		 }
	     }
	     
	     }
	     m=0;
	    int np=5/ngrupos; 
         for(i=0;i<ngrupos;i++){
         printf("\nGrupo %d",i+1);
          if((5%ngrupos)==0){	
          for(j=0;j<np;j++){
             if(m<5){
	    grupos[i][j]=valores[m][0];
	    printf("%d ",grupos[i][j]);
             m++;	
             }
	 }
          }
          else{
             if(i==0){
             for(j=0;j<(np+1);j++){
             if(m<5){	
             grupos[i][j]=valores[m][0];
             printf("\ng[%d]=%d",m,grupos[i][j]);
	    m++;	
             }
             }
             }
             else{
             for(j=0;j<np;j++){
             if(m<5){	
             grupos[i][j]=valores[m][0];
             printf("\ng[%d]=%d",m,grupos[i][j]);
	    m++;	
             }	
	    }
             }
	 }
	 	
	
	
        }
	
	 printf("\nLa distancia entre %d y %d con:%d",uno,dos,dmax);
	 for(i=0;i<5;i++){
           printf("\n%d",valores[i][0]);
	     
         }
         printf("\n%d",m);
         for(i=0;i<=ngrupos;i++){
          printf("\nGrupo %d:",(i+1));	
           for(j=0;j<=np;j++){
             printf("\n%s",nombres[grupos[i][j]-1]);
	  }	
	}
    
}

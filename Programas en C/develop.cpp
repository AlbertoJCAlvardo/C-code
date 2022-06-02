#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int main(void){
	char nombres [5][30];
	int valores [5][5],i,j=0,z=0,ngrupos,grupos[5][3],uno,dos,suma=0,cuad,k,m=0,dab=0,aux,cen[5];
	float dmax=0,dist,dim[5][2];
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
	     dim[j-1][0]=j;
	     dim[j-1][1]=dist;
	     printf("\nDistancia %d-%d = %f",valores[i][0],valores[j][0],dist);
	     if(dist>dmax&&dist>0){
	     	dmax=dist;
	     	uno=valores[i][0];
	     	dos=valores[j][0];
	     }
	     
	     }
	      for(m=0;m<5;m++){
	       for(int n=1;n<m;n++){
	       	if(dim[n][1]<dim[m][1]){
	       		aux=dim[n][1];
	       		dim[n][1]=dim[m][1];
	       		dim[m][1]=aux;
		       }      
	       } 
            }
           }
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
	
	 printf("\nLa distancia entre %d y %d con:%f",uno,dos,dmax);
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

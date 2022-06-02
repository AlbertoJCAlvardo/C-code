#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int alpar(){
	int n,ind=0;
	do{
	   srand(time(NULL));
	    n=rand()%100+1;
	    if(n%2==0){
	    	ind=1;
	    }	
	}while(ind==0);
	return n;
}
int alimpar(){
	int n,ind=0;
	do{
	    srand(time(NULL));	
	    n=rand()%100+1;
	    if(n%2==1){
	    	ind=1;
	    }	
	}while(ind==0);
	
	return n;
}
int main(void){
  int i,nr,n=5,m=1,j,**matriz,z,ind;
  matriz=(int**)calloc(9,sizeof(int*));
  for(i=0;i<9;i++){
     if(n>1){
     	matriz[i]=(int*)calloc(n,sizeof(int));
     	if(n%2==0){
     	  for(j=0;j<n;j++){
     	     nr=alpar();
     	     z=j;
     	     ind=0;
              do{
                if(nr==matriz[i][z])
                {
                	nr=alpar();
                	z=j;
	       }
	       z--;
                if(z==-1){
                	ind=1;
	       }
	     }while(ind==0);
	     matriz[i][j]=nr;
	     printf("%d  ",matriz[i][j]);		 	
	   }
	       	
	}
	else{
	  for(j=0;j<n;j++){
     	     nr=alimpar();
     	     z=j;
     	     ind=0;
              do{
                if(nr==matriz[i][z])
                {
                	nr=alimpar();
                	z=j;
	       }
	       z--;
                if(z==-1){
                	ind=1;
	       }
	     }while(ind==0);
	     matriz[i][j]=nr;
	     printf("%d  ",matriz[i][j]);		 	
	   }	
	}
	n--;
	
     }
     else{
     	matriz[i]=(int*)calloc(m,sizeof(int));
     	if(m%2==0){
     	  for(j=0;j<m;j++){
     	      nr=alpar();
     	     z=j;
     	     ind=0;
              do{
                if(nr==matriz[i][z])
                {
                	nr=alpar();
                	z=j;
	       }
	       z--;
                if(z==-1){
                	ind=1;
	       }
	     }while(ind==0);
	     matriz[i][j]=nr;
	     printf("%d  ",matriz[i][j]);		 	
	   }
	       	
	}
	else{
	  for(j=0;j<m;j++){
     	      nr=alimpar();
     	     z=j;
     	     ind=0;
              do{
                if(nr==matriz[i][z])
                {
                	nr=alimpar();
                	z=j;
	       }
	       z--;
                if(z==-1){
                	ind=1;
	       }
	     }while(ind==0);
	     matriz[i][j]=nr;
	     printf("%d  ",matriz[i][j]);		 	
	   }	
	}
       m++;
     }
     printf("\n\n");	
  }
  free(matriz);
}

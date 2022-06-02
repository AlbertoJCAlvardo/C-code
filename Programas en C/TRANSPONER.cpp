#include<stdio.h>
#include<stdlib.h>
int **Transponer(int**);
void imprimir(int**);
int igualdad(int **m1,int **m2){
   int i=0,j=0,count=0;
   printf("Matriz 1:\n");
   imprimir(m1);
    printf("Matriz 2:\n");
   imprimir(m2);
   for(i=0;i<8;i++){
     for(j=0;j<8;j++)
      if(m1[i][j]==m2[i][j])
       count++;	
   }
   if(count==64){
    printf("\nSon iguales");	
    return true;
    }
    printf("\nNo son iguales");
   return false;	
}
int main(void){
   int i=0,j=0,**mat=NULL,**ver=NULL,**tr=NULL;
   mat=(int**)malloc(8*sizeof(int*));
   for(i=0;i<8;i++)
    mat[i]=(int*)malloc(8*sizeof(int));
    ver=(int**)malloc(8*sizeof(int*));
   for(i=0;i<8;i++)
    ver[i]=(int*)malloc(8*sizeof(int));
   for(i=0;i<8;i++)
    for(j=0;j<8;j++)
     mat[i][j]=i+1;
    tr=(int**)malloc(8*sizeof(int*));
   for(i=0;i<8;i++)
    tr[i]=(int*)malloc(8*sizeof(int));
      int l=0,k=0;
    ver=mat;
      printf("-------------------------\n\n");
     igualdad(mat,ver);
   for(i=7;i>=0;i--){
     l=0;
    for(j=7;j>=0;j--){
     tr[j][i]=mat[i][j];
       l++;
      }
       k++;
     }
     k=0;
       printf("-------------------------\n\n");
     igualdad(tr,ver);
       
      printf("-------------------------\n\n");
     igualdad(tr,ver);
     for(i=7;i>=0;i--){
    l=0;
    for(j=7;j>=0;j--){
     tr[k][l]=mat[i][j];
       l++;
      }
      k++;
     }
     k=0;
    
     printf("-------------------------\n\n");
     igualdad(tr,ver);
    for(i=7;i>=0;i--){
    l=0;
    for(j=7;j>=0;j--){
     tr[l][k]=mat[i][j];
       l++;
      }
      k++;
     }
      k=0;
     printf("-------------------------\n\n");
     imprimir(tr);
    for(i=7;i>=0;i--){
    l=0;
    for(j=7;j>=0;j--){
     tr[l][l]=mat[i][j];
       l++;
      }
      k++;
     }

         printf("-------------------------\n\n");
     igualdad(tr,ver);
      k=0;

    for(i=7;i>=0;i--){
    l=0;
    for(j=7;j>=0;j--){
     tr[k][k]=mat[i][j];
       l++;
      }
      k++;
     }
       printf("-------------------------\n\n");
     igualdad(tr,ver);
       k=7;
       l=7;
     for(i=0;i<4;i++){
      k=7;	
      for(j=0;j<8;j++){
       tr[l][j]=mat[i][j];
       tr[i][j]=mat[i][j];    
       k--;
      }
      l--;
     }
       printf("a-------------------------\n\n");
     igualdad(tr,ver);       
    
}


int **Transponer(int **mat){
  int i=0,j=0,k=0,l=0,**tr=NULL;
  
}


void imprimir(int **mat){
	 int i=0,j=0;
  for(i=0;i<8;i++){
    for(j=0;j<8;j++)
     printf("   %d",mat[i][j]);	
  printf("\n\n");	
  }
}

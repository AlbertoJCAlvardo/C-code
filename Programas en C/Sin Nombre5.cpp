#include <stdio.h>
 
int main(){
 
    int M[4][2][2];
    int i, j, k;
 
    for(i = 0; i < 4; i++)
        for(j = 0; j < 2; j++)
            for(k = 0; k < 2; k++)
                M[i][j][k] = i*4 + j*2 + k;
 
    for(i = 0; i < 4; i++){
        printf("\nTabla %d:\n", i);
        for(j = 0; j < 2; j++){
            for(k = 0; k < 2; k++)
                printf("M[%d][%d] = %d  ", j, k, M[i][j][k]);
            printf("\n");
        }
    }
 
    return 0;
}
 

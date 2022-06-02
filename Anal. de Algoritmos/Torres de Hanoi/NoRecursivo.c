#include <stdio.h>
#include <stdlib.h>
#include<time.h>
/*---------------------------------------------------------
|Declaraciones de Prototipos
+--------------------------------------------------------*/

int move_torre (int n ,int from ,int to);


int move_torre (int n, int from, int to){
	int aux, n_moves;

	if (n==1){
		printf ("\nMueva el disco [1] de la torre no. %d a la torre no.%dn", from, to);
		return (1);
	}

	aux = 6 - from - to;

	n_moves= move_torre (n-1,from, aux);

	printf ("\nMueva el disco [%d] de la torre no. %d a la torre no.%dn",n, from, to);
	n_moves++;

	n_moves += move_torre(n-1,aux,to);
	return(n_moves);
}


int main ()
{
  clock_t tiempo_inicio, tiempo_final;
  double segundos;
	int n, n_moves;



	do{
		printf("Introduzca el numero de Discos en la Torre: ");
		scanf ("%d",&n);
	} while (n<=0);



		n_moves=move_torre(n,1,3);
		if (n_moves<=1)
			printf("\n\nLa solución requiere %d movimiento.n",n_moves);
		else
			printf("\n\nLa solución requiere %d movimientos.n",n_moves);
			
		tiempo_final = clock();

  		segundos = (double)(- tiempo_inicio  + tiempo_final) / CLOCKS_PER_SEC;

		printf("\nTiempo : %f seg",segundos);

		return(0);
		

}

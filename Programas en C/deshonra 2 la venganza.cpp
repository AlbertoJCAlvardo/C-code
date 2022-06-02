/*
	5x06-Torres_de_Hanoi_parte_1
	18/01/2012

	Haz una versión del ejercicio siguiente (también recursiva) que simplemente vaya dando por pantalla las instrucciones necesarias para dar solución al problema de tamaño n.
	Es decir, se trata de una versión del ejercicio siguiente que no muestra nada gráficamente, sino que simplemente dice qué disco mover de qué torre a qué torre,
	para que un manipulador pueda ir haciendo esos movimientos sobre una maqueta y solucione correctamente el problema.
*/


#include <stdio.h>


void manoi( int disc, int *cont, char O, char A, char D )
{
	/*
	Precondición:
					Se ha de recibir un parámetro de tipo entero que indica el numero de discos que se están usando.
					Un puntero a un parámetro de tipo entero que almacena el numero de movimientos.
					Y tres parámetros de tipo carácter cuyo valor va cambiando de orden por cada recursividad.
	*/


	if( disc == 1 )
	{
	  printf("%i:  %c -> %c\n", *cont, O, D );
		(*cont)++;
	}
	else
	{
		manoi( disc-1, cont, O, D, A );

	        printf("%i: Disco: %d  %c -> %c\n",disc, *cont, O, D );
		(*cont)++;

		manoi( disc-1, cont, A, O, D );
	};

};


main()
{
	int disc, cont=1;

	printf( "Indique el numero de discos: " );
	scanf( "%i", &disc );

	manoi( disc, &cont, 'O', 'A', 'D' );
};

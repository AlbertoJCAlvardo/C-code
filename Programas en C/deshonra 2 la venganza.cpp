/*
	5x06-Torres_de_Hanoi_parte_1
	18/01/2012

	Haz una versi�n del ejercicio siguiente (tambi�n recursiva) que simplemente vaya dando por pantalla las instrucciones necesarias para dar soluci�n al problema de tama�o n.
	Es decir, se trata de una versi�n del ejercicio siguiente que no muestra nada gr�ficamente, sino que simplemente dice qu� disco mover de qu� torre a qu� torre,
	para que un manipulador pueda ir haciendo esos movimientos sobre una maqueta y solucione correctamente el problema.
*/


#include <stdio.h>


void manoi( int disc, int *cont, char O, char A, char D )
{
	/*
	Precondici�n:
					Se ha de recibir un par�metro de tipo entero que indica el numero de discos que se est�n usando.
					Un puntero a un par�metro de tipo entero que almacena el numero de movimientos.
					Y tres par�metros de tipo car�cter cuyo valor va cambiando de orden por cada recursividad.
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

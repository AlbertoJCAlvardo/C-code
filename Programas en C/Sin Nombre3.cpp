#include <stdio.h>


void manoi( int disc, int *cont, char A, char B, char C )
{

	if( disc == 1 )
	{
	  printf("%i: Disco: %d %c -> %c\n", *cont, disc, O, D );
		(*cont)++;
	}
	else
	{
		manoi( disc-1, cont, A, C, B );

	        printf("%i: Disco: %d  de palo %c a palo %c\n", *cont,disc, O, D );
		(*cont)++;

		manoi( disc-1, cont, B, A, C );
	};

};


main()
{
	int disc, cont=1;

	printf( "Indique el numero de discos: " );
	scanf( "%i", &disc );

	manoi( disc, &cont, 'O', 'A', 'D' );
};

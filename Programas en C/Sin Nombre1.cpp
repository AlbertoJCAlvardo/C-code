#include <iostream>
  using namespace:: std;
  /* Se usa entrada-salida estandar */

  #include <ctime>
  /* Esta encabezado se usa para meter semillas a srand() */
  #include <cstdlib>

  const int Tamano_Arreglo = 8;
  int x = 0;
  int y = 0;
  // Este par de variables daran las coordenadas de la reina

  int accesibilidad = 100;
  // Accesibilidad es una cantidad que se le dara a las casillas
  // donde haya una reina o que sea atacada por una reina
  // el numero 100 es arbitrario, puede ser un entero que sea
  // mayor que cualquier valor del arreglo Valores que se define
  // en la funcion main

  // PASO1

  // La primera parte del PASO 1 se realiza en estos pasos:
  // a) determinar el minimo absoluto
  // b) contarlas
  // c) marcarlas en el tablero
  //
  //para a) se define una  funcion

  ////////////////////////////////////////////////////////
  //SE DEFINE FUNCION DETERMINA MINIMO
  ////////////////////////////////////////////////////////

   // Esta funcion recibe el arreglo Valores y el tamanio del arreglo
   // ojo, que en c++ se puede no indicar el primer indice pero
   // es obligatorio incluir los siguientes
   //  retorna un entero llamado minimo

   int Determina_Minimo( int Arreglo[][Tamano_Arreglo], int lado)
   {               // Abre funcion Determina_Minino

   int minimo = 30;   //AL DEFINIR minimo = 30 SE GARANTIZA QUE
                     //SERA MAYOR A CUALQUIER NUMERO DEL TABLERO
                    //VALORES PERO TAMBIEN SERA MENOR QUE 100 Y 97
                     //QUE SE USARAN MAS ADELANTE
                     //

   for ( int i = 0; i < lado; i++)
   for ( int j = 0; j < lado; j++)
   {            // Abre for
    if ( Arreglo[i][j] < minimo )
    minimo = Arreglo[i][j];
    // Esta funcion para determinar el minimo
    // trabaja bien para el caso en el que todos las
    // casillas son accesibles, pero a medida que se avanza
    // mas y mas casillas NO deben evaluarse, porque si bien
    // en el arreglo Valores tienen un peso bajo, ya se ocuparon.
    // Se puede salvar este problema limitando esta funcion
    // o mejorandola, pero es mejor cambiar el arreglo Valores
    // a medida que se avanza en el llenado del tablero
    // y asignar un valor muy alto, digamos 100, para la
    // accesibilidad de las casillas ocupadas y de las atacadas
   }         // Cierra for

   return minimo;
   }            // Cierra la funcion Determina_Minimo

   // la parte c) se realiza mediante una funcion
   
   /////////////////////////////////////////////////////////
   // Se define funcion marca minimos
   // //////////////////////////////////////////////////////

   // Esta funcion recive el valor minimo, arreglo Tablero y el
   // arreglo Valores
   // No regresa nada, solo modifica los arreglos

   void Marca_Minimos( int menor, int Arreglo_Valores[][Tamano_Arreglo], int Arreglo_Tablero[][Tamano_Arreglo])

 {         // Abre funcion
 for ( int i = 0; i < Tamano_Arreglo; i++)
 for ( int j = 0; j < Tamano_Arreglo; j++)
 {   // abre for      
  if ( Arreglo_Valores[i][j] == menor)
  Arreglo_Tablero[i][j] = 'a';

  // Si el arreglo Valores, en esta casilla es accesible y de menor peso,
  // la casilla en el Tablero se marca con una 'a', cuyo valor
  // ascii es 97.
 }   // Cierra for
 }            // cIERRA Funcion marca minimos


  ///////////////////////////////////////////////////////
  //PASO 2 DEL ALGORITMO
  ///////////////////////////////////////////////////////

  // una vez que se tienen marcadas las casillas accesibles,
  // es necesario elegir una para esto se define una nueva funcion
  // que regresa el numero de casillas disponibles
  // y recibe el tablero y el numero de reinas
  // que se han colocado hasta el momento

  int Determina_Posicion( int Tabla[][Tamano_Arreglo], int contador_reinas)
  {         // ABre funcion Determina_POsicion

   // para determinar la casilla, primero
   // se cuentan las casillas accesibles que estan
   // en el arreglo Tabla marcadas con el valor 'a'
   int contador = 0;

   for( int i = 0; i < Tamano_Arreglo; i++ )
   for( int j = 0; j < Tamano_Arreglo; j++ )
   {         // Abre for anidado
   if ( 'a' == Tabla[i][j])
   {     // Abre if
   contador++;
   }    // Cierra if
   }        // Cierra for anidado

  //Descomentar esto para ver la ejecucion del programa paso a paso
  //cout <<endl<< "Hay " << contador << " casillas disponibles. " <<endl;
  // ahora se lanza un dado de numero de lados contador
  
   if ( 0 != contador)

   {          // Todo lo demas debe ejecutarse
              // solo si hay casillas disponibles
    int dado;
    srand(time(NULL));   //Se usa para generar numeros aleatorios */

   // Se define una variable dado
   dado = 1 + rand() % contador;

   // Descomentar para ver la ejecucion del programa paso a paso
   //cout << endl << "El dado dio: " << dado << endl;
   
   // ahora, se ha elegido la casilla numero 'dado' de las 'contador'
   // que tenemos

   int s = 0;  // Este contador controla el numero de 'a'
  // Este ciclo cuenta las 'a' en el tablero y marca la
  // numero 'dado'

  for ( int i = 0; i < Tamano_Arreglo; i++)
  for ( int j = 0; j < Tamano_Arreglo; j++)
  { // Abre for
  if( 'a' == Tabla[i][j] )
  {
  s++;
  if (s == dado )
  // ATENCION: Habia puesto este if no anidado, sino fuera
  // del anterior, lo cual causaba un error sutil, ya que se
  // daba el caso en que 'a' != Tabla[i][j], y al evaluar el
  // siguiente if, como s seguia siendo el mismo, se cambiaban
  // las casillas de la reina
  //
  {  // Abre if anidado
  Tabla[i][j] = contador_reinas;
  y = i;   // Estas asignaciones indican las coordenadas de la casilla
  x = j;   // donde se puso la reina
  }   // Cierra if anidado
  }
  }  // Cierra for

  // cout << endl << "se ha elegido la casilla " << y <<" " << x << endl;
  // Descomentar esto para ver la ejecucion del programa paso a paso
  // ahora que se ha determinado cual es la casilla correspondiente
  // a esta reina, es necesario que las casillas retomen su
  // valor original

  for ( int i = 0; i < Tamano_Arreglo; i++)
  for ( int j = 0; j < Tamano_Arreglo; j++)
  { // Abre for
  if( 'a' == Tabla[i][j])
  Tabla[i][j] = 0;
  }    // Cierra for

  }        // Se cierra el if que controla
           // el hecho de que haya o no casillas
           //  disponibles

  return contador;
  }          // Cierra funcion Determina_Posicion


  /////////////////////////////////////////////////////////
  //PASO 3
  /////////////////////////////////////////////////////////

  // para realizar el paso 3 se necesita definir primeramente una
  // funcion que marque, no el tablero, sino el arreglo Valores
  // con la casilla de la reina puesta y las casillas que esta reina ataca

  /////////////////////////////////////////////////////////////////
  //SE DEFINE LA FUNCION MODIFICA_VALORES
  ///////////////////////////////////////////////////////////////

  void Modifica_Valores( int Arreglo_Valores[][Tamano_Arreglo])

  {  // abre funcion Modifica_Valores

   Arreglo_Valores[y][x] = accesibilidad;
   // con esto se garantiza que esta casilla ya no sera mas
   // candidata a ser llenada con una reina

  // ahora hay que modificar tambien las casillas que estan en
  // la misma fila

   for ( int i = 0; i < Tamano_Arreglo; i++ )
   Arreglo_Valores[y][i] = accesibilidad;
  // ahora hay que modificar tambien las casillas que estan en
  // la misma columna

   for ( int j = 0; j < Tamano_Arreglo; j++ )
   Arreglo_Valores[j][x] = accesibilidad;
  // Ahora, viene una parte dificil, que es modificar o marcar como
  // no elegibles las diagonales que ataca la reina

  // Lo primero que hay que ver es que una casilla
  // divide
  // al tablero en 4 partes.
  int s;
  int t;
  s = x;
  t = y;
  while ( (s < Tamano_Arreglo) && ( t < Tamano_Arreglo))
  Arreglo_Valores[t++][s++] = accesibilidad;

  s = x;
  t = y;

  while ( (s >= 0) && ( t >= 0))
  Arreglo_Valores[t--][s--] = accesibilidad;

  s = x;
  t = y;

   while ( (t >= 0) && ( s < Tamano_Arreglo))
   Arreglo_Valores[t--][s++] = accesibilidad;
   
   s = x;
   t = y;

   while ( (t < Tamano_Arreglo) && ( s >= 0))
   Arreglo_Valores[t++][s--] = accesibilidad;

  //con esto se han marcado todas las casillas que ataca la dama
  //como inaccesibles y la funcion termina
  }  // Cierra funcion Modifica_Valores

  ///////////////////////////////////////////////////////////////////
  //SE DEFINE FUNCION IMPRIMIR
  //////////////////////////////////////////////////////////////

  void Imprimir( int B[][Tamano_Arreglo ], int lado)

  {                           // ABRE IMPRIMIR
  for ( int k = 0; k < lado; k++ )
  {
  for ( int l = 0; l < lado; l++ )
  cout << "\t " << B[k][l];
  cout << endl<<endl;
  }

  cout << endl<<endl;
  }

  ////////////////////////////////////////////////////////////////////////
  //PASO CUATRO DEL ALGORITMO
  //////////////////////////////////////////////////////////////////////

  ////////////////////////////////////////////////////////////////////
  // FUNCION MAIN
  ///////////////////////////////////////////////////////////////////////

   int main()

   {           // Abre main

   // En el siguiente arreglo se incluyen los pesos de cada
   // casilla. Como es de esperar, las mas externas son las
   // mas adecuadas para colocar las reinas
   // Por falta de un nombre mas adecuado, le llamo al arreglo Valores

   int Valores[Tamano_Arreglo ][Tamano_Arreglo ] =

   { {22, 22, 22, 22, 22, 22, 22, 22},
     {22, 24, 24, 24, 24, 24, 24, 22},
     {22, 24, 26, 26, 26, 26, 24, 22},
     {22, 24, 26, 28, 28, 26, 24, 22},
     {22, 24, 26, 28, 28, 26, 24, 22},
     {22, 24, 26, 26, 26, 26, 24, 22},
     {22, 24, 24, 24, 24, 24, 24, 22},
     {22, 22, 22, 22, 22, 22, 22, 22}

   };


  int Tablero[Tamano_Arreglo][Tamano_Arreglo] = {{0},{0}};
  // En este arreglo se escribira el lugar donde estan las reinas

  int minimo;
  int numero_reina = 1;
  int casillas_disponibles = Tamano_Arreglo*Tamano_Arreglo;

  while ((0 != casillas_disponibles)  )
 {      // Abre while
  minimo =  Determina_Minimo( Valores, Tamano_Arreglo);

  // Descomente todas las instrucciones de este ciclo si quiere
  // ver la ejecucion paso a paso del programa
  // Fueron escritas solo para revisar
  // El programa solo imprime un tablero con el numero
  // de reinas que se colocaron y un mensaje
   //cout << "\nEl minimo es: " << minimo<< endl;

  Marca_Minimos( minimo, Valores, Tablero);

  // Imprimir( Tablero, Tamano_Arreglo   );
  
  casillas_disponibles = Determina_Posicion( Tablero, numero_reina);
  
  //cout<< "\nEl tablero despues de determinar la posicion:"<<endl;
  //cout << "\nCololacion de la reina numero: " <<numero_reina  << endl;
  //Imprimir( Tablero, Tamano_Arreglo   );

  Modifica_Valores( Valores);

  // Imprimir( Valores, Tamano_Arreglo   );

  numero_reina++;
  }    // Cierra while

  ( Tamano_Arreglo == numero_reina -2)? cout <<"\nAQUI ESTAN LAS OCHO REINAS!" << endl: cout <<"\nLo siento, solo se pudo colocar: " << numero_reina -2 <<    " reinas. Intente de nuevo." <<endl;
  Imprimir( Tablero, Tamano_Arreglo   );

  return 0;
  }           

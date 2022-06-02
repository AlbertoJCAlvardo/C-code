#include<stdio.h>
#include<stdlib.h>

typedef struct nodo{
	struct nodo *padre, *izq, *der;
	int dato;
	int id;
	 
} t_nodo, *Nodo;


typedef struct arbol{
	Nodo raiz;
	int longitud;
}t_arbol, *Arbol;


Nodo crearNodo(void){
	Nodo n = NULL;
	n = (Nodo) malloc(sizeof(t_nodo));
	
	n->padre = NULL;
	n->der = NULL;
	n->izq = NULL;
	
	return n;	
};

Arbol crearArbol(void){
	Arbol a = NULL;
	a = (Arbol) malloc(sizeof(t_arbol));
	a->raiz = NULL;
	a->longitud = 0;
	return a;
}

int insertar(int valor, Nodo raiz, Arbol a){
	if(a->raiz == NULL){
		Nodo n = crearNodo();
		n->dato = valor;
		n->id = a->longitud;
		a->raiz = n;
		a->longitud++;
		return 1;
	}
	else{
		if(valor > raiz->dato){
			
			if(raiz->der == NULL){
				Nodo n = crearNodo();
				
				n->id = a->longitud;
				n->dato = valor;
				n->padre = raiz;
				raiz->der = n;
				a->longitud++;
				return 1;
			}
			else{
				insertar(valor, raiz->der, a);				
			}
			
		}
		
		else{
			if(valor <= raiz->dato){
				
				if(raiz->izq == NULL){
					Nodo n = crearNodo();
					
					n->id = a->longitud;
					n->dato = valor;
					n->padre = raiz;
					raiz->izq = n;
					a->longitud++;
					return 1;
				}
				else{
					insertar(valor, raiz->izq, a);
				}
				
			}
		}
		
	}
	
}

int buscar(int valor, Nodo raiz, Nodo *n, int nivel){
	if(valor == raiz->dato){
		*n = raiz;
		printf("\nDato encontrado en el nodo con el id: %d en el nivel: %d",raiz->id, nivel);
		return 1;
	}
	else{
		if(valor > raiz->dato){
			if(raiz->der == NULL){
				printf("\nDato no encontrado");
				return 0;
			}
			else{
				nivel++;
				buscar(valor, raiz->der, n, nivel);
			}
		}
		else{
			if(raiz->izq == NULL){
				printf("\nDato no encontrado");
				return 0;
			}
			else{
				nivel++;
				buscar(valor, raiz->izq, n, nivel);
			}
		}
	}
}

void preorden(Nodo raiz){
	if(raiz == NULL){
		return;
	}
	printf("%d, ",raiz->dato);
	preorden(raiz->izq);
	preorden(raiz->der);
	
}
void inorden(Nodo raiz){
	if(raiz == NULL){
		return;
	}
	
	inorden(raiz->izq);
	printf("%d, ",raiz->dato);
	inorden(raiz->der);
}

void postorden(Nodo raiz){
	if(raiz == NULL){
		return;
	}
	
	postorden(raiz->izq);
	postorden(raiz->der);
	printf("%d, ",raiz->dato);
}

int destruirNodo(Nodo n){
	if(n == NULL)
		return 0;
	if(n != NULL){
		n->padre = NULL;
		n->izq = NULL;
		n->der = NULL;
		printf("Nodo destruido %d\n", n->id);
		free(n);
		n = NULL;
		return 1;
	}
	
}

void destruirNodosRec(Nodo n){
	Nodo izq = NULL, der = NULL;
	
	if(n == NULL){
		return;
	}
	
	izq = n->izq;
	der = n->der;
	
	if(izq != NULL){
		n->izq = NULL;
		destruirNodosRec(izq);
	}
	if(der != NULL){
		n->der = NULL;
		destruirNodosRec(der);
	}
	
	if(izq == NULL  && der == NULL){
		destruirNodo(n);
		return;
	}
	
}




int destruirArbol(Arbol a){
	
	if(a->raiz == NULL)
		return 1;
	if(a->raiz != NULL){
		destruirNodosRec(a->raiz);
		destruirNodo(a->raiz);
		return 1;
	}
	
}


int menu(void){
	Arbol a = NULL;
	
	a = crearArbol();
	int dato;
	int op;
	Nodo n = NULL;
	do{
		system("cls");
		printf("Menu Arbol Binario\n\nQue desea hacer?\n\n1)Insertar\t2)Buscar");
		if(a->longitud > 0){
			printf("\t3)Preorden\t4)Inorden\t4)Postorden");
		}
		printf("\t6)Destruir Arbol\t0)Salir\nSu opcion:  ");
		scanf("%d", &op);
		fflush(stdin);
		switch(op){
			case 1:
				
				printf("\nDato a ingresar: ");
				scanf("%d", &dato);
				
				if(insertar(dato, a->raiz, a) == 1){
					printf("\nDato ingresado correctamente");
					sleep(2);
				}
				else{
					printf("\nError");
					sleep(2);
				}
			break;
			
			case 2:
					
				
				
				printf("\nDato a buscar: ");
				scanf("%d", &dato);
				
				buscar(dato, a->raiz, &n ,0);
				sleep(2);
			
			break;
			
			case 3:
				
				if(a->raiz != NULL)
					preorden(a->raiz);
					sleep(2);
			break;
			case 4:
				if(a->raiz != NULL)
					inorden(a->raiz);
				sleep(2);
			break;
			case 5:
				if(a->raiz != NULL)
					postorden(a->raiz);
				sleep(2);
			break;
			case 6:
				if(destruirArbol(a) == 1)
					printf("Arbol destruido.");
					
					
				sleep(2); 
				
				
			break;
			
			
			
			default:	
				printf("\nAdios");
			break;
		}
	}while(op != 0);
	return 1;
}

int main(void){
	menu();
}

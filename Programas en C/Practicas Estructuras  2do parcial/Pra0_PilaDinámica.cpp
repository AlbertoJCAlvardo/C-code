#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define false 0
#define true 1

typedef struct tda{
 	
}t_tda,*TDA;
 
typedef struct elemento{
 int dato;
 float x;
 char cadena;
 TDA abs;	
}t_elemento,* Elemento;

typedef struct nodo{
 Elemento e;
 struct nodo *sig;
}t_nodo,* Nodo;

typedef struct pila{
 Nodo base;
 Nodo tope;
 int longitud=0;	
} t_pila,* Pila;
Elemento crearElemento(){
 Elemento e=NULL;
 e=(Elemento)malloc(sizeof(t_elemento));
 if(e!=NULL){
   e->dato=0;
   e->x=0;
   e->cadena=NULL;
   e->abs=NULL;
   return e;	
 }	
 return NULL;
}
Nodo crearNodo(){
 Nodo n=NULL;
 n=(Nodo)malloc(sizeof(t_nodo));
 if(n!=NULL){
  n->e=NULL;
  n->sig=NULL;
  return n;
  }
  return NULL;
  	
}
int destruirElemento(Elemento e){
  if(e==NULL)
   return false;
  e->abs=NULL;
  e->cadena=NULL;
  e->dato=NULL;
  e->x=NULL;
  free(e);
  return true; 	
}
int destruirNodo(Nodo n){
  int sw=false;
  if(n==NULL)
  return false;
   sw=destruirElemento(n->e);
   if(sw==false)
   return false;
   n->e=NULL;
   n->sig=NULL;
   free(n);
   return true;
}
int escribirElemento(Elemento e,Nodo n,int nN){
 if(n==NULL||e==NULL)
  return false;
   n->e=e;
   e->dato=nN;
return true;	
}
int leerElemento(Nodo n,Elemento *e,int *nN){
  Elemento x=NULL;
  if(n==NULL)
   return false;
   *e=n->e;
   x=*e;
   *nN=x->dato;
   return true;	
}
Nodo buscarPretope(Pila p,Nodo tope,Nodo pre){
  if(tope==NULL)
   return NULL;
  if(p->longitud==1)
  return (p->base);
  while(tope->sig!=NULL){
    pre=tope;
    tope=tope->sig; 	
  }
  return pre;
      	
}
int quitarDato(Pila p, int *eliminado){
 Elemento e=NULL;
 int sw=0;
 Nodo n=NULL,aux=NULL;
 aux=buscarPretope(p,p->base,NULL);
 n=p->tope;
 e=n->e;
 *eliminado=e->dato;
 aux->sig=NULL;
 destruirNodo(n);
 p->tope=aux;
 p->longitud--;
 return true;	
}
Nodo obtenerEnlace(Nodo n){
  if(n!=NULL)
   return n->sig;
  return NULL; 	
}
Pila crearPila(){
  Pila p=NULL;
  p=(Pila)malloc(sizeof(t_pila));
  if(p!=NULL){
   p->base=NULL;
   p->tope=NULL;
   p->longitud=0;
   return p;	
  }	
  return NULL;
}
int colocarEnlace(Nodo n,Nodo sig){
  if(n==NULL)
   return false;
   n->sig=sig;
   return true;	
}
int insertarElemento(Pila p,Elemento e,int x){
  int sw=false;
  Nodo n=NULL;
  if(p==NULL||e==NULL)
   return false;
  n=crearNodo();
  if(n==NULL)
   return false;
  sw=escribirElemento(e,n,x);
  if(sw==false)
   return false;
  if(p->longitud==0)
   p->base=n;
  else
   colocarEnlace(p->tope,n);
  
  p->tope=n;
  p->longitud++;
   
   return true;   	
}
int destruirPila(Pila p){
   Nodo aux=NULL;
   if(p!=NULL){
   if(p->longitud>0){
    while(p->tope!=NULL){
    aux=p->tope;
    p->tope=obtenerEnlace(p->tope);
    destruirNodo(aux);
    }
    p->base=NULL;
    free(p);
    printf("\nPila destruida\n");
    return true;
   }	
  }
  return false;	
}

void imprimirPila(Pila p,Nodo n,int i){ 
 int x=0;
 Elemento e=NULL;
 
  i++; 
 leerElemento(n,&e,&x);  
 printf("\n%d. %d\n",i,x);
 if(n->sig==NULL)
  return;
 imprimirPila(p,n->sig,i); 	
}
int generaAleatorio(int parametro){
 int nN=0;
 nN=rand()%parametro; 
 return nN;	
}
int main(void){
  int sw=3,numero=0,i=0,nN=0,volado=2;
  Elemento e=NULL,f=NULL;
  srand(time(NULL));
  printf("HOLA CULEBRA\n");
  Pila p=crearPila();
for(i=0;i<1000;i++){
  e=crearElemento();
   numero=generaAleatorio(1000);	
   insertarElemento(p,e,numero);
  }
  i=0;
 imprimirPila(p,p->base,i);
 
 for(i=0;i<1000;i++){
  
  quitarDato(p,&numero);  	
 }
 printf("\nPila Vacia\n");
 
  for(i=0;i<1000;i++){
   volado=generaAleatorio(2);
   switch(volado){
     case 0:
      if(p->longitud==0){
       break;	
      }	
      quitarDato(p,&numero);
      printf("\nElemento Eliminado: %d\n",numero);  
      break;
    case 1:
      e=crearElemento();
      numero=generaAleatorio(667);
      insertarElemento(p,e,numero);
      printf("\nElemento Insertado: %d\n",numero);  
      
    break;
     
   }	
   if(numero==666){
     
    system("color c");
    	
   }
  }
  i=0;
  imprimirPila(p,p->base,i);
  destruirPila(p);
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

#include<stdio.h>
#include<stdlib.h>
#define true 1
#define false 0


typedef struct cadena{
 char *str;
 int longitud;
}t_cadena,*Cadena;

typedef struct elemento{
 Cadena cadena;	
}t_elemento,*Elemento;

typedef struct nodo{
  Elemento e;
  struct nodo* sig;
}t_nodo,*Nodo;

typedef struct pila{
 Nodo tope;
 Nodo base;
 int longitud;
}t_pila,*Pila;

//Cadena:

Cadena crearCadena(int longitud){
 Cadena cad=NULL;
 char *str=NULL;
 cad=(Cadena)malloc(sizeof(t_cadena)); 
 str=(char*)malloc(longitud*sizeof(char));
 cad->str=str;
 cad->longitud=longitud;
 return cad;	
}
int escribirCadena(Cadena cad,char *exp){
 if(cad==NULL||cad->str==NULL)
   return false;
   cad->str=exp;
   return true; 	
}
int destruirCadena(Cadena cad){
  if(cad==NULL||cad->str==NULL)
   return false;
   cad->longitud=0;
   free(cad->str);
   free(cad);
   return true;   
}
int copiarCadena(Cadena fuente,Cadena destino){
 if(fuente==NULL||destino==NULL)
  return false;
 destino->str=fuente->str;
 destino->longitud=fuente->longitud;
 return true;  	
}
Cadena concatenar(Cadena a,Cadena b){
  char *ax=NULL,*bx=NULL,*cx=NULL;
  Cadena c=NULL;
  int lc=0,i=0,j=0;
  if(a==NULL || b==NULL)
  return NULL;
  lc=(a->longitud)+(b->longitud);
  ax=(char*)malloc(a->longitud*sizeof(char));
  bx=(char*)malloc(b->longitud*sizeof(char));
  cx=(char*)malloc(lc*sizeof(char));
  ax=a->str;
  bx=b->str;
  c=crearCadena(lc);
  for(i=0;i<a->longitud;i++)
   cx[i]=ax[i];  
  for(j=0;j<b->longitud;j++){
   cx[i]=bx[j];
   i++;
  }
   c->str=cx;
   return c;	
}
Cadena extraerSubcadenas(Cadena *c){
  int lc=0,l2=0,i=0;
  char *nuev=NULL,*xe=NULL;
  Cadena cad=NULL;
  for(i=0;i<(*c)->longitud;i++){
   printf("%c",(*c)->str[i]);
   }
  for(i=0;i<(*c)->longitud;i++){
   if(((*c)->str)[i]=='('||((*c)->str)[i]==')'||((*c)->str)[i]=='+'||((*c)->str)[i]=='-'||((*c)->str)[i]=='*'||((*c)->str)[i]=='/')
    break;	
  }
  lc=i;
  l2=(*c)->longitud-i;
  cad=crearCadena(i);
  nuev=(char*)malloc(i*sizeof(char));
  xe=(char*)malloc(l2*sizeof(char));
  for(i=0;i<lc;i++){
    nuev[i]=((*c)->str)[i];
  }
  for(i=0;i<(((*c)->longitud)-lc);i++){
   lc++;	
   xe[i]=((*c)->str)[lc];
  }
  (*c)->longitud=l2;
  (*c)->str=xe;
  cad->str=nuev;
  return cad;
}
//Elemento:
Elemento crearElemento(){
 Elemento e=NULL;
 e=(Elemento)malloc(sizeof(t_elemento));
 e->cadena=NULL;
 return e;	
}
int destruirElemento(Elemento e){
 if(e==NULL)
  return false;
 destruirCadena(e->cadena);
 free(e);
 return true; 	
}
int escribirElemento(Elemento e,char *cad){
  if(e==NULL||cad==NULL)
   return false;
  escribirCadena(e->cadena,cad);
  return true;  
}
char *leerElemento(Elemento e){
 char *cad=NULL;
 Cadena cero=NULL;
 if(e==NULL)
  return NULL;
 cero=e->cadena; 
 cad=cero->str;
 return cad;  	
}
int eliminarElemento(Elemento e){
 if(e==NULL)
  return false;
 destruirCadena(e->cadena);
 return true; 	
}
//Nodo:
Nodo crearNodo(){
 Nodo n=NULL;
 n=(Nodo)malloc(sizeof(t_nodo));
 n->e=NULL;
 n->sig=NULL;
 return n;	
}
int destruirNodo(Nodo n){
 if(n==NULL)
  return false;
 n->sig=NULL;
 destruirElemento(n->e);
 return true; 	
}
int colocarEnlace(Nodo n,Nodo sig){
 if(n==NULL||sig==NULL)
  return false;
 n->sig=sig;
 return true; 	
}
Nodo consultarEnlace(Nodo n){
 Nodo enlace=NULL;
 if(n==NULL)
  return false;
 enlace=n->sig;
 return enlace;  	
}
int insertarDato(Pila p,Cadena cad){
  int sw=false;
  Nodo n=NULL;
  Elemento e=NULL;
  e=crearElemento();
  e->cadena=cad;
  if(p==NULL||e==NULL)
   return false;
  n=crearNodo();
  if(n==NULL)
   return false;
  if(p->longitud==0)
   p->base=n;
  else
   colocarEnlace(p->tope,n);
  
  p->tope=n;
  p->longitud++;
  printf("\nDato insertado: %s",cad->str); 
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
int quitarDato(Pila p,Cadena *cade){
 Elemento e=NULL;
 int sw=0;
 Nodo n=NULL,aux=NULL;
 aux=buscarPretope(p,p->base,NULL);
 n=p->tope;
 e=n->e;
 *cade=e->cadena;
 aux->sig=NULL;
 destruirNodo(n);
 p->tope=aux;
 p->longitud--;
 return true;	
}
//Pila:
Pila crearPila(){
 Pila p=NULL;
 p=(Pila)malloc(sizeof(t_pila));
 p->base=NULL;
 return p;	
}
int destruirPila(Pila p){
   Nodo aux=NULL;
   if(p!=NULL){
   if(p->longitud>0){
    while(p->tope!=NULL){
    aux=p->tope;
    p->tope=consultarEnlace(p->tope);
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
//Conversores
Cadena infijaAPrefija(Cadena inf){
 Cadena z=NULL,pre=NULL,op=NULL,X=NULL,Y=NULL,auxi=NULL;
 char *aux=NULL;
 Pila p=NULL;
 int lon=0,i=0,sw=0;
 lon=inf->longitud;
 aux=inf->str;
 for(i=0;i<lon;i++){
  auxi=extraerSubcadenas(&inf);
  printf("\n%s\n",(auxi->str));	
 }
 p=crearPila();	
 while(1){
  auxi=extraerSubcadenas(&inf);
  
  if(p->longitud==0)
   break;	
  if((auxi->str)[0]==')'||(auxi->str)[0]=='\0'){
    while((((p->tope)->e)->cadena)->str[0]!='('){
      if(sw==0){
       if((((p->tope)->e)->cadena)->str[0]=='+'||(((p->tope)->e)->cadena)->str[0]=='-'||(((p->tope)->e)->cadena)->str[0]=='*'||(((p->tope)->e)->cadena)->str[0]=='/')
        quitarDato(p,&op);
       else
        quitarDato(p,&Y);
        sw=1; 	
      }
      else{
       quitarDato(p,&X);	
      }
    }
    z=concatenar(X,Y);
    z=concatenar(op,z);
    insertarDato(p,z);
   }
  else{
   insertarDato(p,auxi);	
  }
 }
 return z;
}


int main(void){
 char *xd=NULL;
 Cadena z=NULL;
 int x=0;
 printf("De cuantos carcteres es su expresion?\n");
 scanf("%d",&x);
 xd=(char*)malloc((x+1)*sizeof(char));
 printf("Ingrese su cadena de corridito:\n");
 scanf("%s",xd);
 for(int i=0;i<x;i++)
 z=crearCadena(x+1);
 z->str=xd;
 z=infijaAPrefija(z);
 printf("\nExpresion prefija:\n");
 for(x=0;x<z->longitud;z++){
  printf("%c",(z->str)[x]);	
 }	
}

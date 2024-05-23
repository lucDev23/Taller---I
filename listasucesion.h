#ifndef LISTASUCESION_H_INCLUDED
#define LISTASUCESION_H_INCLUDED
#include "miembrolista.h"

typedef struct nodoLS {
                      miembrolista info;
                      nodoLS * sig;
                     } NodoS;

typedef NodoS * ListaSucesion;

void CrearLista (ListaSucesion &L);

boolean Vacia (ListaSucesion L);

boolean encontrepadre (miembrolista ml, miembrolista m);

boolean encontrehermano (miembrolista m2, miembrolista m);

boolean encontresobrino (miembrolista m2, miembrolista m);

void mostrarlista (ListaSucesion L);

void InsBackSu (ListaSucesion &L, miembrolista m);

void InsertarAux (ListaSucesion &L, miembrolista m);

void InsEnOrden (ListaSucesion &L, miembrolista m);

void BorrarLista (ListaSucesion &L);

boolean hayMonarca (ListaSucesion L);

boolean hayAspirantes (ListaSucesion L);

fecha darfechamayor (ListaSucesion L);

miembrolista darmiembroS (ListaSucesion L, string nombre);

void nuevomonarca (ListaSucesion &L,string nombre, fecha f);

void Bajar_Lista (ListaSucesion L , string nomArch);

void Levantar_Lista (ListaSucesion &L, string nomArch);


#endif // LISTASUCESION_H_INCLUDED

#ifndef LISTASTRINGS_H_INCLUDED
#define LISTASTRINGS_H_INCLUDED
#include "stringdinamico.h"

typedef struct nodoL {
                     string info;
                     nodoL * sig;
                     } Nodo;

typedef Nodo * ListaString;

void CrearListaString (ListaString &L);

boolean ListaVacia (ListaString L);

void InsBackS (ListaString &L, string s);

void BorrarLS (ListaString &L);

int LargoIter (ListaString L);

void dividirString (ListaString &L, string s);

void MostrarStrings (ListaString L);

void devolver2s (ListaString L, string &s);

void devolver3s (ListaString L, string &s);

void devolver4s (ListaString L, string &s);

void devolver5s (ListaString L, string &s);





#endif // LISTASTRINGS_H_INCLUDED

#ifndef FAMILIAREAL_H_INCLUDED
#define FAMILIAREAL_H_INCLUDED
#include "miembro.h"

typedef struct nodoA {
                     miembro info;
                     nodoA * hizq;
                     nodoA * hder;
                     } nodo;
typedef nodo * ABB;

void CrearABB (ABB &a);

void Insert (ABB &a, miembro m);

boolean PerteneceABB (ABB a, string s);

boolean EsVacio (ABB a);

void Eliminar (ABB &a);

void listarMiembros (ABB a);

fecha darfnacimiento (ABB a, string nombre);

void Bajar_ABB_Aux (ABB a, FILE * f);

void Bajar_ABB (ABB a, string nomArch);

void Levantar_ABB (ABB &a, string nomArch);

#endif // FAMILIAREAL_H_INCLUDED

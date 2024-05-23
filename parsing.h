#ifndef PARSING_H_INCLUDED
#define PARSING_H_INCLUDED
#include "familiareal.h"
#include "listasucesion.h"
#include "comandos.h"
#include "archivo.h"

void ejecutarIniciarAux (ABB &familiareal, ListaSucesion &listasuc, string &nombre, fecha nacimiento);

void ejecutarIniciar (ListaString listastring, ABB &familiareal, ListaSucesion &listasuc, comando com);

void ejecutarNacimientoAux (ABB &familiareal, ListaSucesion &listasuc, string &nombre, string &nombreprog, fecha nacimiento);

void ejecutarNacimiento (ListaString listastring, ABB &familiareal, ListaSucesion &listasuc, comando com);

void ejecutarFallecimientoAux (ABB &familiareal, ListaSucesion &listasuc, string nombre, fecha fallecimiento);

void ejecutarFallecimiento (ListaString listastring, ABB &familiareal, ListaSucesion &listasuc, comando com);

void ejecutarAbdicacionAux (ABB &familiareal, ListaSucesion &listasuc, string nombre, fecha abdicacion);

void ejecutarAbdicacion (ListaString listastring, ABB &familiareal, ListaSucesion &listasuc, comando com);

void ejecutarMiembros (ListaString listastring, ABB familiareal, comando com);

void ejecutarMonarcasAux (ListaSucesion listasuc);

void ejecutarMonarcas (ListaString listastring, ListaSucesion listasuc, comando com);

void ejecutarAspirantesAux (ListaSucesion listasuc);

void ejecutarAspirantes (ListaString listastring, ListaSucesion listasuc, comando com);

void ejecutarHistorial (ListaString listastring, ListaSucesion listasuc, comando com);

void ejecutarRespaldar (ListaString listastring, ABB familiareal, ListaSucesion listasuc, comando com);

void ejecutarRecuperar (ListaString listastring, ABB &familiareal, ListaSucesion &listasuc, comando com);

void ejecutarSalir (ListaString listastring, ABB &familiareal, ListaSucesion &listasuc, comando &com);
#endif // PARSING_H_INCLUDED

#ifndef MIEMBRO_H_INCLUDED
#define MIEMBRO_H_INCLUDED
#include "fecha.h"

typedef struct {
                string nombre;
                fecha nacimiento;
                string progenitor;
                boolean primer_monarca;
                } miembro;

void cargarmiembro1 (miembro &m, string nombre, fecha f);

void cargarmiembro (miembro &m, string nombre, fecha f, string progenitor);

void desplegarmiembro (miembro m);

void darnombre (miembro m, string &s);

fecha darfechan (miembro m);

void darnombreprog (miembro m, string &s);

boolean primerM (miembro m);

boolean miembropref (miembro m, miembro m2);

void Bajar_Miembro (miembro m, FILE * f);

void Levantar_Miembro (miembro &m, FILE * f);

void LiberarMiembro (miembro &m);

#endif // MIEMBRO_H_INCLUDED

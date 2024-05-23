#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
#include "stringdinamico.h"

typedef struct
{   int dia;
    int mes;
    int anio;
}fecha;

void CargarFecha (fecha &f);

void DesplegarFecha (fecha f);

void IniciarFecha (fecha &f);

int dardia (fecha f);

int darmes (fecha f);

int daranio (fecha f);

boolean validarFecha (fecha f);

boolean fechaapta (fecha f1, fecha f2);

fecha stringAFecha (string s);


#endif // FECHA_H_INCLUDED

#ifndef MIEMBROLISTA_H_INCLUDED
#define MIEMBROLISTA_H_INCLUDED
#include "miembro.h"

typedef struct {
                miembro m;
                boolean monarca_actual;
                boolean fue_monarca;
                boolean aspirante;
                boolean abdico;
                boolean fallecio;
                fecha ascension;
                fecha abdicacion;
                fecha fallecimiento;
                } miembrolista;

void cargarmiemlist1 (miembrolista &ml, miembro m);

void cargarmiemlist (miembrolista &ml, miembro m);

miembro darmiembro (miembrolista m);

boolean esactualM (miembrolista m);

boolean fueM (miembrolista m);

boolean esAsp (miembrolista m);

boolean abdico (miembrolista m);

boolean fallecio (miembrolista m);

fecha darFascension (miembrolista m);

fecha darFabdicacion (miembrolista m);

fecha darFfallecimiento (miembrolista m);

void listarMonarcas (miembrolista m);

void listarprimerM (miembrolista m);

void listaractualM (miembrolista m);

void listarfueM (miembrolista m);

void listarAsp (miembrolista m);

void listaresAsp (miembrolista m);

void listaraof (miembrolista m);

void Bajar_MiembroL (miembrolista ml, FILE * f);

void Levantar_MiembroL (miembrolista &ml, FILE * f);

void BorrarMiembroL (miembrolista ml);

#endif // MIEMBROLISTA_H_INCLUDED

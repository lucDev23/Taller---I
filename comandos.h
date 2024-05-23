#ifndef COMANDOS_H_INCLUDED
#define COMANDOS_H_INCLUDED
#include "listastrings.h"

typedef enum {INICIAR, NACIMIENTO, FALLECIMIENTO, ABDICACION, MIEMBROS, MONARCAS, ASPIRANTES, HISTORIAL, RESPALDAR, RECUPERAR, SALIR, ERROR} comando;

comando identificarcomando (ListaString s);

#endif // COMANDOS_H_INCLUDED

#include <stdio.h>
#include "boolean.h"
void cargar (boolean &b)
{
    int valor;
        printf ("ingrese 1 si para true y 0 para false: ");
        scanf ("%d",& valor);
    if (valor == 0)
        b = FALSE;
    else
        b = TRUE;
}
void mostrar (boolean b)
{
    if (b)
        printf ("verdadero");
    else
        printf ("falso");
}


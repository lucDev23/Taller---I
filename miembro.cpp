#include <stdio.h>
#include "miembro.h"

void cargarmiembro1 (miembro &m, string nombre, fecha f)
{
    strcrear (m.nombre);
    strcrear (m.progenitor);
    strcop (m.nombre, nombre);
    m.nacimiento = f;
    m.primer_monarca = TRUE;
}

void cargarmiembro (miembro &m, string nombre, fecha f, string progenitor)
{
    strcrear (m.nombre);
    strcrear (m.progenitor);
    strcop (m.nombre, nombre);
    m.nacimiento = f;
    strcop (m.progenitor, progenitor);
    m.primer_monarca = FALSE;
}

void desplegarmiembro (miembro m)
{
    print (m.nombre);
    if (m.primer_monarca)
        printf (" primer monarca");
    else
    {
        printf (" hijo/a de ");
        print (m.progenitor);
    }
    printf (" nacio el ");
    DesplegarFecha (m.nacimiento);
    printf ("\n                  ");
}

void darnombre (miembro m, string &s)
{
    strcop (s, m.nombre);
}

fecha darfechan (miembro m)
{
    return (m.nacimiento);
}

void darnombreprog (miembro m, string &s)
{
    strcop (s, m.progenitor);
}

boolean primerM (miembro m)
{
    return (m.primer_monarca);
}

boolean miembropref (miembro m, miembro m2)
{
    boolean preferencia = FALSE, resultado = FALSE;
    int i=0;
    while ((m.nombre [i] != '\0' || m2.nombre [i] != '\0') && !resultado)
    {
        if (m2.nombre [i] < m.nombre [i])
        {
            resultado = TRUE;
            preferencia = TRUE;
        }
        else
            if (m2.nombre [i] > m.nombre [i])
            {
                resultado = TRUE;
                preferencia = FALSE;
            }
            else
                if (m2.nombre [i] == m.nombre [i])
                    i++;
    }
    return preferencia;
}

void Bajar_Miembro (miembro m, FILE * f)
{
    Bajar_String (m.nombre, f);
    fwrite (&m.nacimiento, sizeof(fecha), 1, f);
    Bajar_String (m.progenitor, f);
    fwrite (&m.primer_monarca, sizeof(boolean), 1, f);
}

void Levantar_Miembro (miembro &m, FILE * f)
{
    strcrear (m.nombre);
    Levantar_String (m.nombre, f);
    fread (&m.nacimiento, sizeof(fecha), 1, f);
    strcrear (m.progenitor);
    Levantar_String (m.progenitor, f);
    fread (&m.primer_monarca, sizeof(boolean), 1, f);
}

void LiberarMiembro (miembro &m)
{
    strdestruir (m.nombre);
    strdestruir (m.progenitor);
}



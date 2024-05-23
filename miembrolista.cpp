#include <stdio.h>
#include "miembrolista.h"

void cargarmiemlist1 (miembrolista &ml, miembro m)
{
    ml.m = m;
    ml.monarca_actual = TRUE;
    ml.abdico = FALSE;
    ml.fallecio = FALSE;
    ml.fue_monarca = FALSE;
    ml.ascension = m.nacimiento;
    ml.aspirante = FALSE;
    IniciarFecha (ml.abdicacion);
    IniciarFecha (ml.fallecimiento);
}

void cargarmiemlist (miembrolista &ml, miembro m)
{
    ml.m = m;
    ml.aspirante = TRUE;
    ml.abdico = FALSE;
    ml.fallecio = FALSE;
    ml.fue_monarca = FALSE;
    IniciarFecha (ml.abdicacion);
    IniciarFecha (ml.fallecimiento);
}

miembro darmiembro (miembrolista m)
{
    return m.m;
}

boolean esactualM (miembrolista m)
{
    return m.monarca_actual;
}

boolean fueM (miembrolista m)
{
    return m.fue_monarca;
}

boolean esAsp (miembrolista m)
{
    return m.aspirante;
}

boolean abdico (miembrolista m)
{
    return m.abdico;
}

boolean fallecio (miembrolista m)
{
    return m.fallecio;
}

fecha darFascension (miembrolista m)
{
    return m.ascension;
}

fecha darFabdicacion (miembrolista m)
{
    return m.abdicacion;
}

fecha darFfallecimiento (miembrolista m)
{
    return m.fallecimiento;
}

void listarMonarcas (miembrolista m)
{
    string s;
    strcrear (s);
    darnombre (m.m,s);
    print (s);
    strdestruir (s);
    printf (" desde el ");
    DesplegarFecha (m.ascension);
    if (esactualM (m))
        printf (" hasta la actualidad");
    else
    {
        printf (" hasta el ");
        if (abdico (m))
            DesplegarFecha (m.abdicacion);
        else
            DesplegarFecha (m.fallecimiento);
    }
    printf ("\n                  ");
}

void listarprimerM (miembrolista m)
{
    string s;
    strcrear (s);
    darnombre (m.m,s);
    print (s);
    printf (" primer monarca\n                      monarca desde el ");
    DesplegarFecha (m.ascension);
    if (m.monarca_actual)
        printf (" hasta la actualidad");
    else
    {
        if (m.abdico)
        {
            printf (" hasta el ");
            DesplegarFecha (m.abdicacion);
        }
        if (m.fallecio)
        {
            if (!m.abdico)
            {
                printf (" hasta el ");
                DesplegarFecha (m.fallecimiento);
            }
            printf ("\n                      fallecio el ");
            DesplegarFecha (m.fallecimiento);
        }
    }
    strdestruir (s);
}

void listaractualM (miembrolista m)
{
    string s,s2;
    strcrear (s);
    strcrear (s2);
    darnombre (m.m,s);
    darnombreprog (m.m,s2);
    print (s);
    printf (" hijo/a de ");
    print (s2);
    printf ("\n                      monarca desde el ");
    DesplegarFecha (m.ascension);
    printf (" hasta la actualidad");
    strdestruir (s);
    strdestruir (s2);
}

void listarfueM (miembrolista m)
{
    string s,s2;
    strcrear (s);
    strcrear (s2);
    darnombre (m.m,s);
    darnombreprog (m.m,s2);
    print (s);
    printf (" hijo/a de ");
    print (s2);
    printf ("\n                      monarca desde el ");
    DesplegarFecha (m.ascension);
    if (m.abdico)
    {
        printf (" hasta el ");
        DesplegarFecha (m.abdicacion);
        printf ("\n                      abdico el ");
        DesplegarFecha (m.abdicacion);
    }
    if (m.fallecio)
    {
        if (!m.abdico)
        {
            printf (" hasta el ");
            DesplegarFecha (m.fallecimiento);
        }
        printf ("\n                      fallecio el ");
        DesplegarFecha (m.fallecimiento);
    }
    strdestruir (s);
    strdestruir (s2);
}

void listarAsp (miembrolista m)
{
    string s,s2;
    strcrear (s);
    strcrear (s2);
    darnombre (m.m,s);
    darnombreprog (m.m,s2);
    print (s);
    printf (" hijo/a de ");
    print (s2);
    strdestruir (s);
    strdestruir (s2);
    printf ("\n                  ");
}

void listaresAsp (miembrolista m)
{
    string s,s2;
    strcrear (s);
    strcrear (s2);
    darnombre (m.m,s);
    darnombreprog (m.m,s2);
    print (s);
    printf (" hijo/a de ");
    print (s2);
    printf ("\n                      aspirante al trono ");
    strdestruir (s);
    strdestruir (s2);
}

void listaraof (miembrolista m)
{
    string s,s2;
    strcrear (s);
    strcrear (s2);
    darnombre (m.m,s);
    darnombreprog (m.m,s2);
    print (s);
    printf (" hijo/a de ");
    print (s2);
    if (m.abdico)
    {
        printf ("\n                      abdico el ");
        DesplegarFecha (m.abdicacion);
    }
    if (m.fallecio)
    {
        printf ("\n                      fallecio el ");
        DesplegarFecha (m.fallecimiento);
    }
    strdestruir (s);
    strdestruir (s2);
}

void Bajar_MiembroL (miembrolista ml, FILE * f)
{
    Bajar_Miembro (ml.m, f);
    fwrite (&ml.monarca_actual, sizeof(boolean), 1, f);
    fwrite (&ml.fue_monarca, sizeof(boolean), 1, f);
    fwrite (&ml.aspirante, sizeof(boolean), 1, f);
    fwrite (&ml.abdico, sizeof(boolean), 1, f);
    fwrite (&ml.fallecio, sizeof(boolean), 1, f);
    fwrite (&ml.ascension, sizeof(fecha), 1, f);
    fwrite (&ml.abdicacion, sizeof(fecha), 1, f);
    fwrite (&ml.fallecimiento, sizeof(fecha), 1, f);
}

void Levantar_MiembroL (miembrolista &ml, FILE * f)
{
    Levantar_Miembro (ml.m, f);
    fread (&ml.monarca_actual, sizeof(boolean), 1, f);
    fread (&ml.fue_monarca, sizeof(boolean), 1, f);
    fread (&ml.aspirante, sizeof(boolean), 1, f);
    fread (&ml.abdico, sizeof(boolean), 1, f);
    fread (&ml.fallecio, sizeof(boolean), 1, f);
    fread (&ml.ascension, sizeof(fecha), 1, f);
    fread (&ml.abdicacion, sizeof(fecha), 1, f);
    fread (&ml.fallecimiento, sizeof(fecha), 1, f);
}

void BorrarMiembroL (miembrolista ml)
{
    LiberarMiembro (ml.m);
}

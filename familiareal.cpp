#include <stdio.h>
#include "familiareal.h"

void CrearABB (ABB &a)
{
    a = NULL;
}

void Insert (ABB &a, miembro m)
{
    if (a == NULL)
    {
        a = new nodo;
        a -> info = m;
        a -> hizq = NULL;
        a -> hder = NULL;
    }
    else
    {
        if (miembropref(a -> info, m))
            Insert (a -> hizq, m);
        else
            Insert (a -> hder, m);
    }
}

boolean PerteneceABB (ABB a, string s)
{
    if (a == NULL)
    {
        return FALSE;
    }
    else
    {
        string s2;
        strcrear (s2);
        darnombre (a -> info, s2);
        if (streq (s2,s))
        {
            return TRUE;
        }
        else
            if (stringpref(s2,s))
            {
                return PerteneceABB (a -> hizq, s);
            }
            else
            {
                return PerteneceABB (a -> hder, s);
            }
    }
}

boolean EsVacio (ABB a)
{
    return (boolean) (a == NULL);
}

void Eliminar (ABB &a)
{
    if (a != NULL)
    {
        Eliminar (a -> hizq);
        Eliminar (a -> hder);
        LiberarMiembro (a -> info);
        delete a;
        a = NULL;
    }
}

void listarMiembros (ABB a)
{
    if (a != NULL)
    {
        listarMiembros (a -> hizq);
        desplegarmiembro (a -> info);
        listarMiembros (a -> hder);
    }
}

fecha darfnacimiento (ABB a, string nombre)
{
    if (a != NULL)
    {
        string s2;
        strcrear (s2);
        darnombre (a -> info, s2);
        if (streq (s2,nombre))
            return darfechan (a -> info);
        else
            if (stringpref(s2,nombre))
                return darfnacimiento (a -> hizq, nombre);
            else
                return darfnacimiento (a -> hder, nombre);
    }
}

void Bajar_ABB_Aux (ABB a, FILE * f)
{
    if (a != NULL)
    {
        Bajar_Miembro (a -> info, f);
        Bajar_ABB_Aux (a -> hizq, f);
        Bajar_ABB_Aux (a -> hder, f);
    }
}

void Bajar_ABB (ABB a, string nomArch)
{
    FILE * f = fopen (nomArch, "wb");
    Bajar_ABB_Aux (a, f);
    fclose (f);
}

void Levantar_ABB (ABB &a, string nomArch)
{
    FILE * f = fopen (nomArch, "rb");
    miembro m;
    Levantar_Miembro (m, f);
    while (!feof(f))
    {
        Insert (a, m);
        Levantar_Miembro (m, f);
    }
    fclose (f);
}



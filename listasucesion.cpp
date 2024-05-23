#include <stdio.h>
#include "listasucesion.h"

void CrearLista (ListaSucesion &L)
{
    L = NULL;
}

boolean Vacia (ListaSucesion L)
{
    boolean es = FALSE;
    if (L == NULL)
        es = TRUE;
    return es;
}

boolean encontrepadre (miembrolista ml, miembrolista m)
{
    string sl,sm;
    strcrear (sl);
    strcrear (sm);
    darnombre (darmiembro (ml),sl);
    darnombreprog (darmiembro (m),sm);
    if (streq (sl,sm))
    {
        strdestruir (sl);
        strdestruir (sm);
        return TRUE;
    }
    else
    {
        strdestruir (sl);
        strdestruir (sm);
        return FALSE;
    }
}

boolean encontrehermano (miembrolista m2, miembrolista m)
{
    string sl,sm;
    strcrear (sl);
    strcrear (sm);
    darnombreprog (darmiembro (m2),sl);
    darnombreprog (darmiembro (m),sm);
    if (streq (sl,sm))
    {
        strdestruir (sl);
        strdestruir (sm);
        return TRUE;
    }
    else
    {
        strdestruir (sl);
        strdestruir (sm);
        return FALSE;
    }
}


//Chequea hermanos
void InsertarAux (ListaSucesion &L, miembrolista m)
{
    if (L -> sig == NULL)
    {
        ListaSucesion nuevo = new NodoS;
        nuevo->info = m;
        nuevo->sig = L->sig;
        L->sig = nuevo;
    }
    else
    {
        if(!encontrehermano(L->sig->info,m) && !encontrepadre (L->info, L->sig->info))
        {
            ListaSucesion nuevo = new NodoS;
            nuevo->info = m;
            nuevo->sig = L->sig;
            L->sig = nuevo;
        }
        else
            InsertarAux(L->sig,m);
    }
}

void InsEnOrden (ListaSucesion &L, miembrolista m)
{
    if (L == NULL)
    {
        ListaSucesion aux = new NodoS;
        aux -> info = m;
        aux -> sig = L;
        L = aux;
    }
    else
    {
        if(L != NULL)
        {
            if(encontrepadre(L ->info, m))
                InsertarAux(L,m);
            else
                InsEnOrden(L->sig, m);
        }
    }
}

void InsBackSu (ListaSucesion &L, miembrolista m)
{
    if (L == NULL)
    {
        L = new NodoS;
        L -> info = m;
        L -> sig = NULL;
    }
    else
        InsBackSu (L -> sig, m);
 }

void mostrarlista (ListaSucesion L)
{
    int i = 1;
    while (L != NULL)
        {
            printf ("%d - ", i);
            if (primerM (L ->info.m))
                listarprimerM (L->info);
            else
                if (esactualM (L->info))
                    listaractualM (L->info);
                else
                    if (fueM (L->info))
                        listarfueM (L->info);
                    else
                        if (esAsp (L->info))
                            listaresAsp (L->info);
                        else
                            listaraof (L->info);
            printf ("\n                  ");
            i++;
            L = L -> sig;
        }
}
void BorrarLista (ListaSucesion &L)
{
    if(L != NULL)
    {
        ListaSucesion aux;
        aux = L;
        L = L -> sig;
        delete aux;
        BorrarLista(L);
    }
}

boolean hayMonarca (ListaSucesion L)
{
    boolean existe = FALSE;
    while (L != NULL && !existe)
    {
        if (esactualM (L -> info))
            existe = TRUE;
        else
            L = L -> sig;
    }
    return existe;
}

boolean hayAspirantes (ListaSucesion L)
{
    boolean existe = FALSE;
    while (L != NULL && !existe)
    {
        if (esAsp (L -> info))
            existe = TRUE;
        else
            L = L -> sig;
    }
    return existe;
}

fecha darfechamayor (ListaSucesion L)
{
    if (L != NULL)
    {
    fecha fmayor;
    fmayor = darfechan (darmiembro (L -> info));
    while (L != NULL)
    {
        if (fechaapta (fmayor,darFfallecimiento (L -> info)))
            fmayor = darFfallecimiento (L -> info);
        else
            if (fechaapta (fmayor,darFabdicacion (L -> info)))
                fmayor = darFabdicacion (L -> info);
            else
                if (fechaapta (fmayor,darfechan (darmiembro (L -> info))))
                    fmayor = darfechan (darmiembro (L -> info));
        L = L -> sig;
    }
    return fmayor;
    }
}

miembrolista darmiembroS (ListaSucesion L, string nombre)
{
    string nombre2;
    miembrolista m;
    boolean encontro = FALSE;
    while (L != NULL && !encontro)
    {
        strcrear (nombre2);
        darnombre (darmiembro(L -> info), nombre2);
        if (streq (nombre2, nombre))
        {
            encontro = TRUE;
            m = L -> info;
            strdestruir (nombre2);
        }
        else
        {
            L = L -> sig;
            strdestruir (nombre2);
        }
    }
    return m;
}

void nuevomonarca (ListaSucesion &L,string nombre, fecha f)
{
    string nombre2;
    boolean encontro = FALSE, encontro2 = FALSE;
    ListaSucesion aux = L;
    while (aux != NULL && !encontro)
    {
        strcrear (nombre2);
        darnombre (darmiembro(aux -> info), nombre2);
        if (streq (nombre2, nombre))
        {
            encontro = TRUE;
            while (aux != NULL && !encontro2)
            {
                if (esAsp (aux -> info))
                {
                    aux -> info.monarca_actual = TRUE;
                    aux -> info.ascension = f;
                    aux -> info.aspirante = FALSE;
                    encontro2 = TRUE;
                }
                else
                    aux = aux -> sig;
            }
            strdestruir (nombre2);
        }
        else
        {
            aux = aux -> sig;
            strdestruir (nombre2);
        }
    }
}

void Bajar_Lista (ListaSucesion L, string nomArch)
{
    FILE * f = fopen (nomArch, "wb");
    while (L != NULL)
    {
        Bajar_MiembroL (L -> info, f);
        L = L -> sig;
    }
    fclose (f);
}

void Levantar_Lista (ListaSucesion &L, string nomArch)
{
    FILE * f = fopen (nomArch, "rb");
    miembrolista ml;
    Levantar_MiembroL (ml, f);
    while (!feof(f))
    {
        InsBackSu (L, ml);
        Levantar_MiembroL (ml, f);
    }
    fclose (f);
}



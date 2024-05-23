#include <stdio.h>
#include "listastrings.h"

void CrearListaString (ListaString &L)
{
    L = NULL;
}

boolean ListaVacia (ListaString L)
{
    boolean es = FALSE;
    if (L == NULL)
        es = TRUE;
    return es;
}

void InsBackS (ListaString &L, string s)
{
    if (L == NULL)
    {
        L = new Nodo;
        strcrear (L -> info);
        strcop (L -> info, s);
        L -> sig = NULL;
    }
    else
        InsBackS (L -> sig, s);
}

void BorrarLS (ListaString &L)
{
    if(L != NULL)
    {
        ListaString aux;
        aux = L;
        L = L -> sig;
        strdestruir (aux->info);
        delete aux;
        BorrarLS(L);
    }
}

int LargoIter (ListaString L)
{
    int largo = 0;
    while (L != NULL)
    {
        largo++;
        L = L -> sig;
    }
    return largo;
}

void dividirString (ListaString &L, string s)
{
    int i=0, i2;
    string s2;
    while (s [i] != '\0')
    {
        if (s [i] == ' ')
            i++;
        else
        {
            strcrear (s2);
            string aux = new char[MAX];
            i2=0;
            while (s [i] != ' ' && s [i] != '\0')
            {
                aux [i2] = s [i];
                i2++;
                i++;
            }
            aux [i2] = '\0';
            strcop (s2,aux);
            strdestruir (aux);
            InsBackS (L, s2);
            strdestruir (s2);
        }
    }
}

void MostrarStrings (ListaString L)
{
    while (L != NULL)
    {
        print (L -> info);
        printf (" ");
        L = L -> sig;
    }
}

void devolver2s (ListaString L, string &s)
{
    strcop (s,L -> sig -> info);
}

void devolver3s (ListaString L, string &s)
{
    strcop (s,L -> sig -> sig -> info);
}

void devolver4s (ListaString L, string &s)
{
    strcop (s,L -> sig -> sig -> sig -> info);
}

void devolver5s (ListaString L, string &s)
{
    strcop (s,L -> sig -> sig -> sig -> sig -> info);
}


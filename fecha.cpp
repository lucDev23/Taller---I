#include <stdio.h>
#include "fecha.h"


void CargarFecha (fecha &f)
{
    printf (" Ingrese un dia: ");
    scanf ("%d", &f.dia);
    printf ("\n Ingrese un mes: ");
    scanf ("%d", &f.mes);
    printf ("\n Ingrese un anio: ");
    scanf ("%d", &f.anio);
}

void IniciarFecha (fecha &f)
{
    f.dia = 0;
    f.mes = 0;
    f.anio = 0;
}

void DesplegarFecha (fecha f)
{
    if (f.dia < 10)
        printf ("0%d/",f.dia);
    else
        printf ("%d/",f.dia);
    if (f.mes < 10)
        printf ("0%d/",f.mes);
    else
        printf ("%d/",f.mes);
    if (f.anio < 10)
        printf ("000%d",f.anio);
    else
        if (f.anio < 100)
            printf ("00%d",f.anio);
        else
            if (f.anio < 1000)
                printf ("0%d",f.anio);
            else
                printf ("%d",f.anio);
}

int dardia (fecha f)
{
    return (f.dia);
}
int darmes (fecha f)
{
    return (f.mes);
}
int daranio (fecha f)
{
    return (f.anio);
}

boolean validarFecha (fecha f)
{
    boolean valida2;
    switch (f.mes)
    {
        case 1:case 3:case 5:case 7:case 8:case 10:case 12:
            if (f.dia >= 1 && f.dia <= 31)
                valida2 = TRUE;
            else
                valida2 = FALSE;
            break;

        case 4:case 6:case 9:case 11:
            if (f.dia >= 1 && f.dia <= 30)
                valida2 = TRUE;
            else
                valida2 = FALSE;
            break;

        case 2:
            if (f.anio % 4 == 0)
                if (f.dia >= 1 && f.dia <= 29)
                    valida2 = TRUE;
                else
                    valida2 = FALSE;
            else
                if (f.dia >= 1 && f.dia <= 28)
                    valida2 = TRUE;
                else
                    valida2 = FALSE;
            break;

        default: valida2 = FALSE;
    }
    return (valida2);
}

boolean fechaapta (fecha f1, fecha f2)
{
    if (f2.anio > f1.anio)
        return (TRUE);
    else
        if (f2.mes > f1.mes && f2.anio == f1.anio)
            return (TRUE);
        else
            if (f2.dia > f1.dia && f2.mes == f1.mes && f2.anio == f1.anio)
                return (TRUE);
            else
                if (f2.dia == f1.dia && f2.mes == f1.mes && f2.anio == f1.anio)
                    return (TRUE);
                else
                    return (FALSE);
}

fecha stringAFecha (string s)
{
    fecha f;
    IniciarFecha (f);
    string aux = new char[MAX];
    int i=0;
    while (s [i] != '\0' && s [i] != '/')
    {
        aux [i] = s [i];
        i++;
    }
    i++;
    f.dia = f.dia + (aux [0] - 48) * 10 + (aux [1] - 48);
    while (s [i] != '\0' && s [i] != '/')
    {
        aux [i] = s [i];
        i++;
    }
    i++;
    f.mes = f.mes + (aux [3] - 48) * 10 + (aux [4] - 48);
    while (s [i] != '\0' && s [i] != '/')
    {
        aux [i] = s [i];
        i++;
    }
    i++;
    f.anio = f.anio + (aux [6] - 48) * 1000 + (aux [7] - 48) * 100 + (aux [8] - 48) * 10 + (aux [9] - 48);
    strdestruir (aux);
    return (f);
}






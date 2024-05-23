#include <stdio.h>
#include "parsing.h"


void ejecutarIniciarAux (ABB &familiareal, ListaSucesion &listasuc, string &nombre, fecha nacimiento)
{
    miembro m;
    miembrolista ml;
    cargarmiembro1 (m,nombre,nacimiento);
    Insert (familiareal, m);
    cargarmiemlist1 (ml,m);
    InsEnOrden (listasuc, ml);
}

void ejecutarIniciar (ListaString listastring, ABB &familiareal, ListaSucesion &listasuc, comando com)
{
    string sfecha,snombre;
    strcrear (sfecha);
    strcrear (snombre);
    fecha f;
    if (com == INICIAR)
    {
        if (LargoIter (listastring) != 3)
            printf ("cantidad de parametros incorrecta\n");
        else
        {
            devolver2s (listastring, sfecha);
            if (!stringEsFecha (sfecha))
                printf ("el formato de la fecha es invalido\n");
            else
            {
                f = stringAFecha (sfecha);
                if (!validarFecha (f))
                    printf ("la fecha es invalida\n");
                else
                    {
                        devolver3s (listastring, snombre);
                        if (!esAlfabetico (snombre))
                            printf ("el nombre del miembro no es alfabetico\n");
                        else
                        {
                            if (!EsVacio (familiareal) || !Vacia (listasuc))
                            {
                                printf ("ya existe algun miembro en la dinastia\n");
                            }
                            else
                            {
                                ejecutarIniciarAux (familiareal,listasuc,snombre,f);
                                printf ("dinastia iniciada\n");
                            }
                        }
                    }
            }
        }
    }
    strdestruir (sfecha);
    strdestruir (snombre);
}

void ejecutarNacimientoAux (ABB &familiareal, ListaSucesion &listasuc, string &nombre, string &nombreprog, fecha nacimiento)
{
    miembro m;
    miembrolista ml;
    cargarmiembro (m,nombre,nacimiento,nombreprog);
    Insert (familiareal, m);
    cargarmiemlist (ml,m);
    if (!hayMonarca)
    {
        ml.monarca_actual = TRUE;
        ml.ascension = darfechan (ml.m);
    }
    else
    {
        ml.monarca_actual = FALSE;
        IniciarFecha (ml.ascension);
    }
    InsEnOrden (listasuc, ml);
}

void ejecutarNacimiento (ListaString listastring, ABB &familiareal, ListaSucesion &listasuc, comando com)
{
    string sfecha,schar,nombre,nprogenitor;
    strcrear (sfecha);
    strcrear (schar);
    strcrear (nombre);
    strcrear (nprogenitor);
    fecha f,f2;
    if (com == NACIMIENTO)
    {
        if (LargoIter (listastring) != 5)
            printf ("cantidad de parametros incorrecta\n");
        else
        {
            devolver2s (listastring, sfecha);
            if (!stringEsFecha (sfecha))
                printf ("el formato de la fecha es invalido\n");
            else
            {
                f = stringAFecha (sfecha);
                if (!validarFecha (f))
                    printf ("la fecha es invalida\n");
                else
                    {
                        f2 = darfechamayor (listasuc);
                        if (!fechaapta(f2,f))
                            printf ("la fecha ingresada no es posterior a todas las fechas ingresadas en el sistema\n");
                        else
                        {
                            devolver3s (listastring, nprogenitor);
                            if (!esAlfabetico (nprogenitor))
                                printf ("el nombre del progenitor no es alfabetico\n");
                            else
                            {
                                if (!PerteneceABB (familiareal, nprogenitor))
                                    printf ("el nombre del progenitor no existe en la dinastia\n");
                                else
                                {
                                    miembrolista m;
                                    m = darmiembroS (listasuc, nprogenitor);
                                    if (fallecio (m))
                                        printf ("el progenitor ya fallecio\n");
                                    else
                                    {
                                        devolver4s (listastring, schar);
                                        if (!streq (schar, "->"))
                                            printf ("el cuarto parametro no es igual a ->\n");
                                        else
                                        {
                                            devolver5s (listastring, nombre);
                                            if (!esAlfabetico (nombre))
                                                printf ("el nombre del miembro no es alfabetico\n");
                                            else
                                                if (PerteneceABB (familiareal, nombre))
                                                    printf ("el nombre del nuevo miembro ya existe en la familia\n");
                                                else
                                                {
                                                    ejecutarNacimientoAux (familiareal, listasuc, nombre, nprogenitor, f);
                                                    printf ("nacimiento registrado\n");
                                                }
                                        }
                                    }
                                }
                            }
                        }
                    }
            }
        }
    }
    strdestruir (sfecha);
    strdestruir (schar);
    strdestruir (nombre);
    strdestruir (nprogenitor);
}

void ejecutarFallecimientoAux (ABB &familiareal, ListaSucesion &listasuc, string nombre, fecha fallecimiento)
{
    string nombre2;
    boolean encontro = FALSE;
    ListaSucesion aux = listasuc;
    while (aux != NULL && !encontro)
    {
        strcrear (nombre2);
        darnombre (darmiembro(aux -> info), nombre2);
        if (streq (nombre2, nombre))
        {
            encontro = TRUE;
            strdestruir (nombre2);
            aux -> info.fallecimiento = fallecimiento;
            aux -> info.fallecio = TRUE;
            if (esactualM (aux -> info))
            {
                aux -> info.fue_monarca = TRUE;
                aux -> info.monarca_actual = FALSE;
                nuevomonarca (listasuc, nombre, fallecimiento);
            }
            else
                if (esAsp (aux -> info))
                    aux -> info.aspirante = FALSE;
        }
        else
        {
            aux = aux -> sig;
            strdestruir (nombre2);
        }
    }
}

void ejecutarFallecimiento (ListaString listastring, ABB &familiareal, ListaSucesion &listasuc, comando com)
{
    string sfecha,snombre;
    strcrear (sfecha);
    strcrear (snombre);
    fecha f,f2;
    if (com == FALLECIMIENTO)
    {
        if (LargoIter (listastring) != 3)
            printf ("cantidad de parametros incorrecta\n");
        else
        {
            devolver2s (listastring, sfecha);
            if (!stringEsFecha (sfecha))
                printf ("el formato de la fecha es invalido\n");
            else
            {
                f = stringAFecha (sfecha);
                if (!validarFecha (f))
                    printf ("la fecha es invalida\n");
                else
                {
                    f2 = darfechamayor (listasuc);
                    if (!fechaapta(f2,f))
                        printf ("la fecha ingresada no es posterior a todas las fechas ingresadas en el sistema\n");
                    else
                    {
                        devolver3s (listastring, snombre);
                        if (!esAlfabetico (snombre))
                            printf ("el nombre del miembro no es alfabetico\n");
                        else
                        {
                            if (!PerteneceABB (familiareal, snombre))
                                printf ("el miembro no existe\n");
                            else
                            {
                                miembrolista m;
                                m = darmiembroS (listasuc, snombre);
                                if (fallecio (m))
                                {
                                    printf ("el miembro ya fallecio\n");
                                }
                                else
                                {
                                    ejecutarFallecimientoAux (familiareal, listasuc, snombre, f);
                                    printf ("fallecimiento registrado\n");
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    strdestruir (sfecha);
    strdestruir (snombre);
}

void ejecutarAbdicacionAux (ABB &familiareal, ListaSucesion &listasuc, string nombre, fecha abdicacion)
{
    string nombre2;
    boolean encontro = FALSE;
    ListaSucesion aux = listasuc;
    while (aux != NULL && !encontro)
    {
        strcrear (nombre2);
        darnombre (darmiembro(aux -> info), nombre2);
        if (streq (nombre2, nombre))
        {
            encontro = TRUE;
            strdestruir (nombre2);
            aux -> info.abdicacion = abdicacion;
            aux -> info.abdico = TRUE;
            if (esactualM (aux -> info))
            {
                aux -> info.fue_monarca = TRUE;
                aux -> info.monarca_actual = FALSE;
                nuevomonarca (listasuc, nombre, abdicacion);
            }
            else
                if (esAsp (aux -> info))
                    aux -> info.aspirante = FALSE;
        }
        else
        {
            aux = aux -> sig;
            strdestruir (nombre2);
        }
    }
}

void ejecutarAbdicacion (ListaString listastring, ABB &familiareal, ListaSucesion &listasuc, comando com)
{
    string sfecha,snombre;
    strcrear (sfecha);
    strcrear (snombre);
    fecha f,f2;
    if (com == ABDICACION)
    {
        if (LargoIter (listastring) != 3)
            printf ("cantidad de parametros incorrecta\n");
        else
        {
            devolver2s (listastring, sfecha);
            if (!stringEsFecha (sfecha))
                printf ("el formato de la fecha es invalido\n");
            else
            {
                f = stringAFecha (sfecha);
                if (!validarFecha (f))
                    printf ("la fecha es invalida\n");
                else
                {
                    f2 = darfechamayor (listasuc);
                    if (!fechaapta(f2,f))
                        printf ("la fecha ingresada no es posterior a todas las fechas ingresadas en el sistema\n");
                    else
                    {
                        devolver3s (listastring, snombre);
                        if (!esAlfabetico (snombre))
                            printf ("el nombre del miembro no es alfabetico\n");
                        else
                        {
                            if (!PerteneceABB (familiareal, snombre))
                                printf ("el miembro no existe\n");
                            else
                            {
                                miembrolista m;
                                m = darmiembroS (listasuc, snombre);
                                if (abdico (m) || fallecio(m))
                                {
                                    if (abdico (m))
                                        printf ("el miembro ya abdico\n");
                                    else
                                        printf ("el miembro ya fallecio\n");
                                }
                                else
                                {
                                    ejecutarAbdicacionAux (familiareal, listasuc, snombre, f);
                                    printf ("abdicacion registrada\n");
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    strdestruir (sfecha);
    strdestruir (snombre);
}

void ejecutarMiembros (ListaString listastring, ABB familiareal, comando com)
{
    if (com == MIEMBROS)
    {
        if (LargoIter (listastring) != 1)
            printf ("cantidad de parametros incorrecta\n");
        else
        {
            if (EsVacio (familiareal))
                printf ("no hay ningun miembro en la dinastia\n");
            else
            {
                listarMiembros (familiareal);
                printf ("\r");
            }
        }
    }
}

void ejecutarMonarcasAux (ListaSucesion listasuc)
{
    int i = 1;
    while (listasuc != NULL)
        {
            if (esactualM (listasuc -> info) || fueM (listasuc -> info))
            {
                printf ("%d - ", i);
                listarMonarcas (listasuc->info);
                i++;
            }
            listasuc = listasuc -> sig;
        }
}

void ejecutarMonarcas (ListaString listastring, ListaSucesion listasuc, comando com)
{
    if (com == MONARCAS)
    {
        if (LargoIter (listastring) != 1)
            printf ("cantidad de parametros incorrecta\n");
        else
        {
            if (Vacia (listasuc))
                printf ("no ha habido ningun monarca en la lista\n");
            else
            {
                ejecutarMonarcasAux (listasuc);
                printf ("\r");
            }
        }
    }
}

void ejecutarAspirantesAux (ListaSucesion listasuc)
{
    int i = 1;
    if (!hayAspirantes (listasuc))
        printf ("no hay aspirantes en la lista\n");
    else
    {
        while (listasuc != NULL)
        {
            if (esAsp (listasuc -> info))
            {
                printf ("%d - ", i);
                listarAsp (listasuc -> info);
                i++;
            }
            listasuc = listasuc -> sig;
        }
    }
}

void ejecutarAspirantes (ListaString listastring, ListaSucesion listasuc, comando com)
{
    if (com == ASPIRANTES)
    {
        if (LargoIter (listastring) != 1)
            printf ("cantidad de parametros incorrecta\n");
        else
        {
            if (Vacia (listasuc))
                printf ("la lista no tiene aspirantes\n");
            else
            {
                ejecutarAspirantesAux (listasuc);
                printf ("\r");
            }
        }
    }
}

void ejecutarHistorial (ListaString listastring, ListaSucesion listasuc, comando com)
{
    if (com == HISTORIAL)
    {
        if (LargoIter (listastring) != 1)
            printf ("cantidad de parametros incorrecta\n");
        else
        {
            if (Vacia (listasuc))
                printf ("la lista no tiene ningun miembro\n");
            else
            {
                mostrarlista (listasuc);
                printf ("\r");
            }
        }
    }
}

void ejecutarRespaldar (ListaString listastring, ABB familiareal, ListaSucesion listasuc, comando com)
{
    if (com == RESPALDAR)
    {
        if (LargoIter (listastring) != 1)
            printf ("cantidad de parametros incorrecta\n");
        else
        {
            if (Vacia (listasuc))
                printf ("la lista no tiene ningun miembro\n");
            else
            {
                if (EsVacio (familiareal))
                    printf ("el arbol no tiene ningun miembro\n");
                else
                {
                    Bajar_Lista (listasuc, "listasucesionA.dat");
                    Bajar_ABB (familiareal, "familiarealA.dat");
                    printf ("informacion respaldada con exito\n");
                }
            }
        }
    }
}

void ejecutarRecuperar (ListaString listastring, ABB &familiareal, ListaSucesion &listasuc, comando com)
{
    if (com == RECUPERAR)
    {
        if (LargoIter (listastring) != 1)
            printf ("cantidad de parametros incorrecta\n");
        else
        {
            if (!Vacia (listasuc))
                printf ("la lista no esta vacia\n");
            else
            {
                if (!EsVacio (familiareal))
                    printf ("el arbol no esta vacio\n");
                else
                {
                    if (!Existe ("familiarealA.dat") && !Existe ("listasucesionA.dat"))
                        printf ("no hay archivos para recuperar\n");
                    else
                        {
                            Levantar_Lista (listasuc, "listasucesionA.dat" );
                            Levantar_ABB (familiareal, "familiarealA.dat");
                            printf ("informacion recuperada con exito\n");
                        }
                }
            }
        }
    }
}

void ejecutarSalir (ListaString listastring, ABB &familiareal, ListaSucesion &listasuc, comando &com)
{
    if (com == SALIR)
    {
        if (LargoIter (listastring) != 1)
        {
            printf ("cantidad de parametros incorrecta\n");
            com = ERROR;
        }
        else
        {
            Eliminar (familiareal);
            BorrarLista (listasuc);
            printf ("hasta la proxima");
        }
    }
}


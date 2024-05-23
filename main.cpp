#include <stdio.h>
#include <stdlib.h>
#include "parsing.h"

int main()
{
//VARIABLES

    string s;
    char c;
    comando comando;
    ListaString lstring;
    ListaSucesion lsuc;
    ABB familia;

//COMANDOS

    CrearABB (familia);
    CrearLista (lsuc);

//MENU

    printf ("Bienvenidos a la dinastia\n\n");
    printf ("Lista de comandos:\n\n");
    printf ("  - Iniciar: da inicio a la dinastia, registrando el primer monarca de la familia real.\n");
    printf ("  - Nacimiento: registra el nacimiento de un nuevo miembro de la familia real.\n");
    printf ("  - Fallecimiento: registra el fallecimiento de un miembro de la familia real.\n");
    printf ("  - Abdicacion: registra la abdicacion de un miembro de la familia real.\n");
    printf ("  - Miembros: lista todos los miembros de la familia real desde el inicio de la dinastia.\n");
    printf ("  - Monarcas: lista todos los monarcas que ha habido desde el inicio de la dinastia.\n");
    printf ("  - Aspirantes: lista los actuales aspirantes al trono, segun su orden en la linea de sucesion.\n");
    printf ("  - Historial: lista todo el historial de la linea de sucesion desde el inicio de la dinastia.\n");
    printf ("  - Respaldar: guarda en disco toda la informacion manejada por el sistema.\n");
    printf ("  - Recuperar: recupera nuevamente a memoria toda la informacion almacenada en disco.\n");
    printf ("  - Salir: sale de la aplicacion, liberando toda la memoria dinamica utilizada.\n");
    printf ("\nPRESIONE ENTER PARA CONTINUAR\n\n");
    scanf ("%c", &c);
    fflush (stdin);
    system("cls");

    printf ("\n Orden de los parametros a ingresar\n\n");
    printf ("  - Iniciar fecha nombre\n");
    printf ("  - Nacimiento fecha nombreProgenitor -> nombreNuevo\n");
    printf ("  - Fallecimiento fecha nombre\n");
    printf ("  - Abdicacion fecha nombre\n");
    printf ("  - Miembros\n");
    printf ("  - Monarcas\n");
    printf ("  - Aspirantes\n");
    printf ("  - Historial\n");
    printf ("  - Respaldar\n");
    printf ("  - Recuperar\n");
    printf ("  - Salir\n");

    printf ("\n Forma de ingresarlos:\n");
    printf ("\n  - Todos los parametros ingresados deben estar separados por al menos un espacio, de lo contrario saltara un error.");
    printf ("\n  - Todos los comandos deben ser ingresados con la cantidad justa de parametros, de lo contrario saltara un error.");
    printf ("\n  - El parametro fecha debe ser ingresado en el formato dd/mm/aaaa, de lo contrario saltara un error.");
    printf ("\n  - El parametro nombre debe ser ingresado de forma alfabetica, es decir solo letras, de lo contrario saltara un error.\n\n");

//EJECUCION

    do
    {
        printf ("Ingrese comando:  ");
        strcrear (s);
        scan (s);
        printf ("Resultado:        ");
        while (s [0] == '\0')
        {
            printf ("debes ingresar algo\n");
            strdestruir (s);
            printf ("Ingrese comando:  ");
            scan (s);
            printf ("Resultado:        ");
        }
        pasaramayuscula (s);
        CrearListaString (lstring);
        dividirString (lstring, s);
        comando = identificarcomando (lstring);
        switch (comando)
        {
            case INICIAR: ejecutarIniciar (lstring, familia, lsuc, comando); break;
            case NACIMIENTO: ejecutarNacimiento (lstring, familia, lsuc, comando); break;
            case FALLECIMIENTO: ejecutarFallecimiento (lstring, familia, lsuc, comando); break;
            case ABDICACION: ejecutarAbdicacion (lstring, familia, lsuc, comando); break;
            case MIEMBROS: ejecutarMiembros (lstring, familia, comando); break;
            case MONARCAS: ejecutarMonarcas (lstring, lsuc, comando); break;
            case ASPIRANTES: ejecutarAspirantes (lstring, lsuc, comando); break;
            case HISTORIAL: ejecutarHistorial (lstring, lsuc, comando); break;
            case RESPALDAR: ejecutarRespaldar (lstring, familia, lsuc, comando); break;
            case RECUPERAR: ejecutarRecuperar (lstring, familia, lsuc, comando); break;
            case SALIR: ejecutarSalir (lstring, familia, lsuc, comando); break;
            case ERROR: printf ("ingresaste un comando que no existe\n");
        }
        strdestruir (s);
        BorrarLS (lstring);
    }
    while (comando!= SALIR);
}






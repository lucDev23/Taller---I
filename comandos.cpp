#include <stdio.h>
#include "comandos.h"

//ARREGLAR

comando identificarcomando (ListaString l)
{
    string s;
    strcrear (s);
    strcop (s,l -> info);
    if (streq ("INICIAR", s))
        return INICIAR;
    else
        if (streq ("NACIMIENTO", s))
            return NACIMIENTO;
        else
            if (streq ("FALLECIMIENTO", s))
                return FALLECIMIENTO;
            else
                if (streq ("ABDICACION", s))
                    return ABDICACION;
                else
                    if (streq ("MIEMBROS", s))
                        return MIEMBROS;
                    else
                        if (streq ("MONARCAS", s))
                            return MONARCAS;
                        else
                            if (streq ("ASPIRANTES", s))
                                return ASPIRANTES;
                            else
                                if (streq ("HISTORIAL", s))
                                    return HISTORIAL;
                                else
                                    if (streq ("RESPALDAR", s))
                                        return RESPALDAR;
                                    else
                                        if (streq ("RECUPERAR", s))
                                            return RECUPERAR;
                                        else
                                            if (streq ("SALIR", s))
                                                return SALIR;
                                            else
                                                return ERROR;
}



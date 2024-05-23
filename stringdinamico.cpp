#include <stdio.h>
#include "stringdinamico.h"

void strcrear (string &str)
{
    str = new char [1];
    str [0] = '\0';
}

void strdestruir (string &str)
{
    delete [] str;
    str = NULL;
}

int strlar (string s)
{
    int i = 0;
    while (s[i] != '\0')
        i++;
    return i;
}

void print (string s)
{
    int i = 0;
    while(s[i]!= '\0')
    {
        printf ("%c", s[i]);
        i++;
    }
}

void strcop(string &str1,string str2)
{
    int i=0;
    int largo = strlar (str2)+1;
    delete [] str1;
    str1 = new char [largo];
    while(str2[i] != '\0')
    {
        str1[i] = str2[i];
        i++;
    }
    str1[i]='\0';
}

void scan (string &s)
{
    string aux = new char[MAX];
    int i=0;
    char c;
    fflush (stdin);
    scanf ("%c", &c);
    while (c!= '\n' && i < MAX-1)
    {
        aux[i] = c;
        i++;
        scanf ("%c", &c);
    }
    aux[i] = '\0';
    strcop (s,aux);
    strdestruir (aux);
}


boolean strmen (string str1, string str2)
{
    int i=0; boolean boo=FALSE;
    while(str1[i] != '\0' && str2[i] != '\0')
    {
        if(str1[i] != str2[i])
            if(str1[i] < str2[i])
                boo = TRUE;
        i++;
    }
    return(boo);
}

boolean streq (string str1, string str2)
{
    boolean iguales = TRUE;
    int i=0;
    while (str1[i] != '\0' && str2[i] != '\0' && iguales == TRUE)
        {
        if (strlar(str1) != strlar(str2))
            iguales = FALSE;
        else
            {
            if (str1[i] == str2[i])
                i++;
            else
                iguales = FALSE;
            }
        }
    return(iguales);
}

boolean stringEsFecha (string s) //PREGUNTAR
{
    int i=0;
    boolean fecha = TRUE;
    if (strlar (s) != 10)
        fecha = FALSE;
    while (s [i] != '\0' && fecha != FALSE)
    {
        if ((s [i] < '0' || s [i] > '9') && (i >= 0 && i <=1))
            fecha = FALSE;
        else
            if (s [i] != '/' && i == 2)
                fecha = FALSE;
            else
                if ((s [i] < '0' || s [i] > '9') && (i >= 3 && i <=4))
                    fecha = FALSE;
                else
                    if (s [i] != '/' && i == 5)
                        fecha = FALSE;
                    else
                        if ((s [i] < '0' || s [i] > '9') && (i >= 6 && i <=9))
                            fecha = FALSE;
        i++;
    }
    return fecha;
}

void pasaramayuscula (string &s)
{
    int i=0;
    while (s [i] != '\0')
    {
        if (s [i] >= 'a' && s [i] <= 'z')
            s [i] = s [i] - 32;
        i++;
    }
}

boolean esAlfabetico (string s)
{
    int i=0;
    boolean nombre = TRUE;
    pasaramayuscula (s);
    while (s [i] != '\0' && nombre != FALSE)
    {
        if (s [i] < 'A' || s [i] > 'Z')
            nombre = FALSE;
        i++;
    }
    return nombre;
}

void Bajar_String (string s, FILE * f)
{
    int i=0;
    while (s[i] != '\0')
    {
        fwrite (&s[i], sizeof(char), 1, f);
        i++;
    }
    // escribo el '\0'
    fwrite (&s[i], sizeof(char), 1, f);
}
void Levantar_String (string &s, FILE * f)
{
    int i=0;
    string aux;
    aux = new char[MAX];
    fread (&aux[i], sizeof(char), 1, f);
    while (!feof(f) && (aux[i] != '\0'))
    {
        i++;
        fread (&aux[i], sizeof(char), 1, f);
    }
    strcop (s, aux);
    delete [] aux;
}

boolean stringpref (string s, string s2)
{
    boolean preferencia = FALSE, resultado = FALSE;
    int i=0;
    while ((s2 [i] != '\0' || s [i] != '\0') && !resultado)
    {
        if (s2 [i] < s [i])
        {
            resultado = TRUE;
            preferencia = TRUE;
        }
        else
            if (s2 [i] > s [i])
            {
                resultado = TRUE;
                preferencia = FALSE;
            }
            else
                if (s2 [i] == s [i])
                    i++;
    }
    return preferencia;
}


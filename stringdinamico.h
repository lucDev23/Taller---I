#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED
#include "boolean.h"

const int MAX = 200;
typedef char * string;

void strcrear (string &str);

void strdestruir (string &str);

int strlar(string str);

void print(string str);

void strcop(string &str1,string str2);

void scan(string &str);

boolean streq(string str1, string str2);

boolean stringEsFecha (string s);

void pasaramayuscula (string &s);

boolean esAlfabetico (string s);

boolean stringpref (string s, string s2);

void Bajar_String (string s, FILE * f);
// Escribe en el archivo los caracteres del string s (incluido '\0')
// Precondición: El archivo viene abierto para escritura.
void Levantar_String (string &s, FILE * f);
// Lee desde el archivo los caracteres del string s.
// Precondición: El archivo viene abierto para lectura.


#endif // STRING_H_INCLUDED

#ifndef MIBIBLIOTECHA_H_INCLUDED
#define MIBIBLIOTECHA_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int pedirName(char name[],char mensaje[],char mensajeError[], int len);
int validarName(char name[],int len);
int pedirEntero(int* entero,char mensaje[],char mensajeError[],int limSup,int limInf);
int validarRangoEntero(int num,  int limSuperior,int limInferior);
int validarCaracter(char auxChar, char a, char b);
float aplicarDescuento(float precio, int porcentajeDescuento);
float aplicarAumento(float precio, int porcentajeAumento);
int invertirPalabra(char* palabra);


#endif // MIBIBLIOTECHA_H_INCLUDED

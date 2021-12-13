#include "menus.h"


/** \brief menu principal
 *
 * \return int opcion elegida por el usuario
 *
 */
int menu()
{

    int opcion=0;
    system("cls");
    printf("     ***RECU*** \n");
    printf("                          \n");
    printf("  1-    cargar archivo    \n");
    printf("  2-    imprimir lista     \n");
    printf("  3-    asignar estadistica \n");
    printf("  4-    filtrar mejores posteos\n");
    printf("  5-    filtrar por heaters\n");
    printf("  6-    ordenar por nivel\n");
    printf("  7-    mostrar mas popular \n");
    printf("  8-    guardar binario\n");
    printf("  9-    lectura binaria \n ");
    printf("  10- Salir\n");
    printf("Ingrese opcion: ");

    while(!(scanf("%d",&opcion)))
    {

        printf("Opcion no valida Reingrese opcion\n");
        fflush(stdin);

    }

    return opcion;

}



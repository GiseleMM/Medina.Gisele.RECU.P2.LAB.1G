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
    printf("  1-        \n");
    printf("  2-         \n");
    printf("  3-   \n");
    printf("  4-   \n");
    printf("  5-  \n");
    printf("  6-  \n");
    printf("  7-  \n");
    printf("  8- Salir\n");
    printf("Ingrese opcion: ");

    while(!(scanf("%d",&opcion)))
    {

        printf("Opcion no valida Reingrese opcion\n");
        fflush(stdin);

    }

    return opcion;

}

/** \brief submenu de filatrado
 *
 * \return int opcion elegida
 *
 */
int menuFilter()
{

    int opcion=0;
    system("cls");
    printf("     ***ELIGA opcion de filtrado*** \n");
    printf("  1-    cargar archivo    \n");
    printf("  2-    imprinir lista     \n");
    printf("  3-    asignar estadistica \n");
    printf("  4-    filtrar mejores posteos\n");
    printf("  5-   filtrar por headers\n");
    printf("  6-  ordenar por nivel\n");
    printf("  7-   mostrar mas popular n");
    printf("  8- Salir\n");
    printf("Ingrese opcion: ");

    while(!(scanf("%d",&opcion)))
    {

        printf("Opcion no valida Reingrese opcion\n");
        fflush(stdin);

    }

    return opcion;

}
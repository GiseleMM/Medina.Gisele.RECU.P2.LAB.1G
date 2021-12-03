#include <stdio.h>
#include <stdlib.h>
#include "MiBibliotecha.h"
#include "LinkedList.h"
#include <time.h>
#include "menus.h"
#include "post.h"
#include "controller.h"


int main()
{
    ///https://github.com/GiseleMM/Medina.Gisele.RECU.P2.LAB.1G.git

    srand(time(NULL));

    /* https://github.com/GiseleMM/Medina.Gisele.P2.Lab1G.git
     printf("Hello world!\n");
     srand(time(NULL));
     float numero;
     int max=100;
     int min=10;
     numero=(float)(rand()% (max - min +1)+min)/10;//3 decimales divido por 100
     printf("%f\n",numero);
     numero=(float)(rand()% (max - min +1)+min)/10;//3 decimales divido por 100
     printf("%f\n",numero);
     numero=(float)(rand()% (max - min +1)+min)/10;//3 decimales divido por 100
     printf("%f\n",numero);*/

    LinkedList*  lista=ll_newLinkedList();
    if(lista==NULL)
    {
        printf("No se pudo crear lista \n");
        exit(1);
    }

    int seguir=0;
    int seCargo=0;
    char path[50];
    char confirma[3];
    do
    {
        switch(menu())
        {
        case 1:
            printf("ingrese al case 1\n");
            if(ll_isEmpty(lista) || seCargo==0)
            {
                fflush(stdin);
                printf("ingrese path ");
                gets(path);
                if(controller_loadFromText(path,lista))
                {
                    seCargo=1;
                    printf("archivo cargado con exito\n");
                }
            }
            else
            {
                printf("ya hay lista en el sistema\n");
            }


            break;

        case 2:
            printf("ingrese al case 2\n");
            if(!ll_isEmpty(lista))/*no esta vacia*/
            {
                controller_listar(lista);
            }
            else
            {
                printf("no hay elementos en la lista\n");
            }
            break;

        case 3:
            printf("ingrese al case 3\n");
            if(!ll_isEmpty(lista))
            {
                controller_asignarEstadistica(lista);
            }
            else
            {
                printf("no hay elementoas en la lista\n");
            }

            break;

        case 4:
            if(!ll_isEmpty(lista))
            {
                    if(controller_filtrarMejorPost(lista))
                    {
                        printf("filtrado exitoso\n");
                    }
            }
            else
            {
                printf("lista vacia\n");
            }


            break;


        case 5:
            if(!ll_isEmpty(lista))
            {
                    if(controller_filtrarHeaters(lista))
                    {
                        printf("filtrado exitoso\n");
                    }
            }
            else
            {
                printf("lista vacia\n");
            }

            break;


        case 6:
            if(!ll_isEmpty(lista))
            {
                    if(controller_ordenar(lista))
                    {
                        printf("ordenamiento exitoso\n");
                    }
            }
            else
            {
                printf("lista vacia\n");
            }

            break;

        case 7:
            if(!ll_isEmpty(lista))
            {
                    if(controller_mayorFollowers(lista))
                    {
                        printf(" mas popular exitoso\n");
                    }
            }
            else
            {
                printf("lista vacia\n");
            }
            break;
        case 8:
            printf("ingrese aSALIR confirma? si o no \n");
            fflush(stdin);
            gets(confirma);
            if(stricmp(confirma,"si")==0)
            {
                seguir=10;
            }
            break;/*
            if(seCargo==1 && !ll_isEmpty(lista))
            {
                fflush(stdin);
                printf("deseas guardar antes de salir?\n");
                gets(confirmar);
                if(stricmp(confirmar,"si")==0)
                {
                    controller_saveAsText(path,lista);
                    seCargo=1;

                }
                else
                {
                    seguir=10;
                }
            }
            else
            {
                seguir=10;
            }
            break;*/
        default:
            printf("opcion no valida Reingrese opcion\n");
            break;


        }
        system("pause");
    }
    while(seguir!=10);

    return 0;
}
////////////////////////////////////////////////////MAIN



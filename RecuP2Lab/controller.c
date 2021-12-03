#include "controller.h"



int controller_saveAsText(char* path, LinkedList* pArrayListposts)
{
    int todoOk=0;
    FILE* aux=NULL;
    int tam;//deLL-LEN
    char confirma[3];
    int id;
    char user[50];
    int likes;
    int deslikes;
    float followers;
    ePost* auxpost=NULL;
    if(path!=NULL && pArrayListposts!=NULL)
    {
        aux=fopen(path,"r");
        if(aux!=NULL)
        {
            fclose(aux);
            printf("El archivo ya exite desea sobreescribirlo confirmar :\n");
            fflush(stdin);
            gets(confirma);
        }

        if(aux==NULL || (stricmp(confirma,"si")==0))
        {
            FILE*pFile=fopen(path,"w");
            if(pFile!=NULL)
            {
                tam=ll_len(pArrayListposts);
                if(tam>0)
                {
                    fprintf(pFile, "id,user,likes,deslikes,followers\n");
                    for(int i=0; i<tam; i++)
                    {
                        auxpost=(ePost*)ll_get(pArrayListposts,i);
                        if(auxpost!=NULL)
                        {
                            if(post_getid(auxpost,&id)&&
                                    post_getuser(auxpost,user)&&
                                    post_getlikes(auxpost,&likes)&&
                                    post_getdeslikes(auxpost,&deslikes)&&
                                    post_getfollowers(auxpost,&followers))
                            {
                                fprintf(pFile, "%d,%s,%d,%d,%f\n",id,user,likes,deslikes,followers);
                            }
                        }
                    }
                }

                fclose(pFile);
            }
        }
    }
    return todoOk;
}

int controller_listar(LinkedList* lista)
{
    int todoOk=0;
    if(lista!=NULL)
    {
        todoOk=post_mostrarLista(lista);
    }
    return todoOk;
}

int controller_loadFromText(char* path,LinkedList* pArrayListposts)
{
    int todoOk=0;
    FILE*pFile=NULL;
    if(path!=NULL && pArrayListposts!=NULL)
    {
        pFile=fopen(path,"r");
        if(pFile==NULL)
        {
            printf("No se pudo abrir archivo %s\n",path);
        }
        else
        {
            if(parser_postFromText(pFile,pArrayListposts))
            {
                printf(" se cargo con exito archivo\n");
                todoOk=1;
            }

            fclose(pFile);
        }

    }


    return todoOk;
}
int controller_asignarEstadistica(LinkedList* lista)
{
    int todoOk=0;
    LinkedList* nuevo=NULL;
    if(lista!=NULL)
    {
        nuevo=ll_map(lista,asignarFollowers);
        nuevo=ll_map(lista,asignarDeslikes);
        nuevo=ll_map(lista,asignarLikes);
        if(nuevo!=NULL)
        {
            controller_listar(nuevo);
            todoOk=1;
        }
    }
    return todoOk;
}
///////////////////////FILTER
int controller_filtrarMejorPost(LinkedList* lista)
{
    int todoOk=0;
    char path[50];
    LinkedList* mejores=NULL;
    if(lista!=NULL)
    {
        mejores=ll_filter(lista,filtrarMejoresPosteos);
        if(mejores!=NULL)
        {
            if(ll_isEmpty(mejores))
            {
                printf("no hay elementos en la lista para guardar\n");

            }
            else
            {
                controller_listar(mejores);
                fflush(stdin);
                printf("ingrese path para guardar mejores posteo   ");
                gets(path);
                if(controller_saveAsText(path,mejores))
                {
                    printf("se guardo con exito, archivo generado\n");

                    todoOk=1;
                }
                else
                {
                printf("Error no se pudo guardar lista\n");
                }
            }

        }
    }
    return todoOk;
}
int controller_filtrarHeaters(LinkedList* lista)
{
    int todoOk=0;
    char path[50];
    LinkedList* heaters=NULL;
    if(lista!=NULL)
    {
        heaters=ll_filter(lista,filtrarHeaters);
        if(heaters!=NULL)
        {
            if(ll_isEmpty(heaters))
            {
                printf("no hay elementos en la lista para guardar\n");

            }
            else
            {
                controller_listar(heaters);
                fflush(stdin);
                printf("ingrese path para guardar heaters posteo   ");
                gets(path);
                if(controller_saveAsText(path,heaters))
                {
                    printf("se guardo con exito, archivo generado\n");

                    todoOk=1;
                }
                else
                {
                    printf("error no se pudo guardar lista\n");
                }
            }

        }
    }
    return todoOk;
}
int controller_ordenar(LinkedList* lista)
{
    int todoOk=0;
    if(lista!=NULL)
    {
        if(ll_sort(lista,ordenarPorFollowers,0)==0)
        {
            printf("ordenamiento exitoso \n");
            controller_listar(lista);

            todoOk=1;
        }
    }
    return todoOk;
}
int controller_mayorFollowers(LinkedList* lista)
{
    ePost* mayor=NULL;
    int todoOk=0;
    if(lista!=NULL)
    {
        if(ll_sort(lista,ordenarPorFollowers,0)==0)
        {
           mayor=(ePost*)ll_get(lista,0);
           if(mayor!=NULL)
           {
               printf("Mas Popular\n");
               post_mostrar(mayor);
               todoOk=1;
           }


        }
    }
    return todoOk;
}

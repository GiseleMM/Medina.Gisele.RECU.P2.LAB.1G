#include "parser.h"

//////PARSER
/** \brief Parsea los datos los datos de los posts desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListposts LinkedList*
 * \return int 0 Error 1 correcto
 *
 */
int parser_postFromText(FILE* pFile, LinkedList* pArrayListpost)
{
    int todoOk=0;
    int cant;
    char buffer[5][20];
    ePost* auxpost=NULL;
    if(pFile!=NULL && pArrayListpost!=NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]);
        do
        {
            //printf("INgrese a parser");
            //system("pause");
            cant=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]);
            if(cant<4)
            {
                break;
            }
            //system("pause");
            printf("%s- %s- %s- %s -%s \n", buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]);
            //CREO post
            auxpost=post_newParametros(buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]);
            if(auxpost!=NULL)
            {
                //post_mostrar(auxpost);
                //system("pause");
                //printf(">>>>add %d\n",ll_add(pArrayListpost,auxpost));
                ll_add(pArrayListpost,auxpost);
                todoOk=1;
                auxpost=NULL;
            }
        }
        while(!feof(pFile));


    }
    return todoOk;
}
int parser_postFromBinary(FILE* pFile, LinkedList* lista)
{
    int todoOk=0;
    ePost* aux=NULL;
    int cant;

    if(pFile!=NULL && lista!=NULL)
    {
        do{
                aux=post_new();
                if(aux!=NULL)
                {
                    cant=fread(aux,sizeof(ePost),1,pFile);
                    printf("cant %d \n",cant);
                    if(cant==1)
                    {
                        post_mostrar(aux);
                        ll_add(lista,aux);
                        printf("elemento agregado en el indice %d\n ",ll_indexOf(lista,aux));
                        todoOk=1;
                        aux=NULL;
                    }

                }

        }while(!feof(pFile));
    }
    return todoOk;

}

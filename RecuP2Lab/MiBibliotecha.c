#include "MiBibliotecha.h"

int validarName(char name[],int len)
{
    int todoOk=0;
    if(name!=NULL  && len>0)
    {
        if(strlen(name)<len)
        {
        	int i=0;
           while(name[i]!='\0')
           {
        	   todoOk=1;
                if(isdigit(name[i]))
                {
                	printf("ingrese a isdigit %d",i);
                    todoOk=-1;
                    break;
                }

                i++;
            }
        }
        else
        {
            todoOk=-1;
        }

    }
    //printf("retorno de validar name %d\n",todoOk);
    return todoOk;
}

int pedirName(char name[],char mensaje[],char mensajeError[], int len)
{
    int todoOk=0;
    if(name!=NULL && len>0)
    {
        todoOk=1;
        fflush(stdin);
        printf("%s", mensaje);
        gets(name);


        while(validarName(name,len)==-1)
        {
            fflush(stdin);
            printf("%s",mensajeError);
            gets(name);

        }
        strlwr(name);
        name[0]=toupper(name[0]);
        int i=1;
        while(name[i]!='\0')
        {
            if(name[i]==' ')
            {
                name[i+1]=toupper(name[i+1]);
            }
            i++;

        }

    }
//printf("retorno de pedir name %d\n",todoOk);
    return todoOk;


}
int validarRangoEntero(int num,  int limSuperior,int limInferior)
{
    int todoOk=0;
    if(num<=limSuperior && num>=limInferior)
    {
        todoOk=1;
    }
    return todoOk;
}
int pedirEntero(int* entero,char mensaje[],char mensajeError[],int limSup,int limInf)
{
    int todoOk=0;
    // int retornoValidarRango;
    int auxEntero;
    if(entero!=NULL && mensaje!=NULL && mensajeError!=NULL && limInf<=limSup)
    {
        todoOk=1;
        printf("%s\n",mensaje);
        while(!scanf("%d",&auxEntero))
        {
            fflush(stdin);
            printf("%s\n",mensajeError);

        }

        //retornoValidarRango=validarRangoEntero(auxSector,10,0);
        //printf("%d",  retornoValidarRango);
        //system("pause");
        while(!validarRangoEntero(auxEntero,limSup,limInf))
        {
            // printf("Ingrese a validar rango");

            fflush(stdin);
            printf("%s",mensajeError);
            scanf("%d",&auxEntero);
        }
        *entero=auxEntero;
    }
    return todoOk;
}

int validarCaracter(char auxChar, char a, char b)
{

    int todoOk=1;
    if(auxChar!=a && auxChar!=b)
    {

        todoOk=0;
    }

    return todoOk;
}
float aplicarDescuento(float precio, int porcentajeDescuento)
{
    float nuevoPrecio=-1;
    if(precio>=0 && porcentajeDescuento>=0)
    {
        nuevoPrecio=precio-(precio*porcentajeDescuento/100);
    }
    return nuevoPrecio;
}
float aplicarAumento(float precio, int porcentajeAumento)
{
    float nuevoPrecio=-1;
    if(precio>=0 && porcentajeAumento>=0)
    {
        nuevoPrecio=precio-(precio*porcentajeAumento/100);
    }
    return nuevoPrecio;
}

int invertirPalabra(char* palabra)
{
    char aux;
    int todoOk=0;
    if(palabra!=NULL)
    {
        for(int i=0; i<(strlen(palabra))-1;i++)
        {
            for(int j=i+1;j<strlen(palabra);j++)
            {
                aux=palabra[i];
                palabra[i]=palabra[j];
                palabra[j]=aux;
            }


        }
        todoOk=1;
    }
    return todoOk;
}

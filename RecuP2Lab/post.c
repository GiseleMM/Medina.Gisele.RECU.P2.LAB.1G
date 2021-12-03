#include "post.h"


void post_mostrar(ePost* unpost)
{
    if(unpost!=NULL)
    {
        printf(" %6d - %-20s - %6d  %6d - %6.1f\n",unpost->id,
               unpost->user,
               unpost->likes,
               unpost->deslikes,
               unpost->followers);
    }
}
int post_mostrarposts(ePost* lista, int tam)
{
    int todoOk=0;
    if(lista!=NULL && tam>0)
    {
        printf("id    user                      likes  deslikes       followers\n");
        for(int i=0; i<tam; i++)
        {
            post_mostrar((lista+i));
        }
    }
    return todoOk;
}
ePost* post_new()
{
   ePost* nuevopost=NULL;
    nuevopost=(ePost*)malloc(sizeof(ePost));
    if(nuevopost!=NULL)
    {
        nuevopost->id=0;
        strcpy(nuevopost->user," ");
        nuevopost->likes=0;
        nuevopost->deslikes=0;
        nuevopost->followers=0.0;
    }
    return nuevopost;
}
ePost* post_newParametros(char* strid, char* struser, char* strlikes,char* strdeslikes, char* strfollowers)
{
   ePost* nuevopost=NULL;
    if(strid!=NULL && struser!=NULL && strlikes!=NULL && strfollowers!=NULL)
    {
        nuevopost=post_new();
        if(nuevopost!=NULL)
        {
            /* USO LS  SETTER
            nuevopost->id=atoi(strid);
            strcpy(nuevopost->user,struser);
            strcpy(nuevopost->likes,strlikes);
            nuevopost->followers=atof(strfollowers);*/
            //printf("%d",post_setid(nuevopost,atoi(strid)));
              //      printf("%d",post_setuser(nuevopost,struser));
                //    printf("%d",post_setlikes(nuevopost,atoi(strlikes)));
                  //  printf("%d",post_setdeslikes(nuevopost,atoi(strdeslikes)));
                    //printf("%d",post_setfollowers(nuevopost,atof(strfollowers)));
            if(!(post_setid(nuevopost,atoi(strid))&&
                    post_setuser(nuevopost,struser)&&
                    post_setlikes(nuevopost,atoi(strlikes))&&
                    post_setdeslikes(nuevopost,atoi(strdeslikes))&&
                    post_setfollowers(nuevopost,atof(strfollowers))))
            {
                free(nuevopost);/*si algun parametro no es valido libero memeoria y hago q el puntero apunte a NULL */
                nuevopost=NULL;
                //printf("ingrese a set invalido\n");
                //system("pause");
            }
        }
    }

    return nuevopost;
}
ePost* post_newParam(int id, char* user, int likes, int deslikes, float followers)
{
   ePost* nuevopost=NULL;
    if(user!=NULL)
    {
        nuevopost=post_new();
        if(nuevopost!=NULL)
        {
            /* USO LS  SETTER
            nuevopost->id=atoi(strid);
            strcpy(nuevopost->user,struser);
            strcpy(nuevopost->likes,strlikes);
            nuevopost->followers=atof(strfollowers);*/

            if(!((post_setid(nuevopost,id))&&
                    post_setuser(nuevopost,user)&&
                    post_setlikes(nuevopost,likes)&&
                    post_setdeslikes(nuevopost,deslikes)&&
                    post_setfollowers(nuevopost,followers)))
            {
                free(nuevopost);/*si algun parametro no es valido libero memeoria y hago q el puntero apunte a NULL */
                nuevopost=NULL;
            }
        }
    }

    return nuevopost;
}
//////////SETTERS
int post_setid(ePost* post, int id)
{
    int todoOk=0;
    if(post!=NULL)
    {
        post->id=id;
        todoOk=1;

    }
    return todoOk;
}
int post_setuser(ePost* post, char* user)
{
    int todoOk=0;
    if(post!=NULL && user!=NULL && strlen(user)>=0)
    {
        todoOk=1;
        strcpy(post->user, user);

    }
    return todoOk;
}
int post_setlikes(ePost* post, int likes)
{
    int todoOk=0;
    if(post!=NULL)
    {
        todoOk=1;
        post->likes= likes;

    }
    return todoOk;

}
int post_setdeslikes(ePost* post, int deslikes)
{
    int todoOk=0;
    if(post!=NULL )
    {
        post->deslikes=deslikes;
        todoOk=1;
    }
    return todoOk;
}
int post_setfollowers(ePost* post, float followers)
{
    int todoOk=0;
    if(post!=NULL )
    {
        todoOk=1;
        post->followers=followers;

    }
    return todoOk;
}
///////////////GETTERS
int post_getid(ePost* post, int* id)
{
    int todoOk=0;
    if(post!=NULL && id!=NULL)
    {
        todoOk=1;
        *id=post->id;
    }

    return todoOk;
}
int post_getuser(ePost* post, char* user)
{
    int todoOk=0;
    if(post!=NULL && user!=NULL)
    {
        todoOk=1;
        strcpy(user,post->user);
    }

    return todoOk;
}
int post_getlikes(ePost* post, int* likes)
{
    int todoOk=0;
    if(post!=NULL && likes!=NULL)
    {
        todoOk=1;
        *likes=post->likes;

    }

    return todoOk;
}
int post_getdeslikes(ePost* post, int* deslikes)
{
    int todoOk=0;
    if(post!=NULL && deslikes!=NULL)
    {
        todoOk=1;
        *deslikes=post->deslikes;

    }

    return todoOk;
}
int post_getfollowers(ePost* post, float* followers)
{
    int todoOk=0;
    if(post!=NULL && followers!=NULL)
    {
        todoOk=1;
        *followers=post->followers;
    }

    return todoOk;
}
/////////DESTROY
void post_destroy(ePost* post)
{
    if(post!=NULL)
    {
        free(post);
    }
}
int post_mostrarLista(LinkedList* pArrayListposts)
{
    int todoOk=0;
   ePost* aux=NULL;
    int tam;
    if(pArrayListposts!=NULL)
    {
        tam=ll_len(pArrayListposts);
        if(tam>0)
        {
            printf("id      user        likes   deslikes    followers\n");

            for(int i=0; i<tam; i++)
            {
                todoOk=1;
                aux=(ePost*)ll_get(pArrayListposts,i);
                if(aux!=NULL)
                {
                    post_mostrar(aux);

                }
            }
        }

    }
    return todoOk;
}
void* asignarLikes(void* likes)
{
    int min=500;
    int max=5000;
    float likesAux;

    if(likes!=NULL)
    {
        likesAux= rand()% (max-min+1)+min;
        ((ePost*)likes)->likes=likesAux;
    }
    return (ePost*)likes;
}
void* asignarDeslikes(void* deslikes)
{
    int min=3000;
    int max=3500;
    float deslikesAux;

    if(deslikes!=NULL)
    {
        deslikesAux= rand()% (max-min+1)+min;
        ((ePost*)deslikes)->deslikes=deslikesAux;
    }
    return (ePost*)deslikes;
}
void* asignarFollowers(void* followers)
{
    int min=10000;
    int max=20000;
    float followersAux;

    if(followers!=NULL)
    {
        followersAux= rand()% (max-min+1)+min;
        ((ePost*)followers)->followers=followersAux;
    }
    return (ePost*)followers;
}
int filtrarMejoresPosteos(void* posteo)
{
    int esMejor=0;
    if(posteo!=NULL)
    {
        if(((ePost*)posteo)->likes >3000)
        {
            esMejor=1;
        }
    }

    return esMejor;
}
int filtrarHeaters(void* posteo)
{
    int esHeaters=0;
    if(posteo!=NULL)
    {
        if(((ePost*)posteo)->likes < ((ePost*)posteo)->deslikes)
        {
            esHeaters=1;
        }
    }

    return esHeaters;
}
//////ORDENAR
int ordenarPorFollowers(void* follower1, void* follower2)
{
    int comparacion=0;
    if(follower1!=NULL && follower2!=NULL)
    {
        if(((ePost*)follower1)->followers >  ((ePost*)follower2)->followers)
        {
         comparacion=1;
        }
        if(((ePost*)follower1)->followers <  ((ePost*)follower2)->followers)
        {
         comparacion=-1;
        }
    }
    return comparacion;
}

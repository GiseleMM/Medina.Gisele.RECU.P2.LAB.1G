#ifndef POST_H_INCLUDED
#define POST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "post.h"
#include <string.h>

typedef struct
{
    int id;
    char user[50];
    int likes;
    int deslikes;
    int followers;

} ePost;

//////ORDENAR
int ordenarPorFollowers(void* follower1, void* follower2);
//FILTRAR
int filtrarMejoresPosteos(void* posteo);
int filtrarHeaters(void* posteo);
//MAP
void* asignarDeslikes(void* deslikes);
void* asignarLikes(void* likes);
void* asignarFollowers(void* followers);


void post_mostrar(ePost* unpost);
int post_mostrarLista(LinkedList* pArrayListposts);
int post_mostrarposts(ePost* lista, int tam);

//CONSTRUCTORES
ePost* post_newParam(int id, char* user, int likes,int deslikes, int followers);
ePost* post_newParametros(char* strid, char* struser, char* strlikes,char* strdeslikes, char* strfollowers);
ePost* post_new();
//SETTERS
int post_setid(ePost* post, int id);
int post_setuser(ePost* post, char* user);
int post_setlikes(ePost* post, int likes);
int post_setdeslikes(ePost* post,int deslikes);
int post_setfollowers(ePost* post, int followers);
///////////////GETTERS
int post_getid(ePost* post, int* id);
int post_getuser(ePost* post, char* user);
int post_getlikes(ePost* post, int* likes);
int post_getdeslikes(ePost* post, int* deslikes);
int post_getfollowers(ePost* post, int* followers);

#endif // POST_H_INCLUDED
//MOSTRAR

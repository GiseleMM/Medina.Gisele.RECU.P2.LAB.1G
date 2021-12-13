#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

#include "LinkedList.h"
#include "post.h"
#include <stdio.h>
#include <stdlib.h>
#include "parser.h"

int controller_mayorFollowers(LinkedList* lista);
int controller_ordenar(LinkedList* lista);
int controller_filtrarHeaters(LinkedList* lista);
int controller_listar(LinkedList* lista);
int controller_saveAsBinary(char* path, LinkedList* pArrayListposts);
int controller_saveAsText(char* path, LinkedList* pArrayListposts);
int controller_loadFromBinary(char* path,LinkedList* pArrayListposts);
int controller_loadFromText(char* path,LinkedList* pArrayListposts);
int controller_asignarEstadistica(LinkedList* lista);
int controller_filtrarMejorPost(LinkedList* lista);
#endif // CONTROLLER_H_INCLUDED

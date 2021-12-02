#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED
#include "LinkedList.h"
#include "post.h"
#include <stdio.h>
#include <stdlib.h>
#include "parser.h"

int controller_listar(LinkedList* lista);
int controller_saveAsText(char* path, LinkedList* pArrayListposts);
int controller_loadFromText(char* path,LinkedList* pArrayListposts);
int controller_asignarEstadistica(LinkedList* lista);

#endif // CONTROLLER_H_INCLUDED

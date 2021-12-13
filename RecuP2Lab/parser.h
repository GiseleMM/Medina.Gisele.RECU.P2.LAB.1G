#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "post.h"

int parser_postFromText(FILE* pFile,LinkedList* pArrayListpost);
int parser_postFromBinary(FILE* pFile, LinkedList* lista);
#endif // PARSER_H_INCLUDED

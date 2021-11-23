/*
 * parser.c
 *
 *  Created on: 21 nov. 2021
 *      Author: caroo
 */



#include "parser.h"
#include <stdlib.h>
#include <stdio.h>
#include "LinkedList.h"
#include "arcades.h"

int parserArcadeFromTxt(FILE*pFile,LinkedList* pArray)
{
    int retorno=-1;
    int cant;
    char buffer[4][128];
    eArcades* newArcade=NULL;

    if(pFile!=NULL&&pArray!=NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);//leo el encabezado
        while(!feof(pFile))
        {
            cant=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);
            if(cant==4)
            {
                newArcade=arcade_newParams(atoi(buffer[0]),buffer[1],buffer[2][0],atof(buffer[3]));
                if(newArcade!=NULL)
                {
                    ll_add(pArray,newArcade);
                    retorno=0;
                }
            }else
            {
                break;
            }
        }

    }

    return retorno;
}

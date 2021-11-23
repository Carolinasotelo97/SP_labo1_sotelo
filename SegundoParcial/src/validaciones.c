/*
 * validaciones.c
 *
 *  Created on: 22 nov. 2021
 *      Author: caroo
 */




#include "validaciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int getInt(int* pNumber,char message[],char errorMessage[])
{
    char strNumber[32];
    int returnValue=-1;

    if(pNumber!=NULL)
    {
        puts(message);
        fflush(stdin);
        fgets(strNumber,sizeof(strNumber),stdin);
        strNumber[strlen(strNumber)-1]='\0';

        while(validatePositiveInteger(strNumber)==-1)
        {
            puts(errorMessage);
            fflush(stdin);
            fgets(strNumber,sizeof(strNumber),stdin);
            strNumber[strlen(strNumber)-1]='\0';
        }

        *pNumber=atoi(strNumber);

        returnValue=0;
    }

    return returnValue;
}

int validatePositiveInteger(char number[])
{
    int returnValue=0;

    for(int i=0;number[i]!='\0';i++)
    {
        if(number[i]<'0'||number[i]>'9')
        {
            returnValue=-1;
            break;
        }
    }

    return returnValue;
}

int getFloat(float* pFloat,char message[],char errorMessage[])
{
    char strFloat[32];
    int returnValue=-1;

    if(pFloat!=NULL)
    {
        puts(message);
        fflush(stdin);
        fgets(strFloat,sizeof(strFloat),stdin);
        strFloat[strlen(strFloat)-1]='\0';

        while(validatePositiveFloat(strFloat)==-1)
        {
            puts(errorMessage);
            fflush(stdin);
            fgets(strFloat,sizeof(strFloat),stdin);
            strFloat[strlen(strFloat)-1]='\0';
        }

        *pFloat=atof(strFloat);

        returnValue=0;
    }

    return returnValue;
}

int validatePositiveFloat(char numberFloat[])
{
    int returnValue=0;
    int pointCounter=0;

    for(int i=0;numberFloat[i]!='\0';i++)
    {
        if(numberFloat[i]<'0'||numberFloat[i]>'9')
        {
            if(numberFloat[i]=='.'&&pointCounter==0)
            {
                pointCounter++;
            }else
            {
                returnValue=-1;
                break;
            }
        }
    }

    return returnValue;
}

void getString(char string[],int len,char message[],char errorMessage[])
{
    puts(message);
    fflush(stdin);
    fgets(string,len,stdin);
    string[strlen(string)-1]='\0';

    while(isOnlyLetters(string)==-1)
    {
        puts(errorMessage);
        fflush(stdin);
        fgets(string,len,stdin);
        string[strlen(string)-1]='\0';
    }
}

int isOnlyLetters(char string[])
{
    int returnValue=0;

    for(int i=0;string[i]!='\0';i++)
    {
        if((string[i]<'a'||string[i]>'z')&&(string[i]<'A'||string[i]>'Z'))
        {
            returnValue=-1;
        }
    }

    return returnValue;
}

int getChar(char* pChar,char message[],char errorMessage[])
{
    char aux;
    int returnValue=-1;

    if(pChar!=NULL)
    {
        puts(message);
        fflush(stdin);
        scanf("%c",&aux);

        while((aux<'a'||aux>'z')&&(aux<'A'||aux>'Z'))
        {
            puts(errorMessage);
            fflush(stdin);
            scanf("%c",&aux);
        }

        *pChar=aux;
        returnValue=0;
    }

    return returnValue;
}

int getCharTwoOptions(char* pChar,char message[],char errorMessage[],char option1,char option2)
{
    int returnValue=-1;
    char aux;

    puts(message);
    fflush(stdin);
    scanf("%c",&aux);
    aux=tolower(aux);//lo paso a toLower para no tener que pasarlo en el main

    while(aux!=option1&&aux!=option2)
    {
        puts(errorMessage);
        fflush(stdin);
        scanf("%c",&aux);
        aux=tolower(aux);
    }

    *pChar=aux;
    returnValue=0;

    return returnValue;
}

/*
 ============================================================================
 Name        : SegundoParcial.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "arcades.h"
#include "menu.h"
#include "controller.h"
#include "LinkedList.h"
#include "validaciones.h"
int main(void) {

	setbuf(stdout, NULL);
	LinkedList* arcades=ll_newLinkedList();
	char confirma='n';
	int rta;
	int flag=0;//se levanta si se cargaron empleados desde el archivo

    do
    {
        switch(menu())
        {
        case 1:
            if(!flag)
            {
                if(!controller_chargeTxt(arcades,"arcades.csv"))
                {
                    printf("\nArcades cargados exitosamente!\n\n");
                    flag=1;
                }else
                {
                    printf("\nProblemas para cargar a los arcades\n\n");
                }
            }else
            {
                printf("\nLos arcades ya fueron cargados\n\n");
            }
            break;
        case 2:
            if(!controller_addArcade(arcades))
            {
                printf("\n\nAlta exitosa\n\n");
            }else
            {
                printf("\n\nProblemas para dar de alta\n\n");
            }
            break;
        case 3:
            if(!ll_isEmpty(arcades))
            {
                if(!controller_edit(arcades))
                {
                    printf("\nModificacion exitosa\n\n");
                }else
                {
                    printf("\nProblemas para modificar\n\n");
                }
            }else
            {
                printf("\nPrimero debe cargar algun arcade\n\n");
            }
            break;
        case 4:
            if(!ll_isEmpty(arcades))
            {
                if(controller_remove(arcades))
                {
                    printf("\nProblemas para dar de baja\n\n");
                }
            }else
            {
                printf("\nPrimero debe cargar algun arcade\n\n");
            }
            break;
        case 5:
            if(!ll_isEmpty(arcades))
            {
                if(!controller_sortArcade(arcades))
                {
                    printf("\nOrdenamiento exitoso!\n\n");
                }else
                {
                    printf("\nProblemas para dar de ordenar\n\n");
                }
            }else
            {
                printf("\nPrimero debe cargar algun arcade\n\n");
            }
            break;
        case 6:
            if(!ll_isEmpty(arcades))
            {
                system("cls");
                controller_listArcade(arcades);
            }else
            {
                printf("\nNo hay arcades para listar aun\n\n");
            }
            break;
        case 7:
            if(!controller_insertArcade(arcades))
            {
                printf("\nArcade agregado exitosamente!\n\n");
            }else
            {
                printf("\nProblemas para agregar arcade\nChequee que el indice indicado sea valido\n\n");
            }
            break;
        case 8:
            if(!ll_isEmpty(arcades))
            {
                rta=controller_clearList(arcades);
                if(rta==-1)
                {
                    printf("Problemas para cargar la lista\n\n");
                }else if(!rta)
                {
                    printf("La lista ya esta vacia\n\n");
                }else
                {
                    printf("Operacion cancelada\n\n");
                }
            }else
            {
                printf("\nPrimero debe cargar algun arcade\n\n");
            }
            break;
        case 9://ANDA MASO TESTEAR MAS
            if(!ll_isEmpty(arcades))
            {
                if(!controller_backupFile(arcades,"arcadesSeguridad.csv"))
                {
                    printf("\nArchivo de seguridad creado exitosamente\n\n");
                }else
                {
                    printf("\nNo se pudo crear el archivo\n\n");
                }
            }else
            {
                printf("\nNo hay estudiantes para listar aun\n\n");
            }
        break;
        case 10:
            if(!ll_isEmpty(arcades))
            {
                printf("\nPrimero cargue algun arcade\n\n");
            }else
            {
                if(!controller_saveAsTxt(arcades,"arcades.csv"))
                {
                    printf("\nArcades guardados exitosamente!\n\n");
                }else
                {
                    printf("\nProblemas al guardar arcades\n\n");
                }
            }
            break;
        default:
            printf("\nOpcion no valida\n\n");
            break;
        }

        printf("\n\nPresiona una tecla para continuar\n\n");
		getchar();
		fflush(stdin);
    }while(confirma!='s');

    ll_deleteLinkedList(arcades);//borro la lista cuando termina el programa
	return EXIT_SUCCESS;
}
